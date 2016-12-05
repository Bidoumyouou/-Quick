#include"Dxlib.h"
#include"key.h"
#include"phadeout.h"

int Key[256];
int Mouse[3];
int MouseX, MouseY;

int gpUpdateKey(){
	char tmpKey[256]; //現在のキーの入力状態を格納する
	

	GetHitKeyStateAll(tmpKey); //全てのキー入力状態を得る
	if (phade->getmode() == DEF_PHADE){		//フェードアウトの途中でなければ
		for (int i = 0; i < 256; i++){
			if (tmpKey[i] != 0){//i番のキーコードに対応するキーが押されていたら
				Key[i]++;//加算
			}
			else {
				Key[i] = 0;
			}
		}
	}
	
	return 0;
}

int gpUpdateMouse() {
	char tmpMouse[3]; //現在のキーの入力状態を格納する
	GetMousePoint(&MouseX, &MouseY);
	//GetHitKeyStateAll(tmpKey); //全てのキー入力状態を得る
	if (phade->getmode() == DEF_PHADE) {		//フェードアウトの途中でなければ
	
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)Mouse[0]++;
		else Mouse[0] = 0;
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)Mouse[1]++;
		else Mouse[1] = 0;
		if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)Mouse[2]++;
		else Mouse[2] = 0;

	}

	return 0;
}