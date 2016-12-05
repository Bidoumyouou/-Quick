#pragma once
#include"DxLib.h"

#include<math.h>

extern bool practiceflag;

class Vector2 {
public:
	int x;
	int y;
	void Set(const int _x,const int _y) {
		x = _x;
		y = _y;
	}
	void Set(const Vector2 _V) {
		*this = _V;
	}
	double distance(Vector2 _V) {
		double temp = sqrt((_V.x - x) * (_V.x - x) + (_V.y - y) * (_V.y - y));
		return temp;
	}
	double distance(const int _x, const int _y) {
		double temp = sqrt((_x - x) * (_x - x) + (_y - y) * (_y - y));
		return temp;
	}
	//éläpå`Ç∆ÇÃÇ†ÇΩÇËîªíË
	bool InSquare (                           const int _x1, const int _y1, const int _x2, const int _y2) {
		if (!(x >= _x1 && x < _x2))return false;
		if (!(y >= _y1 && y < _y2))return false;
		return true;
	}
	bool InSquare (const Vector2 _V1, Vector2 _V2                                   ) {return InSquare(_V1.x, _V1.y, _V2.x, _V2.y);}
	bool InSquare2(const Vector2 _V,				                  int _x, int _y) {return InSquare(_V.x, _V.y, _V.x + _x, _V.y + _y);}
	bool InSquare2(                           const int _x, int _y, int _x2, int _y2) {return InSquare(_x, _y, _x + _x2, _y + _y2);}

	//ââéZ
	//+
	Vector2 operator+(const Vector2 _V) {
		Vector2 ans;
		ans.x = this->x + _V.x;
		ans.y = this->y + _V.y;
		return ans;
	}
	//-
	Vector2 operator-(const Vector2 _V) {
		Vector2 ans;
		ans.x = x - _V.x;
		ans.y = y - _V.y;
		return ans;
	}

	
	
};
// 0 > 1 > 2 > > 1 >0 > 1...Ç›ÇΩÇ¢Ç…ëJà⁄Ç∑ÇÈílÇóLÇ∑ÇÈÉNÉâÉX 
class Loop_int {
public:
	int var = 0;
	bool up = true;//trueÇ»ÇÁupfalseÇ»ÇÁdown(default = true)
	void rapup(int _min, int _max) {
		if (up == true) {
			if (var == _max) {
				up = false;
			}
			add(up);
		}
		else {
			if (var == _min) {
				up = true;
			}
			add(up);
		}
	}
private: 
	void add(bool _up) {
		if (_up == true) {var++;}else {var--;}
	}
};
class Up_int {
public:
	int var = 0;
	void Up(int _min, int _max, int _degree = 1) {
		if (var >= _max) {
			var = _min;
		}
		else {
			var += _degree;
		}
	}
};
// 0 > 1 > 2 > 0 > 1...Ç›ÇΩÇ¢Ç…ëJà⁄Ç∑ÇÈä÷êî 
//int rapup2(int _n,int _max,int _min) {
//	if (_n == _max ) {
//		return _min;
//	}
//	else {
//		return _n++;
//	}
//}

enum e_Item_Spot {
	SPOT_BELT,
	SPOT_POD,
	SPOT_STOCK,
	SPOT_RESULT,
	SPOT_CUSTOMER_1,
	SPOT_CUSTOMER_2,
	SPOT_CUSTOMER_3,
	SPOT_NUM
};

enum E_GameLevel {
	GAME_1,
	GAME_2,
	GAME_NUM
};
extern unsigned int White;
#define WHITE 65535;

void MyDrawRotaGraph(Vector2 v, int GrHandle, int TransFlag = 1, int TurnFlag = FALSE, double ExRate = 1.0, double Angle = 0.0);
void DebugString(Vector2 _v, char* _string);