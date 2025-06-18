#ifndef _CLASSMAKER_H_
#define _CLASSMAKER_H_

class classmaker
{
	public:

		virtual classmaker* clone(char*) = 0;
		virtual void starter() = 0;
		virtual int getvalue() = 0;

	private:


};


#endif

