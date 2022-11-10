#include "alien.h"

#include <iostream>

Alien::Alien() {};

BigAlien::BigAlien() {};

Boss::Boss() {};




void Alien::update_Pos()
{
	COORD temp;
	temp.X = this->x;
	temp.Y = this->y;
	clsrc_rwrt(temp);
	if (this->y % 2 == 0)
	{
		if (this->x == 13)
			this->y+=1;
		else
			this->x+=1;
	}
	else
	{
		if (this->x == 0)
			this->y+=1;
		else
			this->x-=1;
	}
	temp.X = this->x;
	temp.Y = this->y;
	setPos(temp);
	std::cout << this->model;
}

void BigAlien::update_Pos()
{
	COORD temp;
	temp.X = this->x;
	temp.Y = this->y;
	clsrc_rwrt(temp);
	if (this->y % 2 == 0)
	{
		if (this->x == 13)
			this->y += 1;
		else
			this->x += 1;
	}
	else
	{
		if (this->x == 0)
			this->y += 1;
		else
			this->x -= 1;
	}
	temp.X = this->x;
	temp.Y = this->y;
	setPos(temp);
	std::cout << this->model;
}

void Boss::update_Pos()
{
	COORD temp;
	temp.X = this->x;
	temp.Y = this->y;
	clsrc_rwrt(temp);
	if (this->y % 2 == 0)
	{
		if (this->x == 13)
			this->y += 1;
		else
			this->x += 1;
	}
	else
	{
		if (this->x == 0)
			this->y += 1;
		else
			this->x -= 1;
	}
	temp.X = this->x;
	temp.Y = this->y;
	setPos(temp);
	std::cout << this->model;
}


void Enemy::clsrc_rwrt(COORD prev_coords)
{
	setPos(prev_coords);
	std::cout << ' ';
}

void Alien::init_alien()
{
	COORD temp;
	temp.X = 0;
	temp.Y = 0;
	setPos(temp);
	std::cout << this->model;
}

void BigAlien::init_alien()
{
	COORD temp;
	temp.X = 0;
	temp.Y = 0;
	setPos(temp);
	std::cout << this->model;
}

void Boss::init_alien()
{
	COORD temp;
	temp.X = 0;
	temp.Y = 0;
	setPos(temp);
	std::cout << this->model;
}

int Alien::health()
{
	return this->hp;
}

int BigAlien::health()
{
	return this->hp;
}

int Boss::health()
{
	return this->hp;
}

void Alien::sub_healthpoint()
{}


void BigAlien::sub_healthpoint()
{
	this->hp -= 1;
}

void Boss::sub_healthpoint()
{
	this->hp -= 1;
}

char Alien::shw_model()
{
	return this->model;
}

char BigAlien::shw_model()
{
	return this->model;
}

char Boss::shw_model()
{
	return this->model;
}
