#pragma once
#define ITEM_DATA_MAX 64

class C_ItemData {
public:
	int IMAGE;
	int time;//�����܂ł̎���(�g�p���Ȃ�����(recipe�̂��̂��g��))
	int price;//�l�i
	int level;//�ǂ̓�Փx�ŎQ�Ƃ���邩
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