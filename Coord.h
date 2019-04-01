#pragma once
class Coord
{
public:
    int X;
    int Y;
	Coord(int x = 0, int y = 0);
	Coord(const Coord &coord);
    int GetRow();
    int GetColumn();
    char GetCounter();
    void IncrementCounter();
    
protected:
    int counter;
};

