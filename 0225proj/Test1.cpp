//#include "Test1.h"
#include"ObjectList.h"
#include <DxLib.h>
#include "GV.h"

Test1::Test1(int arynum) : ObjectBase(arynum){
	exi[arraynum] = true;
	object_n++;
	id = total;
	total++;
}
Test1::Test1(){
	
}

Test1::~Test1(){
	exi[arraynum] = false;
	object_n--;
}

void Test1::Process(){

}

void Test1::Draw(){
	//���u���̐����`�`��
	DrawBox(x, y, x + 49, y + 49, GetColor(0, 255, 255), 1);
	DrawFormatString(x, y, BLUE, "ID = %d", id);
}
//�N���X��Process���ꊇ�œ������ÓI�����o�֐�
void Test1::AllProcess(){
	for (int i = 0; i < total; i++){
		if (Test1::exi[i]){
			test1[i]->Process();
		}
	}
}
//�N���X��Draw���ꊇ�œ������ÓI�����o�֐�
void Test1::AllDraw(){
	for (int i = 0; i < total; i++){
		if (Test1::exi[i]){
			test1[i]->Draw();
		}
	}
	
}
//�C���X�^���X�̍쐬
void Test1::Make(){
	for (int i = 0; i < object_n + 1; i++){
		if (Test1::exi[i] == 0){
			test1[i] = new Test1(i);
			return;
		}
	}
}
//�C���X�^���X�̍폜
void Test1::Delete(int i){
	if (Test1::object_n > 0){
		delete test1[i];
	}
}
int Test1::GetObject_n(){
	return object_n;
}
int Test1::total = 0;
int Test1::object_n = 0;//�ÓI�����o�ϐ��̎���
bool Test1::exi[OBJECT_MAX] = {};

Test1* test1[1024];
