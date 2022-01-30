#include "Location.h"

Location::Location() : raw(0), column(0), status(LocationStatus::Empty) {}
Location::~Location(){}

Location::Location(int new_raw, int new_column)
{
	this->status = LocationStatus::Empty;

	if (this->set_raw(new_raw) != Status::Ok)
		this->~Location();

	if (this->set_column(new_column) != Status::Ok)
		this->~Location();

}

Status Location::set_raw(int new_raw)
{
	if (new_raw == 0)
		return Status::Error;
	else if (new_raw > MAX_SQUARE_VALUE)
		return Status::Error;

	this->raw = new_raw;

	return Status::Ok;
}

int Location::get_raw()
{
	return this->raw;
}

Status Location::set_column(int new_column)
{
	if (new_column == 0)
		return Status::Error;
	else if (new_column > MAX_SQUARE_VALUE)
		return Status::Error;

	this->column = new_column;

	return Status::Ok;
}

int Location::get_column()
{
	return this->column;
}

void Location::update_status(LocationStatus new_status)
{
	this->status = new_status;
}

LocationStatus Location::get_status()
{
	return this->status;
}

int calculate_distance(Location current_location, Location new_location)
{
	int raw_distance	= 0;
	int column_distance = 0;

	raw_distance	= abs(current_location.get_raw() - new_location.get_raw());
	column_distance = abs(current_location.get_column() - new_location.get_column());

	if (raw_distance >= column_distance)
		return raw_distance;
	else
		return column_distance;
}

MovementType find_movement_type(Location current_location, Location new_location)
{
	int raw_distance	= 0;
	int column_distance = 0;

	raw_distance	= current_location.get_raw() - new_location.get_raw();
	column_distance = current_location.get_column() - new_location.get_column();

	if (raw_distance == 0)
		return MovementType::Horizontal;
	else if (column_distance == 0)
		return MovementType::Vertical;
	else if (abs(raw_distance) == abs(column_distance))
		return MovementType::Diagonal;
	else if (((abs(raw_distance) == 1) && (abs(column_distance == 2))) || ((abs(raw_distance) == 2) && (abs(column_distance == 1))))
		return MovementType::L_Shape;
	else
		return MovementType::None;
}
