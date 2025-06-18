#include <pthread.h>
#include <ncurses.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

#include "windows.h"

void windows::create_action_win()
{

	dummy = newwin(8,130,0,0);
	wborder(dummy, '|', '|', '-', '-','+', '+', '+', '+');
	wmove(dummy,0,7);
	waddstr(dummy,"Action window");
	wrefresh(dummy);

	action_win = newwin(6,128,1,1);
	scrollok(action_win,true);
	idlok(action_win,true);
	wrefresh(action_win);

}
void windows::create_map_win()
{
	dummy = newwin(33,94,8,0);
	wborder(dummy, '|', '|', '-', '-','+', '+', '+', '+');
	wmove(dummy,0,7);
	waddstr(dummy,"Map window");
	wrefresh(dummy);

	map_win = newwin(31,92,9,1);
	wrefresh(map_win);

}
void windows::create_status_win()
{
	dummy = newwin(8,94,41,0);
	wborder(dummy, '|', '|', '-', '-','+', '+', '+', '+');
	wmove(dummy,0,7);
	waddstr(dummy,"Status window");
	wrefresh(dummy);

	status_win = newwin(6,90,42,1);
	scrollok(status_win,true);
	idlok(status_win,true);
	wrefresh(action_win);


}
void windows::create_option_win()
{
	option_win = newwin(6,94,49,0);
	wborder(option_win, '|', '|', '-', '-','+', '+', '+', '+');
	wmove(option_win,0,7);
	waddstr(option_win,"Option window");
	wmove(option_win,2,1);
	waddstr(option_win,"     F1 = Quit  F2 = Weapon of Choice   F3 = Treasure list   F4 = Creatures Killed List");
	wmove(option_win,4,1);
	waddstr(option_win,"              F5 = Hero stats      F6 = Game Mission      F7 = Help  ");
	wrefresh(option_win);

}

void windows::del_action_win()
{

	delwin(action_win);
}
void windows::del_map_win()
{

	delwin(map_win);
}
void windows::del_status_win()
{

	delwin(status_win);
}
void windows::del_option_win()
{

	delwin(option_win);

}

