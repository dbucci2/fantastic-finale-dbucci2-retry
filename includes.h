#pragma once

#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <chrono>

#include <string.h> // memcpy on linux

using namespace std;

static const int X_START = 597;
static const int Y_START = 348;

static const int X_MOVE_CONST = 149;
static const int Y_MOVE_CONST = 150;

static const int HORIZ_MIN = 600;
static const int HORIZ_MAX = 1807;

static const int VERT_MIN = 355;
static const int VERT_MAX = 1560;

static const int W_KING_INDEX = 0;
static const int W_QUEEN_INDEX = 1;
static const int W_BISHOP1_INDEX = 2;
static const int W_BISHOP2_INDEX = 3;
static const int W_KNIGHT1_INDEX = 4;
static const int W_KNIGHT2_INDEX = 5;
static const int W_ROOK1_INDEX = 6;
static const int W_ROOK2_INDEX = 7;
static const int W_PAWN1_INDEX = 8;
static const int W_PAWN2_INDEX = 9;
static const int W_PAWN3_INDEX = 10;
static const int W_PAWN4_INDEX = 11;
static const int W_PAWN5_INDEX = 12;
static const int W_PAWN6_INDEX = 13;
static const int W_PAWN7_INDEX = 14;
static const int W_PAWN8_INDEX = 15;

static const int B_KING_INDEX = 16;
static const int B_QUEEN_INDEX = 17;
static const int B_BISHOP1_INDEX = 18;
static const int B_BISHOP2_INDEX = 19;
static const int B_KNIGHT1_INDEX = 20;
static const int B_KNIGHT2_INDEX = 21;
static const int B_ROOK1_INDEX = 22;
static const int B_ROOK2_INDEX = 23;
static const int B_PAWN1_INDEX = 24;
static const int B_PAWN2_INDEX = 25;
static const int B_PAWN3_INDEX = 26;
static const int B_PAWN4_INDEX = 27;
static const int B_PAWN5_INDEX = 28;
static const int B_PAWN6_INDEX = 29;
static const int B_PAWN7_INDEX = 30;
static const int B_PAWN8_INDEX = 31;

static const int NUM_PIECE_INDEXES = 32;
static const int NUM_PAWNS = 8;
static const int BOARD_LENGTH = 8;