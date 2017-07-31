#ifndef _MEDIUMTILE_
#define _MEDIUMTILE_
#include "Tile.h"


class MediumTile : public Tile {
	
	public:
		
		MediumTile() : Tile() {/*whoAmI();*/}
		MediumTile(Point2D p) : Tile(p) {/*whoAmI();*/}
		~MediumTile() {/*cout << "Destruct Medium Tile\n";*/}
		
		char getSign() {return '#';}
		tileType getType() {return medium;}
		void onEnter(Competitor* c) {c->walk();}
		void whoAmI() {cout << "Medium Tile\n\n";}
		void mediumInformation();
};



#endif
