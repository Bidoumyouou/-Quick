#include "DxLib.h"
#include "Resource.h"

////画像

////////タイトル
int G_IMAGE_TITLE[3];
////////ゲーム
int G_IMAGE_ENEMY[4];
////////リザルト
int G_IMAGE_ITEM[64];

//UIいろいろ
int G_IMAGE_UI[16];
int G_IAMGE_BACK;

//サウンド用メモリ
int sound[64];
//画像クラス
//int G_IMAGE_[];
//サウンド
int G_MUSIC_00;//0~はタイトル
C_GraphResource G_IMAGE;
int Font[3];
int Music[2];
void ResouceLoad(){
	
	//効果音の読み込み(ごめんな)
	sound[0] = LoadSoundMem("sound/yes.mp3");
	sound[1] = LoadSoundMem("sound/no.mp3");
	sound[2] = LoadSoundMem("sound/cursor.mp3");
	sound[3] = LoadSoundMem("sound/buble02.mp3");
	sound[4] = LoadSoundMem("sound/pi14.mp3");//アイテム取り
	sound[5] = LoadSoundMem("sound/bell00.mp3");//開店
	sound[6] = LoadSoundMem("sound/open51.mp3");
	sound[7] = LoadSoundMem("sound/bell10.mp3");//調合終了
	sound[8] = LoadSoundMem("sound/coin06.mp3");//売上増加
	sound[9] = LoadSoundMem("sound/close11.mp3");//閉店
	sound[10] = LoadSoundMem("sound/wood03.mp3");//メニューフリップ
	sound[11] = LoadSoundMem("sound/open13.mp3");//調合開始
	sound[12] = LoadSoundMem("sound/put.mp3");//アイテム配置
	sound[13] = LoadSoundMem("sound/finish.mp3");//閉店
	sound[14] = LoadSoundMem("sound/menu_3.mp3");//メッセージ
	sound[15] = LoadSoundMem("sound/open07.mp3");//客登場
	sound[16] = LoadSoundMem("sound/beep14.mp3");//客退場
	sound[17] = LoadSoundMem("sound/night.mp3");//夜明かし
	sound[18] = LoadSoundMem("sound/fail.mp3");//クエスト成功
	sound[19] = LoadSoundMem("sound/clear.mp3");//クエスト失敗
	sound[20] = LoadSoundMem("sound/power09.mp3");//レベルアップ
												  //ぶくぶくを４つに分ける
	sound[21] = LoadSoundMem("sound/buble02.mp3");
	sound[22] = LoadSoundMem("sound/buble02.mp3");
	sound[23] = LoadSoundMem("sound/buble02.mp3");
	sound[24] = LoadSoundMem("sound/buble02.mp3");
	//新素材
	sound[25] = LoadSoundMem("sound/stewing-1.mp3");
	sound[26] = LoadSoundMem("sound/mecha33.mp3");

	Music[0] = LoadMusicMem("sound/shinyday.mp3");
	AddFontResourceEx("font/setofont.ttf", FR_PRIVATE, NULL);
	Font[0] = CreateFontToHandle("瀬戸フォント", 16, -1, DX_FONTTYPE_ANTIALIASING);
	Font[1] = CreateFontToHandle("瀬戸フォント", 40, -1, DX_FONTTYPE_ANTIALIASING);
	Font[2] = CreateFontToHandle("瀬戸フォント", 64, -1, DX_FONTTYPE_ANTIALIASING);
	if (Font[0] == -1) {
		printfDx("ERROR");
	}
	
	G_IMAGE.back = LoadGraph("picture/backmap2.bmp");
	G_IMAGE.Button = LoadGraph("picture/Button.png");
	G_IMAGE.logo = LoadGraph("picture/logo.png");
	LoadDivGraph("picture/UI.png", 16, 8, 2, 40, 40, G_IMAGE.UI);
	LoadDivGraph("picture/text.png", 8, 1, 8, 128, 20, G_IMAGE.text);
	LoadDivGraph("picture/conbair.png", 256, 16, 16, 32, 32, G_IMAGE.conbair);
	LoadDivGraph("picture/timer.png", 32, 8, 4, 16, 16, G_IMAGE.timer);
	LoadDivGraph("picture/podforturn.png", 2, 2, 1, 80, 80, G_IMAGE.podturn);
	LoadDivGraph("picture/bar.png", 10, 1, 10, 12, 40, G_IMAGE.bar);
	LoadDivGraph("picture/newpot.png", 4, 4, 1, 64, 64, G_IMAGE.pod);
	LoadDivGraph("picture/player.png", 16, 4, 4, 32, 32, G_IMAGE.player);
	LoadDivGraph("picture/recipe.png", 4, 1, 4, 288, 32, G_IMAGE.recipe);


	G_IMAGE_TITLE[0] = LoadGraph("picture/fortitle.bmp");
	G_IMAGE_TITLE[1] = LoadGraph("picture/fortitle.bmp"); 


	LoadDivGraph("picture/item.png", 64, 8, 8, 32, 32, G_IMAGE_ITEM);
	int a = LoadDivGraph("picture/MainGames/spill.png",4,2,2,32,32,G_IMAGE_ENEMY);
	
	LoadDivGraph("picture/UI.png", 16, 8, 2, 40, 40, G_IMAGE_UI);
	//LoadDivGraph("", , , , , , G_IMAGE_);
	//G_MUSIC_00 = LoadSoundMem("sound/music/ピュアヒューリーズ.mp3");//ステージ選択
}

//少し間借りしてサウンド管理室
void MyPlaySound(int _Handle, int _Vol, int _Mode = 1) {
	ChangeVolumeSoundMem(100, _Handle);
	ChangeVolumeSoundMem(100, sound[4]);
	ChangeVolumeSoundMem(100, sound[26]);
	ChangeVolumeSoundMem(85, sound[1]);
	PlaySoundMem(_Handle, _Mode);//BACK = 1 LOOP = 3で可
}