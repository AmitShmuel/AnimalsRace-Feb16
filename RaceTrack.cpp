#include "RaceTrack.h"


RaceTrack::~RaceTrack() {
	
	//cout << "\nDestruct Track.. \n\n";
	for(int i=0; i<rows; ++i)
		for(int j=0; j<columns; ++j)
		{
			delete track[i][j];
			track[i][j] = NULL;
		}
			
	for(int i=0; i<rows; ++i)
	{
		delete[] track[i];
		track[i] = NULL;
	}
		
	delete[] track;
	track = NULL;
	// for some reason delete[] doesnt set to null so i set it myself.. ofc memory is deallocated / not at use..
}



void RaceTrack::printCurrentState() {
	
	int i,j,p;
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			p=j;
				
			if(*track[i][j] == rabbit.getCurrentTile() 		&&	  *track[i][j] == frog.getCurrentTile()		&&	 *track[i][j] == turtle.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "3";
			}
					
			else if(*track[i][j] == rabbit.getCurrentTile() &&    *track[i][j] == frog.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "2";
			}
				
			else if(*track[i][j] == rabbit.getCurrentTile() &&    *track[i][j] == turtle.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "2";
			}
					
			else if(*track[i][j] == frog.getCurrentTile() 	&&    *track[i][j] == turtle.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "2";
			}
				
			else if(*track[i][j] == frog.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "F";
			}
					
			else if(*track[i][j] == turtle.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "T";
			}
					
			else if(*track[i][j] == rabbit.getCurrentTile())
			{
				while(p--)
					cout << "   ";
				cout << "R";
			}
		}
		
		cout << endl;
		
		for(j=0; j<columns; ++j)
		{
			if(track[i][j]->getType() == -1)
				cout << "S  ";
			else
				cout << track[i][j]->getSign() << "  ";
		}	
		cout << endl << endl;
	}
	cout << "\n----------------------------------------------------\n";
}




void RaceTrack::setTrack(char** map) {
	
	int i , j , row = 0 , column = strlen(&map[0][0]);
	
	for(i=0; map[i][0] != '\0'; ++i)
		++row;
	
	track = new Tile**[rows = row];
	for(i=0; i<row; ++i)
		track[i] = new Tile*[columns = column];
		
	for(i=0; i<row; ++i)
		for(j=0; j<column; ++j)
		{
			if(map[i][j] == '=')
				track[i][j] = new EasyTile(Point2D(i,j));
				
			else if(map[i][j] == '#')
				track[i][j] = new MediumTile(Point2D(i,j));
				
			else if(map[i][j] == '~')
				track[i][j] = new WaterTile(Point2D(i,j));
				
			else if(map[i][j] == 'v')
				track[i][j] = new CropTile(Point2D(i,j));
				
			else if(map[i][j] == 'E')
			{
				track[i][j] = new EndTile(Point2D(i,j));
				target.setCordX(track[i][j]->getPosX());
				target.setCordY(track[i][j]->getPosY());
			}
			
			else
				{
					track[i][j] = new Tile(Point2D(i,j));
					frog.moveTo(&(*(track[i][j])));	// placing the competitors on the starting point. (base Tile)
					rabbit.moveTo(&(*(track[i][j])));
					turtle.moveTo(&(*(track[i][j])));
				}
		}
}


void RaceTrack::startRace() {
	
	cout << "Starting race..\n\nREADY..	  SET..	  GO!!!\n";
	printCurrentState();
	bool fin1=0 , fin2=0 , fin3=0; // to avoid entering to getCurrTile() or getPos() when the competitor has reached the target (others are still moving)
	while(1)					   // but mostly to break from the loop
	{
		int input;
		scanf("%d", &input);
		fflush(stdin);
		cout << "\n----------------------------------------------------\n";
		if(fin1 == 0)
		{
			if(rabbit.getCurrentTile()->getPosX() != target.getCordX() 	  || 	 rabbit.getCurrentTile()->getPosY() != target.getCordY())
				rabbit.lookAhead(track , rows , columns , target);
			else
				fin1 = 1;
		}
			
		if(fin2 == 0)
		{
			if(frog.getCurrentTile()->getPosX() != target.getCordX() 	  || 	 frog.getCurrentTile()->getPosY() != target.getCordY())
				frog.lookAhead(track , rows , columns , target);
			else
				fin2 = 1;
		}
		
		if(fin3 == 0)
		{
			if(turtle.getCurrentTile()->getPosX() != target.getCordX() 	  || 	 turtle.getCurrentTile()->getPosY() != target.getCordY())
				turtle.lookAhead(track , rows , columns , target);
			else
				fin3 = 1;
		}
			
		if(fin1 == 1 && fin2 == 1 && fin3 == 1)
			break;
		printCurrentState();
	}
}



void RaceTrack::declareWinner() {
	
	cout << "\n\n=============== THE RACE IS FINISHED ===============\n";
	
	float costR = rabbit.getTotalMovesCost() , costF = frog.getTotalMovesCost() , costT = turtle.getTotalMovesCost();
	
	cout << "Calculating moves cost of each competitor..\nRabbit: " << costR << "\nTurtle: " << costT << "\nFrog: " << costF << endl << endl;
	
	if(costR == costF 	 	&&		costR == costT)
		cout << "Each one of the competitors could have been the prince of nevigators !\n\n";
	
	else if(costR < costT	&&	 costT < costF)
		cout << "The Rabbit could have been the prince of nevigators !\nTurtle finished 2nd, Frog 3rd..\n\n";
	
	else if(costR < costT 	&&	 costF < costT)
		cout << "The Rabbit could have been the prince of nevigators !\nFrog finished 2nd, Turtle 3rd..\n\n";
	
	else if(costT < costR 	&&	 costR < costF)
		cout << "The Turtle could have been the prince of nevigators !\nRabbit finished 2nd, Frog 3rd..\n\n";
		
	else if(costF < costR 	&&	 costR < costT)
		cout << "The Frog could have been the prince of nevigators !\nRabbit finished 2nd, Turtle 3rd..\n\n";
	
	else if(costT < costF 	&&	 costF < costR)
		cout << "The Turtle could have been the prince of nevigators !\nFrog finished 2nd, Rabbit 3rd..\n\n";
		
	else if(costF < costT 	&&	 costT < costR)
		cout << "The Frog could have been the prince of nevigators !\nTurtle finished 2nd, Rabbit 3rd..\n\n";
		
	else if(costR == costT)
	{
		if(costR < costF)
			cout << "Both the Rabbit and Turtle could have been the princes of nevigators !\nFrog finished 2nd..\n\n";
		else
			cout << "The Frog could have been the prince of nevigators !\nBoth the Rabbit and Turtle finished 2nd..\n\n";
	}
	
	else if(costR == costF)
	{
		if(costR < costT)
			cout << "Both the Rabbit and Frog could have been the princes of nevigators !\nTurtle finished 2nd..\n\n";
		else
			cout << "The Turtle could have been the prince of nevigators !\nBoth the Rabbit and Frog finished 2nd..\n\n";
	}
	
	else
	{
		if(costT < costR)
			cout << "Both the Turtle and Frog could have been the princes of nevigators !\nRabbit finished 2nd..\n\n";
		else
			cout << "The Rabbit could have been the prince of nevigators !\nBoth the Turtle and Frog finished 2nd..\n\n";
	}
	
	cout << endl << "Rabbit's path: \n\n"; rabbit.printMoves(track , rows , columns); 
	cout << endl << endl << "Turtle's path: \n\n"; turtle.printMoves(track , rows , columns);
	cout << endl << endl << "Frog's path: \n\n"; frog.printMoves(track , rows , columns);
	cout << endl;
}
