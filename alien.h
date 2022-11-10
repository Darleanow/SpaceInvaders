#pragma once
#include <string>

#include "console_related.h"
#include <windows.h>

class Enemy
{
public:
	int x = 0;
	int y = 0;
	virtual char shw_model() = 0;
	virtual void init_alien() = 0;
	virtual int health() = 0;
	virtual void sub_healthpoint() = 0;
	virtual void update_Pos() = 0;
	void clsrc_rwrt(COORD prev_coords);
};

class Alien : public Enemy
{
private:
	int hp = 1;
	char model = '.';
public:
	void init_alien();
	void sub_healthpoint();
	int health();
	void update_Pos();
	char shw_model();
	Alien();
};

class BigAlien : public Enemy
{
private:
	int hp = 3;
	char model = '*';
public:
	void init_alien();
	int health();
	void update_Pos();
	void sub_healthpoint();
	char shw_model();
	BigAlien();
};

class Boss : public Enemy
{
private:
	int hp = 7;
	char model = '0';
public:
	void init_alien();
	int health();
	void update_Pos();
	void sub_healthpoint();
	char shw_model();
	Boss();
};