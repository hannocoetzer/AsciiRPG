#ifndef _WEAPONF_H_
#define _WEAPONF_H_

#include "weapon.h"

class weaponfactory
{
	public:
		virtual weapon* makesword(int,int) = 0;
		virtual weapon* makeflamethrower(int,int) = 0;
		virtual weapon* makerocketlauncer(int,int) = 0;
		virtual weapon* makesubmachine(int,int) = 0;
		virtual weapon* makeak47(int,int) = 0;
		virtual weapon* makeredeemer(int,int) = 0;
		virtual weapon* makecannon(int,int) = 0;
		virtual weapon* makeknife(int,int) = 0;
		virtual weapon* makepistol(int,int) = 0;
		virtual weapon* makesniper(int,int) = 0;


};

#endif

