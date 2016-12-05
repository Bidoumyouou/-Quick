#ifndef DEF_RESOURCE_H
#define DEF_RESOURCE_H

//素材ハンドルをクラスで一元管理したほうがよくない？
//再利用資源作成の一環
class C_GraphResource{
public:
	int title[3];
	int back;
	int item[64];
	int UI[16];
	int pod[4];
	int podturn[16];
	int conbair[256];
	int timer[32];
	int text[8];
	int bar[10];
	int Button;
	int logo;
	int player[16];
	int recipe[4];
};


void ResouceLoad();
void MyPlaySound(int _Handle, int _Vol, int _Mode);
//素材読み込み関数
extern int Font[3];//おフォント
extern int sound[64];
extern int Music[2];

////画像
extern C_GraphResource G_IMAGE;

////////タイトル
extern int G_IMAGE_TITLE[3];
////////ゲーム
extern int G_IMAGE_ENEMY[4];
extern int G_IMAGE_ITEM[64];
////////リザルト
extern int G_IMAGE_UI[16];

//サウンド
extern int G_MUSIC_00;//0~はタイトル

#endif