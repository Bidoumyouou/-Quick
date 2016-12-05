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
	//�A�C�e�����s������
	
	//�{�^����������邽�т�Belt���X�V

	//�G�����Hand�Ɉړ�

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
			//�����͂�ł���A�C�e����������͂ݏ�Ԃ�����
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
	//�����x���g�̂T�Ԗڈȍ~��������͂߂Ȃ�
	if (spotnum == SPOT_BELT && areaID >= 4) {
		//return;
	}
	
	//�͂Ȃ�
	if (Cursol->Grip == GRIPPED && tracked == true) {
		//�w��X�|�b�g�͈̔͂Ȃ�
			//�ǂ����̃X�|�b�g���߂��Ȃ�
		for (int i = 0; i < SPOT_MAX; i++) {
			if (spot[i] == nullptr)continue;

			Vector2 V; V.Set(64, 64);
			//�G���A�͈̔͂�ݒ�
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
				//�X�|�b�g���Ƃ̓������
				if (IsExtra(i)) {
					break;
				}
				tracked = false;

				int tempspot = spotnum;
				spotnum = i;
				areaID = 99;
				//�����ړ��O�ƈړ��オ�����X�|�b�g�Ȃ�
				if (tempspot == spotnum) {
					MyPlaySound(sound[1], 100, 1);
					break;
				}
				MyPlaySound(sound[4], 100, 1);

				//areaID = spot[tempspot]->Item_n;//�V����spot�ɓ����Ă镨�̐�
				Item::SortItem();
				//�{�������o�[���g��vertor�̑g����ς���ׂ��ł͂Ȃ�
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
		

	//����
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

//�X�|�b�g���Ƃ̓�������ƃX�|�b�g�̐���
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
	
	//�͂܂ꂽ�A�C�e�����Q��E�N���b�N�Ŏ̂Ă�
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
	//if(initflag == true)reutrn;���f�[�^�ɉ��炩�̉e����^����(�v����)
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
	//Spot�̓����Ă邠�����Ăނ����Z����
	spot[_spotnum]->Item_n++;
	

}

void Item::InitPos() {
	//�ꏊ��AreaID����o��
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
	//�܂���spotnum�Ŕ�r
	const Item* p = this;
	if (p->spotnum < _item.spotnum) {
		return true;
	}

	else if (p->spotnum == _item.spotnum) {
		//�����Ȃ�Area_ID�Ŕ�r

		return (p->areaID < _item.areaID);

	}
	else {
		return false;
	}
}

bool Item::operator==(const int val) const {
	return (this->spotnum == val);

}