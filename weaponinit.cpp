#include "weaponinit.h"

using namespace std;

weaponinit::weaponinit(char* temp_filename)
{


	filename = temp_filename;
}


void weaponinit::starter()
{
	int x = 0;
	char ch;

	factory = new weaponcreationfactory;

	ifstream infile(filename);
	while(infile)
	{

		//read first 2 characters -> x position of weapon
		for(int n = 0;n<=1;n++)
		{
			infile.get(ch);
			temp_x[n] = ch;


		}

		//read second 2 characters -> y position of weapon
		for(int n = 0;n<=1;n++)
		{
			infile.get(ch);
			temp_y[n] = ch;


		}

		pos_x = atoi(temp_x);
		pos_y = atoi(temp_y);


		infile.getline(str,20);

		if(strcmp(str,"sword") == 0)
		{
			weapons[x] = factory->makesword(pos_x,pos_y);
		}
		if(strcmp(str,"flamethrower") == 0)
		{
			weapons[x] = factory->makeflamethrower(pos_x,pos_y);
		}
		if(strcmp(str,"rocketlauncher") == 0)
		{
			weapons[x] = factory->makerocketlauncer(pos_x,pos_y);
		}
		if(strcmp(str,"ak47") == 0)
		{
			weapons[x] = factory->makeak47(pos_x,pos_y);
		}
		if(strcmp(str,"redeemer") == 0)
		{
			weapons[x] = factory->makeredeemer(pos_x,pos_y);
		}
		if(strcmp(str,"cannon") == 0)
		{
			weapons[x] = factory->makecannon(pos_x,pos_y);
		}
		if(strcmp(str,"knife") == 0)
		{
			weapons[x] = factory->makeknife(pos_x,pos_y);
		}
		if(strcmp(str,"pistol") == 0)
		{
			weapons[x] = factory->makepistol(pos_x,pos_y);
		}

		if(strcmp(str,"sniper") == 0)
		{
			weapons[x] = factory->makesniper(pos_x,pos_y);
		}

		for(int n = 0;n<20;n++)
		{
			str[n] = 0;

		}


		x++;
	}

	mapweaponcount = x - 1;
	for(int n = 0;n< x - 1;n++)
	{

		weapons[n]->place();

	}

	delete factory;
}

classmaker* weaponinit::clone(char* temp_filename)
{

	return new weaponinit(temp_filename);
}

