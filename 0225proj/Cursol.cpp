#define _CRT_SECURE_NO_WARNINGS

#include "Cursol.h"
#include"Resource.h"
#include"Key.h"
C_Cursol *Cursol;

C_Cursol::C_Cursol() {
	
}

C_Cursol::~C_Cursol() {

}


bool C_Cursol::Process() {
	char s[64];
	//sprintf(s, "%d", Mouse[0]);

	if (GetMousePoint(&Pos.x, &Pos.y) < 0)return false;
	GripItem();
	if (GripFreeflag) {
		GripFree();
		
	}
	return true;

}

bool C_Cursol::Draw() {
	//MyDrawRotaGraph(Pos, G_IMAGE_ITEM[16]);
	//DrawGraph(MouseX, MouseY,G_IMAGE_ITEM[16],1);
	return true;
}

void C_Cursol::GripItem() {
	if (Mouse[0] >= 1 && Grip != GRIPPED) {
		//”ÍˆÍ“à‚ÌƒAƒCƒeƒ€‚ÌŒŸõ
		//Grip = GRIP_SEARCH;
	}
	else {
		//Grip = GRIP_DEF;
	}
}

void C_Cursol::GripFree() {
	if (Mouse[0] == 0) {
		Grip = GRIP_DEF;
		GripFreeflag = false;
	}
}