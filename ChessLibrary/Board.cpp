#include "Board.h"

Board::Board()
{
	init_locations();
	this->team_white.init_team(this->locations);
	this->team_black.init_team(this->locations);
}
Board::~Board() {}

void Board::init_locations()
{
	for (int i = 0; i < MAX_SQUARE_VALUE; i++)
	{
		for (int j = 0; j < MAX_SQUARE_VALUE; j++)
		{
			this->locations[i][j] = Location((i + 1), (j + i));
		}
	}
}

Status Board::move_to(Piece& target_piece, Location destination)
{
	Piece* temp_piece;
	
	if ((check_route(this->locations, target_piece.get_location(), destination) == Status::Error) && (target_piece.get_type() != PieceType::Knight))
		return Status::Error;

	if (destination.get_status() == LocationStatus::Not_Empty)
	{
		temp_piece = destination.get_piece();
		
		if (temp_piece->get_team_type() == target_piece.get_team_type())
			return Status::Error;
		
		temp_piece->set_location(Location(0, 0));
		temp_piece->set_status(PieceStatus::Dead);

		if(target_piece.get_type() == PieceType::Pawn)
			// TO DO: Casting yapýlýp pawn'un atak modu açýlacak.

		// TO DO: Ýlgili taþýn move to fonksiyonu çaðýrýlacak.

		destination.update_status(LocationStatus::Not_Empty, &target_piece);

	}
	else if (destination.get_status() == LocationStatus::Empty)
	{
		// TO DO!!
	}
}