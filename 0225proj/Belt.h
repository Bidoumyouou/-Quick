#pragma once
#include"SpotBehave.h"
#include"CommonClass.h"
#include"Message.h"
class Spot;
class BeltBehavior :public SpotBehavior {
	bool Behave();
	void Draw();
	void Init(Spot *s);

	void ButtonBehave();
	void BeltAutoMove();

	void StepBelt();

	Vector2 Button;
	Vector2 DustBox;
	Message Mes;
	Message MesP;
public:
	Up_int belt_t;
};

