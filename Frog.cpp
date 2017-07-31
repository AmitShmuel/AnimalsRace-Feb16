#include "Frog.h"

Tile* Frog::cheapest(Tile* t1 , Tile* t2) {
	
	//typedef enum{normal=-1,end,easy,medium,water,crops} tileType;
	
	float tmp1 , tmp2;
	if(t1->getType() == 0)
		tmp1 = 0;
	else if(t1->getType() == 3)
		tmp1 = 0.5;
	else if(t1->getType() == 1)
		tmp1 = 2;
	else 
		tmp1 = 1;
		
	if(t2->getType() == 0)
		tmp2 = 0;
	else if(t2->getType() == 3)
		tmp2 = 0.5;
	else if(t2->getType() == 1)
		tmp2 = 2;
	else 
		tmp2 = 1;
		
	if(tmp1 == tmp2)
		return t1->getPosY() > t2->getPosY() ? t1 : t2; // prefering to get closer to the target 
	else
		return tmp1 < tmp2 ? t1 : t2;
}
