#include "Cbase.h"

CCbase::CCbase(){

}
CCbase::~CCbase(){

}

void CCbase::Process(){

}

void CCbase::Draw(){

}

void CCbase::Init(){

}

void CCbase::Finish(){

}

void CCbase::timerinit(){
	for (int i = 0; i < TIMER_NUM; i++){
		time[i] = 0;
	}
	for (int i = 0; i < PHADE_TIMER_NUM; i++){
		phade_time[i] = 0;
	}

}
//��Ԃɓ������ꂽ�^�C�}�[()�I�u�W�F�N�g�ɂ�����
int CCbase::timer(int i){

	time[0] += 1;
	if (time[0] >= i){
		time[0] = 0;
		return 1;
	}
	else{
		return 0;
	}
}
//����Q�ȏ�g�p����Ƃ��̂Q������
int CCbase::timer(int i, int n){
	time[n] += 1;
	if (time[n] >= i){
		time[n] = 0;
		return 1;
	}
	else{
		return 0;
	}
}
//�t�F�[�h�A�E�g�悤�ɕʘg�̃^�C�}�[
int CCbase::phade_timer(int i){
	phade_time[0] += 1;
	if (phade_time[0] >= i){
		phade_time[0] = 0;
		return 1;
	}
	else{
		return 0;
	}
}
//����Q�ȏ�g�p����Ƃ��̂Q������
int CCbase::phade_timer(int i, int n){
	phade_time[n] += 1;
	if (phade_time[n] >= i){
		phade_time[n] = 0;
		return 1;
	}
	else{
		return 0;
	}
}