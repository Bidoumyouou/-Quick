#include "Message.h"
#include"Cursol.h"
#include"key.h"
#include"DxLib.h";
#include"GameMgr.h"
#include"Resource.h"
void Message::Process() {

	if (!initflag) {
		init();
		initflag = true;
	}
	Vector2 mouse;
	mouse.Set(MouseX, MouseY);
	//もし表示範囲の中に入ったら
	if (mouse.InSquare(HitBox[0], HitBox[1])) {
		Calculate(1);
	}
	else {
		Calculate(-1);
	}
}

void Message::Draw() {
	//DrawFormatStringToHandle(Pos.x, Pos.y, GetColor(255, 0, 0), Font[0], string);
	double R = 0;
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	if(type >= 1){
		Color = GetColor(0, 0, 255);
	}
	if (type == 0) {
		Color = GetColor(255, 0, 0);
	}
	
	DrawRotaFormatStringToHandle(Pos.x, Pos.y, exrate, exrate, 0, 0, R, Color, Font[0], GetColor(0, 0, 0), 0, string);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
}
//画像を表示する(もはや汎用性のかけらもない)
void Message::DrawGraph(Vector2 _v,int _no) {
	//DrawRotaGraph(_v.x,_v.y,exrate,0,G_IMAGE.)
}
//サイズと透明度を操作
void Message::Calculate(int _mode){
	if (_mode >= 0) {
		exrate += exspeed;
		if (exrate > 1) {
			exrate = 1.0;
		}
		alpha += alspeed;
		if (alpha > 255) {
			alpha = 255;
		}
	}
	else {
		//減少
		exrate -= exspeed;
		if (exrate < 0) {
			exrate = 0.0;
		}
		alpha -= alspeed;
		if (alpha < 0) {
			alpha = 0;
		}

	}
}