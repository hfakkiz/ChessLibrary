#ifndef chess_board
#define chess_board

#include <vector>
#include "Location.h"
#include "Piece.h"
#include "Team.h"

using namespace std;

class Board
{
private:
	const int totalPieceNumber = 32;
	//vector<vector<Location>> locations;
	Team team_white = Team(TeamType::White_Team);
	Team team_black = Team(TeamType::Black_Team);

public:
	vector<vector<Location>> locations
	{
		{Location(0, 0), Location(0, 1), Location(0, 2), Location(0, 3), Location(0, 4), Location(0, 5), Location(0, 6), Location(0, 7)},
		{Location(1, 0), Location(1, 1), Location(1, 2), Location(1, 3), Location(1, 4), Location(1, 5), Location(1, 6), Location(1, 7)},
		{Location(2, 0), Location(2, 1), Location(2, 2), Location(2, 3), Location(2, 4), Location(2, 5), Location(2, 6), Location(2, 7)},
		{Location(3, 0), Location(3, 1), Location(3, 2), Location(3, 3), Location(3, 4), Location(3, 5), Location(3, 6), Location(3, 7)},
		{Location(4, 0), Location(4, 1), Location(4, 2), Location(4, 3), Location(4, 4), Location(4, 5), Location(4, 6), Location(4, 7)},
		{Location(5, 0), Location(5, 1), Location(5, 2), Location(5, 3), Location(5, 4), Location(5, 5), Location(5, 6), Location(5, 7)},
		{Location(6, 0), Location(6, 1), Location(6, 2), Location(6, 3), Location(6, 4), Location(6, 5), Location(6, 6), Location(6, 7)},
		{Location(7, 0), Location(7, 1), Location(7, 2), Location(7, 3), Location(7, 4), Location(7, 5), Location(7, 6), Location(7, 7)},
	};
	
private:
	void init_locations();

public:
	Board();
	~Board();

	Status move_to(Piece& target_piece, Location& destination);



};

#endif // !chess_board

