//#include "Dammy.h"
#include"ObjectList.h"
#include <DxLib.h>
#include "GV.h"

Dammy::Dammy(int arynum) : ObjectBase(arynum){
	exi[arraynum] = true;
	object_n++;
	id = total;
	total++;
}
Dammy::Dammy(){
	
}

Dammy::~Dammy(){
	exi[arraynum] = false;
	object_n--;
}

void Dammy::Process(){

}

void Dammy::Draw(){
	//仮置きの正方形描画
	DrawBox(x, y, x + 100, y + 100, GetColor(255, 255, 255), 1);
	DrawFormatString(x, y, BLUE, "ID = %d", id);
}
//クラスのProcessを一括で動かす静的メンバ関数
void Dammy::AllProcess(){
	for (int i = 0; i < total; i++){
		if (Dammy::exi[i]){
			dammy[i]->Process();
		}
	}
}
//クラスのDrawを一括で動かす静的メンバ関数
void Dammy::AllDraw(){
	for (int i = 0; i < total; i++){
		if (Dammy::exi[i]){
			dammy[i]->Draw();
		}
	}
	
}
//インスタンスの作成
void Dammy::Make(){
	for (int i = 0; i < object_n + 1; i++){
		if (Dammy::exi[i] == 0){
			dammy[i] = new Dammy(i);
			return;
		}
	}
}
//インスタンスの削除
void Dammy::Delete(int i){
	if (Dammy::object_n > 0){
		delete dammy[i];
	}
}
int Dammy::GetObject_n(){
	return object_n;
}
int Dammy::total = 0;
int Dammy::object_n = 0;//静的メンバ変数の実体
bool Dammy::exi[OBJECT_MAX] = {};

Dammy* dammy[1024];
