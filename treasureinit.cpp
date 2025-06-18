#include "treasureinit.h"

using namespace std;

treasureinit::treasureinit(char* temp_filename)
{



	filename = temp_filename;
}


classmaker* treasureinit::clone(char* temp_filename)
{

	return new treasureinit(temp_filename);
}


void treasureinit::starter()
{
	int x = 0;
	char ch;


	factory = new treasurecreationfactory;

	ifstream infile("tre1");
	while(infile)
	{
		//read first 2 characters -> x position of treasure
		for(int n = 0;n<=1;n++)
		{
			infile.get(ch);
			temp_x[n] = ch;


		}

		//read second 2 characters -> y position of treasure
		for(int n = 0;n<=1;n++)
		{
			infile.get(ch);
			temp_y[n] = ch;


		}

		pos_x = atoi(temp_x);
		pos_y = atoi(temp_y);

		infile.getline(str,20);

		if(strcmp(str,"ring") == 0)
		{
			treasures[x] = factory->makering(pos_x,pos_y);

		}
		if(strcmp(str,"bone") == 0)
		{
			treasures[x] = factory->makebone(pos_x,pos_y);

		}
		if(strcmp(str,"money") == 0)
		{
			treasures[x] = factory->makemoney(pos_x,pos_y);

		}
		if(strcmp(str,"gold") == 0)
		{
			treasures[x] = factory->makegold(pos_x,pos_y);

		}
		if(strcmp(str,"silver") == 0)
		{
			treasures[x] = factory->makesilver(pos_x,pos_y);

		}
		if(strcmp(str,"bronze") == 0)
		{
			treasures[x] = factory->makebronze(pos_x,pos_y);

		}
		if(strcmp(str,"fish") == 0)
		{
			treasures[x] = factory->makefish(pos_x,pos_y);

		}
		if(strcmp(str,"diamond") == 0)
		{
			treasures[x] = factory->makediamond(pos_x,pos_y);

		}
		if(strcmp(str,"hair") == 0)
		{
			treasures[x] = factory->makehair(pos_x,pos_y);

		}
		if(strcmp(str,"tooth") == 0)
		{
			treasures[x] = factory->maketooth(pos_x,pos_y);

		}
		if(strcmp(str,"medikit") == 0)
		{
			treasures[x] = factory->makemedikit(pos_x,pos_y);

		}
		if(strcmp(str,"supermedikit") == 0)
		{
			treasures[x] = factory->makesupermedikit(pos_x,pos_y);

		}
		if(strcmp(str,"crap") == 0)
		{
			treasures[x] = factory->makecrap(pos_x,pos_y);

		}
		if(strcmp(str,"pearl") == 0)
		{
			treasures[x] = factory->makepearl(pos_x,pos_y);

		}
		if(strcmp(str,"hair") == 0)
		{
			treasures[x] = factory->makehair(pos_x,pos_y);

		}
		if(strcmp(str,"card") == 0)
		{
			treasures[x] = factory->makecard(pos_x,pos_y);

		}
		if(strcmp(str,"key") == 0)
		{
			treasures[x] = factory->makekey(pos_x,pos_y);

		}



		for(int n = 0;n<20;n++)
		{
			str[n] = 0;

		}

		x++;
	}

	treasurecount = x - 1;
	for(int n = 0;n< x - 1;n++)
	{

		treasures[n]->place();

	}
	delete factory;

}

