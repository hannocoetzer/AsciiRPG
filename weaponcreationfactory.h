#ifndef _WEAPONCREATION_H_
#define _WEAPONCREATION_H_

#include "weaponfactory.h"

class weaponcreationfactory : public weaponfactory
{
		public:
		weaponcreationfactory(){}
		weapon* makesword(int pos_x,int pos_y);
		weapon* makeflamethrower(int pos_x,int pos_y);
		weapon* makerocketlauncer(int pos_x,int pos_y);
		weapon* makesubmachine(int pos_x,int pos_y);
		weapon* makeak47(int pos_x,int pos_y);
		weapon* makeredeemer(int pos_x,int pos_y);
		weapon* makecannon(int pos_x,int pos_y);
		weapon* makeknife(int pos_x,int pos_y);
		weapon* makepistol(int pos_x,int pos_y);
		weapon* makesniper(int pos_x,int pos_y);


};

#endif
