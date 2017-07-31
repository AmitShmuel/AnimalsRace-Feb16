#ifndef _EASYTILE_H_
#define _EASYTILE_H_
#include "Tile.h"


class EasyTile : public Tile {
	
	public:
		
		EasyTile() : Tile() {/*whoAmI();*/}
		EasyTile(Point2D p) : Tile(p) {/*whoAmI();*/}
		~EasyTile() {/*cout << "Destruct Easy Tile\n"*/;}
		
		char getSign() {return '=';}
		tileType getType() {return easy;}
		void onEnter(Competitor* c) {c->run();}
		void whoAmI() {cout << "Easy Tile\n\n";}
		void easyInformation();
};

#endif

