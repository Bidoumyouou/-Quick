#pragma once
#define START_HOUR 10
#define END_HOUR 18

class C_SCORE {
public:
	int score;
	int date;//今度実装しよっと
	bool rank;//今の順位
	int time;//1800で終了
	int hour;//必ずtimeと連動
	int minute;

	void Set(int _score) {
		score = _score;
	}
	int Get() {
		return score;
	}
	void Add(int _dscore) {
		score += _dscore;
	}
	void Behave() {
		if (hour >= END_HOUR) { return; }
		time++;
		time++;
		//分
		if (time % 60 == 0) {
			minute++;
			if (minute % 60 == 0) {
				hour++;
				minute = 0;
			}
		}
	}
	void Init() {
		hour = START_HOUR;
		minute = 0;
		time = 0;
		score = 0;
	}
	void Draw() {
		DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), Font[0],"%2d時%2d分 稼いだ金額 %6d円", hour, minute, score);
		if (practiceflag == true) {
			DrawFormatStringToHandle(0, 20, GetColor(255, 0, 0), Font[0], "練習モード(Qキーで終了)");
		}
	}
};



