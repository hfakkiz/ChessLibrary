#ifndef chess_location
#define chess_location

#include <iostream>
#include <vector>
//#include "Piece.h"
#include "EnumTypes.h"

using namespace std;

#define MAX_SQUARE_VALUE	7

class Piece;

class Location
{
private:
	int				raw;
	int				column;
	LocationStatus	status;
	Piece*			piece;

public:

public:
	Location();
	Location(int new_raw, int new_column);
	~Location();

	Status	set_raw(int new_raw);
	int		get_raw( void );
	Status	set_column(int new_column);
	int		get_column( void );
	Status	update_status(LocationStatus new_status, Piece* new_piece);
	LocationStatus get_status( void );
	Piece*	get_piece( void );
};

int calculate_distance(Location current_location, Location new_location);
MovementType find_movement_type(Location current_location, Location new_location);
Status check_route(vector<vector<Location>>& board_locations, Location current_location, Location new_location);

#endif // !chess_location

