#ifndef _WEAPON_H_
#define _WEAPON_H_

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

class weapon
{
	public:
		weapon(){}
		weapon(char*,char*,int,int,int);
		void place();
		int getpos_x();
		int getpos_y();
		char* getname();
		int getdamage();


	private:
		char* name;
		char* description;
		int damage;
		int pos_x;
		int pos_y;


};

//char mapchar[30][90];
//int visiblemap[30][90];
//int treasuregrid[30][90];

#endif

