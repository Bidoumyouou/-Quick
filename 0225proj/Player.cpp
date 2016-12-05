//#include "Player.h"
#include"ObjectList.h"
#include <DxLib.h>
#include "GV.h"
#include "key.h"

#define YACCEL	1
#define JUMPY	-10

#define YGRAND 400


Player::Player(int arynum) : ObjectBase(arynum){
	exi[arraynum] = true;
	object_n++;
	id = total;
	total++;

	number = object_n - 1;

	x = 250 - object_n * 50;
	y = YGRAND;
	yspeed = 0;





}
Player::Player(){
	
}

Player::~Player(){
	exi[arraynum] = false;
	object_n--;
}

void Player::Process(){
	if (y > YGRAND) {
		y = YGRAND;
		yspeed = 0;
	}
	if (y < YGRAND) {

		yspeed += YACCEL;
	}
	if (yspeed != 0) {
		y += yspeed;
	}


	if (Key[keymap[number]] == 1)
		if (yspeed == 0)
			yspeed = JUMPY;





}

void Player::Draw(){
	//���u���̐����`�`��
	DrawBox(x, y, x + 48, y + 48, GetColor(255, 255, 255), 1);
	DrawFormatString(x, y, BLUE, "ID = %d", id);
}
//�N���X��Process���ꊇ�œ������ÓI�����o�֐�
void Player::AllProcess(){
	printf("Num:%d\n", object_n);
	for (int i = 0; i < total; i++){
		if (Player::exi[i]){
			player[i]->Process();
		}
	}
}
//�N���X��Draw���ꊇ�œ������ÓI�����o�֐�
void Player::AllDraw(){
	for (int i = 0; i < total; i++){
		if (Player::exi[i]){
			player[i]->Draw();
		}
	}
	
}
//�C���X�^���X�̍쐬
void Player::Make(){
	for (int i = 0; i < object_n + 1; i++){
		if (Player::exi[i] == 0){
			player[i] = new Player(i);
			return;
		}
	}
}
//�C���X�^���X�̍폜
void Player::Delete(int i){
	if (Player::object_n > 0){
		delete player[i];
	}
}
int Player::GetObject_n(){
	return object_n;
}
int Player::total = 0;
int Player::object_n = 0;//�ÓI�����o�ϐ��̎���
bool Player::exi[OBJECT_MAX] = {};
Player* player[1024];


int Player::keymap[8] = {
	KEY_INPUT_K,
	KEY_INPUT_J,
	KEY_INPUT_H,
	KEY_INPUT_G,
	KEY_INPUT_F,
	KEY_INPUT_D,
	KEY_INPUT_S,
	KEY_INPUT_A
};

