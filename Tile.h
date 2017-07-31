// Tile header file
// Tile is implemented as a 2D point

#ifndef _TILE_
#define _TILE_
#include "Point2D.h"
#include "Competitor.h"


typedef enum{normal=-1,end,easy,medium,water,crops} tileType;

class Competitor; // forward declaration


class Tile {
	
protected:
	
	Point2D position;
	
public:
	
	Tile() {/*cout << "(Default) Construct Tile\n"*/;};
	Tile(Point2D p) : position(p) {/*cout << "Construct Tile\n";*/};
	virtual ~Tile() { };
	
	virtual void whoAmI() {};
	virtual char getSign() {};
	virtual void onEnter(Competitor*) {};
	virtual tileType getType() {return normal;}
	bool operator==(Tile* t2) {return getPosX() == t2->getPosX()  &&  getPosY() == t2->getPosY();}

	// setters & getters
	void setPosX(int x) {position.setCordX(x);}
	void setPosY(int y) {position.setCordY(y);}
	int getPosX() const {return position.getCordX();}
	int getPosY() const {return position.getCordY();}
	
	friend ostream& operator<<(ostream& o , const Tile& t) {o << "(" << t.getPosX() << "," << t.getPosY() << ")"; return o;}
};




#endif
