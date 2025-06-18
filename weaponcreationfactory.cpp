#include "weaponcreationfactory.h"

weapon* weaponcreationfactory::makesword(int pos_x,int pos_y)
		{

			return new weapon("Sword","Two bladed sword,useful for close-combat.",3,pos_x,pos_y);
		}
		weapon* weaponcreationfactory::makeflamethrower(int pos_x,int pos_y)
		{
			return new weapon("Flamethrower","Frie the creatures to close you.",4,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makerocketlauncer(int pos_x,int pos_y)
		{
			return new weapon("Rocketlauncher","Advanced weapon for distant attacks.",4,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makesubmachine(int pos_x,int pos_y)
		{
			return new weapon("Sword","Nice,fully automatic, killer.",5,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makeak47(int pos_x,int pos_y)
		{
			return new weapon("AK 47","Machine gun.Most commonly used in South Africa.",5,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makeredeemer(int pos_x,int pos_y)
		{
			return new weapon("Redeemer","New improved version of the Unreal super weapon.",8,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makecannon(int pos_x,int pos_y)
		{

			return new weapon("Cannon","Fire power like you've never experienced.",6,pos_x,pos_y);
		}
		weapon* weaponcreationfactory::makeknife(int pos_x,int pos_y)
		{
			return new weapon("Knife","Portable weapon,used by gangsters.",2,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makepistol(int pos_x,int pos_y)
		{
			return new weapon("Pistol","9mm pistol.Not very useful.",3,pos_x,pos_y);

		}
		weapon* weaponcreationfactory::makesniper(int pos_x,int pos_y)
		{
			return new weapon("Sniper Rifle","Very effective stealth weapon.",7,pos_x,pos_y);

		}

