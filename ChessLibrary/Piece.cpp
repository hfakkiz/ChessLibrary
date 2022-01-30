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

void Piece::set_type(PieceType new_type)
{
	this->type = new_type;
}

PieceType Piece::get_type()
{
	return this->type;
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

	if (new_limit >= MAX_SQUARE_VALUE)
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

Status Piece::move_to(Location new_location)
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
	this->type				= PieceType::Pawn;
	this->movement_options	= (int)MovementType::Vertical;
	this->movement_limit	= 2;
	this->is_first_move		= true;
	this->is_attacking		= true;
}

Status Pawn::move_to(Location new_location)
{
	int distance = 0;
	MovementType movement_type;

	if (this->is_attacking)
	{
		this->set_movement_options((int)MovementType::Diagonal);
		
		if(this->get_movement_limit() == 2)
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

	if (this->is_first_move)
	{
		this->is_first_move = false;
		this->set_movement_limit(1);
	}
	if (this->is_attacking)
	{
		this->is_attacking = false;
		this->set_movement_options((int)MovementType::Vertical);
	}
	
	return this->set_location(new_location);
}

void Pawn::turn_attack_mode()
{
	this->is_attacking = true;
}

/*
 * Bishop Functions
 */
Bishop::Bishop()
{
	this->name = "Bishop";
	this->status = PieceStatus::Alive;
	this->type = PieceType::Bishop;
	this->movement_options = (int)MovementType::Diagonal;
}

Status Bishop::move_to(Location new_location)
{
	MovementType movement_type;

	movement_type = find_movement_type(this->get_location(), new_location);

	if (((int)movement_type & (this->get_movement_options())) == 0)
		return Status::Error;

	return this->set_location(new_location);
}

/*
 * Knight Functions
 */
Knight::Knight()
{
	this->name = "Knight";
	this->status = PieceStatus::Alive;
	this->type = PieceType::Knight;
	this->movement_options = (int)MovementType::L_Shape;
}

Status Knight::move_to(Location new_location)
{
	MovementType movement_type;

	movement_type = find_movement_type(this->get_location(), new_location);

	if (((int)movement_type & (this->get_movement_options())) == 0)
		return Status::Error;

	return this->set_location(new_location);
}

/*
 * Rook Functions
 */
Rook::Rook()
{
	this->name = "Rook";
	this->status = PieceStatus::Alive;
	this->type = PieceType::Rook;
	this->movement_options = (int)MovementType::Horizontal | (int)MovementType::Vertical;
}

Status Rook::move_to(Location new_location)
{
	MovementType movement_type;

	movement_type = find_movement_type(this->get_location(), new_location);

	if (((int)movement_type & (this->get_movement_options())) == 0)
		return Status::Error;

	return this->set_location(new_location);
}

/*
 * Queen Functions
 */
Queen::Queen()
{
	this->name = "Queen";
	this->status = PieceStatus::Alive;
	this->type = PieceType::Queen;
	this->movement_options = (int)MovementType::Horizontal | (int)MovementType::Vertical | (int)MovementType::Diagonal;
}

Status Queen::move_to(Location new_location)
{
	MovementType movement_type;

	movement_type = find_movement_type(this->get_location(), new_location);

	if (((int)movement_type & (this->get_movement_options())) == 0)
		return Status::Error;

	return this->set_location(new_location);
}

/*
 * King Functions
 */
King::King()
{
	this->name = "King";
	this->status = PieceStatus::Alive;
	this->type = PieceType::King;
	this->movement_options = (int)MovementType::Horizontal | (int)MovementType::Vertical | (int)MovementType::Diagonal;
	this->movement_limit = 1;
	this->check_status = false;
}

Status King::move_to(Location new_location)
{
	int distance = 0;
	MovementType movement_type;

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

void King::set_check_status(bool new_check_status)
{
	this->check_status = new_check_status;
}

bool King::get_check_status()
{
	return this->check_status;
}