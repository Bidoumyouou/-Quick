
#pragma once
#include"CommonClass.h"
enum E_ITEM {
	I_REQ_R,
	I_REQ_B,
	I_REQ_G,
	I_REQ_Y,
	I_POWD_A,
	I_POWD_B,
	I_POWD_C,
	I_POWD_D,
	I_NEL_R,
	I_NEL_B,
	I_NEL_G,
	I_NEL_Y,
	I_WATA_R,
	I_WATA_B,
	I_WATA_G,
	I_WATA_Y,
	I_CH_R,
	I_CH_B,
	I_CH_G,
	I_CH_Y,
	I_KING_R,
	I_KING_B,
	I_KING_G,
	I_KING_Y,
	I_CAKE,
	I_FAIL = -1
};

class Spot;
class BeltBehavior;
class SpotBehavior{
public:
	Vector2 ExtraPos[8];//構造の欠陥を感じさせる
	e_Item_Spot SpotType;
	Spot* sp;
	virtual bool Behave() { return true; }
	virtual void Draw() { return; };
	virtual void Init(Spot *);
	Vector2 HitBox[2];//あたり判定の四角形
	Vector2 HitBox_Sub[2];//補助的なHitBox
};

