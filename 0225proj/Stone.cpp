//#include "Stone.h"
#include"ObjectList.h"
#include <DxLib.h>
#include "GV.h"

Stone::Stone(int arynum) : ObjectBase(arynum){
	exi[arraynum] = true;
	object_n++;//������I�u�W�F�N�g�̐�
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
	//���u���̐����`�`��
	DrawBox(x, y, x + 100, y + 100, GetColor(255, 255, 255), 1);
	DrawFormatString(x, y, BLUE, "ID = %d", id);
}
//�N���X��Process���ꊇ�œ������ÓI�����o�֐�
void Stone::AllProcess(){
	for (int i = 0; i < total; i++){
		if (Stone::exi[i]){
			stone[i]->Process();
		}
	}
}
//�N���X��Draw���ꊇ�œ������ÓI�����o�֐�
void Stone::AllDraw(){
	for (int i = 0; i < total; i++){
		if (Stone::exi[i]){
			stone[i]->Draw();
		}
	}
	
}
//�C���X�^���X�̍쐬
void Stone::Make(){
	for (int i = 0; i < object_n + 1; i++){
		if (Stone::exi[i] == 0){
			stone[i] = new Stone(i);
			return;
		}
	}
}
//�C���X�^���X�̍폜
void Stone::Delete(int i){
	if (Stone::object_n > 0){
		delete stone[i];
	}
}
int Stone::GetObject_n(){
	return object_n;
}
int Stone::total = 0;
int Stone::object_n = 0;//�ÓI�����o�ϐ��̎���
bool Stone::exi[OBJECT_MAX] = {};

Stone* stone[1024];
