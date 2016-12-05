#pragma once
#include"SpotBehave.h"
#include"CommonClass.h"
#include "Message.h"
#define STRESS_MAX 4000

//�X�|�b�g����̑��΍��W
#define REQUEST_OFFSET_X 32
#define REQUEST_OFFSET_Y 0

#define STRESS_OFFSET_X -12
#define STRESS_OFFSET_Y -6


class Spot;
class Request;
class CustomerBehavior;

//�����I�ɏ��^�N���X�ō쐬(���ʓI�ɔ���)
class C_Request {
	friend CustomerBehavior;
#define REQUEST_WAIT_MAX 1000
private:
	const int stressspeed = 1;
	int waitlimit;//�q�҂���񂲂Ƃɒ�܂锭���܂ł̑҂�����
	int waittime;
	E_ITEM item = I_FAIL;

public:
	CustomerBehavior *Behavior;
	int stress;

	void Behave();
	void RequestDelete();
	void Draw();
	
};

#define REQUESTLIST_MAX 32
class C_RequestList{
public:
	E_ITEM item[REQUESTLIST_MAX];
	int list_n;
	void MakeList();
};
class CustomerBehavior :public SpotBehavior {
public:
	bool WaitForRequest = true;//t�Ń��N�G�X�g���Ȃ����
	bool Behave();
	bool IsRequestClear();
	void SellItem();
	void Draw();
	double stressdegree = 0.0;
	void Init(Spot *s);
	C_Request Request;
	Vector2 Request_Pos;//���N�G�X�g�\�����W
	Vector2 Stress_Pos;//�Q�[�W�\�����W

	C_RequestList RequestList;
	Message Mes,MesP;
};


