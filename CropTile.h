#ifndef _CROPTILE_
#define _CROPTILE_
#include "Tile.h"


class CropTile : public Tile {
	
	public:
		
		CropTile() : Tile() {/*whoAmI();*/}
		CropTile(Point2D p) : Tile(p) {/*whoAmI();*/}
		~CropTile() {/*cout << "Destruct Crop Tile\n";*/}
		
		char getSign() {return 'v';}
		tileType getType() {return crops;}
		void onEnter(Competitor* c) {c->eat();}
		void whoAmI() {cout << "Crop Tile\n\n";}
		void cropInformation();
};

#endif
