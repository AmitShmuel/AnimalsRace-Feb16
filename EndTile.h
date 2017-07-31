#ifndef _ENDTILE_
#define _ENDTILE_
#include "Tile.h"


class EndTile : public Tile {
	
	public:
		
		EndTile() : Tile() {/*whoAmI();*/}
		EndTile(Point2D p) : Tile(p) {/*whoAmI();*/}
		~EndTile() {/*cout << "Destruct End Tile\n";*/}
		
		char getSign() {return 'E';}
		void onEnter(Competitor* c) {} 
		tileType getType() {return end;}
		void whoAmI() {cout << "End Tile\n\n";}
		void endInformation();
};

#endif
