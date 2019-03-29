#pragma once

//Allows the use of point
using namespace System::Drawing;

public ref class Bullet
{
public:
	bool IsFired;
	Point Location;
	//Constructor for bullet
	Bullet(void);
	//Checks whether the bullet is insde a rectangle
	bool Bullet::IsInside(Rectangle pRectangle);
};
