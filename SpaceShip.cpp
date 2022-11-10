#include "SpaceShip.h"

#include "console_related.h"
#include <conio.h>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


void SpaceShip::move(SpaceShip* ship)
{
    static HANDLE stdinHandle;
    // Get the IO handles
    // getc(stdin);
    stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
    switch (WaitForSingleObject(stdinHandle, 1000))
    {
        case(WAIT_TIMEOUT):
            break; // return from this function to allow thread to terminate
        case(WAIT_OBJECT_0):
            if (_kbhit()) // _kbhit() always returns immediately
            {
                int i = _getch();
                switch (i)
                {
                    case KEY_LEFT:
                        if (ship->x > 0)
                        {
                            COORD new_coords;
                            new_coords.X = ship->x - 1;
                            new_coords.Y = ship->y;
                            clscr_rwrt(ship, new_coords);
                            Beep(420, 100);
                        }
                        break;
                    case KEY_RIGHT:
                        if (ship->x < 15)
                        {
                            COORD new_coords;
                            new_coords.X = ship->x + 1;
                            new_coords.Y = ship->y;
                            clscr_rwrt(ship, new_coords);
                            Beep(420, 100);
                        }
                        break;
                }
            }
            break;
    }
}

void SpaceShip::clscr_rwrt(SpaceShip* ship,COORD new_coord)
{
    COORD temp;
    temp.X = ship->x;
    temp.Y = ship->y;
    setPos(temp);
    std::cout << ' ';
    ship->x = new_coord.X;
    ship->y = new_coord.Y;
    setPos(get_ship_coords(ship));
    std::cout << ship->model;
}

COORD SpaceShip::get_ship_coords(SpaceShip* ship)
{
    COORD temp;
    temp.X = ship->x;
    temp.Y = ship->y;
    return temp;
}
