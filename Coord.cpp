#include "Coord.h"


	Coord::Coord(int x, int y)
	{
		X = x; Y = y;
	}

	Coord::Coord(const Coord &coord)
	{
		X = coord.X; Y = coord.Y;
	}

