#ifndef DEF_GAME_H
#define DEF_GAME_H
#include "Resource.h"
#include "state.h"
#include "StateBase.h"
#include"Spot.h"
#include"Item.h"
#include"Score.h"
#include"ItemList.h"
#include"Message.h"
#include<vector>
#define SPOT_MAX 7
//�Q�[���̃o�����X�����Ɏg�p


class GameMgr:public CSbase{
private:
	int typenum;
	int typeexi;

	void MakeGameObject();
public:
	E_GameLevel gamelevel = GAME_2;

	GameMgr();
	~GameMgr();
	void Init();
	bool iniflag = false;
	void Finish();
	void Process();
	void ItemMaker(int _spot, int _id);
	void Draw();
	void DrawStructure();
	int con_anime = 0;
	int timer(int);
	int time;
	int timerpack(int, int);
	int timepack[16];
	void AllObjectProcess();
	void AllObjectDraw();

	void ResultProcess();
	void DrawResult();
	C_SCORE Score;
	C_ItemList ItemList;
	Vector2 ResultPos;

	int royal_n = 0;//����M�����ł���
	bool royalsignal = false;//true�̂Ƃ��K������M�����r�o�����

	Message Mes,MesP;
	int recipeflag = 0;
	void RoyalMgr();

	void FontTest();
};

extern GameMgr* m_GameMgr;
extern Spot *spot[SPOT_MAX];

#endif