#include "FileParser.h"


char** FileParser::parseFile(char* fileName) {
	
	fp = fopen(fileName , "r");
	if(fp == 0)
	{
		std::cerr << "Cannot open the file " << fileName << "\n";
		return 0;
	}
	
	char buff[256];
	int i=0, j; 
	col = 0; row = 1; // 1 because one row is read while measuring coloumns (line 17)
	
	fgets(buff , 256 , fp);
	for(i=0; buff[i] != '\n'; ++i)
		col++;
	(col /= 2)++; // ignoring the ','
	
	while(fgets(buff , 256 , fp))
		row++;
	
	map = new char*[row+1];
	for(int i=0; i<row+1; ++i)
	{
		map[i] = new char[col+1];
		map[i][col] = '\0';
	}
	for(i=0; i<col; ++i)
		map[row][i] = '\0';
		
	fseek(fp,0,SEEK_SET);
	
	for(i=0;i<row;++i)
	{
		fgets(buff , 256 , fp);
		for(int count=0,j=0; j<col; ++j,count+=2)
			map[i][j] = buff[count];
	}
	
	fclose(fp);
	return map;
}



FileParser::~FileParser() {
	
	for(int i=0; i<row; ++i)
	{
		delete[] map[i];
		map[i] = NULL;
	}
		
	delete[] map;
	map = NULL;
}
