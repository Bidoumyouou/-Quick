#pragma once
#include "ObjectBase.h"

class Player :public ObjectBase 
{
public:
	Player();
	Player(int);
	~Player();
	void Process();
	void Draw();
	static int total;//total�͂��܂܂ł��̃I�u�W�F�N�g�������������ꂽ��
	static bool exi[OBJECT_MAX];
	static void AllProcess();
	static void AllDraw();
	static void Make();
	static void Delete(int);
	static int GetObject_n();
protected:
	static int object_n;//

	static int keymap[8];
	int number;




};
extern Player *player[1024];
