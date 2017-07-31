// RaceTrack header file
// the race is implemented as a 2D array of Tile pointers

#ifndef _RACETRACK_
#define _RACETRACK_
#include "EasyTile.h"
#include "MediumTile.h"
#include "WaterTile.h"
#include "CropTile.h"
#include "EndTile.h"
#include "Turtle.h"
#include "Rabbit.h"
#include "Frog.h"
#include <cstring>



class RaceTrack {
	
	Tile*** track;
	int rows , columns;
	Point2D target;
	
	Frog frog; //Competitors
	Turtle turtle;
	Rabbit rabbit;
	
	void setTrack(char** map); // private method called from the constructor, which sets the track according to a given map from a txt file.

public:
	
	RaceTrack() : track(0) , frog() , turtle() , rabbit() {/*cout << "(Default) Construct Track..\n\n";*/}
	RaceTrack(char** map) : track(0) , frog() , turtle() , rabbit() {/*cout << "Construct Track..\n\n";*/ setTrack(map);}
	~RaceTrack();
	
	void printCurrentState(); // prints the current state of the race at each turn including the competitors on it.
	void startRace();
	void declareWinner();
};



#endif
