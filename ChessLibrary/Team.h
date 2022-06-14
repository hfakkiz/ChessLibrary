#ifndef chess_team
#define chess_team

#include <vector>
#include "Location.h"
#include "Piece.h"
#include "EnumTypes.h"

using namespace std;

class Team
{
private:
	King	king;
	Queen	queen;
	Bishop	bishop[2];
	Knight	knight[2];
	Rook	rook[2];
	Pawn	pawn[8];

	TeamType	team_type;

public:
	Team(TeamType new_team_type);
	~Team();

	void init_team(vector<vector<Location>>& board_locations);
};

#endif // !chess_team



