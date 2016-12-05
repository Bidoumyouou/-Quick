#ifndef DEF_RESOURCE_H
#define DEF_RESOURCE_H

//�f�ރn���h�����N���X�ňꌳ�Ǘ������ق����悭�Ȃ��H
//�ė��p�����쐬�̈��
class C_GraphResource{
public:
	int title[3];
	int back;
	int item[64];
	int UI[16];
	int pod[4];
	int podturn[16];
	int conbair[256];
	int timer[32];
	int text[8];
	int bar[10];
	int Button;
	int logo;
	int player[16];
	int recipe[4];
};


void ResouceLoad();
void MyPlaySound(int _Handle, int _Vol, int _Mode);
//�f�ޓǂݍ��݊֐�
extern int Font[3];//���t�H���g
extern int sound[64];
extern int Music[2];

////�摜
extern C_GraphResource G_IMAGE;

////////�^�C�g��
extern int G_IMAGE_TITLE[3];
////////�Q�[��
extern int G_IMAGE_ENEMY[4];
extern int G_IMAGE_ITEM[64];
////////���U���g
extern int G_IMAGE_UI[16];

//�T�E���h
extern int G_MUSIC_00;//0~�̓^�C�g��

#endif