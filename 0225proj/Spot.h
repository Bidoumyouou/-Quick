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

//領域の基底クラス
class Spot {
public:
	//描画座標
	Vector2 DrawPos;
	Spot(Vector2 _V, e_Item_Spot _arraynum);
	~Spot() {
	}
	e_Item_Spot SpotType;
	//スタブ
	
	//領域
	AREA Area;

	int Item_n = 0;//入ってるアイテムの数

	//プロセス
	bool Process();
	//描画
	bool Draw();
	vector<Item>::iterator itr;
	vector<Item>::iterator itr2;
	void SpotRemake();

	static void AllSpotRemake();

	bool RemakeSignal;
	Vector2 ExtraPos[8];//構造の欠陥を感じさせる
	Vector2 GetHitbox(int _mode,int _mode2) {
		if (_mode == 0) {
			//メインヒットボックス
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