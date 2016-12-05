#pragma once
#include"ObjectBase.h"
#include"CommonClass.h"
#include"SpotBehave.h"
#include<map>
#include<vector>
//#include"Spot.h"
//�A�C�e�����ǂ̗̈�ɂ��邩
#define ITEM_MAX 64

#define ITEM_HIT_RADIATE 16 
using namespace std;
//vector<Item>::iterator Item:: *p;
class Spot;
class GameMgr;
class A {

};




class Item {
	//�K��
public:
	
	Vector2 Pos;//Pos�͓���̏����ł̂ݕω��ADrawPos�͖��t���[���X�V
	Vector2 DrawPos;
	static void MakeItem();
	static void MakeItem(int);
	static void MakeItem(int _spot, int _id);
	void DeleteItem();
	static int Inspect(int _spot, int _spotnum);
	static void DeleteItem(int _spot, int _spotnum);
	static void SortItem();
	void Process();
	void Discard();
	void TrackedBehave();
	void Clicked();
	bool tracked = false;
	bool Istrack();
	void Draw();
	bool IsExtra(int _spot);
	int spotnum;//���Ԃ̃X�|�b�g�ɓ����Ă邩
	//�ǂ̃X�|�b�g�ɓ����Ă��邩
	e_Item_Spot Spot;
	//�G���A�̉��Ԃɓ����Ă��邩
	int area_x;
	int area_y;
	int areaID;
	static vector<Item> item_v;
	static vector<Item>::iterator p;
	
	Item(int _id, int _size, int _spotnum);

	void InitPos();

	~Item();
	static bool Item_Iter();

	bool IsSpot(e_Item_Spot _spot) {
		if (_spot == spotnum) {
			return true;
		}
		return false;
	}

	e_Item_Spot Item_Spot;
	int Item_ID;
	bool initflag = false;
	//���I�����o�֐�
	static void AllProcess();
	static void AllDraw();

	
	//bool Isspot(int i) {
	//	return spotnum == i;
	//}
	bool operator<(Item _item) const;
	bool operator==(const int val) const;

protected:
	void init();
	void D_Stab();
	//void P_Stab();
};


//extern vector<Item> item_v(ITEM_MAX);