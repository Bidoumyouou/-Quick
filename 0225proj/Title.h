#ifndef DEF_TITLE_H
#define DEF_TITLE_H
#include"StateBase.h"
#include"Resource.h"
#include "state.h"
#include"CommonClass.h"
class Title: public CSbase{
private:
	int cursol = 0;
	int pushflag = 0;
public:
	Title();
	~Title();
	void Init();
	void Finish();
	void Process();
	void Draw();

	Vector2 Pos[2];
	Vector2 Pos2[2];
};

extern Title* m_title;
#endif