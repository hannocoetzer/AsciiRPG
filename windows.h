#ifndef _WINDOWS_H_
#define _WINDOWS_H_

#include <pthread.h>
#include <ncurses.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

#include "winvar.h"

class windows
{
	public:
		windows(){}
		void create_action_win();
		void create_map_win();
		void create_status_win();
		void create_option_win();
		void del_action_win();
		void del_map_win();
		void del_status_win();
		void del_option_win();


};



#endif
