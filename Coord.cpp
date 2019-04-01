#include "Coord.h"


	Coord::Coord(int x, int y)
	{
		X = x; Y = y;
	}

	Coord::Coord(const Coord &coord)
	{
		X = coord.X; Y = coord.Y;
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


