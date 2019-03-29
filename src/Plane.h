#pragma once
#include "stdafx.h"
#include "Bullet.h"

//Allows the use of point
using namespace System::Drawing;

public ref class Plane
{
	public:
		//Stores the data for projectiles
		array<Bullet^>^Bullets;
		//Stores bullet damage. Health taken off when hit plane
		int BulletDamage;
		//Stores how fast the bullet moves
		int BulletSpeed;
		//Stores whether there is two firing points
		bool DualGuns;
		//Stores whether the top or bottom gun is used - not used if DualGuns = false
		bool NextGun;
		//Stores the rate of fire
		int RateOfFire;
		//Stores how much health the plane has
		int Health;
		//Store which type of plane this is
		int PlaneType;
		//Stores where the plane is
		Point Location;

		//Stores the frame index for the plane's explosion
		int ExplosionFrame;

		//Constructor for Plane Class
		Plane(void);
		//Fires a bullet
		void Plane::Fire();
		//Moves all fired bullets
		void Plane::MoveBullets();
		//Gets the rectangle for the plane
		Rectangle Plane::getRectangle();
		//Stores the current cool down
		int CoolDown;
	private:
		//Keeps an index if which bullet hasn't been fired
		int NextBullet;

};
