#include "creaturecreationfactory.h"

creature* creaturecreationfactory::makehero(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{

			return new creature(pos_x,pos_y,true,'X',false,20,40,40,"white",mapweaponcount,
											treasurecount,"Fist",2,"Hero",0,0,89,29);

		}
		creature* creaturecreationfactory::makeelf(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'E',true,2000,10,25,"green",mapweaponcount,
											treasurecount,"Longsword",1,"Elf",0,0,89,29);

		}
		creature* creaturecreationfactory::makepixie(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'P',true,2000,9,50,"yellow",mapweaponcount,
											treasurecount,"Stiletto",1,"Pixie",0,0,89,29);

		}
		creature* creaturecreationfactory::makehus(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{

			return new creature(pos_x,pos_y,false,'H',true,2000,20,30,"cyan",mapweaponcount,
											treasurecount,"Iets",1,"Hus",0,0,89,29);


		}
		creature* creaturecreationfactory::makeorc(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'O',false,2000,10,15,"brown",mapweaponcount,
											treasurecount,"Crude axe",1,"Orc",0,0,89,29);


		}
		creature* creaturecreationfactory::makegoblin(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'G',false,2000,9,15,"blue",mapweaponcount,
											treasurecount,"Spear",1,"Goblin",0,0,89,29);


		}
		creature* creaturecreationfactory::makedragon(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{

			return new creature(pos_x,pos_y,false,'D',true,2000,150,5,"red",mapweaponcount,
											treasurecount,"Flamer",1,"Dragon",0,0,89,29);


		}
		creature* creaturecreationfactory::makebandit(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'B',true,2000,9,17,"green",mapweaponcount,
											treasurecount,"Broadsword",1,"Bandit",0,0,89,29);



		}
		creature* creaturecreationfactory::makeshade(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'S',true,2000,12,23,"black",mapweaponcount,
											treasurecount,"Talon",1,"Shade",0,0,89,29);



		}
		creature* creaturecreationfactory::makekobold(int pos_x,int pos_y,int agility,int mapweaponcount,int treasurecount)
		{
			return new creature(pos_x,pos_y,false,'K',false,2000,9,15,"yellow",mapweaponcount,
											treasurecount,"Shortsword",1,"Kobold",0,0,89,29);



		}


