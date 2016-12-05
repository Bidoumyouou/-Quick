#include "GameMgr.h"
#include "Dxlib.h"
#include "key.h"

#include "class.h"
#include "GameMgr_class.h"
#include"Spot.h"
#include<algorithm>
//�ȉ��̓e�X�g�ȊO�ł͕s�v
#include"ObjectList.h"
#include"Item.h"
int square_exi = 0;
Spot *spot[SPOT_MAX];

GameMgr::GameMgr(){
	PlayMusicMem(Music[0],DX_PLAYTYPE_LOOP);
	SetVolumeMusicMem(120, Music[0]);
	timerinit();
	Score.Init();
	//Result
}

GameMgr::~GameMgr(){
	StopMusicMem(Music[0]);

}

void GameMgr::MakeGameObject(){

	//���Ɉ�����X�|�b�g���쐬
	Vector2 v1, v2, v3, v4, v5, v6,v7;
	v1.Set(32 *11,32 * 2);//�R���x�A
	v2.Set(32 * 5,32 * 9);//�q
	v3.Set(32 * 3,32 * 3);//�X�g�b�N
	v4.Set(32 * 9 + 16, 32 * 9 + 16);//���U���g
	v5.Set(32 * 18 - 16, 32 * 8);//�q
	v6.Set(32 * 18 - 16, 32 * 13 - 16);
	v7.Set(32 * 13, 32 * 13 - 16);
	spot[0] = new Spot(v1,SPOT_BELT);
	spot[1] = new Spot(v2,SPOT_POD);
	spot[2] = new Spot(v3, SPOT_STOCK);
	spot[3] = new Spot(v4, SPOT_RESULT);
	spot[4] = new Spot(v5, SPOT_CUSTOMER_1);
	spot[5] = new Spot(v6, SPOT_CUSTOMER_2);
	spot[6] = new Spot(v7, SPOT_CUSTOMER_3);
	//���ɃA�C�e�����쐬
	Item::MakeItem(0);
	Item::MakeItem(0);
	Item::MakeItem(0);
	Item::MakeItem(2);
	Item::MakeItem(2);
	Item::MakeItem(2);
	//���U���g
	ResultPos.Set(32*2,32  * 2);
}


void GameMgr::Process(){
	if (iniflag == 0) {
		iniflag = 1;
		//Init();
	}
	Score.Behave();
	if (Score.hour >= 18) {
		//�Q�[���I��
		ResultProcess();
	}
	else {

		GameMgr_class_Process();
		//�X�|�b�g
		for (int i = 0; i < SPOT_MAX; i++) {
			if (spot[i] != nullptr) {
				spot[i]->Process();
			}
		}
		//�J�[�\��
		if (Key[KEY_INPUT_Q] == 1) {
			if (practiceflag == true) {
				Score.hour = 18;
			}
		}

		Item::AllProcess();
		RoyalMgr();
	}
}

void GameMgr::RoyalMgr() {
	if (Key[KEY_INPUT_K] == 1) {
		royalsignal = true;
	}
	if (royal_n == 0) {
		if (Score.score >= 4000) {
			royal_n++;
			royalsignal = true;
		}
	}
	if (royal_n == 1) {
		if (Score.score >= 11000) {
			royal_n++;
			royalsignal = true;
		}
	}
}

void GameMgr::ResultProcess() {
	for (int i = 0; i < 256; i++) {
		if (Key[i] == 1) {
			//�^�C�g���֖߂�
			G_Next_GameState = TITLE;
			Finish();
			MyPlaySound(sound[7], 100, 1);
		}
	}

}

//
void GameMgr::ItemMaker(int _spot, int _id) {
	Item::MakeItem(_spot, _id);
}

void GameMgr::Draw() {
	//�w�i�̕`��
	DrawGraph(0, 0, G_IMAGE.back, 1);
	DrawStructure();

	//�ݒu��(�q�A�R���x�A�̈ړ�)
	GameMgr_class_Draw();
	for (int i = 0; i < SPOT_MAX; i++) {
		if (spot[i] != nullptr) {
			spot[i]->Draw();
		}
	}
	Item::AllDraw();
	//FontTest();
	//���V�s�\��
	char *str;
	if (recipeflag == 1) {
		str = "���V�s���\��";
	}else {
		str = "���V�s��\��";
	}
	DrawFormatStringToHandle(0, 64, GetColor(0, 0, 255), Font[0],str);
	Vector2 V;
	Vector2 V2;
	Vector2 mouse;
	V.Set(0, 48);
	V2.Set(96, 88);
	mouse.Set(MouseX, MouseY);
	if (mouse.InSquare(V, V2)) {
		if (Mouse[0] == 1) {
			recipeflag = 1 - recipeflag;
		}
		DrawGraph(0, 80, G_IMAGE.recipe[0], 1);
		DrawGraph(0, 112, G_IMAGE.recipe[1], 1);
		DrawGraph(0, 144, G_IMAGE.recipe[2], 1);
		DrawGraph(0, 176, G_IMAGE.recipe[3], 1);
	}
	if (recipeflag == 1) {
		DrawGraph(0, 80, G_IMAGE.recipe[0], 1);
		DrawGraph(0, 112, G_IMAGE.recipe[1], 1);
		DrawGraph(0, 144, G_IMAGE.recipe[2], 1);
		DrawGraph(0, 176, G_IMAGE.recipe[3], 1);
	}
	Score.Draw();
	if (Score.hour >= END_HOUR) {
		//�Q�[���I��
		DrawResult();
	}

}
void GameMgr::DrawStructure() {
	//�R���x�A
	//�n���ɂЂƂÂ�����
	int SIZE = 32;
	//�J�E���g�A�b�v�֐����炢���
	
	DrawGraph(SIZE * 17, SIZE * 1, G_IMAGE.conbair[4], 1);
	DrawGraph(SIZE * 17, SIZE * 2, G_IMAGE.conbair[0 + con_anime], 1);
	DrawGraph(SIZE * 17, SIZE * 3, G_IMAGE.conbair[18 + con_anime], 1);
	DrawGraph(SIZE * 16, SIZE * 3, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 15, SIZE * 3, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 14, SIZE * 3, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 13, SIZE * 3, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 12, SIZE * 3, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 11, SIZE * 3, G_IMAGE.conbair[3 + con_anime], 1);
	DrawGraph(SIZE * 11, SIZE * 4, G_IMAGE.conbair[0 + con_anime], 1);
	DrawGraph(SIZE * 11, SIZE * 5, G_IMAGE.conbair[16 + con_anime], 1);
	DrawGraph(SIZE * 12, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 13, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 14, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 15, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 16, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 17, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	DrawGraph(SIZE * 18, SIZE * 5, G_IMAGE.conbair[17 + con_anime], 1);
	//���̓y��
	DrawGraph(SIZE * 12, SIZE * 4, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 13, SIZE * 4, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 14, SIZE * 4, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 15, SIZE * 4, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 16, SIZE * 4, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 17, SIZE * 4, G_IMAGE.conbair[34], 1);
	DrawGraph(SIZE * 11, SIZE * 6, G_IMAGE.conbair[32], 1);
	DrawGraph(SIZE * 12, SIZE * 6, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 13, SIZE * 6, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 14, SIZE * 6, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 15, SIZE * 6, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 16, SIZE * 6, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 17, SIZE * 6, G_IMAGE.conbair[33], 1);
	DrawGraph(SIZE * 18, SIZE * 6, G_IMAGE.conbair[33], 1);

	
}

void GameMgr::DrawResult() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	DrawFormatString(ResultPos.x, ResultPos.y, GetColor(255, 255, 255), "����F%6d�~   �����ꂳ�܁I", Score.score);
	DrawFormatString(ResultPos.x, ResultPos.y + 64, GetColor(255, 255, 255), "PRESS ANY KEY�`�^�C�g���ց`");
}

void GameMgr::Init(){
	gamelevel = GAME_2;
	ItemList.DataSet();
	MakeGameObject();

	//PlaySoundMem(G_MUSIC_00, DX_PLAYTYPE_BACK, true);
}
void GameMgr::Finish(){
	StopSoundMem(G_MUSIC_00);
	//�e�I�u�W�F�N�g�̔j��
	for (int i = 0; i < 7; i++) {
		delete spot[i];
		spot[i] = nullptr;
	}
	
	while (!(Item::item_v.empty())) {
		Item::item_v.pop_back();
	}
}

void GameMgr::FontTest() {
	DrawFormatStringFToHandle(0, 0, GetColor(255, 0, 0), Font[0], "Testting Trest");
}

GameMgr* m_GameMgr;