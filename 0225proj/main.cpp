#include "DxLib.h"
#include "key.h"
#include "main.h"
#include "state.h"
#include "Resource.h"
#include "phadeout.h"
#include "Cursol.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	SetMainWindowText("�������͂���̈�l�������Ƃ̂˂�Z��˂�ˍH����p������`QuickVersion");


	//SetMainWindowText("Proj0225");			//�E�B���h�E�^�C�g�����Z�b�g
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ɕύX
	DxLib_Init();								//DX���C�u����������
	SetDrawScreen(DX_SCREEN_BACK);			//�`���𗠉�ʂɐݒ�
	SetOutApplicationLogValidFlag(FALSE);		//���O�o�͂��Ȃ�
	SetAlwaysRunFlag(TRUE);			//�E�B���h�E���m���A�N�e�B�u�ł����s
	SetWindowSizeChangeEnableFlag(TRUE);		//�E�B���h�E�T�C�Y�����R�ɕύX�ł���
	//SetDXArchiveKeyString("bonz");

	ResouceLoad();
	G_MainGameState = DEF;
	G_Pre_GameState = DEF;
	G_Next_GameState = TITLE;
	//m_title = new Title();
	//m_GameMgr = new GameMgr();
	//m_result = new Result();

	//�J�[�\���͏�ɂ�����̂Ȃ̂ł�����


	Cursol = new C_Cursol();

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !clsDx() && !gpUpdateKey() && !gpUpdateMouse()){
		//������
		stateMgr();
		
		
		phadeMgr();
		
	}
	
	return 0;
}