#ifndef chess_location
#define chess_location

#include <iostream>

#define MAX_RAW_VALUE		8
#define MAX_COLUMN_VALUE	8

enum class Status
{
	Error,
	Ok
};

enum class LocationStatus
{
	Not_Empty,
	Empty
};

enum class MovementType
{
	Vertical = 1,
	Horizontal = 2,
	Diagonal = 4
};

class Location
{
private:
	int raw;
	int column;
	LocationStatus status;

public:

public:
	Location();
	Location(int new_raw, int new_column);
	~Location();

	Status set_raw(int new_raw);
	int get_raw( void );
	Status set_column(int new_column);
	int get_column(void);
	void update_status(LocationStatus new_status);
	LocationStatus get_status(void);
};

int calculate_distance(Location current_location, Location new_location);
MovementType find_movement_type(Location current_location, Location new_location);

#endif // !chess_location

