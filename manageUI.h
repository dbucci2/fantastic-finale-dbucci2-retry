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
	friend std::vector<Point*> movePiece(std::vector<Point> input, int index);

	friend std::vector<std::vector<Point>> buildBoardMap();
	
	friend bool moveTo(int x, int y);

};

int findPiece(int x, int y, std::vector<Point> pieceCoords, std::vector<std::vector<Point>> boardMap);
