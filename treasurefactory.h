#ifndef _TREASUREFACTORY_H_
#define _TREASUREFACTORY_H_
#include "treasure.h"

class treasurefactory
{
	public:
		virtual treasure* makering(int,int) = 0;
		virtual treasure* makebone(int,int) = 0;
		virtual treasure* makemedikit(int,int) = 0;
		virtual treasure* makepearl(int,int) = 0;
		virtual treasure* makefish(int,int) = 0;
		virtual treasure* makemoney(int,int) = 0;
		virtual treasure* makegold(int,int) = 0;
		virtual treasure* makesilver(int,int) = 0;
		virtual treasure* makebronze(int,int) = 0;
		virtual treasure* makesupermedikit(int,int) = 0;
		virtual treasure* maketooth(int,int) = 0;
		virtual treasure* makehair(int,int) = 0;
		virtual treasure* makecard(int,int) = 0;
		virtual treasure* makediamond(int,int) = 0;
		virtual treasure* makecrap(int,int) = 0;
		virtual treasure* makekey(int,int) = 0;




};

#endif

