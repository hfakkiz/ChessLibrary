#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Location.h"

using namespace std;

void DisplayBoard(Board& chessBoard);

int main()
{
	Board chessBoard;

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[0][1].get_piece()), chessBoard.locations[2][0]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[1][7].get_piece()), chessBoard.locations[2][7]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[2][7].get_piece()), chessBoard.locations[3][7]);

	DisplayBoard(chessBoard);
	
	chessBoard.move_to(*(chessBoard.locations[3][7].get_piece()), chessBoard.locations[4][7]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[4][7].get_piece()), chessBoard.locations[5][7]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[5][7].get_piece()), chessBoard.locations[6][6]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[6][6].get_piece()), chessBoard.locations[7][7]);

	DisplayBoard(chessBoard);
}

void DisplayBoard(Board& chessBoard)
{
	for (int i = 0; i < MAX_SQUARE_VALUE; i++)
	{
		for (int j = 0; j < MAX_SQUARE_VALUE; j++)
		{
			if (chessBoard.locations[i][j].get_status() == LocationStatus::Not_Empty)
				cout << chessBoard.locations[i][j].get_piece()->get_name() << "\t";
			else
				cout << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}
