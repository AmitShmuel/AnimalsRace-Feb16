#ifndef _TUTRTLE_
#define _TUTRTLE_
#include "Competitor.h"


class Turtle : public Competitor {
	
public:
	
	Turtle() : Competitor("Turtle") {};
	~Turtle() {/*cout << "Destruct Turtle\n";*/}
	
	
	Tile* cheapest(Tile* , Tile*);
	void eat() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void walk() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void swim() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void run() {setTotalMovesCost(getTotalMovesCost() + 0.75);}
	void makeTurtleNoise() {cout << "*Turtle noise*\nCurrent total cost: " << getTotalMovesCost() << endl << endl;}
};


#endif
