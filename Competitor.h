#ifndef _COMPETITOR_
#define _COMPETITOR_
#include "Tile.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;

class Tile; // forward declaration

class Competitor {
	
protected:
	
	string name;
	Tile* currentTile;
	Tile* prevTile;
	Vector<Tile> allMoves; // self implemented vector
	float totalMovesCost;
	
public:
	
	Competitor() : totalMovesCost(0) , name("Default") , currentTile(NULL) , prevTile(NULL) {/*cout << "(Default) Cunstruct Competitor\n";*/}
	Competitor(string s);
	~Competitor() {/*cout << "Destruct Competitor: " << name << "\n";*/}
	
	virtual void run() {};
	virtual void eat() {};
	virtual void walk() {};
	virtual void swim() {};
	
	void printNoises(); //  prints competitors noises
	
	void printInformation(Tile*); // prints tiles information
	
	virtual void moveTo(Tile* t); // moves to tiles in the track.
	
	virtual Tile* cheapest(Tile* , Tile*) { }; // returns the cheapest tile. overriden on each derived.
	
	void printMoves(Tile*** track , int row , int col); // prints the moves the competitor took along the race. 
	
	Tile* lookAhead(Tile***& , int row , int col , Point2D target); // competitor checks which way is better for him
	
	friend ostream& operator<<(ostream& os , const Competitor& c) {os << c.getName() << endl << c.getTotalMovesCost() << endl; return os;}
	
	//getters
	string getName() const {return name;}
	Tile* getCurrentTile() const {return currentTile;}
	float getTotalMovesCost() const {return totalMovesCost;}
	
	//setters
	void setName(string n) {name = n;}
	void setTotalMovesCost(float c) {totalMovesCost = c;}
};

#endif
