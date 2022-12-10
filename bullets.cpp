#include "bullets.h"

#include <iostream>

#include "console_related.h"

void bullets::init_bullet(COORD shooted_from, bullets* bullet)
{
	shooted_from.Y -= 1;
	setPos(shooted_from);
	std::cout << bullet->model;
	bullet->x = shooted_from.X;
	bullet->y = shooted_from.Y;
}

int bullets::update_bullet(bullets* bullet,SpaceShip* ship)
{
	COORD update;
	
	update.Y = bullet->y;
	update.X = bullet->x;
	setPos(update);
	std::cout << ' ';
	
	bullet->y -= 1;
	update.Y -= 1;
	if (bullet->y == -1)
	{
		return -1;
	}
	setPos(update);
	std::cout << bullet->model;
	COORD shiptemp;
	shiptemp.X = ship->x;
	shiptemp.Y = ship->y;
	setPos(shiptemp);
	std::cout << '^';
	return 0;
}

bullets::bullets(int a, int b)
{
	x = a;
	y = b;
}

void bullets::destroy(char model, int x,int y)
{
	COORD temp;
	temp.X = x;
	temp.Y = y;
	if (model == '.')
	{
		setPos(temp);
		std::cout << " ";
	}
	else if (model == '*')
	{
		setPos(temp);
		std::cout << "*";
	}
	else if (model == 'O')
	{
		setPos(temp);
		std::cout << "O";
	}
}
