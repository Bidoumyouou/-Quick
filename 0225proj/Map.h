#ifndef DEF_MAP_H
#define DEF_MAP_H




#define MASU_N 64//オブジェクトの数の上限
extern int Masu_N;//オブジェクトを現在クラスからいくつ作っているか

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

	int connect[8];//隣接しているマスのIDを格納
};

extern CMasu* Masu[64];
extern void Masu_Process();
extern void Masu_Draw();


#endif