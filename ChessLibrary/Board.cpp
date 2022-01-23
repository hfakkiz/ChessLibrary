#include "Board.h"

Board::Board()
{
	init_locations();
}
Board::~Board() {}

void Board::init_locations()
{
	for (int i = 0; i < MAX_RAW_VALUE; i++)
	{
		for (int j = 0; j < MAX_COLUMN_VALUE; j++)
		{
			this->locations[i][j] = Location((i + 1), (j + i));
		}
	}
}
