// Assignment 4: Animal Race
// Made by: Amit Shmuel - 305213621

#include "FileParser.h"
#include "RaceTrack.h"
#include "EasyTile.h"
#include "MediumTile.h"
#include "WaterTile.h"
#include "CropTile.h"


int main(int argc, char** argv) {

	
	FileParser f;
	
	RaceTrack race(f.parseFile("map.txt"));
	
	race.startRace();
		
	race.declareWinner();
	
	return 0;
}
