#pragma once
#define OBJECT_MAX 1024 
class ObjectBase
{
public:
	//static�̓N���X���ł���������ϐ��ŕ\��(�ÓI�����o�ϐ�)
	ObjectBase();
	ObjectBase(int);
	~ObjectBase();
	
	
	int arraynum;//���̃I�u�W�F�N�g����������Ă�����̂̔z��ԍ�(ID�ł͂Ȃ�)
	int global_id;//�I�u�W�F�N�g�̒ʂ��ԍ�
	int actionID[8];//�����Ă�s���̒ʂ��ԍ�

	int id;//�I�u�W�F�N�g��ޕʂ̒ʂ��ԍ�(������)
	double x;
	double y;
	int z;//�`��̏���
	int t;//��������Ă���̎���
	double speed;
	double xspeed;
	double yspeed;
	double direction;//�ǂ��\�����邩�v����
	int state;//���(����`)
	int sprite;//������
	//bool exi;

	virtual void Process();
	virtual void Draw();
	static void AllProcess();
	static void AllDraw();
	static void Make();
	static void Delete(int);
	//Anime animation;//�A�j���[�V�����N���X�̃I�u�W�F�N�g�����L������
	//Hitter hitter;//�����蔻��N���X�̃I�u�W�F�N�g�����L������
	

private:
	static int global_object_n;//
	static int global_total;

};
extern ObjectBase* Object[OBJECT_MAX];

