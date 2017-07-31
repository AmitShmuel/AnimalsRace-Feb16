// FileParser header file:
// This class can read a map from a text file using a two dimension array of characters.

#ifndef _FILEPARSER_
#define _FILEPARSER_
#include <iostream>
#include <cstring>


class FileParser {
	
	FILE* fp;
	char** map;
	int row,col;
	
public:
	
	char** parseFile(char* fileName);
	~FileParser(); // deallocating map.
};

#endif
