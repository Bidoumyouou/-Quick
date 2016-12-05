#pragma once
#include"CommonClass.h"
class Message {
public:
	Vector2 HitBox[2];//Squareクラスを作成すべき
	Vector2 Pos;//Posを左上に描画
	char *string;
	void SetHitBox(Vector2 _v1, Vector2 _v2) {
		HitBox[0] = _v1;
		HitBox[1] = _v2;
	}
	void SetPos(Vector2 _v) {
		Pos = _v;
	}
	void SetString(char* _str) {
		string = _str;
	}
	void init() {
		exrate = 0.0;
		alpha = 0;
		exspeed = 0.33;
		alspeed = 32;
	}
	void Process();
	void Draw();
	void DrawGraph(Vector2 _v, int _no);
	void DrawGraph();
	int type = 0;//0は練習用緑表示　1は赤の警告表示
private:
	void Calculate(int _mode);

	bool initflag = false;
	float exrate;
	int alpha;
	float exspeed;
	int alspeed;
	unsigned int Color;

};