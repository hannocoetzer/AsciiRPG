#ifndef _CREATINIT_H_
#define _CREATINIT_H_

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
#include <thread>   // for std::this_thread::sleep_for
#include <chrono>   // for std::chrono::milliseconds


//#include "trecrewea.h"
#include "creaturecreationfactory.h"
#include "classmaker.h"


class creatureinit : public classmaker
{
	public:
		creatureinit(){}
		creatureinit(char*);
		classmaker* clone(char*);
		void starter();
		int getvalue();

	private:

		creaturefactory* factory;
		char* filename;
		char str[20];
		char temp_x[3];
		char temp_y[3];
		char temp_agility[3];
		int creaturecount;
		int pos_x;
		int pos_y;
		int agility;


};


#endif

