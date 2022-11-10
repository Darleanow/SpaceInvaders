#pragma once
#include "console_related.h"

class SpaceShip
{
protected:
	char model = '^';
public:
	int x = 7;
	int y = 8;
	void move(SpaceShip *ship);
	void clscr_rwrt(SpaceShip* ship, COORD new_coord);
	COORD get_ship_coords(SpaceShip* ship);
};
