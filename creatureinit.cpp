#include "creatureinit.h"

using namespace std;

creatureinit::creatureinit(char* temp_filename)
{

	filename = temp_filename;

}


classmaker* creatureinit::clone(char* temp_filename)
{

	return new creatureinit(temp_filename);
}

int creatureinit::getvalue()
{


	return creaturecount;
}


void creatureinit::starter()
{
	creaturecount = 0;
	int x = 0;
	char ch;
	int temp_mapweaponcount = 0,temp_treasurecount = 0;
	char* treasure_filename = new char[30];
	char* weapon_filename = new char[30];
	int file_num;

	file_num = (int)filename[3];
	file_num = file_num - 48;

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



	treasure_filename[3] = file_num + '0';
	weapon_filename[3] = file_num + '0';



	if(true)
	{
		ifstream infile("tre1");
		while(infile)
		{


			infile.getline(str,20);
			temp_treasurecount++;
			}
		temp_treasurecount--;
	}

	if(true)
	{
		ifstream infile("wea1");
		while(infile)
		{

			infile.getline(str,20);
			temp_mapweaponcount++;


		}

	}

	factory = new creaturecreationfactory;

	ifstream infile("cre1");

	while(infile)
	{

		//read first 2 characters -> x position of creature
		for(int n = 0;n<=1;n++)
		{
			infile.get(ch);
			temp_x[n] = ch;


		}

		//read second 2 characters -> y position of creature
		for(int n = 0;n<=1;n++)
		{
			infile.get(ch);
			temp_y[n] = ch;


		}



		pos_x = atoi(temp_x);
		pos_y = atoi(temp_y);
		agility = 3;
		int blah = 0;

		infile.getline(str,20);

		if(strcmp(str,"hero") == 0)
		{
			creatures[x] = factory->makehero(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Elf") == 0)
		{
			creatures[x] = factory->makeelf(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Pixie") == 0)
		{
			creatures[x] = factory->makepixie(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Hus") == 0)
		{
			creatures[x] = factory->makehus(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Orc") == 0)
		{
			creatures[x] = factory->makeorc(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Dragon") == 0)
		{
			creatures[x] = factory->makedragon(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Bandit") == 0)
		{
			creatures[x] = factory->makebandit(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Shade") == 0)
		{
			creatures[x] = factory->makeshade(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Kobold") == 0)
		{
			creatures[x] = factory->makekobold(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}
		if(strcmp(str,"Goblin") == 0)
		{
			creatures[x] = factory->makegoblin(pos_x,pos_y,agility,temp_mapweaponcount,temp_treasurecount);
		}



		for(int n = 0;n<20;n++)
		{
			str[n] = 0;

		}


		x++;
	}

	creaturecount = x;

	delete factory;
}


