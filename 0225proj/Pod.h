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
	void Set(SpotBehavior *_pod, E_ITEM _result = I_NEL_R, int _pool = 4, int _time = 0,int _mat1 = -1, int _mat2 = -1, int _mat3 = -1, int _mat4 = -1, int _mat5 = -1, int _mat6 = -1);//先頭の引数はthis
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
	void SuggestChange(int);//実際に作成候補を変更する(数字のぶんだけ)
	void ButtonBehave();
	void NoPod();
	void Convine();
	int suggest[24];
	
	Vector2 Button;
	Vector2 Pool;//まぜる部分
	Vector2 PoolSector[4];// 0 1
	                      // 3 2
	Vector2 PoolSectorSize;
	
	//混ぜる用のフラグ
	int mixflag = 0;
	int mixstate = -1;//どの場所で混ぜてるか
	bool mixangle = false;//falseが時計周り
	Vector2 Suggest;//推定完成アイテムを表示する部分
	Vector2 SuggestNow;//今作ろうとしてるものを表示する場所
	Vector2 SuggestChanger[2];//今作るものを候補から選ぶボタン
	Recipe recipe[RECIPE_MAX];

	Loop_int pod_anime_t;

	int suggest_num = 0;
	int nowsuggest = 0;
	int Inpodmatel[6];
	int making = -1;//作成するアイテム(-1なら作ってない)
	int nowmake = -1;//作成しているレシピ番号

	int makingpool;
	int makingtime;
	
	int makingtimer = 0;
	int stewflag = 0;
	bool waitingmake;//混ぜるまでの待ち時間かどうか
	bool ispod() {
		return makingtimer >= makingtime;
	}//混ぜ混ぜ状態か否か
	Message Mes,MesP;
};

//podとresultをニコイチで作ってみる

class ResultBehavior :public SpotBehavior {
public:
	bool Behave();
	void Draw();
	void Init(Spot *s);
	Message Mes;
};