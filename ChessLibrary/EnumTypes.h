#ifndef chess_enum_types
#define chess_enum_types

/*
 *	GENERAL ENUMS
 */
enum class Status
{
	Error,
	Ok
};

/*
 *	TEAM ENUMS
 */
enum class TeamType
{
	White_Team,
	Black_Team
};

/*
 *	PIECE ENUMS
 */
enum class PieceStatus
{
	Alive,
	Dead
};

enum class PieceType
{
	Pawn = 0,
	Bishop,
	Knight,
	Rook,
	Queen,
	King
};

/*
 *	LOCATION ENUMS
 */
enum class LocationStatus
{
	Not_Empty,
	Empty
};

enum class MovementType
{
	None = 0,
	Vertical = 1,
	Horizontal = 2,
	Diagonal = 4,
	L_Shape = 8
};

#endif // !chess_enum_types