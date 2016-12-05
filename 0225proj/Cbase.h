#ifndef DEF_CBASE_H
#define DEF_CBASE_H
#include"Resource.h"
#include "DXlib.h"
#include "GV.h"
#define TIMER_NUM 256
#define PHADE_TIMER_NUM 16

class CCbase{
private:
protected:
	void timerinit();
public:
	virtual void Init();
	virtual void Finish();
	virtual void Process();
	virtual void Draw();

	int timer(int);
	int timer(int, int);
	int time[TIMER_NUM];
	int phade_timer(int);
	int phade_timer(int, int);
	int phade_time[PHADE_TIMER_NUM];
	//�����܂ł̗v�fstatebase.h�Ɠ���
	int x;
	int y;
	int draw_x;//�K�v�ɉ����Ďg��
	int draw_y;
	int z;//�`��̏���(�O����Ԍ��)
	int ID;//�����N���X�łł����I�u�W�F�N�g���m�̎��ʔԍ�

	CCbase();
	~CCbase();
};

#endif
