#pragma once
#define OBJECT_MAX 1024 
class ObjectBase
{
public:
	//staticはクラス内でただ一つ作られる変数で表現(静的メンバ変数)
	ObjectBase();
	ObjectBase(int);
	~ObjectBase();
	
	
	int arraynum;//このオブジェクトが実装されている実体の配列番号(IDではない)
	int global_id;//オブジェクトの通し番号
	int actionID[8];//持ってる行動の通し番号

	int id;//オブジェクト種類別の通し番号(生成順)
	double x;
	double y;
	int z;//描画の順番
	int t;//生成されてからの時間
	double speed;
	double xspeed;
	double yspeed;
	double direction;//どう表現するか要調整
	int state;//状態(未定義)
	int sprite;//見た目
	//bool exi;

	virtual void Process();
	virtual void Draw();
	static void AllProcess();
	static void AllDraw();
	static void Make();
	static void Delete(int);
	//Anime animation;//アニメーションクラスのオブジェクトを所有したい
	//Hitter hitter;//当たり判定クラスのオブジェクトを所有したい
	

private:
	static int global_object_n;//
	static int global_total;

};
extern ObjectBase* Object[OBJECT_MAX];

