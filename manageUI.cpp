//
// Created by dbucc on 12/6/2019.
//

#include "manageUI.h"

Point::Point(int newX, int newY) {
	x = newX;
	y = newY;
}
 
int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

/*
bool Point::moveRight(int spaces) {
	if (x + X_MOVE_CONST * spaces > HORIZ_MAX) {
		return false;
	}
	x = x + X_MOVE_CONST * spaces;
}

bool Point::moveLeft(int spaces) {
	if (x - X_MOVE_CONST * spaces < VERT_MIN) {
		return false;
	}
	x = x - X_MOVE_CONST * spaces;
}

bool Point::moveUp(int spaces) {
	if (y - Y_MOVE_CONST * spaces < VERT_MIN) {
		return false;
	}
	y = y - Y_MOVE_CONST * spaces;
}

bool Point::moveDown(int spaces) {
	if (y + Y_MOVE_CONST * spaces > VERT_MAX) {
		return false;
	}
	y = y + Y_MOVE_CONST * spaces;
	return true;
}
*/

bool moveTo(int x, int y) {
	return true;
}
 
std::vector<Point> assignPieceCoords() {
	
	std::vector<Point> pieceCoords;

	// White piece points

	Point a = Point(1201, 1405);
	pieceCoords.push_back(a);
	Point b = Point(1047, 1410);
	pieceCoords.push_back(b);

	Point c = Point(904, 1405);
	pieceCoords.push_back(c);
	Point d = Point(1351, 1405);
	pieceCoords.push_back(d);

	Point e = Point(754, 1405);
	pieceCoords.push_back(e);
	Point f = Point(1499, 1405);
	pieceCoords.push_back(f);

	Point g = Point(610, 1405);
	pieceCoords.push_back(g);
	Point h = Point(1653, 1405);
	pieceCoords.push_back(h);

	Point i = Point(615, 1255);
	pieceCoords.push_back(i);
	Point j = Point(764, 1255);
	pieceCoords.push_back(j);
	Point k = Point(913, 1255);
	pieceCoords.push_back(k);
	Point l = Point(1062, 1255);
	pieceCoords.push_back(l);
	Point m = Point(1211, 1255);
	pieceCoords.push_back(m);
	Point n = Point(1360, 1255);
	pieceCoords.push_back(n);
	Point o = Point(1509, 1255);
	pieceCoords.push_back(o);
	Point p = Point(1658, 1255);
	pieceCoords.push_back(p);

	// Black piece points

	Point q = Point(1201, 348);
	pieceCoords.push_back(q);
	Point r = Point(1047, 360);
	pieceCoords.push_back(r);

	Point s = Point(904, 355);
	pieceCoords.push_back(s);
	Point t = Point(1351, 355);
	pieceCoords.push_back(t);

	Point u = Point(754, 355);
	pieceCoords.push_back(u);
	Point v = Point(1499, 355);
	pieceCoords.push_back(v);

	Point w = Point(610, 355);
	pieceCoords.push_back(w);
	Point x = Point(1653, 355);
	pieceCoords.push_back(x);

	Point y = Point(615, 505);
	pieceCoords.push_back(y);
	Point z = Point(764, 505);
	pieceCoords.push_back(z);
	Point aa = Point(913, 505);
	pieceCoords.push_back(aa);
	Point bb = Point(1062, 505);
	pieceCoords.push_back(bb);
	Point cc = Point(1211, 505);
	pieceCoords.push_back(cc);
	Point dd = Point(1360, 505);
	pieceCoords.push_back(dd);
	Point ee = Point(1509, 505);
	pieceCoords.push_back(ee);
	Point ff = Point(1658, 505);
	pieceCoords.push_back(ff);

	return pieceCoords;

}

Point movePiece(std::vector<std::vector<Point>> boardMap, Point toUse, int x, int y) {

	int savedX = 0;
	int savedY = 0;

	for (std::vector<Point> vector : boardMap) {
		if (savedX != 0 && savedY != 0) {
			break;
		}
		for (Point point : vector) {
			if (point.getY() > y && savedY == 0) {
				savedY = point.getY() - Y_MOVE_CONST;
			}
			if (point.getX() > x && savedX == 0) {
				savedX = point.getX() - X_MOVE_CONST;
			}
		}
	}

	bool xIsGreater = false;
	bool yIsGreater = false;

	if (toUse.getX() > savedX) {
		xIsGreater = true;
	}
	if (toUse.getY() > savedY) {
		yIsGreater = true;
	}

	// Adjust X first

	if (xIsGreater) {
		while (toUse.getX() > savedX) {
			if (toUse.getX() > savedX) {
				toUse.x -= X_MOVE_CONST;
			}
		}
		toUse.x += X_MOVE_CONST;
	} else {
		while (toUse.getX() < savedX) {
			if (toUse.getX() < savedX) {
				toUse.x += X_MOVE_CONST;
			}
		}
	}

	if (yIsGreater) {
		while (toUse.getY() > savedY) {
			if (toUse.getY() > savedY) {
				toUse.y -= Y_MOVE_CONST;
			}
		}
		toUse.y += Y_MOVE_CONST;
	} else {
		while (toUse.getY() < savedY) {
			if (toUse.getY() < savedY) {
				toUse.y += Y_MOVE_CONST;
			}
		}
	}
	
	return toUse;
	
}


std::vector<std::vector<Point>> buildBoardMap() {
	std::vector<std::vector<Point>> vector;
	for (int i = 0; i < BOARD_LENGTH + 1; i++) {
		std::vector<Point> points;
		for (int j = 0; j < BOARD_LENGTH + 1; j++) {
			points.push_back(Point(X_START + (X_MOVE_CONST * j), Y_START + (Y_MOVE_CONST * i)));
		}
		vector.push_back(points);
	}
	return vector;
}

int findPiece(int x, int y, std::vector<Point> pieceCoords, std::vector<std::vector<Point>> boardMap) {

	int savedX = 0;
	int savedY = 0;

	for (std::vector<Point> vector : boardMap) {
		if (savedX != 0 && savedY != 0) {
			break;
		}
		for (Point point : vector) {
			if (point.getY() > y && savedY == 0) {
				savedY = point.getY() - Y_MOVE_CONST;
			}
			if (point.getX() > x && savedX == 0) {
				savedX = point.getX() - X_MOVE_CONST;
			}
		}
	}

	int savedIndex = -1;
	int savedDistance = HALF_SQUARE_DIST;
	int count = 0;
	for (Point point : pieceCoords) {
		int dist = sqrt(((savedY - point.getY()) * (savedY - point.getY())) + ((savedX - point.getX()) * (savedX - point.getX())));
		if (dist < savedDistance) {
			savedDistance = dist;
			savedIndex = count;
		}
		count++;
	}
	

	return savedIndex;
}

/**
* Random number generator from https://bytefreaks.net/programming-2/cc-get-a-random-number-that-is-in-a-specific-range 
*/
Point captured(Point currentCoords) {
	
	// Find a new X

	int maxNickNumber = 2500;
	int minNickNumber = 1500;
	int newX = (rand() % (maxNickNumber + 1 - minNickNumber)) + minNickNumber;

	// Find a new Y 

	maxNickNumber = -150;
	minNickNumber = 150;
	int newY = (rand() % (maxNickNumber + 1 - minNickNumber)) + minNickNumber;

	return Point(currentCoords.x + newX, currentCoords.y + newY);

}