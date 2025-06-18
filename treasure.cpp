#include "treasure.h"


void treasure::place()
{
	mapchar[pos_y][pos_x] = look;
	treasuregrid[pos_y][pos_x] = 5;		//indication that there is a treasure

}

char* treasure::getname()
{

	return name;
}

char* treasure::getdescription()
{

	return description;
}


int treasure::getpos_x()
{


	return pos_x;

}

int treasure::getpos_y()
{

	return pos_y;

}

int treasure::gethitpointincrease()
{


	return hitpointincrease;

}

treasure::treasure(char* temp_name,char* temp_description,char temp_look,int temp_pos_x,int temp_pos_y,int temp_hitpointincrease)
{
	name = temp_name;
	description = temp_description;
	look = temp_look;
	pos_x = temp_pos_x;
	pos_y = temp_pos_y;
	hitpointincrease = temp_hitpointincrease;

}

