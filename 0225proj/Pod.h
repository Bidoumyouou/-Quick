#pragma once
#pragma once
#include"SpotBehave.h"
#include"CommonClass.h"
#include"Message.h"

class Spot;
#define RECIPE_MAX 64
enum E_RECIPE {
	R_NEL_R,
	R_NEL_B,
	R_NEL_G,
	R_NEL_Y,
	R_WATA_R,
	R_WATA_B,
	R_WATA_G,
	R_WATA_Y,
	R_CH_R,
	R_CH_B,
	R_CH_G,
	R_CH_Y,
	R_FAIL = -1
};

class Recipe {
public:
	int ID;
	int matel[6];
	int Inpodmatel[6];
	int pool;
	int time;
	E_ITEM result;
	bool IsClear();
	void Set(SpotBehavior *_pod, E_ITEM _result = I_NEL_R, int _pool = 4, int _time = 0,int _mat1 = -1, int _mat2 = -1, int _mat3 = -1, int _mat4 = -1, int _mat5 = -1, int _mat6 = -1);//�擪�̈�����this
	void Show();
	SpotBehavior *pod;
};

class PodBehavior :public SpotBehavior {
public:
	void RecipeMgr();
	bool Behave();
	void Making();
	void Draw();
	void Init(Spot *s);

	void SetRecipe();

	void SuggestMgr();
	void SuggestChange(int);//���ۂɍ쐬����ύX����(�����̂Ԃ񂾂�)
	void ButtonBehave();
	void NoPod();
	void Convine();
	int suggest[24];
	
	Vector2 Button;
	Vector2 Pool;//�܂��镔��
	Vector2 PoolSector[4];// 0 1
	                      // 3 2
	Vector2 PoolSectorSize;
	
	//������p�̃t���O
	int mixflag = 0;
	int mixstate = -1;//�ǂ̏ꏊ�ō����Ă邩
	bool mixangle = false;//false�����v����
	Vector2 Suggest;//���芮���A�C�e����\�����镔��
	Vector2 SuggestNow;//����낤�Ƃ��Ă���̂�\������ꏊ
	Vector2 SuggestChanger[2];//�������̂���₩��I�ԃ{�^��
	Recipe recipe[RECIPE_MAX];

	Loop_int pod_anime_t;

	int suggest_num = 0;
	int nowsuggest = 0;
	int Inpodmatel[6];
	int making = -1;//�쐬����A�C�e��(-1�Ȃ����ĂȂ�)
	int nowmake = -1;//�쐬���Ă��郌�V�s�ԍ�

	int makingpool;
	int makingtime;
	
	int makingtimer = 0;
	int stewflag = 0;
	bool waitingmake;//������܂ł̑҂����Ԃ��ǂ���
	bool ispod() {
		return makingtimer >= makingtime;
	}//����������Ԃ��ۂ�
	Message Mes,MesP;
};

//pod��result���j�R�C�`�ō���Ă݂�

class ResultBehavior :public SpotBehavior {
public:
	bool Behave();
	void Draw();
	void Init(Spot *s);
	Message Mes;
};