#include "Location.h"
#include "Piece.h"

Location::Location() : raw(-1), column(-1), status(LocationStatus::Empty)
{
	this->piece = (Piece*)malloc(sizeof(Piece));
}
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
	if (new_raw < 0)
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
	if (new_column < 0)
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

Status Location::update_status(LocationStatus new_status, Piece* new_piece)
{
	this->status = new_status;
	this->piece = new_piece;

	return Status::Ok;
}

LocationStatus Location::get_status()
{
	return this->status;
}

Piece* Location::get_piece()
{
	return this->piece;
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
	else if (((abs(raw_distance) == 1) && (abs(column_distance) == 2)) || ((abs(raw_distance) == 2) && (abs(column_distance) == 1)))
		return MovementType::L_Shape;
	else
		return MovementType::None;
}

Status check_route(vector<vector<Location>>& board_locations, Location current_location, Location new_location)
{
	int raw_distance = 0;
	int column_distance = 0;
	int distance = 0;
	int raw_start_point = 0;
	int column_start_point = 0;
	MovementType movement_type;

	movement_type = find_movement_type(current_location, new_location);

	if ((movement_type == MovementType::Horizontal) || (movement_type == MovementType::Vertical))
	{
		if (movement_type == MovementType::Vertical)
			distance = current_location.get_raw() - new_location.get_raw();
		else if (movement_type == MovementType::Horizontal)
			distance = current_location.get_column() - new_location.get_column();

		if (distance == 1 || distance == -1)
		{
			return Status::Ok;
		}
		else if (distance < -1)
		{
			column_start_point = current_location.get_column();
			raw_start_point = current_location.get_raw();
		}
		else if (distance > 1)
		{
			column_start_point = new_location.get_column();
			raw_start_point = new_location.get_raw();
		}
		else
		{
			return Status::Error;
		}

		for (int i = 1; i < abs(distance); i++)
		{
			if (movement_type == MovementType::Vertical)
			{
				if (board_locations[raw_start_point + i][column_start_point].get_status() == LocationStatus::Not_Empty)
					return Status::Error;
			}
			else if (movement_type == MovementType::Horizontal)
			{
				if (board_locations[raw_start_point][column_start_point + i].get_status() == LocationStatus::Not_Empty)
					return Status::Error;
			}
		}
	}
	else if (movement_type == MovementType::Diagonal)
	{
		raw_distance = current_location.get_raw() - new_location.get_raw();
		column_distance = current_location.get_column() - new_location.get_column();

		if (raw_distance == 1 || raw_distance == -1)
		{
			return Status::Ok;
		}
		else if (((raw_distance < -1) && (column_distance < -1)) || ((raw_distance > 1) && (column_distance > 1)))
		{
			if ((raw_distance < -1) && (column_distance < -1))
			{
				column_start_point = current_location.get_column();
				raw_start_point = current_location.get_raw();
			}
			else if ((raw_distance > 1) && (column_distance > 1))
			{
				column_start_point = new_location.get_column();
				raw_start_point = new_location.get_raw();
			}

			for (int i = 1; i < abs(column_distance); i++)
			{
				if (board_locations[raw_start_point + i][column_start_point + i].get_status() == LocationStatus::Not_Empty)
					return Status::Error;
			}
		}
		else if (((raw_distance < -1) && (column_distance > 1)) || ((raw_distance > 1) && (column_distance < -1)))
		{
			if ((raw_distance < -1) && (column_distance > 1))
			{
				column_start_point = new_location.get_column();
				raw_start_point = new_location.get_raw();
			}
			else if ((raw_distance > 1) && (column_distance < -1))
			{
				column_start_point = current_location.get_column();
				raw_start_point = current_location.get_raw();
			}

			for (int i = 1; i < abs(column_distance); i++)
			{
				if (board_locations[raw_start_point - i][column_start_point + i].get_status() == LocationStatus::Not_Empty)
					return Status::Error;
			}
		}
		else
		{
			return Status::Error;
		}
	}
	else
	{
		return Status::Error;
	}

	return Status::Ok;
}
