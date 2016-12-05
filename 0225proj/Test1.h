#pragma once
#include "ObjectBase.h"

class Test1 :public ObjectBase 
{
public:
	Test1();
	Test1(int);
	~Test1();
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
extern Test1 *test1[1024];
