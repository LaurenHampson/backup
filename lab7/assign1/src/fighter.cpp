
#include "fighter.h"

using namespace std;


	Fighter::Fighter(string name) : Player(name)
	{
		//do nothing
	}

	void  Fighter:: doAction(Player *target)
	{
		target->setHP(target->getHP()-75);
	}


