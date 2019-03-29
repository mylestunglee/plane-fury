#include "StdAfx.h"
#include "stdlib.h"
#include "Plane.h"
#include "Core.h"

Plane::Plane(void)
{
	//Sets default values to the class
	this->NextBullet = 0;
	this->BulletDamage = 128;
	this->BulletSpeed = Globals::DisplayUnit / 2;
	this->DualGuns = false;
	this->NextGun = false;
	this->RateOfFire = 4;
	this->CoolDown = 0;
	this->Health = 0;
	this->PlaneType = 1;

	//Allocates memory space for the bullets
	this->Bullets = gcnew array<Bullet^>(100);
	//Loops through all the 
	for(int i = 0; i < this->Bullets->Length; i++)
	{
		this->Bullets[i] = gcnew Bullet();
	}
}

void Plane::Fire()
{
	//You can't fire a bullet if your plane is crashed because your gun is distroyed
	if(!(this->Health > 0))
	{
		return;
	}
	
	//Checks whether the plane can fire
	if(this->CoolDown > 0)
	{
		this->CoolDown--;
		return;
	}

	//Gets which direction the plane is firing
	this->Bullets[NextBullet]->Location.X = this->Location.X + (Globals::DisplayUnit / 2);

	//Gun can't be fired until cool down
	this->CoolDown = this->RateOfFire;

	//Sets the bullet's active flag
	this->Bullets[NextBullet]->IsFired = true;
	//Checks whether dual guns are used
	if(DualGuns)
	{
		//Checks which gun is going to be used
		if(NextGun)
		{
			//Sets the bullet according the plane's position
			this->Bullets[NextBullet]->Location.Y = this->Location.Y - (Globals::DisplayUnit / 3);
		} else {
			//Sets the bullet according the plane's position
			this->Bullets[NextBullet]->Location.Y = this->Location.Y + (Globals::DisplayUnit / 3);
		}
		
		NextGun = !NextGun;

	} else {
		//Sets the bullet according the plane's position
		this->Bullets[NextBullet]->Location.Y = this->Location.Y;
	}

	

	//Allows the next bullet to be fired
	NextBullet++;
	//Checks if the next bullet doesn't exist
	if(NextBullet >= 100)
	{
		//Reset the counter to 0
		NextBullet = 0;
	}
}

void Plane::MoveBullets()
{
	//Loops through all the bullets
	for(int i = 0; i < 100; i++)
	{
		//Checks whether the bullet needs to be moved
		if(this->Bullets[i]->IsFired)
		{
			//Check which direction the plane's bullets if firing
			if(this->PlaneType == 0)
				{
				//Moves the bullet to the right by the amount of the BulletSpeed
				Bullets[i]->Location.X += this->BulletSpeed;
				//Checks whether the bullet is out of bounds
				if(Bullets[i]->Location.X > Globals::DisplayGridUnits->Width)
				{
					//Bullet has crashed
					Bullets[i]->IsFired = false;
				}
			} else {
				//Moves the bullet to the right by the amount of the BulletSpeed
				Bullets[i]->Location.X -= this->BulletSpeed;
				//Checks whether the bullet is out of bounds
				if(Bullets[i]->Location.X < 0)
				{
					//Bullet has crashed
					Bullets[i]->IsFired = false;
				}
			}
			//If the plane is the player
			if(this->PlaneType == 0)
			{
				//Loop through all the enemy planes to see if it hits it
				for(int j = 0; j < Globals::Enemies->Length; j++)
				{
					//If the bullet has hit the plane...
					if(this->Bullets[i]->IsInside(Globals::Enemies[j]->getRectangle())
						&& Globals::Enemies[j]->Health > 0 && this->Bullets[i]->IsFired)
					{
						//Damage the plane
						Globals::Enemies[j]->Health -= this->BulletDamage;
						//Checks if the plane crashes
						if(Globals::Enemies[j]->Health <= 0)
						{
							Globals::Enemies[j]->Health = -1;
							//Displays explosion animation of the plane
							Globals::Enemies[j]->ExplosionFrame = 50;

							//If the plane hasn't died yet
							if(Globals::Player->Health > 0)
							{
								Globals::Score+= 3;
							}
							
							//Only make a new pickup item if one isn't been using right now
							if(!Globals::PickupItem->Enabled)
							{
								//1 in 20 change of getting a pick up
								if(rand() % 21 == 1)
								{
								delete Globals::PickupItem;
								Globals::PickupItem = gcnew Pickup;
								
								//Allows a new item to be picked up
								Globals::PickupItem->Enabled = true;
								Globals::PickupItem->Location = Globals::Enemies[j]->Location;
								Globals::PickupItem->RemainingFrame = 50;
								}
							}
						}
						//Distroy the currnet bullet
						this->Bullets[i]->IsFired = false;
					}
				}
			} else {
				//Loops through all the enemies
				for(int j = 0; j < Globals::Enemies->Length; j++)
				{
					if(Globals::Enemies[j]->Bullets[i]->IsInside(Globals::Player->getRectangle())
						&& Globals::Player->Health > 0 && Globals::Enemies[j]->Bullets[i]->IsFired)
					{
						Globals::Player->Health -= this->BulletDamage;
						
						//Checks if the plane has crashed
						if(Globals::Player->Health <= 0)
						{
							playerCrash();
						}						
						//Distroy the current bullet
						this->Bullets[i]->IsFired = false;
					}
				}
			}
		}
	}
}

//Gets the rectangle of the plane
Rectangle Plane::getRectangle()
{
	return Rectangle(this->Location.X - (Globals::DisplayUnit / 2),
		this->Location.Y - (Globals::DisplayUnit / 2),
		Globals::DisplayUnit, Globals::DisplayUnit);
}
