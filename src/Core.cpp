#pragma once

#include "stdafx.h"
#include "frmMain.h"
#include "Plane.h"
#include "Pickup.h"
#include "Core.h"
#include "frmLevel.h"

#include <stdlib.h>

//Allows the use of point
using namespace System;

//Allows to access frmMain's items
using namespace PlaneFury;

//Constructor for Global Class
Globals::Globals()
{
	//Globals::Globals();
	Globals::Player = gcnew Plane;
	Globals::Enemies = gcnew array<Plane^>(12);
	Globals::PickupItem = gcnew Pickup;
	//Loops through all the enemies allocating space for them.
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		Globals::Enemies[i] = gcnew Plane();
	}
}


//Start the stars
void intialiseStars()
{
	//Loops through all the stars
	for(int i = 0; i < Globals::StarLocations->Length; i++)
	{
		Globals::StarLocations[i] = Point(Globals::DisplayGridUnits->Width / (float)Globals::StarLocations->Length * i
			+ Globals::ScrollingSpeed
			, int((rand() / (float)RAND_MAX) * Globals::DisplayGridUnits->Height));
		Globals::StarAlpha[i] = rand() % 256;
	}
}

//Moves the stars
void moveStars()
{
	//Loops through all the stars
	for(int i = 0; i < Globals::StarLocations->Length; i++)
	{
		//Moves the star

		Globals::StarLocations[i]->X -= Globals::ScrollingSpeed;
		
		//Checks whether the star is out of bounds
		if(Globals::StarLocations[i]->X < -Globals::ScrollingSpeed)
		{
			Globals::StarLocations[i]->X += Globals::DisplayGridUnits->Width + Globals::ScrollingSpeed;
			Globals::StarLocations[i]->Y = int(rand() / (float)RAND_MAX * Globals::DisplayGridUnits->Height);
			Globals::StarAlpha[i] = (rand() + 1) % 256;
		}
	}
}



//
void updatePickup()
{
	//Checks whether the pickup is used
	if(Globals::PickupItem->Enabled)
	{
		//Check whether it is inside the player
		if(Globals::PickupItem->IsInside(Globals::Player->getRectangle()))
		{
			Globals::PickupItem->Action();
			Globals::PickupItem->Enabled = false;
		}
		//Update the animation	
		if(Globals::PickupItem->RemainingFrame <= 0)
		{
			Globals::PickupItem->Enabled = false;
		} else
		{
			Globals::PickupItem->RemainingFrame -= 1;
		}
	}
}
//Starts a new enemy to be used
void intialiseEnemy()
{
	static int tempOffset = 0;
	int j = 0;

	//No more enemies when the player has crashed
	if(Globals::Player->Health <= 0)
	{
		return;
	}

	//Loops through all the enemy planes
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		j = (i + tempOffset) % Globals::Enemies->Length;
		//If the current plane is free...
		if(Globals::Enemies[j]->Health == 0)
		{
			if(Globals::IsPlayingLeveledGame)
			{
				int tempBase = Globals::gLevelsCompleted + 1;
				
				Globals::Enemies[j]->Health = 1000;
				Globals::Enemies[j]->PlaneType = rand() % 3 + 1;
				Globals::Enemies[j]->CoolDown = 0;
				Globals::Enemies[j]->BulletSpeed = (Globals::DisplayUnit / 20) * tempBase + Globals::PlaneSpeed;
				//Type of plane selected
				switch(Globals::Enemies[j]->PlaneType)
				{
					case 1: //Sprayer
						if(Globals::Score < 200)
						{
							Globals::Enemies[j]->BulletDamage = 5 * tempBase;
						} else if(Globals::Score < 400)
						{
							Globals::Enemies[j]->BulletDamage = 7.5 * tempBase;
						} else
						{
							Globals::Enemies[j]->BulletDamage = 10 * tempBase;
						}
						Globals::Enemies[j]->RateOfFire = 5;
						Globals::Enemies[j]->DualGuns = true;
						break;
					case 2: //Sharper
						if(Globals::Score < 200)
						{
							Globals::Enemies[j]->BulletDamage = 10 * tempBase;
						} else if(Globals::Score < 400)
						{
							Globals::Enemies[j]->BulletDamage = 15 * tempBase;
						} else
						{
							Globals::Enemies[j]->BulletDamage = 20 * tempBase;
						}
						Globals::Enemies[j]->RateOfFire = 14;
						Globals::Enemies[j]->DualGuns = false;
						break;
					case 3: //Striker
						if(Globals::Score < 200)
						{
							Globals::Enemies[j]->BulletDamage = 25 * tempBase;
						} else if(Globals::Score < 400)
						{
							Globals::Enemies[j]->BulletDamage = 33.4 * tempBase;
						} else
						{
							Globals::Enemies[j]->BulletDamage = 50 * tempBase;
						}
						Globals::Enemies[j]->RateOfFire = 30;
						Globals::Enemies[j]->DualGuns = false;
				}
			} else {
				Globals::Enemies[j]->Health = 1000;
				Globals::Enemies[j]->PlaneType = rand() % 3 + 1;
				Globals::Enemies[j]->CoolDown = 0;
				Globals::Enemies[j]->BulletSpeed = Globals::DisplayUnit / 2;
				//Type of plane selected
				switch(Globals::Enemies[j]->PlaneType)
				{
					case 1: //Sprayer
						if(Globals::Score < 200)
						{
							Globals::Enemies[j]->BulletDamage = 50;
						} else if(Globals::Score < 400)
						{
							Globals::Enemies[j]->BulletDamage = 75;
						} else
						{
							Globals::Enemies[j]->BulletDamage = 100;
						}
						Globals::Enemies[j]->RateOfFire = 5;
						Globals::Enemies[j]->DualGuns = true;
						break;
					case 2: //Sharper
						if(Globals::Score < 200)
						{
							Globals::Enemies[j]->BulletDamage = 100;
						} else if(Globals::Score < 400)
						{
							Globals::Enemies[j]->BulletDamage = 150;
						} else
						{
							Globals::Enemies[j]->BulletDamage = 200;
						}
						Globals::Enemies[j]->RateOfFire = 14;
						Globals::Enemies[j]->DualGuns = false;
						break;
					case 3: //Striker
						if(Globals::Score < 200)
						{
							Globals::Enemies[j]->BulletDamage = 250;
						} else if(Globals::Score < 400)
						{
							Globals::Enemies[j]->BulletDamage = 334;
						} else
						{
							Globals::Enemies[j]->BulletDamage = 500;
						}
						Globals::Enemies[j]->RateOfFire = 30;
						Globals::Enemies[j]->DualGuns = false;
				}


				
			}

			//Settings for planes both for leveled and survivial
			Globals::Enemies[j]->CoolDown = 0;
			Globals::Enemies[j]->Location = Point(Globals::DisplayGridUnits->Width + Globals::DisplayUnit / 2
				,int((rand() / (float)RAND_MAX) * Globals::DisplayGridUnits->Height));
			//Increases the number of planes
			Globals::NumberEnemies++;
			tempOffset++;
			//Exit the function. There isn't a need to find another plane
			return;
		}
	}
}

//Moves the enemies
void moveEnemies()
{
	//Loops through all the enemy planes
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		//If the current plane is alive then...
		if(Globals::Enemies[i]->Health > 0)
		{
			//Moves the enemies towards the player
			Globals::Enemies[i]->Location.X -= Globals::PlaneSpeed;
			
			//Checks if plane is out of bounds
			if(Globals::Enemies[i]->getRectangle().Right < 0)
			{
				Globals::Enemies[i]->Health = 0;
				//If the plane hasn't died yet
				if(Globals::Player->Health > 0)
				{
					Globals::Score++;
				}
				Globals::NumberEnemies--;
				intialiseEnemy();
			}
			
			//Moves the enemies up or down according to the player's position
			if(Globals::Player->Location.Y < Globals::Enemies[i]->Location.Y - (Globals::DisplayUnit / 3))
			{
				//Moves the enemies towards the player
				Globals::Enemies[i]->Location.Y -= Globals::ScrollingSpeed / 8;			
			} else if(Globals::Player->Location.Y > Globals::Enemies[i]->Location.Y + (Globals::DisplayUnit / 3))
			{
				//Moves the enemies towards the player
				Globals::Enemies[i]->Location.Y += Globals::ScrollingSpeed / 8;			
			}
		} else if(Globals::Enemies[i]->Health == -1)
		{
			//Moves the enemies towards the player
			Globals::Enemies[i]->Location.X -= Globals::PlaneSpeed;
		}
	}
}

//
void crashEnemy(int pIndex)
{

	Globals::Enemies[pIndex]->Health = 0;			
	intialiseEnemy();
	Globals::NumberEnemies --;
}

//
void updateDataFile()
{
	//Makes a string where the statistics are saved 
	String^ FilePath = Application::StartupPath + "\\Statistics.dat";
	//Check if the file exists
	if(System::IO::File::Exists(FilePath))
	{
		//Make variable to modify the stats
		int High;
		int Average;
		int Count;
		
		//Check for errors
		try
		{
			readStatFile(High, Average, Count);

			if(Globals::Score > High)
			{
				High = Globals::Score;
			}
			//Changes the average score
			Average = ((Average * Count) + Globals::Score) / (Count + 1);
			//Increase the number of games played
			Count++;

			writeStatFile(High, Average, Count);
		} catch (...) {
			//Asks whether a new file wants to be made
			bool Result = MessageBox::Show(
				"There is an error in updating the statistics. Would you like to create a new statistics file?", 
				"Error",
				System::Windows::Forms::MessageBoxButtons::YesNo,
				System::Windows::Forms::MessageBoxIcon::Question) == 
				System::Windows::Forms::DialogResult::Yes;
			//If so, create a new file
			if(Result)
			{
				try
				{
					//Create a new file and check if there is an error
					writeStatFile(Globals::Score, Globals::Score, 1);
				} catch (...) {
					//Shows an error message
					MessageBox::Show(
						"There is an error in creating a new statistics file", 
						"Error",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Error);
				}
			}
		}
	} else {
		try
		{
			//Create a new file and check if there is an error
			writeStatFile(Globals::Score, Globals::Score, 1);
		} catch (...) {
			//Shows an error message
			MessageBox::Show(
				"There is an error in creating a new statistics file", 
				"Error",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
		}
	}
}

//Reading statistics file returns
void readStatFile(int& pHigh, int& pAverage, int& pCount)
{
	//Makes the file path
	String^ FilePath = Application::StartupPath + "\\Statistics.dat";
	//Allows the use of the writer
	System::IO::FileStream^ Stream = gcnew System::IO::FileStream(
		FilePath, 
		System::IO::FileMode::Open,
		System::IO::FileAccess::Read);
	//Uses this class to write stuff
	System::IO::BinaryReader^ Reader = gcnew System::IO::BinaryReader(Stream);
	//Check for error	
	//Write the file from the beginning
	Reader->BaseStream->Seek(0, System::IO::SeekOrigin::Begin);
	
	//Reads the following data
	pHigh = Convert::ToInt32(Reader->ReadUInt16());
	pAverage = Convert::ToInt32(Reader->ReadUInt16());
	pCount = Convert::ToInt32(Reader->ReadUInt16());
	
	//Closes the file
	Reader->Close();
	Stream->Close();

	//Clears the memory
	delete Stream;
	delete Reader;
}

//Write to a statistics file
void writeStatFile(int pHigh, int pAverage, int pCount)
{
	//Makes the file path
	String^ FilePath = Application::StartupPath + "\\Statistics.dat";
	//Allows the use of the writer
	System::IO::FileStream^ Stream = gcnew System::IO::FileStream(
		FilePath, 
		System::IO::FileMode::OpenOrCreate,
		System::IO::FileAccess::Write);
	//Uses this class to write stuff
	System::IO::BinaryWriter^ Writer = gcnew System::IO::BinaryWriter(Stream);
	//Write the file from the beginning
	Writer->BaseStream->Seek(0, System::IO::SeekOrigin::Begin);
	
	//Saves the following data
	Writer->Write(Convert::ToUInt16(pHigh));
	Writer->Write(Convert::ToUInt16(pAverage));
	Writer->Write(Convert::ToUInt16(pCount));

	//Closes the file
	Writer->Close();
	Stream->Close();

	//Clears the memory
	delete Stream;
	delete Writer;
}

//
void newLeveledGame()
{
	Globals::gLevelsCompleted = 0;
	Globals::gTotalScore = 0;
	Globals::gUpgradePoints = 40;
	Globals::gBulletDamage = 200;
	Globals::gBulletSpeed = 100;
	Globals::gRateOfFire = 10;
	Globals::gMaxHealth = 500;
	Globals::gRegenerateHealth = 0;

	frmLevel^ dlg = gcnew frmLevel;
    dlg->ShowDialog();
	delete dlg;
}

void openLeveledGame()
{
	try
	{
	//Makes the file path
	String^ FilePath = Globals::GameFilePath;
	//Allows the use of the writer
	System::IO::FileStream^ Stream = gcnew System::IO::FileStream(
		FilePath, 
		System::IO::FileMode::Open,
		System::IO::FileAccess::Read);
	//Uses this class to write stuff
	System::IO::BinaryReader^ Reader = gcnew System::IO::BinaryReader(Stream);
	//Check for error	
	//Write the file from the beginning
	Reader->BaseStream->Seek(0, System::IO::SeekOrigin::Begin);
	
	//Reads the following data
	Globals::gLevelsCompleted = Reader->ReadInt32();
	Globals::gTotalScore = Reader->ReadInt32();
	Globals::gUpgradePoints	 = Reader->ReadInt32();	
	Globals::gBulletDamage = Reader->ReadInt32();
	Globals::gBulletSpeed = Reader->ReadInt32();
	Globals::gRateOfFire = Reader->ReadInt32();
	Globals::gMaxHealth = Reader->ReadInt32();
	Globals::gRegenerateHealth = Reader->ReadInt32();
	
	//Closes the file
	Reader->Close();
	Stream->Close();

	//Clears the memory
	delete Stream;
	delete Reader;
	clearCurrentGame();
	Globals::IsPlayerCrashed = false;
	Globals::IsPlayingLeveledGame = true;

	frmLevel^ dlg = gcnew frmLevel;
    dlg->ShowDialog();
	delete dlg;

	}
	catch(...)
	{
		//Shows an error message
		MessageBox::Show(
			"There is an error in opening the file", 
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);	
	}
}

void saveLeveledGame()
{
	try
	{
		//Makes the file path
		String^ FilePath = Globals::GameFilePath;
		//Allows the use of the writer
		System::IO::FileStream^ Stream = gcnew System::IO::FileStream(
			FilePath, 
			System::IO::FileMode::OpenOrCreate,
			System::IO::FileAccess::Write);
		//Uses this class to write stuff
		System::IO::BinaryWriter^ Writer = gcnew System::IO::BinaryWriter(Stream);
		//Write the file from the beginning
		Writer->BaseStream->Seek(0, System::IO::SeekOrigin::Begin);
		
		//Saves the following data
		Writer->Write(Globals::gLevelsCompleted);
		Writer->Write(Globals::gTotalScore);
		Writer->Write(Globals::gUpgradePoints);		
		Writer->Write(Globals::gBulletDamage);
		Writer->Write(Globals::gBulletSpeed);
		Writer->Write(Globals::gRateOfFire);
		Writer->Write(Globals::gMaxHealth);
		Writer->Write(Globals::gRegenerateHealth);

		//Closes the file
		Writer->Close();
		Stream->Close();

		//Clears the memory
		delete Stream;
		delete Writer;
	}
	catch(...)
	{
		//Shows an error message
		MessageBox::Show(
			"There is an error in saving the file", 
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);	
	}
}

void startSurvialGame()
{
	Globals::ScrollingSpeed = 300;
	Globals::PlaneSpeed = 300;

	Globals::IsPlayerCrashed = false;
	clearCurrentGame();
	
	//Resets and assigns values to the player's plane
	Globals::Player->DualGuns = true;
	Globals::Player->RateOfFire = 0;
	Globals::Player->BulletDamage = 125;
	Globals::Player->BulletSpeed = Globals::PlaneSpeed;
	Globals::Player->PlaneType = 0;
	
	Globals::PickupItem->Enabled = false;
	Globals::Player->Health = Globals::MaxHealth;
	intialiseEnemy();
}

//TODO: Refresh stats settings for the player
void startLeveledGame()
{
	clearCurrentGame();
	Globals::IsPlayerCrashed = false;
	//Resets and assigns values to the player's plane
	clearCurrentGame();
	
	Globals::PickupItem->Enabled = false;
	
	Globals::Player->PlaneType = 0;
	
	Globals::Player->DualGuns = true;

	Globals::Player->BulletDamage = Globals::gBulletDamage;
	Globals::Player->BulletSpeed = Globals::gBulletSpeed;
	Globals::Player->RateOfFire = Globals::gRateOfFire;
	Globals::Player->Health = Globals::gMaxHealth;
	
	intialiseEnemy();

	if(Globals::gLevelsCompleted >= 14)
	{
		Globals::ScrollingSpeed = 500;
		Globals::PlaneSpeed = 500;
	} else {
		Globals::ScrollingSpeed = 100 + ((Globals::gLevelsCompleted / (float)2) * 50);
		Globals::PlaneSpeed = 100 + ((Globals::gLevelsCompleted / (float)2) * 50);
	}
}

void playerCrash()
{
	Globals::IsPlayerCrashed = true;
	Globals::Player->Health = -1;
	//Displays explosion animation of the plane
	Globals::Player->ExplosionFrame = 50;
	if(Globals::IsPlayingLeveledGame)
	{
		//If level target is achieved...
		if(IsLevelCompleted())
		{
			Globals::gLevelsCompleted++;
			Globals::gTotalScore += Globals::Score;			
		}
		Globals::gUpgradePoints += Globals::Score;
		//Show the level form
		frmLevel^ dlg = gcnew frmLevel;
		dlg->ShowDialog();
		delete dlg;
	} else {
	//Updates the file
	updateDataFile();
	}
}

bool IsLevelCompleted()
{
	return (Globals::Score > (Globals::gLevelsCompleted + 1) * 40);
}

void clearCurrentGame()
{
	Globals::NumberEnemies = 0;
	Globals::Score = 0;
	//Resets all the enemies
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		delete Globals::Enemies[i];
		Globals::Enemies[i] = gcnew Plane();
	}
}

void explodeEnemies()
{
	for(int i = 0; i < Globals::Enemies->Length; i++)
	{
		if(Globals::Enemies[i]->ExplosionFrame > 0)
		{
				Globals::Enemies[i]->ExplosionFrame--;

			if(Globals::Enemies[i]->ExplosionFrame == 0)
			{
				//Plane has now fully crashed
				crashEnemy(i);
			}
		}
	}
}

//Reads the option file
void readOptionFile()
{
	try
	{
		//Makes the file path
		String^ FilePath = Application::StartupPath + "\\Options.dat";
		//Allows the use of the writer
		System::IO::FileStream^ Stream = gcnew System::IO::FileStream(
			FilePath, 
			System::IO::FileMode::Open,
			System::IO::FileAccess::Read);
		//Uses this class to write stuff
		System::IO::BinaryReader^ Reader = gcnew System::IO::BinaryReader(Stream);
		//Check for error	
		//Write the file from the beginning
		Reader->BaseStream->Seek(0, System::IO::SeekOrigin::Begin);
		
		//Reads the following data
		Globals::cPlayer = Color::FromArgb(Reader->ReadInt32());
		Globals::cSprayer = Color::FromArgb(Reader->ReadInt32());
		Globals::cSmasher = Color::FromArgb(Reader->ReadInt32());
		Globals::cStriker = Color::FromArgb(Reader->ReadInt32());
		Globals::cPickup = Color::FromArgb(Reader->ReadInt32());
		Globals::cBackground = Color::FromArgb(Reader->ReadInt32());
		Globals::cMisc = Color::FromArgb(Reader->ReadInt32());

		//Closes the file
		Reader->Close();
		Stream->Close();

		//Clears the memory
		delete Stream;
		delete Reader;
	}
	catch(...)
	{
		//Shows an error message
		MessageBox::Show(
			"There is an error in opening the options file", 
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);	
	}
}
//Writes to the options file
void writeOptionFile()
{
	try
	{
		//Makes the file path
		String^ FilePath = Application::StartupPath + "\\Options.dat";
		//Allows the use of the writer
		System::IO::FileStream^ Stream = gcnew System::IO::FileStream(
			FilePath, 
			System::IO::FileMode::OpenOrCreate,
			System::IO::FileAccess::Write);
		//Uses this class to write stuff
		System::IO::BinaryWriter^ Writer = gcnew System::IO::BinaryWriter(Stream);
		//Write the file from the beginning
		Writer->BaseStream->Seek(0, System::IO::SeekOrigin::Begin);
		
		//Saves the following data
		Writer->Write(Globals::cPlayer.ToArgb());
		Writer->Write(Globals::cSprayer.ToArgb());		
		Writer->Write(Globals::cSmasher.ToArgb());
		Writer->Write(Globals::cStriker.ToArgb());
		Writer->Write(Globals::cPickup.ToArgb());
		Writer->Write(Globals::cBackground.ToArgb());
		Writer->Write(Globals::cMisc.ToArgb());

		//Closes the file
		Writer->Close();
		Stream->Close();

		//Clears the memory
		delete Stream;
		delete Writer;
	}
	catch(...)
	{
		//Shows an error message
		MessageBox::Show(
			"There is an error in saving the options file", 
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);	
	}

}