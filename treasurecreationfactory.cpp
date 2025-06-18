#include "treasurecreationfactory.h"

treasure* treasurecreationfactory::makering(int pos_x,int pos_y)
		{
			return new treasure("Ring","Worn by kings,now it's you're chance.",'$',pos_x,pos_y,9);

		}
		treasure* treasurecreationfactory::makebone(int pos_x,int pos_y)
		{
			return new treasure("Ancient Bone","Used by long time dead cavemen.",'$',pos_x,pos_y,3);

		}
		treasure* treasurecreationfactory::makemedikit(int pos_x,int pos_y)
		{

			return new treasure("MediKit","Civilized means of increasing health.",'$',pos_x,pos_y,5);

		}
		treasure* treasurecreationfactory::makepearl(int pos_x,int pos_y)
		{

			return new treasure("Pearl","Forgot mistery of deep ocean treasures.",'$',pos_x,pos_y,2);

		}
		treasure* treasurecreationfactory::makefish(int pos_x,int pos_y)
		{
			return new treasure("Fish","You can probaly eat this.",'$',pos_x,pos_y,4);


		}
		treasure* treasurecreationfactory::makemoney(int pos_x,int pos_y)
		{

			return new treasure("Money","With this you can by you're way to wealth (and health).",'$',pos_x,pos_y,6);


		}
		treasure* treasurecreationfactory::makegold(int pos_x,int pos_y)
		{

			return new treasure("Gold","May be used for a good cause.",'$',pos_x,pos_y,6);


		}
		treasure* treasurecreationfactory::makesilver(int pos_x,int pos_y)
		{

			return new treasure("Silver","Second best too gold.",'$',pos_x,pos_y,5);


		}
		treasure* treasurecreationfactory::makebronze(int pos_x,int pos_y)
		{


			return new treasure("Bronze","Second best too silver.",'$',pos_x,pos_y,2);


		}
		treasure* treasurecreationfactory::makesupermedikit(int pos_x,int pos_y)
		{

			return new treasure("Super Medikit","A massive increase in health",'$',pos_x,pos_y,12);


		}
		treasure* treasurecreationfactory::maketooth(int pos_x,int pos_y)
		{

			return new treasure("Elephant Tooth","Very useful if barbequed.",'$',pos_x,pos_y,10);


		}
		treasure* treasurecreationfactory::makehair(int pos_x,int pos_y)
		{

			return new treasure("Lion Hair","Don't wear this near male lions",'$',pos_x,pos_y,5);



		}
		treasure* treasurecreationfactory::makecard(int pos_x,int pos_y)
		{

			return new treasure("Credit card","Very,Very useful if you know the pin code.",'$',pos_x,pos_y,7);


		}
		treasure* treasurecreationfactory::makediamond(int pos_x,int pos_y)
		{

			return new treasure("Diamond","Worn by Queen Elizabeth.Worn by you.",'$',pos_x,pos_y,9);


		}
		treasure* treasurecreationfactory::makecrap(int pos_x,int pos_y)
		{

			return new treasure("Crap","Very smelly business.",'$',pos_x,pos_y,2);



		}
		treasure* treasurecreationfactory::makekey(int pos_x,int pos_y)
		{

			return new treasure("key","Very useful for opening doors.",'$',pos_x,pos_y,0);



		}
