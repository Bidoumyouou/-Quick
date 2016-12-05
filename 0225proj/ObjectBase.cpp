#include "ObjectBase.h"
#include "DxLib.h"
#include <vector>
#include <algorithm>
#include <cstdio>
ObjectBase* Object[OBJECT_MAX];
//コンストラクタ
ObjectBase::ObjectBase(int arynum) 
{
	t = 0;
	//x = 100 + GetRand(400);
	//y = 100 + GetRand(400);
	arraynum = arynum;
	
	Object[arraynum]->global_object_n++;
	global_id = global_total;
	global_total++;
	
}
ObjectBase::ObjectBase(){}
ObjectBase::~ObjectBase(){
	global_object_n--;
	
}
void ObjectBase::Process(){	
	//時間変化
	t++;
}

void ObjectBase::Draw(){}

void ObjectBase::AllProcess(){
	//for (int i = 0; i < object_n; i++){
		//if (ObjectBase::exi[i]){
		//	Object[i]->Process();
		//}
	//}
}
void ObjectBase::AllDraw(){
	//for (int i = 0; i < object_n; i++){
//		if (ObjectBase::exi[i]){
//			Object[i]->Draw();
//		}
	//}
	
}
void ObjectBase::Make(){
	//for (int i = 0; i < object_n; i++){
		//if (ObjectBase::exi[i] == 0){
		//	Object[i] = new ObjectBase(i);
		//	return;
		//}
	//}
}
void ObjectBase::Delete(int i){
	/*if (ObjectBase::object_n){
		delete Object[i];
	}*/
}




int ObjectBase::global_object_n = 0;//静的メンバ変数の実体
int ObjectBase::global_total = 0;



