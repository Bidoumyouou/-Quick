#include"Belt.h"
#include"Spot.h"
#include"Cursol.h"
#include"key.h"
#include"Resource.h"

bool BeltBehavior::Behave()
{
	BeltAutoMove();
	//ボタンを押すとアイテムが増える
	ButtonBehave();
	Mes.Process();
	MesP.Process();
	return true;
}

void BeltBehavior::BeltAutoMove() {
	
	//自動でベルトコンベアをめくる
	belt_t.Up(0, 240, 1);
	if (belt_t.var % 240 == 1) {
		StepBelt();
	}
}

void BeltBehavior::StepBelt() {
	if (sp->Item_n >= 8) {
		Item::DeleteItem(sp->SpotType, 0);
	}
	Item::MakeItem(sp->SpotType);
	MyPlaySound(sound[26], 100, 1);
}

void BeltBehavior::Init(Spot *s) {
	s->Area.X = 4;
	s->Area.Y = 2;
	//各スポットの座標指定
	s->ExtraPos[0].Set(18 * 32, 32 * 5);
	s->ExtraPos[1].Set(16 * 32, 32 * 5);
	s->ExtraPos[2].Set(14 * 32, 32 * 5);
	s->ExtraPos[3].Set(12 * 32, 32 * 5);
	s->ExtraPos[4].Set(12 * 32, 32 * 3);
	s->ExtraPos[5].Set(14 * 32, 32 * 3);
	s->ExtraPos[6].Set(16 * 32, 32 * 3);
	s->ExtraPos[7].Set(17 * 32, 32 * 2);
	//ExtraPos = DrawPos
	for (int i = 0; i < 8; i++) {
		//DrawPos[i] = ExtraPos[i];
	}
	Button.Set(s->DrawPos.x - 32, s->DrawPos.y);
	DustBox.Set(s->DrawPos.x + 32 * 4, s->DrawPos.y + 32 * 5);
	//ここなんとか親クラスと纏められへんの？
	sp = s;
	HitBox[0].Set(32 * 9, 0);
	HitBox[1].Set(32 * 20, 32 * 8 - 1);
	HitBox_Sub[0].Set(32 * 8, 32 * 2);
	HitBox_Sub[1].Set(32 * 11 -1, 32 * 5 - 1);
	Vector2 V; V.Set(Button.x - 8, Button.y - 12);
	Mes.SetPos(V);
	Mes.SetHitBox(HitBox_Sub[0], HitBox_Sub[1]);
	Mes.SetString("Click!");
	Mes.type = 1;
	MesP.SetHitBox(HitBox[0], HitBox[1]);
	MesP.SetString("ベルトコンベアから\n材料が流れてきます。\nクリックして持ち運びましょう。");
	MesP.SetPos(HitBox[0]);
}

void BeltBehavior::ButtonBehave() {
	//ボタンの□に入ったら	
	if (Cursol->Pos.InSquare2(Button,32,32) && Mouse[0] == 1) {
			//beltmove = 1 - beltmove;
			//Item::MakeItem(sp->SpotType);
		StepBelt();
	}
	//ごみ箱の□に入ったら	
	if (Cursol->Pos.InSquare2(DustBox, 32, 32) && Mouse[0] == 1) {
		if (1) {
			//Item::DeleteItem(sp->SpotType,0);
		}
	}
	
}

void BeltBehavior::Draw() {
	//ベルトコンベアのみ特殊な方法で
	for (int i = 0; i < 8; i++) {
		//DrawGraph(ExtraPos[i].x - 4, ExtraPos[i].y - 4, G_IMAGE.UI[0], 1);
	}
	//MyDrawRotaGraph(Button + 16, G_IMAGE.UI[4]);
	//MyDrawRotaGraph(DustBox + 16, G_IMAGE.conbair[5]);
	DrawGraph(Button.x, Button.y, G_IMAGE.UI[4], 1);
	//DrawGraph(DustBox.x,DustBox.y, G_IMAGE.conbair[5], 1);
	Mes.Draw();
	if (practiceflag) {
		MesP.Draw();
	}
}
