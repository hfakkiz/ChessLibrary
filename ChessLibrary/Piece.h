#ifndef chess_piece
#define chess_piece

#include <iostream>
#include "Location.h"

using namespace std;

enum class PieceStatus
{
	Alive,
	Dead
};

class Piece
{
private:
	string		name;
	PieceStatus status;
	Location*	location;

public:

public:
	Piece();
	~Piece();

	Status	set_name(string new_name);
	string	get_name();

	void		set_status(PieceStatus new_status);
	PieceStatus get_status();

	Status		set_location(Location new_location);
	Location	get_location();

	Status moveTo(Location new_location);

};

#endif // !chess_piece

