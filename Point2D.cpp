#include "Point2D.h"

Point2D::Point2D() : x(0) , y(0) {
	
	//cout << "(Default) Construct point: (0,0)\n";
}


Point2D::Point2D(int _x , int _y) : x(_x) , y(_y) {
	
	//cout << "Construct point: (" << x << "," << y << ")\n";
}


Point2D::~Point2D() {
	
	//cout << "Destruct point..\n\n";
}
