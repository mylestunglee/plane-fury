#include "StdAfx.h"
#include "Pickup.h"
#include "Core.h"

//Allows the use of rand()
#include <stdlib.h>

//Constructor for Pickup class
Pickup::Pickup(void)
{
	this->Location = System::Drawing::Point(0,0);
	this->Enabled = false;
	this->PickupType = rand() % 3;
	this->RemainingFrame = 0;
}

//Checks whether the item is inside the Pickup
bool Pickup::IsInside(Rectangle pTest)
{
	return pTest.IntersectsWith(Rectangle(
		this->Location.X - (Globals::DisplayUnit / 2),
		this->Location.Y - (Globals::DisplayUnit / 2),
		Globals::DisplayUnit,
		Globals::DisplayUnit));
}
//Preforms the action according to the Pickup type
void Pickup::Action()
{
	///Checks which type of pick up this is
	switch(this->PickupType)
	{
	case 0: //Health
		if(Globals::IsPlayingLeveledGame)
		{
			Globals::Player->Health = Globals::gMaxHealth;
		} else {
			Globals::Player->Health = Globals::MaxHealth;
		}
		break;
	case 1: //Speed
		if(Globals::Player->BulletSpeed >= Globals::DisplayUnit)
		{
			//If the bullet speed is too fast, the bullet collision detection is broken
			return;
		}
		Globals::Player->BulletSpeed += Globals::DisplayUnit / 10;
		break;
	case 2: //Damage
		if(Globals::Player->BulletDamage >= Globals::MaxHealth)
		{
			//There's no point if the damage is too high
			return;
		}
		Globals::Player->BulletDamage *= 2;
		break;
	}
}