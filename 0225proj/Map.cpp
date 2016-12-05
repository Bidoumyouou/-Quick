#include"Cbase.h"
#include"Map.h"
int Masu_N = 0;

CMasu::CMasu(int id){
	ID = id;
	x = (ID % 4) * 80;
	y = 200 + ID * 25;
	draw_x = 0;
	draw_y = 0; 
}

CMasu::~CMasu(){

}

void CMasu::Process(){

}

void CMasu::Draw(){
	//DrawBox(x - (MASU_X / 2), y - (MASU_Y / 2), x + (MASU_X / 2), y + MASU_Y / 2, BLUE, 1);
}

void CMasu::Init(){

}

void CMasu::Finish(){

}

CMasu* Masu[64];
//GameMgrから呼び出される生成したオブジェクトを動かす関数
void Masu_Process(){
	
}

void Masu_Draw(){
	
}
