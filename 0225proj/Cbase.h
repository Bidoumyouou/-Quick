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
	//ここまでの要素statebase.hと同じ
	int x;
	int y;
	int draw_x;//必要に応じて使う
	int draw_y;
	int z;//描画の順番(０が一番後ろ)
	int ID;//同じクラスでできたオブジェクト同士の識別番号

	CCbase();
	~CCbase();
};

#endif
