#include "Coord.h"

class Coord
{
public:
	int X;
	int Y;

	Coord::Coord(int x = 0, int y = 0)
	{
		X = x; Y = y;
	}

	Coord::Coord(const Coord &coord)
	{
		X = coord.X; Y = coord.Y;
	}

};