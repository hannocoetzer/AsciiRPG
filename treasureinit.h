#ifndef _TREASINIT_H_
#define _TREASINIT_H_

#include <pthread.h>
#include <ncurses.h>
#include <ctime>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

#include "treasurecreationfactory.h"
#include "classmaker.h"
#include "trecrewea.h"

using namespace std;

class treasureinit : public classmaker
{
	public:
		treasureinit(){}
		treasureinit(char* temp_filename);
		void starter();
		int getvalue(){}	//may be used for future references
		classmaker* clone(char* temp_filename);

	private:

		treasurefactory* factory;
		char* filename;
		char str[20];
		char temp_x[3];
		char temp_y[3];
		int treasurecount;
		int pos_x;
		int pos_y;

};


#endif

