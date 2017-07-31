#ifndef _RABBIT_
#define _RABBIT_
#include "Competitor.h"


class Rabbit : public Competitor {
	
public:
	
	Rabbit() : Competitor("Rabbit") {};
	~Rabbit() {/*cout << "Destruct Rabbit\n";*/}
	
	Tile* cheapest(Tile* , Tile*);
	void eat() {setTotalMovesCost(getTotalMovesCost() + 2);}
	void walk() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void swim() {setTotalMovesCost(getTotalMovesCost() + 1);}
	void run() {setTotalMovesCost(getTotalMovesCost() + 0.5);}
	void makeRabbitNoise() {cout << "*Rabbit noise*\nCurrent total cost: " << getTotalMovesCost() << endl << endl;}
};


#endif
