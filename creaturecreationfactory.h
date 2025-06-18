#ifndef _CREATURECREATION_H_
#define _CREATURECREATION_H_

#include "creaturefactory.h"

class creaturecreationfactory : public creaturefactory
{
	public:
		creaturecreationfactory(){}

		creature* makehero(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makeelf(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makepixie(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makehus(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makeorc(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makegoblin(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makedragon(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makebandit(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makeshade(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);
		creature* makekobold(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount);

	private:



};

#endif

