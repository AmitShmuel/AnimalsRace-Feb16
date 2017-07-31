#ifndef _POINT2D_
#define _POINT2D_
#include <iostream>
using namespace std;

class Point2D {
	
	int x;
	int y;
	
public:
	
	Point2D();
	Point2D(int,int);
	~Point2D();
	
	void setCordX(int _x) {x = _x;}
	void setCordY(int _y) {y = _y;}
	int getCordX() const {return x;}
	int getCordY() const {return y;}
};

#endif
