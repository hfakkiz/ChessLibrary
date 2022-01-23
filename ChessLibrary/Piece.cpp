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
