#include "mainMenu.h"
#include <thread>


void Menu::title_screen()
{
	std::cout << R""(
		     _                      _______                      _
		  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_
		 dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb
		 V      ~"Mb          dOOOOOOOOOOOOOOOOOb          dM"~      V
		          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'
		           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'
		      __     `YMMM| OP'~"YOOOOOOOOOOOP"~`YO |MMMP'     __
		    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.
		 _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb._

		             `YMMMM\`OOOo     OOO     oOOO'/MMMMP'
		     ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.
		   ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.
		  ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM.
		  MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM
		  YMb           ~YMMMM\`OOOOI`````IOOOOO'/MMMMP~           dMP
		   `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'
		     `'                  `OObNNNNNdOO'                   `'
		                           `~OOOOO~'
   _____                        _____                     _                 __  __ _       _ 
  / ____|                      |_   _|                   | |               |  \/  (_)     (_)
 | (___  _ __   __ _  ___ ___    | |  _ ____   ____ _  __| | ___ _ __ ___  | \  / |_ _ __  _ 
  \___ \| '_ \ / _` |/ __/ _ \   | | | '_ \ \ / / _` |/ _` |/ _ \ '__/ __| | |\/| | | '_ \| |
  ____) | |_) | (_| | (_|  __/  _| |_| | | \ V / (_| | (_| |  __/ |  \__ \ | |  | | | | | | |
 |_____/| .__/ \__,_|\___\___| |_____|_| |_|\_/ \__,_|\__,_|\___|_|  |___/ |_|  |_|_|_| |_|_|
        | |                                                                                  
        |_|                                                                                 
	)"";
	std::cout << std::endl;
	std::cout << "Press enter to continue. . .";
	bool start = false;
	while (!_kbhit())
	{
		if (start==false)
		{
			PlaySound(TEXT("Game_background.wav"), NULL, SND_ASYNC);
			start = true;
		}
	}
	PlaySound(TEXT("Undertale.wav"), NULL, SND_ASYNC);
	system("cls");
}

void Menu::game_over()
{
	system("cls");
	PlaySound(TEXT("GameOver.wav"), NULL, SND_ASYNC);
	std::cout << R""(
  _____                         ____                 
 / ____|                       / __ \                
| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ 
| | |_ |/ _` | '_ ` _ \ / _ \ | |  | \ \ / / _ \ '__|
| |__| | (_| | | | | | |  __/ | |__| |\ V /  __/ |   ._. ._. ._.
 \_____|\__,_|_| |_| |_|\___|  \____/  \_/ \___|_|   |_| |_| |_|                                                      
	)"";
	std::cout << std::endl << std::endl << "Thanks for playing ! :)" << std::endl;
	system("pause");
	exit(0);
}


