#include"Spot.h"
#include"Dxlib.h"
#include"Item.h"
#include<functional>
#include<algorithm>
#include"Cursol.h"
#include<vector>
#include"Belt.h"
#include"Pod.h"
#include"Customer.h"
bool operator<(Item I1, Item I2) {
	double dist1 = I1.DrawPos.distance(Cursol->Pos);
	double dist2 = I2.DrawPos.distance(Cursol->Pos);
	
	return dist1 < dist2;
}

Spot::Spot(Vector2 _V, e_Item_Spot _arraynum) {
	SpotType = _arraynum;
	switch (SpotType) {
	case SPOT_BELT:behavior = new BeltBehavior();  break;
	case SPOT_POD:behavior = new PodBehavior(); break;
	case SPOT_RESULT:behavior = new ResultBehavior(); break;
	case SPOT_CUSTOMER_1:	case SPOT_CUSTOMER_2:	case SPOT_CUSTOMER_3:
		behavior = new CustomerBehavior(); break;
	default:behavior = new SpotBehavior(); break;
	}
	behavior->SpotType = SpotType;
	DrawPos.Set(_V);
	DrawPos.Set(_V);
	behavior->Init(this);
	//Area.X = 3;
	//Area.Y = 2;
}

bool Spot::Process() {
	//�����킯
	init();
	//SpotRemake();
	//�e�X�|�b�g�̃A�C�e���̐�����ɍX�V
	Item_n = count_if(Item::item_v.begin(), Item::item_v.end(), bind2nd((mem_fun_ref(&Item::IsSpot)), SpotType));

	//�x���g�Ȃǂ̓���@�\
	if (RemakeSignal)SpotRemake();
	if (!behavior->Behave())return false;
	
	return true;
}



bool Spot::Draw() {

	D_Stab();
	return true;
}


void Spot::D_Stab() {
	//���ɗ̈�����F���l�p�ŕ\��
	//�x���g�R���x�A���ۂ���
	if (SpotType != SPOT_BELT) {

		for (int i = 0; i < Area.X; i++) {
			for (int j = 0; j < Area.Y; j++) {
				int t_X = DrawPos.x + i * 40;
				int t_Y = DrawPos.y + j * 40;
				DrawGraph(t_X - 4, t_Y - 4, G_IMAGE.UI[0], 1);
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			DrawGraph(ExtraPos[i].x - 4, ExtraPos[i].y - 4, G_IMAGE_UI[0],1);
		}
	}
	behavior->Draw();
}


void Spot::init() {
	if (initflag == true)return;
	initflag = true;

}

void Spot::SpotRemake() {
	int num = count(Item::item_v.begin(), Item::item_v.end(), SpotType);
	itr = find(Item::item_v.begin(), Item::item_v.end(),(int)SpotType);
	itr2 = itr + num;
	//if (itr2 - 1 == Item::item_v.end())itr2--;
	int n = 0;
	for (itr ;itr != itr2 ;itr++) {
		//AreaID��������0,1,2...�ɋl�߂�
		itr->areaID = n;
		itr->InitPos();
		n++;
	}
	RemakeSignal = false;
}

void Spot::AllSpotRemake() {
	for (int j = 0; j < SPOT_MAX; j++) {
		if(spot[j] != nullptr)
		spot[j]->SpotRemake();
	}
}