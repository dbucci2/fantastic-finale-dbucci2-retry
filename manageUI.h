#pragma once

//
// Created by dbucc on 12/6/2019.
//

#include <vector>
#include "includes.h"


class Point {
private:
	int x;
	int y;
public:
	
	Point(int newX, int newY);

	int getX();
	int getY();

	friend std::vector<Point> assignPieceCoords();
	friend Point movePiece(std::vector<std::vector<Point>> boardMap, Point toUse, int x, int y);

	friend std::vector<std::vector<Point>> buildBoardMap();
	friend Point captured(Point currentCoords);
	friend bool moveTo(int x, int y);

};

int findPiece(int x, int y, std::vector<Point> pieceCoords, std::vector<std::vector<Point>> boardMap);

