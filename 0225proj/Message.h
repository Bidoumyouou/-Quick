#pragma once
#include"CommonClass.h"
class Message {
public:
	Vector2 HitBox[2];//SquareNXπμ¬·Χ«
	Vector2 Pos;//PosπΆγΙ`ζ
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
	int type = 0;//0ΝϋKpΞ\¦@1ΝΤΜx\¦
private:
	void Calculate(int _mode);

	bool initflag = false;
	float exrate;
	int alpha;
	float exspeed;
	int alspeed;
	unsigned int Color;

};