#ifndef _TREASEURECREATION_H_
#define _TREASEURECREATION_H_

#include "treasurefactory.h"

class treasurecreationfactory : public treasurefactory
{
	public:
		treasure* makering(int pos_x,int pos_y);
		treasure* makebone(int pos_x,int pos_y);
		treasure* makemedikit(int pos_x,int pos_y);
		treasure* makepearl(int pos_x,int pos_y);
		treasure* makefish(int pos_x,int pos_y);
		treasure* makemoney(int pos_x,int pos_y);
		treasure* makegold(int pos_x,int pos_y);
		treasure* makesilver(int pos_x,int pos_y);
		treasure* makebronze(int pos_x,int pos_y);
		treasure* makesupermedikit(int pos_x,int pos_y);
		treasure* maketooth(int pos_x,int pos_y);
		treasure* makehair(int pos_x,int pos_y);
		treasure* makecard(int pos_x,int pos_y);
		treasure* makediamond(int pos_x,int pos_y);
		treasure* makecrap(int pos_x,int pos_y);
		treasure* makekey(int pos_x,int pos_y);
};

#endif

