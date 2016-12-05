#pragma once
#include"ObjectBase.h"
#include"CommonClass.h"
#include"SpotBehave.h"
#include<map>
#include<vector>
//#include"Spot.h"
//アイテムがどの領域にあるか
#define ITEM_MAX 64

#define ITEM_HIT_RADIATE 16 
using namespace std;
//vector<Item>::iterator Item:: *p;
class Spot;
class GameMgr;
class A {

};




class Item {
	//適当
public:
	
	Vector2 Pos;//Posは特定の条件でのみ変化、DrawPosは毎フレーム更新
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
	int spotnum;//何番のスポットに入ってるか
	//どのスポットに入っているか
	e_Item_Spot Spot;
	//エリアの何番に入っているか
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
	//性的メンバ関数
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