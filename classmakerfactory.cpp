#include "classmakerfactory.h"

classmaker* classmakerfactory::create(int x,char* temp_filename)
{
	return prototypes[x]->clone(temp_filename);

}
