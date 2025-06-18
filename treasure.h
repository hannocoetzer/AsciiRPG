#ifndef _TREASURE_H_
#define _TREASURE_H_

#include <pthread.h>
#include <ncurses.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

#include "mapvar.h"
#include "trecrewea.h"

class treasure
{
	public:
		treasure(){}
		treasure(char*,char*,char,int,int,int);
		void place();
		char* getname();
		char* getdescription();
		int getpos_x();
		int getpos_y();
		int gethitpointincrease();

	private:
		char* name;
		char* description;
		char look;
		int pos_x;
		int pos_y;
		int hitpointincrease;

};


//char mapchar[30][90];
//int visiblemap[30][90];
//int treasuregrid[30][90];

#endif

