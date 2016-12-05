#include "Title.h"
#include "Dxlib.h"
#include "key.h"
#include "phadeout.h"
#include"CommonClass.h"
Title::Title(){
	cursol = 0;
	pushflag = 0;
	timerinit();
	Pos[0].Set(80,200);
	Pos[1].Set(360, 260);
	Pos2[0].Set(80, 200 + 180);
	Pos2[1].Set(360, 260 + 180);
}

Title::~Title(){

}

void Title::Process(){
	Vector2 M;
	M.Set(MouseX, MouseY);
	if (M.InSquare(Pos[0],Pos[1])) {
		cursol = 0;
	}
	if (M.InSquare(Pos2[0], Pos2[1])) {
		cursol = 1;
	}
	/*if (Key[KEY_INPUT_DOWN] == 1){
		cursol = 1;
	}
	if (Key[KEY_INPUT_UP] == 1){
		cursol = 0;
	}
	if (Key[KEY_INPUT_Z] == 1){
		pushflag = 1;
	}*/
	if (Mouse[0] == 1) {
		pushflag = 1;
	}
	if (pushflag > 0){
		if (pushflag == 1){
			if (cursol == 1) {
				practiceflag = false;
			}else{
				practiceflag = true;
			}
			phadeout(NORMAL);
			pushflag = 2;
		}
		if (timer(16) == 1){
			G_Next_GameState = GAME;
		}
	}
}

void Title::Draw(){
	DrawGraph(0, 0, G_IMAGE_TITLE[cursol], 1);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 0, 640, 480, GetColor(0,0, 0), 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);
	DrawGraph(40, 40, G_IMAGE.logo,1);
	int color = GetColor(255, 32, 32);
	DrawRotaFormatStringToHandle(450, 122,1.0 ,1,0,0,3.14 / 8,GetColor(255, 32, 32), Font[1],0,0, "QUICKver!");
	int yazirusi = 0;
	if (cursol == 0) {
		yazirusi = 200;
	}
	if (cursol == 1) {
		yazirusi = 380;
	}
	DrawFormatStringToHandle(16, yazirusi, color, Font[2], "→");

	DrawFormatStringToHandle(80, 200, color, Font[2], "れんしゅう");
	DrawFormatStringToHandle(80, 380, color, Font[2], "スタート");
}

void Title::Init(){

}
void Title::Finish(){

}
Title* m_title;