#pragma once

#include "ofMain.h"
#include "manageUI.h"
#include "ofxImgButton.h"
#include "includes.h"

class ofApp : public ofBaseApp {

public:

	bool clicked  = false;
	int clickedIndex = -1;
	bool isWhiteTurn = true;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void loadBoardAndRoyals();
	void loadPawns();
	void loadSidekicks();
	bool isCorrectColor(int index);

	std::vector<Point> pieceCoords;
	std::vector<std::vector<Point>> boardMap;
	ofImage chessBoard;

	ofImage w_king_pic;
	ofImage w_queen_pic;
	ofImage w_bishop_pic;
	ofImage w_knight_pic;
	ofImage w_rook_pic;
	ofImage w_pawn_pic;

	ofxImgButton w_king;
	ofxImgButton w_queen;
	ofxImgButton w_bishop1;
	ofxImgButton w_bishop2;
	ofxImgButton w_knight1;
	ofxImgButton w_knight2;
	ofxImgButton w_rook1;
	ofxImgButton w_rook2;
	ofxImgButton w_pawn1;
	ofxImgButton w_pawn2;
	ofxImgButton w_pawn3;
	ofxImgButton w_pawn4;
	ofxImgButton w_pawn5;
	ofxImgButton w_pawn6;
	ofxImgButton w_pawn7;
	ofxImgButton w_pawn8;

	ofImage b_king_pic;
	ofImage b_queen_pic;
	ofImage b_bishop_pic;
	ofImage b_knight_pic;
	ofImage b_rook_pic;
	ofImage b_pawn_pic;

	ofxImgButton b_king;
	ofxImgButton b_queen;
	ofxImgButton b_bishop1;
	ofxImgButton b_bishop2;
	ofxImgButton b_knight1;
	ofxImgButton b_knight2;
	ofxImgButton b_rook1;
	ofxImgButton b_rook2;
	ofxImgButton b_pawn1;
	ofxImgButton b_pawn2;
	ofxImgButton b_pawn3;
	ofxImgButton b_pawn4;
	ofxImgButton b_pawn5;
	ofxImgButton b_pawn6;
	ofxImgButton b_pawn7;
	ofxImgButton b_pawn8;

};
