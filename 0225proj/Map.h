#ifndef DEF_MAP_H
#define DEF_MAP_H




#define MASU_N 64//�I�u�W�F�N�g�̐��̏��
extern int Masu_N;//�I�u�W�F�N�g�����݃N���X���炢������Ă��邩

#define MASU_X 48
#define MASU_Y 48

class CCbase;

class CMasu :public CCbase{
public:
	CMasu(int);
	~CMasu();

	void Init();
	void Finish();
	void Process();
	void Draw();

	int connect[8];//�אڂ��Ă���}�X��ID���i�[
};

extern CMasu* Masu[64];
extern void Masu_Process();
extern void Masu_Draw();


#endif