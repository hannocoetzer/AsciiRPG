#ifndef _WEAPINIT_H_
#define _WEAPINIT_H_

#include <pthread.h>
#include <ncurses.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <fstream>

#include "weaponcreationfactory.h"
#include "classmaker.h"


class weaponinit : public classmaker
{
	public:
		weaponinit(){}
		weaponinit(char* temp_filename);
		void starter();
		int getvalue(){}		//may be used for future references
		classmaker* clone(char* temp_filename);

	private:
		weaponfactory* factory;
		char* filename;
		char str[20];
		char temp_x[3];
		char temp_y[3];
		int mapweaponcount;
		int pos_x;
		int pos_y;
		int agility;

};


#endif

