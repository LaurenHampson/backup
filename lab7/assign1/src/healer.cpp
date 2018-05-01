#include "healer.h"
using namespace std;
	Healer::Healer(string name) : Player(name)
	{
		// do nothing
	}

	void Healer::doAction(Player *target)
	{
		if ((target->getHP()+75)>=target->getMaxHP())
		{
			target->setHP(target->getMaxHP());
		}
		else
		{
			target->setHP(target->getHP()+75);
		}
	}
