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
protected:
	string		name;
	PieceStatus status;
	Location*	location;
	int			movement_limit;
	int			movement_options;

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

	Status		set_movement_limit(int new_limit);
	int			get_movement_limit();

	Status		set_movement_options(int new_options);
	int			get_movement_options();

	Status moveTo(Location new_location);

};

class Pawn : public Piece
{
private:
	bool is_first_move;

public:
	Pawn();
	Status moveTo(Location new_location);
};

#endif // !chess_piece

