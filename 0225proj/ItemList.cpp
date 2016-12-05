#include"ItemList.h"
#include"CommonClass.h"
#include"GameMgr.h"

void C_ItemList::DataSet() {
	switch (m_GameMgr->gamelevel) {
	case GAME_1:
		/////////////// (i    t    p  l)
		//ëfçﬁ
		ItemData[0].Set(0, 0, 0, 0);
		ItemData[1].Set(0, 0, 0, 0);
		ItemData[2].Set(0, 0, 0, 0);
		ItemData[3].Set(0, 0, 0, 0);
		ItemData[4].Set(0, 0, 0, 0);
		ItemData[5].Set(0, 0, 0, 0);
		ItemData[6].Set(0, 0, 0, 0);
		ItemData[7].Set(0, 0, 0, 1);
		//ÇÀÇÈ
		ItemData[8].Set(0, 180, 350, 0);
		ItemData[9].Set(0, 180, 350, 0);
		ItemData[10].Set(0, 180, 350, 0);
		ItemData[11].Set(0, 180, 350, 0);
		//ÇÌÇΩ
		ItemData[12].Set(0, 180, 350, 0);
		ItemData[13].Set(0, 180, 350, 0);
		ItemData[14].Set(0, 180, 350, 0);
		ItemData[15].Set(0, 180, 350, 0);
		//Ç†Çﬂ
		ItemData[16].Set(0, 180, 350, 0);
		ItemData[17].Set(0, 180, 350, 0);
		ItemData[18].Set(0, 180, 350, 0);
		ItemData[19].Set(0, 180, 350, 0);
		/////////////// (i    t    p  l)
		for (int i = 20; i < ITEM_DATA_MAX; i++) {
			ItemData[i].Set();
		}

		break;
	case GAME_2:
		/////////////// (i    t    p  l)
		//ëfçﬁ
		ItemData[0].Set(0, 0, 0, 0);
		ItemData[1].Set(0, 0, 0, 0);
		ItemData[2].Set(0, 0, 0, 0);
		ItemData[3].Set(0, 0, 0, 0);
		ItemData[4].Set(0, 0, 0, 0);
		ItemData[5].Set(0, 0, 0, 0);
		ItemData[6].Set(0, 0, 0, 0);
		ItemData[7].Set(0, 0, 0, 1);
		//ÇÀÇÈ
		ItemData[8].Set(0, 180, 350, 0);
		ItemData[9].Set(0, 180, 350, 0);
		ItemData[10].Set(0, 180, 350, 0);
		ItemData[11].Set(0, 180, 350, 0);
		//ÇÌÇΩ
		ItemData[12].Set(0, 180, 650, 0);
		ItemData[13].Set(0, 180, 650, 0);
		ItemData[14].Set(0, 180, 650, 0);
		ItemData[15].Set(0, 180, 650, 0);
		//Ç†Çﬂ
		ItemData[16].Set(0, 180, 350, 0);
		ItemData[17].Set(0, 180, 350, 0);
		ItemData[18].Set(0, 180, 350, 0);
		ItemData[19].Set(0, 180, 350, 0);
		//â§åÚ
		ItemData[20].Set(0, 180, 2450, 0);
		ItemData[21].Set(0, 180, 2450, 0);
		ItemData[22].Set(0, 180, 2450, 0);
		ItemData[23].Set(0, 180, 2450, 0);
		//ÉPÅ[ÉL
		ItemData[24].Set(0, 180, 2450, 0);

		/////////////// (i    t    p  l)
		for (int i = 20; i < ITEM_DATA_MAX; i++) {
			ItemData[i].Set();
		}

		break;

	}
}
