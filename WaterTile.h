#ifndef _WATERTILE_
#define _WATERTILE_
#include "Tile.h"


class WaterTile : public Tile {
	
	public:
		
		WaterTile() : Tile() {/*whoAmI();*/}
		WaterTile(Point2D p) : Tile(p) {/*whoAmI();*/}
		~WaterTile() {/*cout << "Destruct Water Tile\n";*/}
		
		char getSign() {return '~';}
		tileType getType() {return water;}
		void onEnter(Competitor* c) {c->swim();}
		void whoAmI() {cout << "Water Tile\n\n";}
		void waterInformation();
};



#endif
