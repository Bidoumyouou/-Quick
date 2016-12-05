#pragma once
#include"CommonClass.h"
#define GRIP_RANGE_ITEM 8
enum GRIPSTATE {
	GRIP_DEF,
	GRIP_SEARCH,
	GRIPPED,
	GRIP_NUM
};

class C_Cursol {

	
	void TrackPointer();
	void GripItem();
	void GripFree();
public:
	

	C_Cursol();
	~C_Cursol();
	bool Process();
	bool Draw();
	Vector2 Pos;
	GRIPSTATE Grip = GRIP_DEF;

	bool GripFreeflag = false;
};

extern C_Cursol *Cursol;