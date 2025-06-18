#ifndef _CREATUREF_H_
#define _CREATUREF_H_

#include "creature.h"

class creaturefactory
{
	public:
		virtual creature* makehero(int,int,int,int,int) = 0;
		virtual creature* makeelf(int,int,int,int,int) = 0;
		virtual creature* makepixie(int,int,int,int,int) = 0;
		virtual creature* makehus(int,int,int,int,int) = 0;
		virtual creature* makeorc(int,int,int,int,int) = 0;
		virtual creature* makegoblin(int,int,int,int,int) = 0;
		virtual creature* makedragon(int,int,int,int,int) = 0;
		virtual creature* makebandit(int,int,int,int,int) = 0;
		virtual creature* makeshade(int,int,int,int,int) = 0;
		virtual creature* makekobold(int,int,int,int,int) = 0;

};


#endif

