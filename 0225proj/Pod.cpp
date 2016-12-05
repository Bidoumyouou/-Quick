#include"Pod.h"
#include"Spot.h"
#include"Cursol.h"
#include"key.h"
#include"Resource.h"
#include "Pot.h"
#include"Item.h"
#include"GameMgr.h"
void Recipe::Set(SpotBehavior *_pod, E_ITEM _result, int _pool, int _time,int _mat1, int _mat2, int _mat3, int _mat4, int _mat5, int _mat6) {
	matel[0] = _mat1;
	matel[1] = _mat2;
	matel[2] = _mat3;
	matel[3] = _mat4;
	matel[4] = _mat5;
	matel[5] = _mat6;
	result = _result;
	pool = _pool;
	time = _time;
	pod = _pod;
}

bool PodBehavior::Behave()
{
	RecipeMgr();
	ButtonBehave();
	SuggestMgr();
	if (making != -1) {
		if (ispod()) {
			waitingmake = false;
			if (recipe[nowmake].pool == 0) {
				Convine();
			}
			else {
				Making();
			}
		}
		else {
			waitingmake = true;
			makingtimer++;
			if (makingtimer % 15 == 0) {
				//pod_anime_t = rapup(pod_anime_t,0,2);
				pod_anime_t.rapup(0, 2);
				MyPlaySound(sound[21], 100, 1);
			}
		}
	}
	Mes.Process(); MesP.Process();
	return true;
}


//今回最悪のアルゴリズム
void PodBehavior::Making() {
	if (stewflag == false) {
		stewflag = true;
		MyPlaySound(sound[25], 100, 3);
	}
	//混ぜるところの処理
	Vector2 mouse;
	mouse.x = MouseX;
	mouse.y = MouseY;
	if (mouse.InSquare(Pool.x , Pool.y, Pool.x + 96 * 2,Pool.y + 96 * 2)) {
		//マウスがプールに入ったら
		for (int i = 0; i < 4; i++) {
			if (mouse.InSquare(PoolSector[i], PoolSector[i] + PoolSectorSize)) {
				if (mixstate == -1) {
					mixstate = i;
					mixflag++;
					break;
				}
				//向きを決める箇所
				if (mixflag == 1) {
					//時計回り
					if (mixstate == (i + 1) % 4) {
						mixstate = i;
						mixflag++;
						mixangle = false;
						break;
					}
					//反時計回り
					if (mixstate== (i + 3) % 4) {
						mixstate = i;
						mixflag++;
						mixangle = true;
						break;
					}
				}
				int nowmake = suggest[nowsuggest];
				if (mixstate == (i + 1) % 4 && mixangle == false) {
					mixstate = i;
					mixflag++;
					if (mixflag >= makingpool) {
						Convine();
					}
					break;
				}
				if (mixstate  == (i + 3)% 4 && mixangle == true) {
					mixstate = i;
					mixflag++;
					if (mixflag >= makingpool) {
						Convine();
					}
					break;
				}

			}
		}
	}
	else {
		//mixflag = 0; 
		mixstate = -1;
	}
}

void PodBehavior::Convine() {
	Item::MakeItem(3,making);
	making = -1;
	mixflag = 0;
	mixstate = -1;
	nowsuggest = 0;
	nowmake = I_FAIL;
	stewflag = false;
	StopSoundMem(sound[25]);
	MyPlaySound(sound[7], 100, 1);

}

void PodBehavior::RecipeMgr() {
	suggest_num = 0;
	for (int i = 0; i < RECIPE_MAX; i++) {
		if (recipe[i].IsClear()) {
			suggest[suggest_num] = i;
			suggest_num = suggest_num + 1;
		}
	}
	for (int i = suggest_num; i < 24; i++) {
		suggest[i] = -1;
	}
}

bool Recipe::IsClear() {
	for (int i = 0; i < 6; i++) {
		Inpodmatel[i] = 0;
	}
	
	vector<Item>::iterator itr;
	vector<Item>::iterator itr2,itr3;
	int num = count(Item::item_v.begin(), Item::item_v.end(), spot[SPOT_POD]->SpotType);
	itr = find(Item::item_v.begin(), Item::item_v.end(), (int)spot[SPOT_POD]->SpotType);
	itr2 = itr + num;
	//if (itr2 - 1 == Item::item_v.end())itr2--;
	int n = 0;
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < 6; i++) {
			if ((itr + j)->Item_ID == matel[i]) {
				if(Inpodmatel[i] == 0)
					Inpodmatel[i] = j + 1;
				break;
			}
		}
	}
	
	//もしレシピが空だったら
	int a = 0;
	for (int i = 0; i < 6; i++) {
		if (matel[i] == -1) {
			a++;
		}
	}
	if (a == 6) {
		return false;
	}
	for (int i = 0; i < 6; i++) {
		if (matel[i] != -1 && Inpodmatel[i] == 0) {
			return false;
		}
	}

	return true;
}

void PodBehavior::Init(Spot *s) {
	s->Area.X = 3;
	s->Area.Y = 2;
	Button.Set(s->DrawPos.x - 32 - 16, s->DrawPos.y - 16);
	Pool.Set(s->DrawPos.x - 32, s->DrawPos.y + 32);
	PoolSector[0].Set(Pool);
	PoolSector[1].Set(Pool.x + 96,Pool.y);
	PoolSector[2].Set(Pool.x + 96, Pool.y + 96);
	PoolSector[3].Set(Pool.x, Pool.y + 96);
	PoolSectorSize.Set(96, 96);
	Suggest.Set(s->DrawPos.x - 32, s->DrawPos.y - 64);
	SuggestNow.Set(s->DrawPos.x - 32, s->DrawPos.y - 64);
	SuggestChanger[0].Set(s->DrawPos.x - 72, s->DrawPos.y - 64);
	SuggestChanger[1].Set(s->DrawPos.x + 72, s->DrawPos.y - 64);
	//ここなんとか親クラスと纏められへんの？
	sp = s;

	SetRecipe();

	HitBox[0].Set(32 * 0, 32 * 8);
	HitBox[1].Set(32 * 11 - 1, 32 * 15 - 1);
	HitBox_Sub[0].Set(32 * 2,32 * 9);
	HitBox_Sub[1].Set(32 * 3 -1,32 * 10 -1);

	Vector2 V; V.Set(Button.x - 8, Button.y - 12);
	Mes.SetPos(V);
	Vector2 V2;
	V2.Set(40, 40);
	Mes.SetHitBox(Button, Button + V2);
	Mes.SetString("Click!");
	Mes.type = 1;

	Vector2 V3;
	V3.Set(0, 148);
	MesP.SetHitBox(HitBox[0], HitBox[1]);
	MesP.SetString("材料となるアイテムをここに集めたらボタンを押して\n調合スタート！\nつくる商品によって時間がかかったり\n混ぜる必要があったりします");
	MesP.SetPos(HitBox[0] + V3);

}

void PodBehavior::SetRecipe() {
	
	switch (m_GameMgr->gamelevel) {
	case GAME_1:
		recipe[0].Set(this, I_NEL_R, 6, 180, I_REQ_R, I_POWD_A);
		recipe[1].Set(this, I_NEL_B, 6, 180, I_REQ_B, I_POWD_A);
		recipe[2].Set(this, I_NEL_G, 6, 180, I_REQ_G, I_POWD_A);
		recipe[3].Set(this, I_NEL_Y, 6, 180, I_REQ_Y, I_POWD_A);
		recipe[4].Set(this, I_WATA_R, 6, 180, I_REQ_R, I_POWD_B);
		recipe[5].Set(this, I_WATA_B, 6, 180, I_REQ_B, I_POWD_B);
		recipe[6].Set(this, I_WATA_G, 6, 180, I_REQ_G, I_POWD_B);
		recipe[7].Set(this, I_WATA_Y, 6, 180, I_REQ_Y, I_POWD_B);
		recipe[8].Set(this, I_CH_R, 6, 180, I_REQ_R, I_POWD_C);
		recipe[9].Set(this, I_CH_B, 6, 180, I_REQ_B, I_POWD_C);
		recipe[10].Set(this, I_CH_G, 6, 180, I_REQ_G, I_POWD_C);
		recipe[11].Set(this, I_CH_Y, 6, 180, I_REQ_Y, I_POWD_C);
		for (int i = 12; i < RECIPE_MAX; i++) {
			recipe[i].Set(this);
		}
		break;
	case GAME_2:
		recipe[0].Set(this, I_CAKE, 16, 240, I_REQ_R, I_REQ_B, I_REQ_G, I_REQ_Y,I_POWD_A, I_POWD_B);
		recipe[1].Set(this, I_KING_B, 16, 240, I_REQ_B, I_REQ_B, I_REQ_B, I_POWD_A, I_POWD_A, I_POWD_A);
		recipe[2].Set(this, I_KING_G, 16, 240, I_REQ_G, I_REQ_G, I_REQ_G, I_POWD_A, I_POWD_A, I_POWD_A);
		recipe[3].Set(this, I_KING_Y, 16, 240, I_REQ_Y, I_REQ_Y, I_REQ_Y, I_POWD_A, I_POWD_A, I_POWD_A);
		recipe[4].Set(this, I_WATA_R, 12, 180, I_REQ_R, I_POWD_B, I_POWD_A);
		recipe[5].Set(this, I_WATA_B, 12, 180, I_REQ_B, I_POWD_B, I_POWD_A);
		recipe[6].Set(this, I_WATA_G, 12, 180, I_REQ_G, I_POWD_B, I_POWD_A);
		recipe[7].Set(this, I_WATA_Y, 12, 180, I_REQ_Y, I_POWD_B, I_POWD_A);

		recipe[8].Set(this, I_CH_R, 0, 240, I_REQ_R, I_POWD_B);
		recipe[9].Set(this, I_CH_B, 0, 240, I_REQ_B, I_POWD_B);
		recipe[10].Set(this, I_CH_G, 0, 240, I_REQ_G, I_POWD_B);
		recipe[11].Set(this, I_CH_Y, 0, 240, I_REQ_Y, I_POWD_B);
		recipe[12].Set(this, I_NEL_R, 8, 0, I_REQ_R, I_POWD_A);
		recipe[13].Set(this, I_NEL_B, 8, 0, I_REQ_B, I_POWD_A);
		recipe[14].Set(this, I_NEL_G, 8, 0, I_REQ_G, I_POWD_A);
		recipe[15].Set(this, I_NEL_Y, 8, 0, I_REQ_Y, I_POWD_A);
		for (int i = 16; i < RECIPE_MAX; i++) {
			recipe[i].Set(this);
		}
		break;
	}
}

void PodBehavior::SuggestMgr() {
	if (suggest[0] == I_FAIL)
		return;
	//ボタンでsuggest変更
	if (Mouse[0] != 1) {
		return;
	}
	if (Cursol->Pos.InSquare2(SuggestChanger[0], 32, 32)) {
		SuggestChange(-1);
	}
	if (Cursol->Pos.InSquare2(SuggestChanger[1], 32, 32)) {
		SuggestChange(1);
	}
	Vector2 V;
	V.Set(nowsuggest * 32, 0);
	SuggestNow.Set(Suggest + V);
}

void PodBehavior::SuggestChange(int mode) {
	MyPlaySound(sound[2], 100, 1);
	if (mode == 1) {
		if (suggest[nowsuggest + 1] == I_FAIL) {
			nowsuggest = 0; return;
		}
		else {
			nowsuggest++; return;
		}
	}
	if (mode == -1) {
		if (nowsuggest == 0) {
			int p;
			for (int i = 0; i < 24; i++) {
				if (suggest[i] == I_FAIL) {
					p = i; break;
				}

			}
			nowsuggest = p - 1; return;
		}
		else {
			nowsuggest--;
		}
	}
}


void PodBehavior::ButtonBehave() {
	//ボタンの□に入ったら
	if (nowmake != I_FAIL) {return; }
	if (Cursol->Pos.InSquare2(Button, 32, 32) && Mouse[0] == 1) {
		//すでに何かresultに入ってたらダメ
		if (spot[3]->Item_n != 0) { 
			//ダメ効果音
			NoPod();
			return; 
		}
		if (suggest[0] != I_FAIL) {
			making = recipe[suggest[nowsuggest]].result;
			makingpool = recipe[suggest[nowsuggest]].pool;
			makingtime = recipe[suggest[nowsuggest]].time;
			nowmake = suggest[nowsuggest];
			makingtimer = 0;
			for (int i = 0; i < 6; i++) {
				int p = recipe[suggest[nowsuggest]].Inpodmatel[i] - 1;
				if (p >= 0) {
					Item::DeleteItem(SPOT_POD, p);
				}
			}
			//サウンド
			MyPlaySound(sound[0], 100, 1);

		}
	}
	

}
void PodBehavior::NoPod() {
	MyPlaySound(sound[1], 100, 1);
	//既にResultにアイテムが入ってないことを教えてやるようにする
}


void PodBehavior::Draw() {
	float exrate = 0.4;
	//MyDrawRotaGraph(Button, G_IMAGE.UI[5]);
	DrawGraph(Button.x, Button.y, G_IMAGE_UI[5],1);
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 4; i++) {
			Vector2 V;
			V.Set(j * 20, i * 20);
			V = V + Suggest;
			if (suggest[j + 6 * i] >= 0)
				if (nowsuggest == j + 6 * i) {
					exrate = 1.0;
				}
				else {
					exrate = 0.4;
				}
				//MyDrawRotaGraph(V, G_IMAGE_ITEM[recipe[suggest[i]].result]);
				DrawRotaGraph(V.x, V.y, exrate, 0, G_IMAGE_ITEM[recipe[suggest[j + 6 * i]].result], 1);
		}
	}
	int c;
	//ほんとはmakingは関数にすべき
	if (waitingmake == 0) {
		c = 255;
	}
	else {
		c = 0;
	}
	if (making != -1 && waitingmake == 0) {
		//プールの描画
		double pool_degree = mixstate * 3.14159;
		DrawRotaGraph(PoolSector[2].x, PoolSector[2].y, 1.0,pool_degree / 2,G_IMAGE.podturn[1], 1);
		for (int i = 0; i < 4; i++) {
			//DrawBox(PoolSector[i].x, PoolSector[i].y, PoolSector[i].x + PoolSectorSize.x, PoolSector[i].y + PoolSectorSize.y,GetColor(72 * i,c,255),1);
		}
		DrawRotaGraph(PoolSector[2].x, PoolSector[2].y,1.0,0.0 ,G_IMAGE.podturn[0], 1);
	}
	int pod_anime = 0;
	if(waitingmake == 0){
		DrawGraph(32 * 2 + 4, 32 * 9 + 4, G_IMAGE.pod[1], 1);
	}
	else {
		DrawGraph(32 * 2 + 4, 32 * 9 + 4, G_IMAGE.pod[pod_anime_t.var], 1);

	}

	DrawGraph(SuggestChanger[0].x, SuggestChanger[0].y, G_IMAGE.UI[2], 1);
	DrawGraph(SuggestChanger[1].x, SuggestChanger[1].y, G_IMAGE.UI[3], 1);
	//DrawFormatString(PoolSector[0].x, PoolSector[0].y, GetColor(255, 255, 255), "%d",mixflag);
	Mes.Draw();
	if (practiceflag) {
		MesP.Draw();
	}
}

//Resultクラス

void ResultBehavior::Init(Spot *s) {
	s->Area.X = 1;
	s->Area.Y = 1;
	Vector2 V1;
	V1.Set(s->DrawPos.x, s->DrawPos.y);
	Vector2 V2; 
	V2.Set(32,32);
	Vector2 V3;
	V3.Set(64, 0);
	Mes.SetPos(V1 + V3);
	Mes.SetHitBox(V1,V1 + V2);
	Mes.SetString("ここに商品が残ってると次の商品を\n調合できないので注意！");

}

bool ResultBehavior::Behave() {
	
	Mes.Process();
	return true;
}

void ResultBehavior::Draw() {
	if (practiceflag) {
		Mes.Draw();
	}
}