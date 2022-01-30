#include "Team.h"

#define SIZEOFARRAY(array)	sizeof(array)/sizeof(array[0])

Team::Team(TeamType new_team_type)
{
	this->team_type = new_team_type;

	for (int i = 0; i < SIZEOFARRAY(this->pawn); i++)
	{
		this->pawn[i].set_team_type(this->team_type);
	}

	this->rook[0].set_team_type(this->team_type);
	this->knight[0].set_team_type(this->team_type);
	this->bishop[0].set_team_type(this->team_type);
	this->queen.set_team_type(this->team_type);
	this->king.set_team_type(this->team_type);
	this->bishop[1].set_team_type(this->team_type);
	this->knight[1].set_team_type(this->team_type);
	this->rook[1].set_team_type(this->team_type);
}
Team::~Team() {}

void Team::init_team(vector<vector<Location>>& board_locations)
{
	int raw = 0, column = 0;

	if (this->team_type == TeamType::White_Team)
	{
		for (int i = 0; i < SIZEOFARRAY(this->pawn); i++)
		{
			this->pawn[i].set_location(board_locations[1][i]);
			board_locations[1][i].update_status(LocationStatus::Not_Empty, &(this->pawn[i]));
		}

		this->rook[0].set_location(board_locations[0][0]);
		board_locations[0][0].update_status(LocationStatus::Not_Empty, &(this->rook[0]));
		this->knight[0].set_location(board_locations[0][1]);
		board_locations[0][1].update_status(LocationStatus::Not_Empty, &(this->knight[0]));
		this->bishop[0].set_location(board_locations[0][2]);
		board_locations[0][2].update_status(LocationStatus::Not_Empty, &(this->bishop[0]));
		this->queen.set_location(board_locations[0][3]);
		board_locations[0][3].update_status(LocationStatus::Not_Empty, &(this->queen));
		this->king.set_location(board_locations[0][4]);
		board_locations[0][4].update_status(LocationStatus::Not_Empty, &(this->king));
		this->bishop[1].set_location(board_locations[0][5]);
		board_locations[0][5].update_status(LocationStatus::Not_Empty, &(this->bishop[1]));
		this->knight[1].set_location(board_locations[0][6]);
		board_locations[0][6].update_status(LocationStatus::Not_Empty, &(this->knight[1]));
		this->rook[1].set_location(board_locations[0][7]);
		board_locations[0][7].update_status(LocationStatus::Not_Empty, &(this->rook[1]));
	}
	else if (this->team_type == TeamType::Black_Team)
	{
		for (int i = 0; i < SIZEOFARRAY(this->pawn); i++)
		{
			this->pawn[i].set_location(board_locations[6][MAX_SQUARE_VALUE - 1 - i]);
			board_locations[6][MAX_SQUARE_VALUE - 1 - i].update_status(LocationStatus::Not_Empty, &(this->pawn[i]));
		}

		this->rook[0].set_location(board_locations[7][7]);
		board_locations[7][7].update_status(LocationStatus::Not_Empty, &(this->rook[0]));
		this->knight[0].set_location(board_locations[7][6]);
		board_locations[7][6].update_status(LocationStatus::Not_Empty, &(this->knight[0]));
		this->bishop[0].set_location(board_locations[7][5]);
		board_locations[7][5].update_status(LocationStatus::Not_Empty, &(this->bishop[0]));
		this->queen.set_location(board_locations[7][4]);
		board_locations[7][4].update_status(LocationStatus::Not_Empty, &(this->queen));
		this->king.set_location(board_locations[7][3]);
		board_locations[7][3].update_status(LocationStatus::Not_Empty, &(this->king));
		this->bishop[1].set_location(board_locations[7][2]);
		board_locations[7][2].update_status(LocationStatus::Not_Empty, &(this->bishop[1]));
		this->knight[1].set_location(board_locations[7][1]);
		board_locations[7][1].update_status(LocationStatus::Not_Empty, &(this->knight[1]));
		this->rook[1].set_location(board_locations[7][0]);
		board_locations[7][0].update_status(LocationStatus::Not_Empty, &(this->rook[1]));
	}
}
