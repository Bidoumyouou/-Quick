#include"Item.h"
#include"CommonClass.h"
#include<vector>
#include<Dxlib.h>
#include"Resource.h"
#include"Spot.h"
#include"Cursol.h"
#include<functional>
#include<algorithm>
#include<assert.h>
#include<vector>
#include"Key.h"
#include"GameMgr.h"
using namespace std;

vector<Item> Item::item_v;
vector<Item>::iterator Item:: p;



Item::~Item() {
	//spot[spotnum]->Item_n--;
}

bool Item::Item_Iter() {
	//アイテムが行うこと
	
	//ボタンが押されるたびにBeltを更新

	//触られるとHandに移動

	return true;
}

void Item::AllProcess() {

	printfDx("\n");

	for_each(item_v.begin(), item_v.end(), mem_fun_ref(&Item::Process));
}
void Item::AllDraw() {
	for_each(item_v.begin(), item_v.end(), mem_fun_ref(&Item::Draw));
}

void Item::MakeItem() {
	if(spot[0] != nullptr)MakeItem(0);
}
void Item::MakeItem(int _spot) {
	assert(spot[_spot] != nullptr);
	int itemno;
	switch (m_GameMgr->gamelevel) {
	case GAME_2:
		itemno = GetRand(7);
		if (itemno == 4 || itemno == 5) {
			itemno = 4;
		}
		if (itemno == 6 || itemno == 7) {
			itemno = 5;
		}
		break;
	default:itemno = GetRand(7); break;
	}
	item_v.push_back(Item(itemno, item_v.size(),_spot));
	//p = item_v.end() - 1;
	Item::SortItem();
}

void Item::MakeItem(int _spot, int _id) {
	assert(spot[_spot] != nullptr);
	item_v.push_back(Item(_id, item_v.size(), _spot));
	Item::SortItem();
	
	//spot[_spot]->SpotRemake();

}
void Item::DeleteItem() {

}

int Item::Inspect(int _spot, int _spotnum) {
	for (p = item_v.begin(); p != item_v.end(); ) {
		if (p->spotnum == _spot && _spotnum == p->areaID) {
			return p->Item_ID;
		}
		p++;
	}
}

void Item::DeleteItem(int _spot,int _spotnum) {
	assert(spot[_spot] != nullptr);
	spot[_spot]->Item_n--;

	//p = item_v.begin();;
	//p = find_if(item_v.begin(), item_v.end(), (p->spotnum == _spotnum));
	//item_v.erase(p);
	for (p = item_v.begin(); p!=item_v.end(); ) {
		if (p->spotnum == _spot && _spotnum == p->areaID) {
			//もし掴んでいるアイテムだったら掴み状態を解除
			if (p->tracked) { Cursol->Grip = GRIP_DEF; }
			item_v.erase(p);
			break;
		}
		p++;
	}
	spot[_spot]->RemakeSignal = true;
}

void Item::SortItem() {
	sort(p = item_v.begin(), item_v.end());
}

void Item::Clicked() {
	//もしベルトの５番目以降だったら掴めない
	if (spotnum == SPOT_BELT && areaID >= 4) {
		//return;
	}
	
	//はなす
	if (Cursol->Grip == GRIPPED && tracked == true) {
		//指定スポットの範囲なら
			//どこかのスポットが近いなら
		for (int i = 0; i < SPOT_MAX; i++) {
			if (spot[i] == nullptr)continue;

			Vector2 V; V.Set(64, 64);
			//エリアの範囲を設定
			switch (spot[i]->SpotType) {
			case SPOT_BELT:V.Set(32 * 8, 32 * 5); break;
			case SPOT_STOCK:V.Set(32 * 4, 32 * 3); break;
			case SPOT_POD:V.Set(40 * 3, 40 * 2); break;
			case SPOT_RESULT:V.Set(40 * 1, 40 * 1); break;
			case SPOT_CUSTOMER_1:V.Set(40 * 1, 40 * 1); break;
			case SPOT_CUSTOMER_2:V.Set(40 * 1, 40 * 1); break;
			case SPOT_CUSTOMER_3:V.Set(40 * 1, 40 * 1); break;
			default:V.Set(64, 64);
			}
					//
			if (DrawPos.InSquare(spot[i]->GetHitbox(0,0), spot[i]->GetHitbox(0,1))) {
				//スポットごとの特殊条件
				if (IsExtra(i)) {
					break;
				}
				tracked = false;

				int tempspot = spotnum;
				spotnum = i;
				areaID = 99;
				//もし移動前と移動後が同じスポットなら
				if (tempspot == spotnum) {
					MyPlaySound(sound[1], 100, 1);
					break;
				}
				MyPlaySound(sound[4], 100, 1);

				//areaID = spot[tempspot]->Item_n;//新しいspotに入ってる物の数
				Item::SortItem();
				//本来メンバー自身がvertorの組成を変えるべきではない
				Spot::AllSpotRemake();
				
				Item::SortItem();

				InitPos();
				break;
			}
		}
		tracked = false;

		//Cursol->Grip = GRIP_DEF;
		Cursol->GripFreeflag = true;
		DrawPos = Pos;
		return;
	}
		

	//つかむ
	if (DrawPos.distance(MouseX, MouseY) < 32) {
		if (Cursol->Grip != GRIPPED) {
			tracked = true;
			Cursol->Grip = GRIPPED;
			//PlaySoundMem(sound[4], DX_PLAYTYPE_BACK);
			MyPlaySound(sound[4], 100,1);
			return;
		}
	}

}

//スポットごとの特殊条件とスポットの数量
bool Item::IsExtra(int _spot) {
	switch (_spot) {
	case SPOT_RESULT:return true; break;
	
	}
	if (spot[_spot]->Area.GetAreaNum() <= spot[_spot]->Item_n) {
		return true;
	}

	return false;
}

void Item::Process() {
	
	
	
	init();
	
	//printfDx("%d\n", DrawPos.x);
	//printfDx("%f\n", DrawPos.distance(MouseX, MouseY));
	
	if (Mouse[0] == 1) {
		Clicked();
	}

	if (tracked == true) {
		DrawPos.x = MouseX;
		DrawPos.y = MouseY;
	}
	
	//掴まれたアイテムを２回右クリックで捨てる
	Discard();
}

void Item::Discard() {
	if (Mouse[1] == 1) {
		if (tracked == true) {
			Item::DeleteItem(spotnum, areaID);
			
		}
	}
}

void Item::init() {
	//if(initflag == true)reutrn;がデータに何らかの影響を与えた(要調査)
	if (initflag == false) {
		Item_Spot = spot[spotnum]->SpotType;
		InitPos();
		initflag = true;
	}
}

Item::Item(int _id, int _size, int _spotnum) {
	Item_ID = _id;
	//Item_Spot = p->SpotType;
	areaID = spot[_spotnum]->Item_n;
	spotnum = _spotnum;
	DrawPos.Set(100, 200);
	Pos = DrawPos;
	//Spotの入ってるあいってむを加算する
	spot[_spotnum]->Item_n++;
	

}

void Item::InitPos() {
	//場所をAreaID割り出す
	area_x = areaID % spot[spotnum]->Area.X;
	area_y = (areaID / spot[spotnum]->Area.X);
	if (spot[spotnum]->SpotType != SPOT_BELT) {
		int tX = area_x * 40;
		int tY = area_y * 40;
		DrawPos.Set(spot[spotnum]->DrawPos.x + 16 + tX, spot[spotnum]->DrawPos.y + 16 + tY);
		Pos = DrawPos;
	}
	else {
		DrawPos.Set(spot[spotnum]->ExtraPos[areaID].x + 16, spot[spotnum]->ExtraPos[areaID].y + 16);
		Pos = DrawPos;
	}
}

void Item::Draw() {
	D_Stab();
}

void Item::D_Stab() {
	MyDrawRotaGraph(DrawPos ,G_IMAGE_ITEM[Item_ID]);
	//DrawGraph(200, 200, G_IMAGE_ITEM[0],1);

}
bool Item::operator<(Item _item) const {
	//まずはspotnumで比較
	const Item* p = this;
	if (p->spotnum < _item.spotnum) {
		return true;
	}

	else if (p->spotnum == _item.spotnum) {
		//同じならArea_IDで比較

		return (p->areaID < _item.areaID);

	}
	else {
		return false;
	}
}

bool Item::operator==(const int val) const {
	return (this->spotnum == val);

}