#ifndef _FROG_
#define _FROG_
#include "Competitor.h"


class Frog : public Competitor {
	
public:
	
	Frog() : Competitor("Frog") {};
	~Frog() {/*cout << "Destruct Frog\n";*/}
	
	Tile* cheapest(Tile* , Tile*);
	void eat() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void run() {setTotalMovesCost(getTotalMovesCost() + 2);}
	void walk() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void swim() {setTotalMovesCost(getTotalMovesCost() + 0.5);}
	void makeFrogNoise() {cout << "*Frog noise*\nCurrent total cost: " << getTotalMovesCost() << endl << endl;}
};


#endif
