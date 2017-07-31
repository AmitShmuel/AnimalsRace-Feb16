#include "Competitor.h"
#include "EasyTile.h"
#include "MediumTile.h"
#include "WaterTile.h"
#include "CropTile.h"
#include "EndTile.h"
#include "Rabbit.h"
#include "Frog.h"
#include "Turtle.h"
#include <typeinfo>

Competitor::Competitor(string s) : 
totalMovesCost(0) , name(s) , currentTile(new Tile(Point2D(-1,-1))) , prevTile(NULL) , allMoves(30) {

	//cout << "Cunstruct Competitor: " << s << "\n";
}



void Competitor::printInformation(Tile* t) {
	
	try {
		
		switch(t->getSign())
		{
			case '=':
			{	
				EasyTile& et = dynamic_cast<EasyTile&>(*t);
				et.easyInformation();
				break;
			}
				
			case '#':
			{
				MediumTile& mt = dynamic_cast<MediumTile&>(*t);
				mt.mediumInformation();
				break;
			}
				
			case '~':
			{
				WaterTile& wt = dynamic_cast<WaterTile&>(*t);
				wt.waterInformation();	
				break;
			}
				
			case 'v':
			{
				CropTile& ct = dynamic_cast<CropTile&>(*t);
				ct.cropInformation();
				break;
			}
				
			case 'E':
			{
				EndTile& endt = dynamic_cast<EndTile&>(*t);
				endt.endInformation();
				break;
			}
				
			default:
			{
				cout << "\nTile Information::\n"
				 << "Location: " << *t << endl 
				 <<	"Start point.. no cost is taken..\n";
			}
		}
	}
	catch(bad_cast& bc) {
		
		cerr << endl << bc.what() <<" caught, stopping execution,..\n";
		exit(1);
	}
}



void Competitor::printNoises() {
	
	try {
	
		if(getName() == "Rabbit")
		{	
			Rabbit& pr = dynamic_cast<Rabbit&>(*this);
			pr.makeRabbitNoise();
		}
		
		else if(getName() == "Frog")
		{
			Frog& pf = dynamic_cast<Frog&>(*this);
			pf.makeFrogNoise();
		}
		
		else // Tuetle
		{
			Turtle& pt = dynamic_cast<Turtle&>(*this);
			pt.makeTurtleNoise();
		}
	}
	catch(bad_cast& bc) {
		
		cerr << endl << bc.what() <<" caught, stopping execution,..\n";
		exit(1);
	}
}



void Competitor::moveTo(Tile* t) {
	
 printInformation(t);
	prevTile = currentTile;
	currentTile = t; 
	allMoves.add(*t);
	t->onEnter(this); 
	printNoises();
}



Tile* Competitor::lookAhead(Tile***& track , int row , int col , Point2D target) {
	
	int i = currentTile->getPosX() , j = currentTile->getPosY();
	
	if(j < target.getCordY())
	{
		if(i==0)
		{
			if(prevTile->getPosX() == i+1 	&&	prevTile->getPosY() == j)
				moveTo(track[i][j+1]);
			else
				moveTo(cheapest(track[i][j+1] , track[i+1][j]));
		}
	
		else if(i==row-1)
		{
			if(prevTile->getPosX() == i-1 	&&	prevTile->getPosY() == j)
				moveTo(track[i][j+1]);
			else
				moveTo(cheapest(track[i][j+1] , track[i-1][j]));
		}
		
		else
		{
			if(prevTile->getPosX() == i+1 	&&	prevTile->getPosY() == j)
				moveTo(cheapest(track[i][j+1] , track[i-1][j]));
			else if(prevTile->getPosX() == i-1 	&&	prevTile->getPosY() == j)
				moveTo(cheapest(track[i][j+1] , track[i+1][j]));
			else
				moveTo(cheapest(cheapest(track[i][j+1] , track[i+1][j]) , track[i][j+1]));
		}
	}
	
	else if(j > target.getCordY())
	{
		if(i==0)
		{
			if(prevTile->getPosX() == i+1 	&&	prevTile->getPosY() == j)
				moveTo(track[i][j-1]);
			else
				moveTo(cheapest(track[i][j-1] , track[i+1][j]));
		}
		
		else if(i == row-1)
		{
			if(prevTile->getPosX() == i-1 	&&	prevTile->getPosY() == j)
				moveTo(track[i][j-1]);
			else
				moveTo(cheapest(track[i][j-1] , track[i-1][j]));
		}
		
		else
		{
			if(prevTile->getPosX() == i+1 	&&	prevTile->getPosY() == j)
				moveTo(cheapest(track[i][j-1] , track[i-1][j]));
			else if(prevTile->getPosX() == i-1 	&&	prevTile->getPosY() == j)
				moveTo(cheapest(track[i][j-1] , track[i+1][j]));
			else
				moveTo(cheapest(cheapest(track[i][j-1] , track[i+1][j]) , track[i-1][j]));
		}
	}

	else // j == targetj
	{
		if(target.getCordX() < i)
			moveTo(track[i-1][j]);
		else
			moveTo(track[i+1][j]);
	}
} 



void Competitor::printMoves(Tile*** track , int row , int col) {
	
	int i,j,k, count = allMoves.getCount();
	
	char** competitorMap = new char*[row];
	for(i=0;i<row;++i)
		competitorMap[i] = new char[col];
	
	for(i=0; i<row; ++i)
	{
		for(j=0;j<col;++j)
		{
			competitorMap[i][j] = ' ';
			if(track[i][j]->getType() == end)
				competitorMap[i][j] = 'E';
			
			for(k=0; k < count-1; ++k)
			{
				if(allMoves[k] == track[i][j])
				{
					competitorMap[i][j] = track[i][j]->getSign();
					break;
				}
			}
			if(track[i][j]->getType() == normal)
				competitorMap[i][j] = 'S';
		}
	}
	
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
			cout << competitorMap[i][j] << " ";
		cout << endl;
	}
	
	for(i=0; i<row; ++i)
	{
		delete[] competitorMap[i];
		competitorMap[i] = NULL;
	}
		
	delete[] competitorMap;
	competitorMap = NULL;
}
