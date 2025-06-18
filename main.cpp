#include "main.h"



using namespace std;



int creature::weaponcount = 0;
int creature::total = 0;

classmaker* classmakerfactory::prototypes[] = { new treasureinit, new weaponinit, new creatureinit };

int main()
{
	char* map_filename = new char[30];
	char* weapon_filename = new char[30];
	char* treasure_filename = new char[30];
	char* creature_filename = new char[30];
	int file_num;
	bool noexit = true;
	bool advance = true;

	classmaker* roles[3];

	weapon_filename[0] = 'w';
	weapon_filename[1] = 'e';
	weapon_filename[2] = 'a';
	weapon_filename[3] = '1';
	weapon_filename[4] = 0;

	treasure_filename[0] = 't';
	treasure_filename[1] = 'r';
	treasure_filename[2] = 'e';
	treasure_filename[3] = '1';
	treasure_filename[4] = 0;

	creature_filename[0] = 'c';
	creature_filename[1] = 'r';
	creature_filename[2] = 'e';
	creature_filename[3] = '1';
	creature_filename[4] = 0;


	cout<<"\n\nPlease enter the file you wish to load  (eg  map1 ) : ";
	//cin>>map_filename;
  map_filename = "map1";

	//file_num = (int)map_filename[3];
	//file_num = file_num - 48;


	initscr();
	curs_set(0);
	raw();
	keypad(stdscr, TRUE);
	srand ( time (NULL) );
	refresh();
	start_color();
	noecho();

	windows main;

	do
	{
		for(int x = 0 ;x < 30 ;x++)
		{
			treasures[x] = new treasure;
			creatures[x] = new creature;
			weapons[x] = new weapon;

		}


		lifeformcontrol* lifecontrol = new lifeformcontrol;

		roles[0] = classmakerfactory::create(0,"tre1");
		roles[1] = classmakerfactory::create(1,"wea1");
		roles[2] = classmakerfactory::create(2,"cre1");

		main.create_action_win();
		main.create_map_win();
		main.create_status_win();
		main.create_option_win();

		noexit = lifecontrol->start_map("map1");
    //noexit = true;

		if(noexit)
		{
			lifecontrol->start_visiblemap();

			for(int x = 0 ;x < 3;x++)
			{
				roles[0] -> starter();
				roles[1] -> starter();
				roles[2] -> starter();
			}

			advance = lifecontrol->start_gamecontrol(roles[2]->getvalue());
		}

		file_num++;

		/*map_filename[3] = file_num + '0';
		treasure_filename[3] = file_num + '0';
		creature_filename[3] = file_num + '0';
		weapon_filename[3] = file_num + '0';
*/
		delete lifecontrol;

		main.del_action_win();
		main.del_map_win();
		main.del_status_win();
		main.del_option_win();

		for(int x = 0 ;x < 30 ;x++)
		{
			delete weapons[x];
			delete treasures[x];
			delete creatures[x];


		}

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //todo check comment out
	//}while(noexit == true & advance == true);
  }while(true);

	delete map_filename;
	delete weapon_filename;
	delete treasure_filename;
	delete creature_filename;

	refresh();
	endwin();

	return 0;
}

