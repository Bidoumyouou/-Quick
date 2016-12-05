#include"Customer.h"
#include"Spot.h"
#include"Cursol.h"
#include"key.h"
#include"Resource.h"
#include"GameMgr.h"
#include"ItemList.h"
bool CustomerBehavior::Behave() {

	Request.Behave();
	if (!WaitForRequest) {
		//リクエストと入ってるアイテムが同じかどうか見る
		if (IsRequestClear()) {
			SellItem();
		}
	}
	Mes.Process();
	MesP.Process();
	return true;
}

void CustomerBehavior::SellItem() {
	m_GameMgr->Score.Add(m_GameMgr->ItemList.ItemData[Item::Inspect(sp->SpotType,0)].price);
	Item::DeleteItem(sp->SpotType, 0);
	Request.RequestDelete();
	MyPlaySound(sound[8], 100, 1);

	//金を清算する
}

void CustomerBehavior::Init(Spot *s) {
	s->Area.X = 1;
	s->Area.Y = 1;
	Request_Pos.Set(s->DrawPos.x + REQUEST_OFFSET_X, s->DrawPos.y + REQUEST_OFFSET_Y);
	Stress_Pos.Set(s->DrawPos.x + STRESS_OFFSET_X, s->DrawPos.y + STRESS_OFFSET_Y);
	//ここなんとか親クラスと纏められへんの？
	sp = s;
	//Request = new C_Request();
	RequestList.MakeList();
	Request.Behavior = this;
	Request.waitlimit = GetRand(REQUEST_WAIT_MAX) + GetRand(REQUEST_WAIT_MAX);

	HitBox[0].Set(s->DrawPos.x - 32, s->DrawPos.y - 32);
	HitBox[1].Set(s->DrawPos.x + 63, s->DrawPos.y + 63);

	Vector2 V; V.Set(s->DrawPos.x - 9 - 48, s->DrawPos.y - 12 - 32);
	Mes.SetPos(V);
	Mes.SetHitBox(HitBox[0], HitBox[1]);
	//if(Mes.Set)
	if (practiceflag) {
		Mes.SetString("お客さんからの注文通りの商品を\n彼らのストレスがたまる前に\n持っていきましょう。\n作り方は左上から見られます。");
		Mes.type = 0;

	}
	else {
		Mes.SetString("注文通りの商品を\n急いで作ろう！");
		Mes.type = 1;

	}
}

bool CustomerBehavior::IsRequestClear() {
	//もしスポットに入っているアイテムとリクエストが一致したらtrueを返す
	vector<Item>::iterator itr;
	vector<Item>::iterator itr2, itr3;
	//該当スポットの番号とアイテムのスポットNOが一致するものの数を数える
	int num = count(Item::item_v.begin(), Item::item_v.end(), sp->SpotType);
	itr = find(Item::item_v.begin(), Item::item_v.end(), (int)sp->SpotType);
	itr2 = itr + num;
	for (auto p = itr; p < itr2; p++) {
		if (p->Item_ID == Request.item) {
			return true;
		}
	}
	//今のところスポットの枠が一個の場合のみ対応
	return false;
}

void CustomerBehavior::Draw() {
	int tempitem = Request.item;
	if (tempitem != -1) {
		DrawGraph(Request_Pos.x, Request_Pos.y, G_IMAGE.UI[13], 1);
		DrawGraph(Request_Pos.x + 4, Request_Pos.y + 4, G_IMAGE_ITEM[tempitem], 1);
	}
	//ストレスの値とバーの見た目導出
	int bar = 0;
	//Request.stress
	stressdegree = Request.stress;//除算は「商」を求めるので120/1000は0と出る?
	if (0   <= stressdegree  && stressdegree  < 0.1 * STRESS_MAX) { bar = 0; }
	if (0.1*STRESS_MAX <= stressdegree  && stressdegree  < 0.2 * STRESS_MAX) {bar = 1; }
	if (0.2*STRESS_MAX <= stressdegree  && stressdegree  < 0.3*STRESS_MAX) { bar = 2; }
	if (0.3*STRESS_MAX <= stressdegree  && stressdegree  < 0.4*STRESS_MAX) { bar = 3; }
	if (0.4*STRESS_MAX <= stressdegree  && stressdegree  < 0.5*STRESS_MAX) { bar = 4; }
	if (0.5*STRESS_MAX <= stressdegree  && stressdegree  < 0.6*STRESS_MAX) { bar = 5; }
	if (0.6*STRESS_MAX <= stressdegree  && stressdegree  < 0.7*STRESS_MAX) { bar = 6; }
	if (0.7*STRESS_MAX <= stressdegree  && stressdegree  < 0.8*STRESS_MAX) { bar = 7; }
	if (0.8*STRESS_MAX <= stressdegree  && stressdegree  < 0.9*STRESS_MAX) { bar = 8; }
	if (0.9*STRESS_MAX <= stressdegree  && stressdegree  < 1.0*STRESS_MAX) { bar = 9; }

	DrawGraph(Stress_Pos.x, Stress_Pos.y, G_IMAGE.bar[bar], 1);

	Mes.Draw();
}
/////////
//Request
/////////

void C_Request::Behave(){
	if (Behavior->WaitForRequest) {
		//リクエストがないとき
		if (waittime >= waitlimit) {
			//リストから乱数に応じたアイテム番号を取り出しリクエストにする
			int randitem;
			if (m_GameMgr->royalsignal) {
				randitem = 12;//GetRand(3) + Behavior->RequestList.list_n;
				m_GameMgr->royalsignal = false;
			}
			else {
				randitem = GetRand(Behavior->RequestList.list_n - 1);
			}
			item = Behavior->RequestList.item[randitem];
			Behavior->WaitForRequest = false;
			MyPlaySound(sound[15], 100, 1);

		}
		waittime++;
		
	}
	else {
		//リクエストがあるとき
		if (stress < STRESS_MAX) {
			if (practiceflag == false) {
				stress += stressspeed;
			}
		}
		else {
			//ストレスゲージがMAXになったら
			RequestDelete();
			MyPlaySound(sound[16], 100, 1);
		}
	}

};

void C_Request::RequestDelete() {
	Behavior->WaitForRequest = true;
	stress = 0;
	waittime = 0;
	item = I_FAIL;
	waitlimit = GetRand(REQUEST_WAIT_MAX); //+ GetRand(REQUEST_WAIT_MAX);

}
/////////////
//RequestList
/////////////
void C_RequestList::MakeList() {
	item[0] = I_NEL_R;
	item[1] = I_NEL_B;
	item[2] = I_NEL_G;
	item[3] = I_NEL_Y;
	item[4] = I_WATA_R;
	item[5] = I_WATA_B;
	item[6] = I_WATA_G;
	item[7] = I_WATA_Y;
	item[8] = I_CH_R;
	item[9] = I_CH_B;
	item[10] = I_CH_G;
	item[11] = I_CH_Y;
	list_n = 12;//現状ではリクエストの種類とは一致しない
	item[12] = I_CAKE;
	item[13] = I_KING_B;
	item[14] = I_KING_G;
	item[15] = I_KING_Y;
	for (int i = 16; i < REQUESTLIST_MAX; i++) {
		item[i] = I_FAIL;
	}
}
