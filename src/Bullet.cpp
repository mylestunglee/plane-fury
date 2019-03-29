#include "StdAfx.h"
#include "Bullet.h"

//Constructor for bullet
Bullet::Bullet(void)
{
	this->IsFired = false;
	this->Location = Point(0,0);

}

bool Bullet::IsInside(Rectangle pRectangle)
{
	return (this->Location.X > pRectangle.Left &&
		this->Location.X < pRectangle.Right &&
		this->Location.Y > pRectangle.Top &&
		this->Location.Y < pRectangle.Bottom);
}