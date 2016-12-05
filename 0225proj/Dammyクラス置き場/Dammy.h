#pragma once
#include "ObjectBase.h"

class Dammy :public ObjectBase 
{
public:
	Dammy();
	Dammy(int);
	~Dammy();
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
};
extern Dammy *dammy[1024];
