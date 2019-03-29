#pragma once

//Allows the use of points
using namespace System::Drawing;

//Makes the class Pickup
ref class Pickup
{
public:
	//Stores the point where the pickup
	Point Location;
	//Stores whether the item is allowed to be picked up
	bool Enabled;
	//Stores the type of Pickup
	int PickupType;
	//Stores how long before the pickup disappears
	int RemainingFrame;

	//Constructor for Pickup
	Pickup(void);
	//Checks whether the item is inside the Pickup
	bool Pickup::IsInside(Rectangle pTest);
	//Preforms the action according to the Pickup type
	void Pickup::Action();
};
