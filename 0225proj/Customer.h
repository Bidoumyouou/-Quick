#pragma once
#include"SpotBehave.h"
#include"CommonClass.h"
#include "Message.h"
#define STRESS_MAX 4000

//スポットからの相対座標
#define REQUEST_OFFSET_X 32
#define REQUEST_OFFSET_Y 0

#define STRESS_OFFSET_X -12
#define STRESS_OFFSET_Y -6


class Spot;
class Request;
class CustomerBehavior;

//試験的に小型クラスで作成(結果的に微妙)
class C_Request {
	friend CustomerBehavior;
#define REQUEST_WAIT_MAX 1000
private:
	const int stressspeed = 1;
	int waitlimit;//客待ち一回ごとに定まる発生までの待ち時間
	int waittime;
	E_ITEM item = I_FAIL;

public:
	CustomerBehavior *Behavior;
	int stress;

	void Behave();
	void RequestDelete();
	void Draw();
	
};

#define REQUESTLIST_MAX 32
class C_RequestList{
public:
	E_ITEM item[REQUESTLIST_MAX];
	int list_n;
	void MakeList();
};
class CustomerBehavior :public SpotBehavior {
public:
	bool WaitForRequest = true;//tでリクエストがない状態
	bool Behave();
	bool IsRequestClear();
	void SellItem();
	void Draw();
	double stressdegree = 0.0;
	void Init(Spot *s);
	C_Request Request;
	Vector2 Request_Pos;//リクエスト表示座標
	Vector2 Stress_Pos;//ゲージ表示座標

	C_RequestList RequestList;
	Message Mes,MesP;
};


