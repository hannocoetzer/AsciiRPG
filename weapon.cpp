#include "weapon.h"



weapon::weapon(char* temp_name,char* temp_description,int temp_damage,int temp_pos_x,int temp_pos_y)
{
	name = temp_name;
	description = temp_description;
	damage = temp_damage;
	pos_x = temp_pos_x;
	pos_y = temp_pos_y;
}

void weapon::place()
{
	mapchar[pos_y][pos_x] = '(';


}

int weapon::getpos_x()
{

	return pos_x;

}

int weapon::getpos_y()
{

	return pos_y;

}

char* weapon::getname()
{

	return name;

}

int weapon::getdamage()
{

	return damage;

}

