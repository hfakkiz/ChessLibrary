#ifndef chess_piece
#define chess_piece

#include <iostream>
//#include "Location.h"
#include "EnumTypes.h"

using namespace std;

class Location;

class Piece
{
protected:
	string		name;
	PieceStatus status;
	PieceType	type;
	Location*	location;
	int			movement_limit;
	int			movement_options;
	TeamType	team_type;

public:
	Piece();
	~Piece();

	Status				set_name(string new_name);
	string				get_name();

	void				set_status(PieceStatus new_status);
	PieceStatus			get_status();

	void				set_type(PieceType new_type);
	PieceType			get_type();

	void				set_team_type(TeamType new_team_type);
	TeamType			get_team_type();

	Status				set_location(Location& new_location);
	Location*			get_location();

	Status				set_movement_limit(int new_limit);
	int					get_movement_limit();

	Status				set_movement_options(int new_options);
	int					get_movement_options();

	virtual Status		move_to(Location& new_location);

};

class Pawn : public Piece
{
private:
	bool is_first_move;
	bool is_attacking;

public:
	Pawn();
	Status	move_to(Location& new_location) override;
	void	turn_attack_mode();
};

class Bishop : public Piece
{
public:
	Bishop();
	Status	move_to(Location& new_location) override;

};

class Knight : public Piece
{
public:
	Knight();
	Status	move_to(Location& new_location) override;

};

class Rook : public Piece
{
public:
	Rook();
	Status	move_to(Location& new_location) override;

};

class Queen : public Piece
{
public:
	Queen();
	Status	move_to(Location& new_location) override;

};

class King : public Piece
{
private:
	bool check_status;

public:
	King();
	Status	move_to(Location& new_location) override;

	void	set_check_status(bool new_check_status);
	bool	get_check_status();

};

#endif // !chess_piece

