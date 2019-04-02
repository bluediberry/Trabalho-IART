#include "Coord.h"


	Coord::Coord(int x, int y)
	{
		X = x; Y = y;
	}

	Coord::Coord(const Coord &coord)
	{
		X = coord.X; Y = coord.Y;
	}

	bool operator !=(const Coord& coord1, const Coord& coord2)
	{
		if ((coord1.X != coord2.X) || (coord1.Y != coord2.Y)) {
			return true;
		}
		else
			return false;
	}

int Coord::GetRow(){
    return X;
}

int Coord::GetColumn(){
    return Y;
}

char Coord::GetCounter(){
    return counter;
}

void Coord::IncrementCounter(){
    counter++;
}


