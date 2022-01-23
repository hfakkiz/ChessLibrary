#ifndef chess_board
#define chess_board

#include <vector>
#include "Location.h"
#include "Piece.h"

class Board
{
private:
	const int totalPieceNumber = 32;
	vector<vector<Location>> locations;

public:
	
private:
	void init_locations();

public:
	Board();
	~Board();

	



};

#endif // !chess_board

