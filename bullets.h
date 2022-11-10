#pragma once
#include <windows.h>
#include "SpaceShip.h"

class bullets
{
private:
	char model = '\'';
	
	int id;
public:
	int x;
	int y;
	void init_bullet(COORD shooted_from, bullets *bullet);
	int update_bullet(bullets *bullet,SpaceShip *ship);
	void destroy(char model, int x, int y);
	bullets(int x, int y);
};

