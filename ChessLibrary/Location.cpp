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
	else if (new_raw > MAX_RAW_VALUE)
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
	else if (new_column > MAX_RAW_VALUE)
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
