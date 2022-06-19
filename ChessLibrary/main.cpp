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

	chessBoard.move_to(*(chessBoard.locations[1][4].get_piece()), chessBoard.locations[3][4]);
	chessBoard.move_to(*(chessBoard.locations[1][3].get_piece()), chessBoard.locations[3][3]);
	chessBoard.move_to(*(chessBoard.locations[1][5].get_piece()), chessBoard.locations[3][5]);
	chessBoard.move_to(*(chessBoard.locations[0][5].get_piece()), chessBoard.locations[5][0]);
	chessBoard.move_to(*(chessBoard.locations[0][3].get_piece()), chessBoard.locations[4][7]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[0][4].get_piece()), chessBoard.locations[1][4]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[1][4].get_piece()), chessBoard.locations[2][3]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[2][3].get_piece()), chessBoard.locations[2][4]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[2][4].get_piece()), chessBoard.locations[1][5]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[1][5].get_piece()), chessBoard.locations[0][5]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[0][5].get_piece()), chessBoard.locations[0][4]);

	DisplayBoard(chessBoard);

	chessBoard.move_to(*(chessBoard.locations[0][4].get_piece()), chessBoard.locations[2][6]);

	DisplayBoard(chessBoard);
}

void DisplayBoard(Board& chessBoard)
{
	for (int i = 0; i <= MAX_SQUARE_VALUE; i++)
	{
		for (int j = 0; j <= MAX_SQUARE_VALUE; j++)
		{
			if (chessBoard.locations[i][j].get_status() == LocationStatus::Not_Empty)
				cout << chessBoard.locations[i][j].get_piece()->get_name() << "\t";
			else
				cout << "\t";
		}
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------------" << endl;
}
