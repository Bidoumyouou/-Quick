#pragma once
#include<vector>
//#include"Item.h"
#include"CommonClass.h"
#include"GameMgr.h" 
#include"SpotBehave.h"

using namespace std;
class Item;
class AREA {
public:
	int X;
	int Y;
	int GetAreaNum() {
		return X * Y;
	}
};

//�̈�̊��N���X
class Spot {
public:
	//�`����W
	Vector2 DrawPos;
	Spot(Vector2 _V, e_Item_Spot _arraynum);
	~Spot() {
	}
	e_Item_Spot SpotType;
	//�X�^�u
	
	//�̈�
	AREA Area;

	int Item_n = 0;//�����Ă�A�C�e���̐�

	//�v���Z�X
	bool Process();
	//�`��
	bool Draw();
	vector<Item>::iterator itr;
	vector<Item>::iterator itr2;
	void SpotRemake();

	static void AllSpotRemake();

	bool RemakeSignal;
	Vector2 ExtraPos[8];//�\���̌��ׂ�����������
	Vector2 GetHitbox(int _mode,int _mode2) {
		if (_mode == 0) {
			//���C���q�b�g�{�b�N�X
			return behavior->HitBox[_mode2];
		}
		else {
			return behavior->HitBox_Sub[_mode2];
		}
	}
protected:
	//void P_Stab();
	SpotBehavior *behavior;

	void D_Stab();
	void init();
	bool initflag = false;
};