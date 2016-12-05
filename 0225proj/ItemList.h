#pragma once
#define ITEM_DATA_MAX 64

class C_ItemData {
public:
	int IMAGE;
	int time;//完成までの時間(使用しないこと(recipeのものを使う))
	int price;//値段
	int level;//どの難易度で参照されるか
	bool exi;
	void Set(int _image, int _time, int _price, int _level) {
		IMAGE = _image;
		time = _time;
		price = _price;
		level = _level;
		exi = true;
	}
	void Set() {
		exi = false;
	}
};

class C_ItemList {
public:
	C_ItemData ItemData[ITEM_DATA_MAX];
	void DataSet();
};