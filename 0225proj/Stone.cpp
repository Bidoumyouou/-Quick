//#include "Stone.h"
#include"ObjectList.h"
#include <DxLib.h>
#include "GV.h"

Stone::Stone(int arynum) : ObjectBase(arynum){
	exi[arraynum] = true;
	object_n++;//今あるオブジェクトの数
	id = total;
	total++;
	x = 800;
	y = 400;
	xspeed = -1;

}
Stone::Stone(){
}

Stone::~Stone(){
	exi[arraynum] = false;
	object_n--;
}

void Stone::Process(){
	x += xspeed;
}

void Stone::Draw(){
	//仮置きの正方形描画
	DrawBox(x, y, x + 100, y + 100, GetColor(255, 255, 255), 1);
	DrawFormatString(x, y, BLUE, "ID = %d", id);
}
//クラスのProcessを一括で動かす静的メンバ関数
void Stone::AllProcess(){
	for (int i = 0; i < total; i++){
		if (Stone::exi[i]){
			stone[i]->Process();
		}
	}
}
//クラスのDrawを一括で動かす静的メンバ関数
void Stone::AllDraw(){
	for (int i = 0; i < total; i++){
		if (Stone::exi[i]){
			stone[i]->Draw();
		}
	}
	
}
//インスタンスの作成
void Stone::Make(){
	for (int i = 0; i < object_n + 1; i++){
		if (Stone::exi[i] == 0){
			stone[i] = new Stone(i);
			return;
		}
	}
}
//インスタンスの削除
void Stone::Delete(int i){
	if (Stone::object_n > 0){
		delete stone[i];
	}
}
int Stone::GetObject_n(){
	return object_n;
}
int Stone::total = 0;
int Stone::object_n = 0;//静的メンバ変数の実体
bool Stone::exi[OBJECT_MAX] = {};

Stone* stone[1024];
