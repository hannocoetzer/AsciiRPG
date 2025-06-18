#ifndef _MAKE_H_
#define _MAKE_H_

#include "classmaker.h"

class classmakerfactory
{
	public:
		static classmaker* create(int,char*);




	private:
		static classmaker* prototypes[3];

};

#endif

