#ifndef _CREATURE_H_
#define _CREATURE_H_

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
#include <thread>
#include <chrono>

#include "mapvar.h"


#include "windows.h"
#include "weapon.h"
#include "treasure.h"
#include "trecrewea.h"



class creature
{
	public:
		creature(){}

		creature(int,int,bool,char,bool,int,int,int,char*,int,int,char*,int,char*,int,int,int,int);
		~creature();
		void run();
		void precleanup();
		void draw();
		void redraw();
		void borderverify();		//this check that the hero and creatures don't go of the border
		void pathverify();		//this check that the hero and creatures don;t walk where they not supose to
		void treasureverify();		//this check if there is treatures lying around
		void weaponverify();		//this check if there is weapons lying around
		void keyverify();
		void doorverify();
		void randomitemverify();	//this check for adational stuff such as blackholes,teleports etc
		void revealarea();
		void directionrandomizer();
		void movement();
		void findhero();
		void weaponchooser();
		void herodetail();
		void itemlist();
		void killlist();
		void mission();
		void help();
		void charcoloron(int,int);
		void charcoloroff(int,int);
		bool question(char*);
		void colorcheck();
		static int gettotal();
		static int getweaponcount();
		int getpos_x();
		int getpos_y();
		bool getalive();
		bool getadvance();
		char* getname();
		char* getweaponname();
		void setweapon(char*,int);
		int getweapondamage();
		int gethitpoints();
		void sethitpoints(int temp_hitpoints);
		void kill();
		void addweapon(char* temp_weaponname,int temp_weapondamage);
		void additem(char* temp_item);
		void addkilllist(char* temp_creaturename);
		int getagility();
		static int total;

	private:
		char* creaturekill_array[20];
		char* weaponname_array[20];
		int weapondamage_array[20];
		char* itemname_array[20];
		static int weaponcount;
		int itemcount;
		int hero_pos_x;			//Hero x position. This is used by the creatures for finding the hero
		int hero_pos_y;			//Hero x position. This is used by the creatures for finding the hero
		int win_x1;			//Set the moveable area of ALL creatures
		int win_x2;			//Set the moveable area of ALL creatures
		int win_y1;			//Set the moveable area of ALL creatures
		int win_y2;			//Set the moveable area of ALL creatures
		int pos_x;			//All creatures current x position
		int pos_y;			//All creatures current y position
		int pre_x;			//All creatures previous x position
		int pre_y;			//All creatures previous y position
		bool hero;			//Specify if the creature is a enemy or not
		char look;			//Specify how the creature will look
		int speed;			//speed(Delay in miliseconds, before next movement
		int hitpoints;			//strength of the creature
		char* weaponname;		//selected weapon name
		int weapondamage;		//selected weapon damage
		char* name;			//creature name
		bool alive;			//this is to specify if the creature have been killed
		bool suspend;			//if set, will causes that the creature won't terminate but remain inactive
		int direction;			//save direction of hero and enemy
		bool ai;			//specify if the creature has Articial Inteligence or not
		bool exitstate;			//set thread exit state
		bool keystatus;			//set the key state to false at initialization(the hero have to pick the key up)
		int killcount;			//keep track of creature frag count
		int sight;			//how far the creature can see
		int agility;			//agility of creature
		int mapweaponcount;		//wepons on the map available to the hero and creature
		int treasurecount;		//number of treasures on the map
		int treasureremain;		//number of treasures remaining
		char* color;			//creature colour
		bool advance;			//should the hero advance to the next level


};


//char mapchar[30][90];
//int visiblemap[30][90];
//int treasuregrid[30][90];


#endif 

