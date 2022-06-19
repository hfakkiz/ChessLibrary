#include "Board.h"

Board::Board()
{
	//init_locations();
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
			this->locations[i][j] = Location((i), (j));
		}
	}
}

Status Board::move_to(Piece& target_piece, Location& destination)
{	
	if ((check_route(this->locations, *(target_piece.get_location()), destination) == Status::Error) && (target_piece.get_type() != PieceType::Knight))
		return Status::Error;

	if (destination.get_status() == LocationStatus::Not_Empty)
	{		
		if (destination.get_piece()->get_team_type() == target_piece.get_team_type())
			return Status::Error;
		
		if (target_piece.get_type() == PieceType::Pawn)
		{
			Pawn& target_pawn = dynamic_cast<Pawn&>(target_piece);
			target_pawn.turn_attack_mode();

			if (target_pawn.move_to(destination) == Status::Error)
				return Status::Error;

			//destination.get_piece()->set_status(PieceStatus::Dead);
			//destination.get_piece()->set_location(Location(0, 0));
			//destination.update_status(LocationStatus::Not_Empty, &target_pawn);
		}
		else
		{
			// TO DO: Ýlgili taþýn move to fonksiyonu çaðýrýlacak.
			if (target_piece.move_to(destination) == Status::Error)
				return Status::Error;
			//destination.get_piece()->set_status(PieceStatus::Dead);
			//destination.get_piece()->set_location(Location(0, 0));
			//destination.update_status(LocationStatus::Not_Empty, &target_piece);
		}
	}
	else if (destination.get_status() == LocationStatus::Empty)
	{
		if (target_piece.move_to(destination) == Status::Error)
			return Status::Error;

		//destination.update_status(LocationStatus::Not_Empty, &target_piece);
	}
}