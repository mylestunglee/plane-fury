#include "stdafx.h"
#include "Graphics.h"
#include "Core.h"
#include "frmMain.h"

//Allows the type Bitmap to be used
using namespace System::Drawing;

using namespace PlaneFury;

//Draws the main display
Bitmap^ drawDisplay(Size pDisplaySize)
{
	//Makes a temp bitmap to draw all the graphics on. This allows the use of
	//double buffering to reduce flickering of the display
	delete Globals::Canvas;
	Globals::Canvas = gcnew Bitmap(pDisplaySize.Width, pDisplaySize.Height);
	//Defines Paint which will be used in drawing images
	Graphics^ Paint = Graphics::FromImage(Globals::Canvas);
	//Make the drawing slightly faster by no anti-alising
	Paint->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	//Smooths the text
	Paint->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias;
	
	Paint->Clear(Globals::cBackground);

	drawStars(Paint, pDisplaySize);

	drawPickup(Paint, pDisplaySize);

	//Draws the player's bullets
	
	drawEnemiesBullets(Paint, pDisplaySize);
	drawEnemies(Paint, pDisplaySize);

	drawPlayerBullets(Paint, pDisplaySize);
	drawPlayer(Paint, pDisplaySize);

	drawGradient(Paint, pDisplaySize);

	drawText(Paint, pDisplaySize);
	
	if(Globals::IsPlayerCrashed)
	{
		drawGameOver(Paint, pDisplaySize);
	}

	drawHealth(Paint, pDisplaySize);
	
	//Frees the memory - prevents a memory leak
	delete Paint;

	return Globals::Canvas;
}

//Draws the player
void drawPlayer(Graphics^ pPaint, Size pDisplaySize)
{
	if(Globals::Player->Health > 0)
	{
		//The filled colour
		SolidBrush^ brsFront = gcnew SolidBrush(Color::FromArgb(128, Globals::cPlayer));
		//The border
		Pen^ penFront = gcnew Pen(Color::FromArgb(
			(Globals::Player->Health / (float)Globals::MaxHealth) * 255, Globals::cPlayer),2);

		//Makes the bounds of drawing
		Rectangle rctPlane = Rectangle(Rectangle((float(Globals::Player->Location.X - 500) / 
			Globals::DisplayGridUnits->Width) * pDisplaySize.Width, 
			(float(Globals::Player->Location.Y - 500) / 
			Globals::DisplayGridUnits->Height) * pDisplaySize.Height, 
			1 / float(Globals::DisplayGrid->Width) * pDisplaySize.Width, 
			1 / float(Globals::DisplayGrid->Height) * pDisplaySize.Height));

		pPaint->FillRectangle(brsFront, rctPlane);

		pPaint->DrawRectangle(penFront, rctPlane);

		delete brsFront;
		delete penFront;
	} else if(Globals::Player->ExplosionFrame > 0)
	{
		//This line calculates the amount of movement
		int Change = Math::Pow(2.5,(50 - Globals::Player->ExplosionFrame) / (float)10) * 50;

		//The filled colour
		SolidBrush^ brsFront = gcnew SolidBrush(
			Color::FromArgb(128 * (Globals::Player->ExplosionFrame / (float)50), Globals::cPlayer));

		//Loops through all the broken segments
		for(int x = -2; x < 3; x++)
		{
			for(int y = -2; y < 3; y++)
			{
				pPaint->FillRectangle(brsFront,
					(float(Globals::Player->Location.X + (x * Change) + (200 * x)) / 
					Globals::DisplayGridUnits->Width) * pDisplaySize.Width, 
					(float(Globals::Player->Location.Y + (y * Change) + (200 * y)) / 
					Globals::DisplayGridUnits->Height) * pDisplaySize.Height, 
					0.2 / float(Globals::DisplayGrid->Width) * pDisplaySize.Width, 
					0.2 / float(Globals::DisplayGrid->Height) * pDisplaySize.Height);
			}
		}
		//Decrease the counter for the explosion
		Globals::Player->ExplosionFrame--;
		//Check whether the explosion animation has finished
		if(Globals::Player->ExplosionFrame == 0)
		{
			//Plane has now fully crashed
			Globals::Player->Health = 0;
		}
		delete brsFront;
	}
}

//Draws all the bullets for a plane
void drawPlayerBullets(Graphics^ pPaint, Size pDisplaySize)
{
	//Makes a new pen
	Pen^ penFront = gcnew Pen(Globals::cPlayer, System::Math::Log(Globals::Player->BulletDamage / (float)125,2));
	//Loops through all the different bullets
	for(int i = 0; i < Globals::Player->Bullets->Length; i++)
	{
		if(Globals::Player->Bullets[i]->IsFired)
		{
			//Draws the line of the bullet
			pPaint->DrawLine(penFront,
				((Globals::Player->Bullets[i]->Location.X - Globals::Player->BulletSpeed) / (float)Globals::DisplayGridUnits->Width) * pDisplaySize.Width,
				(Globals::Player->Bullets[i]->Location.Y / (float)Globals::DisplayGridUnits->Height) * pDisplaySize.Height,
				(Globals::Player->Bullets[i]->Location.X / (float)Globals::DisplayGridUnits->Width) * pDisplaySize.Width,
				(Globals::Player->Bullets[i]->Location.Y / (float)Globals::DisplayGridUnits->Height) * pDisplaySize.Height);
		}
	}
	//Frees memory
	delete penFront;
}

//Draws the stars
void drawStars(Graphics^ pPaint, Size pDisplaySize)
{
	//Loops through all the stars
	for(int i = 0; i < Globals::StarLocations->Length; i++)
	{
		//Makes a new pen
		Pen^ penFront = gcnew Pen(Color::FromArgb(Globals::StarAlpha[i] / 2, Globals::cMisc));
		//Draws the line
		pPaint->DrawLine(penFront,
			((Globals::StarLocations[i]->X - Globals::ScrollingSpeed) / (float)Globals::DisplayGridUnits->Width) * pDisplaySize.Width,
			(Globals::StarLocations[i]->Y / (float)Globals::DisplayGridUnits->Height) * pDisplaySize.Height,
			(Globals::StarLocations[i]->X / (float)Globals::DisplayGridUnits->Width) * pDisplaySize.Width,
			(Globals::StarLocations[i]->Y / (float)Globals::DisplayGridUnits->Height) * pDisplaySize.Height);
		//Clears the memory
		delete penFront;
	}
}
//Draws the enemies
void drawEnemies(Graphics^ pPaint, Size pDisplaySize)
{
	//Loops through all the enemies
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		//The plane colour
		Color PlaneColour;

		//Sets the plane depending on its type
		switch(Globals::Enemies[i]->PlaneType)
		{
		case 1:
			PlaneColour = Globals::cSprayer;
			break;
		case 2:
			PlaneColour = Globals::cSmasher;
			break;
		case 3:
			PlaneColour = Globals::cStriker;
			break;
		}

		//Draws the enemies if the health is more than zero
		if(Globals::Enemies[i]->Health > 0)
		{
			//The filled colour
			SolidBrush^ brsFront = gcnew SolidBrush(Color::FromArgb(128, PlaneColour));
			//The border
			Pen^ penFront = gcnew Pen(Color::FromArgb(
				(Globals::Enemies[i]->Health / (float)Globals::MaxHealth) * 255, PlaneColour), 2);

			//Makes the bounds of drawing
			Rectangle rctPlane = Rectangle(Rectangle(
				(float(Globals::Enemies[i]->Location.X - 500) / 
				Globals::DisplayGridUnits->Width) * pDisplaySize.Width, 
				(float(Globals::Enemies[i]->Location.Y - 500) / 
				Globals::DisplayGridUnits->Height) * pDisplaySize.Height, 
				1 / float(Globals::DisplayGrid->Width) * pDisplaySize.Width, 
				1 / float(Globals::DisplayGrid->Height) * pDisplaySize.Height));

			pPaint->FillRectangle(brsFront, rctPlane);
			pPaint->DrawRectangle(penFront, rctPlane);

			delete brsFront;
			delete penFront;

		} else if(Globals::Enemies[i]->ExplosionFrame > 0)
		{
			//This line calculates the amount of movement
			int Change = Math::Pow(3,(50 - Globals::Enemies[i]->ExplosionFrame) / (float)10) * 50;

			//The filled colour
			SolidBrush^ brsFront = gcnew SolidBrush(
				Color::FromArgb(128 * (Globals::Enemies[i]->ExplosionFrame / (float)50),  PlaneColour));

			//Loops through all the broken segments
			for(int x = -2; x < 3; x++)
			{
				for(int y = -2; y < 3; y++)
				{
					//Draws the segment
					pPaint->FillRectangle(brsFront,
						(float(Globals::Enemies[i]->Location.X + (x * Change) + (200 * x)) / 
						Globals::DisplayGridUnits->Width) * pDisplaySize.Width, 
						(float(Globals::Enemies[i]->Location.Y + (y * Change) + (200 * y)) / 
						Globals::DisplayGridUnits->Height) * pDisplaySize.Height, 
						0.2 / float(Globals::DisplayGrid->Width) * pDisplaySize.Width, 
						0.2 / float(Globals::DisplayGrid->Height) * pDisplaySize.Height);
				}
			}
			//Clears the memory
			delete brsFront;
		}
	}
}
//Draws the enemies' bullets
void drawEnemiesBullets(Graphics^ pPaint, Size pDisplaySize)
{
	//Loops through all the enemies
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		//The plane colour
		Color PlaneColour;

		//Sets the plane depending on its type
		switch(Globals::Enemies[i]->PlaneType)
		{
		case 1:
			PlaneColour = Globals::cSprayer;
			break;
		case 2:
			PlaneColour = Globals::cSmasher;
			break;
		case 3:
			PlaneColour = Globals::cStriker;
			break;
		}		
		//The border
		Pen^ penFront;
		
		//Checks the score and sets the pen's thickness according to the score
		if(Globals::Score < 200)
		{
			penFront = gcnew Pen(PlaneColour, 1);
		} else if(Globals::Score < 400)
		{
			penFront = gcnew Pen(PlaneColour, 3);
		} else
		{
			penFront = gcnew Pen(PlaneColour, 5);
		}

		//Loops through all the different bullets
		for(int j = 0; j < Globals::Enemies[i]->Bullets->Length; j++)
		{
			//Only draw bullets which have been fired
			if(Globals::Enemies[i]->Bullets[j]->IsFired)
			{
				//Draws the line of the bullet
				pPaint->DrawLine(penFront,
				((Globals::Enemies[i]->Bullets[j]->Location.X + Globals::Enemies[i]->BulletSpeed) / (float)Globals::DisplayGridUnits->Width) * pDisplaySize.Width,
				(Globals::Enemies[i]->Bullets[j]->Location.Y / (float)Globals::DisplayGridUnits->Height) * pDisplaySize.Height,
				(Globals::Enemies[i]->Bullets[j]->Location.X / (float)Globals::DisplayGridUnits->Width) * pDisplaySize.Width,
				(Globals::Enemies[i]->Bullets[j]->Location.Y / (float)Globals::DisplayGridUnits->Height) * pDisplaySize.Height);
			}
		}
		//Clears memory
		delete penFront;
	}
}


//Draws the score on the screen
void drawText(Graphics^ pPaint, Size pDisplaySize)
{
	//Stores the text for the score
	String^ strScore;
	//Checks whether the game is leveled
	if(Globals::IsPlayingLeveledGame)
	{
		strScore = Convert::ToString(Globals::Score + "/" + (Globals::gLevelsCompleted + 1) * 40);
	} else {
		strScore = Convert::ToString(Globals::Score);
	}
	//The brush used to draw the text
	Brush^ brsFront = gcnew SolidBrush(Globals::cMisc);
	//Stores the font
	Font^ fntScore = gcnew System::Drawing::Font("Arial", 
		((pDisplaySize.Width > pDisplaySize.Height) ? pDisplaySize.Height : pDisplaySize.Width) / 10);
	//Draws the string on the bottom-left of the screen.
	pPaint->DrawString(strScore, fntScore, brsFront, 0,
		pDisplaySize.Height - pPaint->MeasureString(strScore, fntScore).Height);
	//Clears memory
	delete fntScore;
	delete brsFront;
}
//Draws the gameover if needed to
void drawGameOver(Graphics^ pPaint, Size pDisplaySize)
{
	//Stores the text for the score
	String^ strScore;
	//Checks which message should be displayed
	strScore = "Game Over";
	//Stores the font
	Font^ fntScore = gcnew System::Drawing::Font("Arial", 
		((pDisplaySize.Width > pDisplaySize.Height) ? pDisplaySize.Height : pDisplaySize.Width) / 8);
	//Makes a new brush for the filling
	SolidBrush^ brsFront = gcnew SolidBrush(Color::FromArgb(
		(50 - Globals::Player->ExplosionFrame) / (float)50 * 255, Globals::cMisc));
	//Draws the string on the bottom-left of the screen.
	pPaint->DrawString(strScore, fntScore, brsFront, 
		(pDisplaySize.Width / 2) - (pPaint->MeasureString(strScore, fntScore).Width / 2),
		(pDisplaySize.Height / 2) - (pPaint->MeasureString(strScore, fntScore).Height / 2));
	//Clears the memory
	delete fntScore;
	delete brsFront;

}
//Draws the amount of health on the screen
void drawHealth(Graphics^ pPaint, Size pDisplaySize)
{
	//Stores where the health bar will be
	Rectangle rctHealth = Rectangle(
		pDisplaySize.Width * 0.5,
		pDisplaySize.Height * 0.90,
		pDisplaySize.Width * 0.45,
		pDisplaySize.Height * 0.05);
	
	//Makes a new brush for the filling
	SolidBrush^ brsFront;
	Pen^ penFront = gcnew Pen(Globals::cMisc);

	if(Globals::Player->Health >= 1000)
	{
		brsFront = gcnew SolidBrush(Color::FromArgb(196, 0, 255, 0));
		//Draws the rectangle's filling
		pPaint->FillRectangle(brsFront, rctHealth.Left, rctHealth.Top, rctHealth.Width, rctHealth.Height);
		delete brsFront;
	} else {
		brsFront = gcnew SolidBrush(Color::FromArgb(
			98, (1 - (Globals::Player->Health / (float)Globals::MaxHealth)) * 255
			, (Globals::Player->Health / (float)Globals::MaxHealth) * 255, 0));
		//Draws the rectangle's filling
		pPaint->FillRectangle(brsFront, rctHealth.Left, rctHealth.Top, 
		int(rctHealth.Width * (Globals::Player->Health / (float)Globals::MaxHealth)), rctHealth.Height);
		delete brsFront;
	}
		//Draws the rectangle
	pPaint->DrawRectangle(penFront, rctHealth);

	delete penFront;

}
//Draws the gradient to fade in the enemies
void drawGradient(Graphics^ pPaint, Size pDisplaySize)
{
	int Redness = Globals::cBackground.R;

	if(Globals::Player->Health > 0 && Globals::Player->Health < 500)
	{
		Redness = ((500-Globals::Player->Health) / (float)500) * 196;
	}
	
	Color frtColour = Color::FromArgb((Globals::cBackground.R + Redness) / 2,
		Globals::cBackground.G, Globals::cBackground.B);

	Rectangle rctArea = Rectangle(pDisplaySize.Width * 0.75, 0, pDisplaySize.Width * 0.25, pDisplaySize.Height);

	Brush^ brsFront = gcnew System::Drawing::Drawing2D::LinearGradientBrush
		(Rectangle(rctArea.X, rctArea.Y, rctArea.Width + 1, rctArea.Height),
		Color::FromArgb(0, 0, 0, 0)
		, frtColour
		, System::Drawing::Drawing2D::LinearGradientMode::Horizontal);

	pPaint->FillRectangle(brsFront, rctArea);

	rctArea = Rectangle(0, 0, pDisplaySize.Width * 0.25, pDisplaySize.Height);

	brsFront = gcnew System::Drawing::Drawing2D::LinearGradientBrush
		(Rectangle(rctArea.X, rctArea.Y, rctArea.Width + 1, rctArea.Height),
		frtColour
		, Color::FromArgb(0, 0, 0, 0)
		, System::Drawing::Drawing2D::LinearGradientMode::Horizontal);

	pPaint->FillRectangle(brsFront, rctArea);
	delete brsFront;
}

//Draws the pickup item onto the screen
void drawPickup(Graphics^ pPaint, Size pDisplaySize)
{
	//Exit if the pickup item doesn't exist or doesn't need to be drawn
	if(!Globals::PickupItem->Enabled)
	{
		return;
	}
	//The filled colour
	SolidBrush^ brsFront = gcnew SolidBrush(Color::FromArgb(
		System::Math::Sin(50 * (Globals::PickupItem->RemainingFrame / (float)800)) * 128, Globals::cPickup));
	//The border
	Pen^ penFront = gcnew Pen(Color::FromArgb(
		System::Math::Sin(50 * (Globals::PickupItem->RemainingFrame / (float)800)) * 255, Globals::cPickup), 2);

	//Makes the bounds of drawing
	Rectangle rctPickup = Rectangle(
		(float(Globals::PickupItem->Location.X - 500) / Globals::DisplayGridUnits->Width) * pDisplaySize.Width, 
		(float(Globals::PickupItem->Location.Y - 500) / Globals::DisplayGridUnits->Height) * pDisplaySize.Height, 
		1 / float(Globals::DisplayGrid->Width) * pDisplaySize.Width, 
		1 / float(Globals::DisplayGrid->Height) * pDisplaySize.Height);

	pPaint->FillRectangle(brsFront, rctPickup);

	pPaint->DrawRectangle(penFront, rctPickup);

	//Draw the item according to its type
	switch(Globals::PickupItem->PickupType)
	{
		case 0: //Health
			{
			//Makes a new array of points to draw the shape
			array<Point>^ pntCorners =
			{Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.2),
			 Point(rctPickup.X + rctPickup.Width * 0.6, rctPickup.Y + rctPickup.Height * 0.2),
			 Point(rctPickup.X + rctPickup.Width * 0.6, rctPickup.Y + rctPickup.Height * 0.4),
			 Point(rctPickup.X + rctPickup.Width * 0.8, rctPickup.Y + rctPickup.Height * 0.4),
			 Point(rctPickup.X + rctPickup.Width * 0.8, rctPickup.Y + rctPickup.Height * 0.6),
			 Point(rctPickup.X + rctPickup.Width * 0.6, rctPickup.Y + rctPickup.Height * 0.6),
			 Point(rctPickup.X + rctPickup.Width * 0.6, rctPickup.Y + rctPickup.Height * 0.8),
			 Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.8),
			 Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.6),
			 Point(rctPickup.X + rctPickup.Width * 0.2, rctPickup.Y + rctPickup.Height * 0.6),
			 Point(rctPickup.X + rctPickup.Width * 0.2, rctPickup.Y + rctPickup.Height * 0.4),
			 Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.4),
			 Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.2)};
			
			pPaint->DrawLines(penFront, pntCorners);
			
			delete pntCorners;
			break;
			}
		case 1: //Speed
			{
			//Makes a new array of points to draw the shape
			array<Point>^ pntCorners =
			{Point(rctPickup.X + rctPickup.Width * 0.25, rctPickup.Y + rctPickup.Height * 0.25),
			 Point(rctPickup.X + rctPickup.Width * 0.5, rctPickup.Y + rctPickup.Height * 0.25),
			 Point(rctPickup.X + rctPickup.Width * 0.75, rctPickup.Y + rctPickup.Height * 0.5),
			 Point(rctPickup.X + rctPickup.Width * 0.5, rctPickup.Y + rctPickup.Height * 0.75),
			 Point(rctPickup.X + rctPickup.Width * 0.25, rctPickup.Y + rctPickup.Height * 0.75),
			 Point(rctPickup.X + rctPickup.Width * 0.5, rctPickup.Y + rctPickup.Height * 0.5),
			 Point(rctPickup.X + rctPickup.Width * 0.25, rctPickup.Y + rctPickup.Height * 0.25)};
			
			pPaint->DrawLines(penFront, pntCorners);
			
			delete pntCorners;
			break;
			}
		case 2: //Damage
			{
			//Makes a new array of points to draw the shape
			array<Point>^ pntCorners =
			{Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.1),
			 Point(rctPickup.X + rctPickup.Width * 0.6, rctPickup.Y + rctPickup.Height * 0.1),
			 Point(rctPickup.X + rctPickup.Width * 0.5, rctPickup.Y + rctPickup.Height * 0.4),
			 Point(rctPickup.X + rctPickup.Width * 0.8, rctPickup.Y + rctPickup.Height * 0.4),
			 Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.9),
			 Point(rctPickup.X + rctPickup.Width * 0.5, rctPickup.Y + rctPickup.Height * 0.6),
			 Point(rctPickup.X + rctPickup.Width * 0.2, rctPickup.Y + rctPickup.Height * 0.6),
			 Point(rctPickup.X + rctPickup.Width * 0.4, rctPickup.Y + rctPickup.Height * 0.1)};
			
			pPaint->DrawLines(penFront, pntCorners);
			
			delete pntCorners;
			break;
			}
	}
	delete brsFront;
	delete penFront;
}