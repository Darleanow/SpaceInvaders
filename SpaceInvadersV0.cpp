// SpaceInvadersV0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>
#include "SpaceShip.h"
#include "console_related.h"

#include "bullets.h"
#include "alien.h"

#include "mainMenu.h"

void game()
{
    //Ship init
    SpaceShip ship;
    COORD temp;
    temp.X = 7;
    temp.Y = 8;

    //Easy way to get back our objects
    std::vector<bullets> bullets_travelling;

    //Handle movement
    std::vector<Enemy*> pos;

    //Score
    int score = 0;
    COORD scr;
    scr.X = 0;
    scr.Y = 10;

    //avoid bugs
    bool augment_possible = false;

    //hide cursor
    set_cursor(false);

    //Ascii of the game init
    setPos(temp);
    std::cout << '^';
    setPos(scr);
    std::cout << "Score: " << score;

    //Tick system
    long long int tickrate = 0;

    //Speed of the game //Don't lower alien_move below 15
    int tick_update = 2;
    int tick_alien_move = 25;
    int tick_shoot = 15;

    //Gamespeed
    int gamespeed = 100;

    //Health points
    int health_points = 1;

    while (health_points > 0)
    {
        if (tickrate % tick_update == 0 && !(bullets_travelling.empty()))
        {
            for (unsigned long long i = 0; i < bullets_travelling.size(); i++) {
                if (!(bullets_travelling.empty()))
                {
                    const int status = bullets_travelling[i].update_bullet(&bullets_travelling[i], &ship);
                    if (status != 0)
                    {
                        bullets_travelling.erase(bullets_travelling.begin());
                        break;
                    }

                    if (!(pos.empty()))
                    {
                        int iter = 0;
                        for (const auto& e : pos)
                        {
                            if (e->x == bullets_travelling[i].x && e->y == bullets_travelling[i].y)
                            {
                                COORD del;
                                del.X = static_cast<SHORT>(e->x);
                                del.Y = static_cast<SHORT>(e->y);
                                const char mod = e->shw_model();
                                if (mod == '.')
                                {
                                    Beep(460, 50);
                                    bullets_travelling[i].destroy(mod, e->x, e->y);
                                    pos.erase(pos.begin() + iter);
                                    bullets_travelling.erase(bullets_travelling.begin());
                                    e->clsrc_rwrt(del);
                                    score += 10;
                                    setPos(scr);
                                    std::cout << "Score: " << score << " | Lives: " << health_points;
                                    augment_possible = true;
                                    break;
                                }
                                else if (mod == '*')
                                {
                                    Beep(480, 50);
                                    bullets_travelling[i].destroy(mod, e->x, e->y);
                                    bullets_travelling.erase(bullets_travelling.begin());
                                    if (e->health() == 1)
                                    {
                                        pos.erase(pos.begin() + iter);
                                        e->clsrc_rwrt(del);
                                        score += 20;
                                        setPos(scr);
                                        std::cout << "Score: " << score << " | Lives: " << health_points;
                                        augment_possible = true;
                                        break;
                                    }
                                    else
                                    {
                                        e->sub_healthpoint();
                                        augment_possible = true;
                                        break;
                                    }
                                }
                                else if (mod == '0')
                                {
                                    Beep(520, 50);
                                    bullets_travelling[i].destroy(mod, e->x, e->y);
                                    bullets_travelling.erase(bullets_travelling.begin());
                                    if (e->health() == 1)
                                    {
                                        pos.erase(pos.begin() + iter);
                                        e->clsrc_rwrt(del);
                                        score += 50;
                                        setPos(scr);
                                        std::cout << "Score: " << score << " | Lives: " << health_points;
                                        augment_possible = true;
                                        break;
                                    }
                                    else
                                    {
                                        e->sub_healthpoint();
                                        augment_possible = true;
                                        break;
                                    }
                                }
                            }
                            iter++;
                        }
                    }
                }
            }
        }
        if (tickrate % tick_alien_move == 0)
        {
            for (const auto& it : pos)
            {
                it->update_Pos();
                if (it->y == 8)
                {
                    health_points -= 1;
                    COORD rem;
                    rem.X = pos.back()->x;
                    rem.Y = pos.back()->y;
                    setPos(rem);
                    std::cout << " ";
                    pos.pop_back();
                }
            }
        }

        //alien creation
        if (tickrate % 400 == 0 && tickrate != 0)
        {
            pos.push_back(new Boss());
            pos.back()->init_alien();
        }
        else if (tickrate % 200 == 0 && tickrate != 0)
        {
            pos.push_back(new BigAlien());
            pos.back()->init_alien();
        }
        else if (tickrate % 25 == 0 && tickrate != 0)
        {
            pos.push_back(new Alien());
            pos.back()->init_alien();
        }


        ship.move(&ship);
        if (tickrate % tick_shoot == 0)
        {
            //BULLETS
            bullets_travelling.emplace_back(bullets(ship.x, ship.y));
            COORD temp_ship;
            temp_ship.X = static_cast<SHORT>(ship.x);
            temp_ship.Y = static_cast<SHORT>(ship.y);
            bullets_travelling.back().init_bullet(temp_ship, &bullets_travelling.back());
            Beep(280, 100);
        }

        //DIFFICULTY
        if (score % 100 == 0 && score != 0 && augment_possible == true)
        {
            if (score < 500)
            {
                tick_alien_move -= 3;
                augment_possible = false;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(gamespeed));
        tickrate++;
    }
}

int main()
{
    //Menu start
    Menu::title_screen();

    game();
    
    Menu::game_over();
}