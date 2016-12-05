#pragma once
#include "ObjectBase.h"

class Stone :public ObjectBase 
{
public:
	Stone();
	Stone(int);
	~Stone();
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
extern Stone *stone[1024];
