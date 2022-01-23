#include "Piece.h"

Piece::Piece()
{
	this->name = "";
	this->status = PieceStatus::Alive;
	this->location = (Location*)malloc(sizeof(Location));
}
Piece::~Piece(){}

Status Piece::set_name(string new_name)
{
	if (new_name.empty())
		return Status::Error;

	this->name = new_name;

	return Status::Ok;
}

string Piece::get_name()
{
	return this->name;
}

void Piece::set_status(PieceStatus new_status)
{
	this->status = new_status;
}

PieceStatus Piece::get_status()
{
	return this->status;
}

Status Piece::set_location(Location new_location)
{
	if (new_location.get_raw() == 0 || new_location.get_column() == 0)
		return Status::Error;

	this->location = &new_location;

	return Status::Ok;
}

Location Piece::get_location()
{
	return *(this->location);
}

Status Piece::set_movement_limit(int new_limit)
{
	if (new_limit == 0)
		return Status::Error;

	if (new_limit >= MAX_RAW_VALUE)
		return Status::Error;

	this->movement_limit = new_limit;

	return Status::Ok;
}

int Piece::get_movement_limit()
{
	return this->movement_limit;
}

Status Piece::set_movement_options(int new_options)
{
	if (new_options == 0)
		return Status::Error;

	if (new_options > ((int)MovementType::Vertical | (int)MovementType::Horizontal | (int)MovementType::Diagonal))
		return Status::Error;

	this->movement_options = new_options;

	return Status::Ok;
}

int Piece::get_movement_options()
{
	return this->movement_options;
}

Status Piece::moveTo(Location new_location)
{
	return this->set_location(new_location);
}


/*
 * Pawn Functions 
 */
Pawn::Pawn()
{
	this->name				= "Pawn";
	this->status			= PieceStatus::Alive;
	this->movement_options	= (int)MovementType::Vertical;
	this->movement_limit	= 2;
	this->is_first_move		= true;
}

Status Pawn::moveTo(Location new_location)
{
	int distance = 0;
	MovementType movement_type;

	if (this->is_first_move)
	{
		this->is_first_move = false;
		this->set_movement_limit(1);
	}

	movement_type = find_movement_type(this->get_location(), new_location);

	if (((int)movement_type & (this->get_movement_options())) == 0)
		return Status::Error;

	distance = calculate_distance(this->get_location(), new_location);

	if (distance == 0)
		return Status::Error;

	if (distance > this->get_movement_limit())
		return Status::Error;

	return this->set_location(new_location);
}
