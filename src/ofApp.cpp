#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	loadBoardAndRoyals();
	loadSidekicks();
	loadPawns();

	pieceCoords = assignPieceCoords();
	boardMap = buildBoardMap();

}

//--------------------------------------------------------------
void ofApp::update() {



}

//--------------------------------------------------------------
void ofApp::draw() {

	chessBoard.draw(500, 250);

	// Draw white pieces
	
	w_king.draw(pieceCoords[W_KING_INDEX].getX(), pieceCoords[W_KING_INDEX].getY());
	w_queen.draw(pieceCoords[W_QUEEN_INDEX].getX(), pieceCoords[W_QUEEN_INDEX].getY());
	w_bishop1.draw(pieceCoords[W_BISHOP1_INDEX].getX(), pieceCoords[W_BISHOP1_INDEX].getY());
	w_bishop2.draw(pieceCoords[W_BISHOP2_INDEX].getX(), pieceCoords[W_BISHOP2_INDEX].getY());
	w_knight1.draw(pieceCoords[W_KNIGHT1_INDEX].getX(), pieceCoords[W_KNIGHT1_INDEX].getY());
	w_knight2.draw(pieceCoords[W_KNIGHT2_INDEX].getX(), pieceCoords[W_KNIGHT2_INDEX].getY());
	w_rook1.draw(pieceCoords[W_ROOK1_INDEX].getX(), pieceCoords[W_ROOK1_INDEX].getY());
	w_rook2.draw(pieceCoords[W_ROOK2_INDEX].getX(), pieceCoords[W_ROOK2_INDEX].getY());
	
	w_pawn1.draw(pieceCoords[W_PAWN1_INDEX].getX(), pieceCoords[W_PAWN1_INDEX].getY());
	w_pawn2.draw(pieceCoords[W_PAWN2_INDEX].getX(), pieceCoords[W_PAWN2_INDEX].getY());
	w_pawn3.draw(pieceCoords[W_PAWN3_INDEX].getX(), pieceCoords[W_PAWN3_INDEX].getY());
	w_pawn4.draw(pieceCoords[W_PAWN4_INDEX].getX(), pieceCoords[W_PAWN4_INDEX].getY());
	w_pawn5.draw(pieceCoords[W_PAWN5_INDEX].getX(), pieceCoords[W_PAWN5_INDEX].getY());
	w_pawn6.draw(pieceCoords[W_PAWN6_INDEX].getX(), pieceCoords[W_PAWN6_INDEX].getY());
	w_pawn7.draw(pieceCoords[W_PAWN7_INDEX].getX(), pieceCoords[W_PAWN7_INDEX].getY());
	w_pawn8.draw(pieceCoords[W_PAWN8_INDEX].getX(), pieceCoords[W_PAWN8_INDEX].getY());
	
	// Draw black pieces
	
	b_king.draw(pieceCoords[B_KING_INDEX].getX(), pieceCoords[B_KING_INDEX].getY());
	b_queen.draw(pieceCoords[B_QUEEN_INDEX].getX(), pieceCoords[B_QUEEN_INDEX].getY());
	b_bishop1.draw(pieceCoords[B_BISHOP1_INDEX].getX(), pieceCoords[B_BISHOP1_INDEX].getY());
	b_bishop2.draw(pieceCoords[B_BISHOP2_INDEX].getX(), pieceCoords[B_BISHOP2_INDEX].getY());
	b_knight1.draw(pieceCoords[B_KNIGHT1_INDEX].getX(), pieceCoords[B_KNIGHT1_INDEX].getY());
	b_knight2.draw(pieceCoords[B_KNIGHT2_INDEX].getX(), pieceCoords[B_KNIGHT2_INDEX].getY());
	b_rook1.draw(pieceCoords[B_ROOK1_INDEX].getX(), pieceCoords[B_ROOK1_INDEX].getY());
	b_rook2.draw(pieceCoords[B_ROOK2_INDEX].getX(), pieceCoords[B_ROOK2_INDEX].getY());

	b_pawn1.draw(pieceCoords[B_PAWN1_INDEX].getX(), pieceCoords[B_PAWN1_INDEX].getY());
	b_pawn2.draw(pieceCoords[B_PAWN2_INDEX].getX(), pieceCoords[B_PAWN2_INDEX].getY());
	b_pawn3.draw(pieceCoords[B_PAWN3_INDEX].getX(), pieceCoords[B_PAWN3_INDEX].getY());
	b_pawn4.draw(pieceCoords[B_PAWN4_INDEX].getX(), pieceCoords[B_PAWN4_INDEX].getY());
	b_pawn5.draw(pieceCoords[B_PAWN5_INDEX].getX(), pieceCoords[B_PAWN5_INDEX].getY());
	b_pawn6.draw(pieceCoords[B_PAWN6_INDEX].getX(), pieceCoords[B_PAWN6_INDEX].getY());
	b_pawn7.draw(pieceCoords[B_PAWN7_INDEX].getX(), pieceCoords[B_PAWN7_INDEX].getY());
	b_pawn8.draw(pieceCoords[B_PAWN8_INDEX].getX(), pieceCoords[B_PAWN8_INDEX].getY());
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if ((x < HORIZ_MIN || x > HORIZ_MAX) || (y < VERT_MIN || y > VERT_MAX)) {
		return;
	}

	if (!clicked) {

		clickedIndex = findPiece(x, y, pieceCoords, boardMap);
		if (clickedIndex == -1) {
			return;
		}
		clicked = true;
		std::cout << clickedIndex << std::endl;
		return;

	}
	
	int pieceToKill = findPiece(x, y, pieceCoords, boardMap);
	if (pieceToKill != -1) {
		pieceCoords[pieceToKill] = Point(NICK_PIECE, NICK_PIECE);
	}
	pieceCoords[clickedIndex] = movePiece(boardMap, pieceCoords[clickedIndex], x, y);
	clicked = false;
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

// ======================== My Code =========================

/**
/ Loads in the chessboard and the king and queen of each side.
*/
void ofApp::loadBoardAndRoyals() {

	chessBoard.load("chessboard.jpg");
	chessBoard.resize(chessBoard.getWidth() * 1.3, chessBoard.getHeight() * 1.3);

	w_king_pic.load("w_king.png");
	w_king.setup("w_king.png", w_king_pic.getWidth() * 0.45, w_king_pic.getHeight() * 0.45);
	w_queen_pic.load("w_queen.png");
	w_queen.setup("w_queen.png", w_queen_pic.getWidth() * 0.45, w_queen_pic.getHeight() * 0.45);

	b_king_pic.load("b_king.png");
	b_king.setup("b_king.png", b_king_pic.getWidth() * 0.56, b_king_pic.getHeight() * 0.56);
	b_queen_pic.load("b_queen.png");
	b_queen.setup("b_queen.png", b_queen_pic.getWidth() * 0.45, b_queen_pic.getHeight() * 0.45);
	
}


/**
/ Loads in the bishops, knights, and rooks of each side.
*/
void ofApp::loadSidekicks() {

	// White Sidekicks
	
	w_bishop_pic.load("w_bishop.png");
	w_bishop1.setup("w_bishop.png", w_bishop_pic.getWidth() * 0.45, w_bishop_pic.getHeight() * 0.45);
	w_bishop2.setup("w_bishop.png", w_bishop_pic.getWidth() * 0.45, w_bishop_pic.getHeight() * 0.45);

	w_knight_pic.load("w_knight.png");
	w_knight1.setup("w_knight.png", w_knight_pic.getWidth() * 0.45, w_knight_pic.getHeight() * 0.45);
	w_knight2.setup("w_knight.png", w_knight_pic.getWidth() * 0.45, w_knight_pic.getHeight() * 0.45);

	w_rook_pic.load("w_rook.png");
	w_rook1.setup("w_rook.png", w_rook_pic.getWidth() * 0.45, w_rook_pic.getHeight() * 0.45);
	w_rook2.setup("w_rook.png", w_rook_pic.getWidth() * 0.45, w_rook_pic.getHeight() * 0.45);

	// Black Sidekicks

	b_bishop_pic.load("b_bishop.png");
	b_bishop1.setup("b_bishop.png", b_bishop_pic.getWidth() * 0.45, b_bishop_pic.getHeight() * 0.45);
	b_bishop2.setup("b_bishop.png", b_bishop_pic.getWidth() * 0.45, b_bishop_pic.getHeight() * 0.45);

	b_knight_pic.load("b_knight.png");
	b_knight1.setup("b_knight.png", b_knight_pic.getWidth() * 0.45, b_knight_pic.getHeight() * 0.45);
	b_knight2.setup("b_knight.png", b_knight_pic.getWidth() * 0.45, b_knight_pic.getHeight() * 0.45);

	b_rook_pic.load("b_rook.png");
	b_rook1.setup("b_rook.png", b_rook_pic.getWidth() * 0.45, b_rook_pic.getHeight() * 0.45);
	b_rook2.setup("b_rook.png", b_rook_pic.getWidth() * 0.45, b_rook_pic.getHeight() * 0.45);
	
}

/**
/ Loads in the bishops, knights, and rooks of each side.
*/
void ofApp::loadPawns() {

	// White pawns
	
	w_pawn_pic.load("w_pawn.png");
	w_pawn1.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn2.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn3.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn4.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn5.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn6.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn7.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);
	w_pawn8.setup("w_pawn.png", w_pawn_pic.getWidth() * 0.45, w_pawn_pic.getHeight() * 0.45);

	// Black pawns

	b_pawn_pic.load("b_pawn.png");
	b_pawn1.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn2.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn3.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn4.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn5.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn6.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn7.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	b_pawn8.setup("b_pawn.png", b_pawn_pic.getWidth() * 0.45, b_pawn_pic.getHeight() * 0.45);
	
}

