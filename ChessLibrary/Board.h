#ifndef chess_board
#define chess_board

#include <vector>
#include "Location.h"
#include "Piece.h"
#include "Team.h"

class Board
{
private:
	const int totalPieceNumber = 32;
	vector<vector<Location>> locations;
	Team team_white = Team(TeamType::White_Team);
	Team team_black = Team(TeamType::Black_Team);

public:
	
private:
	void init_locations();

public:
	Board();
	~Board();

	Status move_to(Piece& target_piece, Location destination);



};

#endif // !chess_board

