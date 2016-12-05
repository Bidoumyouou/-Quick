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
	static int total;//totalはいままでそのオブジェクトがいくつ生成されたか
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
