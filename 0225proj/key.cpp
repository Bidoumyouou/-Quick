#include"Dxlib.h"
#include"key.h"
#include"phadeout.h"

int Key[256];
int Mouse[3];
int MouseX, MouseY;

int gpUpdateKey(){
	char tmpKey[256]; //���݂̃L�[�̓��͏�Ԃ��i�[����
	

	GetHitKeyStateAll(tmpKey); //�S�ẴL�[���͏�Ԃ𓾂�
	if (phade->getmode() == DEF_PHADE){		//�t�F�[�h�A�E�g�̓r���łȂ����
		for (int i = 0; i < 256; i++){
			if (tmpKey[i] != 0){//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
				Key[i]++;//���Z
			}
			else {
				Key[i] = 0;
			}
		}
	}
	
	return 0;
}

int gpUpdateMouse() {
	char tmpMouse[3]; //���݂̃L�[�̓��͏�Ԃ��i�[����
	GetMousePoint(&MouseX, &MouseY);
	//GetHitKeyStateAll(tmpKey); //�S�ẴL�[���͏�Ԃ𓾂�
	if (phade->getmode() == DEF_PHADE) {		//�t�F�[�h�A�E�g�̓r���łȂ����
	
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)Mouse[0]++;
		else Mouse[0] = 0;
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)Mouse[1]++;
		else Mouse[1] = 0;
		if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)Mouse[2]++;
		else Mouse[2] = 0;

	}

	return 0;
}