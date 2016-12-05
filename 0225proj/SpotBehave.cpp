#include"SpotBehave.h"
#include"Spot.h"
void SpotBehavior::Init(Spot * s) {
	s->Area.X = 3;
	s->Area.Y = 2;
	sp = s;
	HitBox[0].Set(0, 0);
	HitBox[1].Set(32* 9 - 1, 32 * 7 - 1);
}