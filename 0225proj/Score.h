#pragma once
#define START_HOUR 10
#define END_HOUR 18

class C_SCORE {
public:
	int score;
	int date;//���x�����������
	bool rank;//���̏���
	int time;//1800�ŏI��
	int hour;//�K��time�ƘA��
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
		//��
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
		DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), Font[0],"%2d��%2d�� �҂������z %6d�~", hour, minute, score);
		if (practiceflag == true) {
			DrawFormatStringToHandle(0, 20, GetColor(255, 0, 0), Font[0], "���K���[�h(Q�L�[�ŏI��)");
		}
	}
};



