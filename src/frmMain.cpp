#include "stdafx.h"
#include "frmMain.h"
#include "frmHelp.h"
#include "frmLevel.h"
#include "frmOptions.h"
#include "Graphics.h"
#include "Core.h"
#include "Plane.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace PlaneFury;
using namespace System;

bool IsFired = false;
bool IsPaused = false;
bool KeyLeft = false;
bool KeyAbove = false;
bool KeyRight = false;
bool KeyBelow = false;

Point tempCurrent;
//When the game loads...
System::Void frmMain::frmMain_Load(System::Object^  sender, System::EventArgs^  e)
{
	//Intialises the random number generators
	srand((unsigned)time(NULL));
	
	Globals::Globals();

	intialiseStars();

	if(Globals::GameFilePath != "")
	{
		openLeveledGame();
	}

	readOptionFile();
}

//When the form is required to be redrawn....
System::Void frmMain::frmMain_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	pctDisplay->Image = drawDisplay(pctDisplay->Size);
}

//When the mouse is moved...
System::Void frmMain::pctDisplay_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	//Dont move plane when paused
	if(IsPaused)
	{
		return;
	}
	
	//Makes a new point to test
	Point pntTest= Point((e->Location.X / (float)pctDisplay->Width) * Globals::DisplayGridUnits->Width,
		(e->Location.Y / (float)pctDisplay->Height) * Globals::DisplayGridUnits->Height);

	if(pntTest.X < 0 || pntTest.X > Globals::DisplayGridUnits->Width ||
		pntTest.Y < 0 || pntTest.Y > Globals::DisplayGridUnits->Height || Globals::Player->Health <= 0)
	{
		return;
	}
	Globals::Player->Location = pntTest;
}

//Every 40 milliseconds...
System::Void frmMain::tmrTick_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if(!IsPaused)
	{
		//Moves the stars
		moveStars();

		if(Globals::Score >= 10 && Globals::NumberEnemies <= 1)
		{
			intialiseEnemy();
		} else if(Globals::Score >= 20 && Globals::NumberEnemies <= 2)
		{
			intialiseEnemy();
		} else if(Globals::Score >= 40 && Globals::NumberEnemies <= 3)
		{
			intialiseEnemy();
		} else if(Globals::Score >= 70 && Globals::NumberEnemies <= 4)
		{
			intialiseEnemy();
		} else if(Globals::Score >= 120 && Globals::NumberEnemies <= 5)
		{
			intialiseEnemy();
		} else if(Globals::Score >= 190 && Globals::NumberEnemies <= 6)
				{
			intialiseEnemy();
		} else if(Globals::Score >= 250 && Globals::NumberEnemies <= 7)
				{
			intialiseEnemy();
		} else if(Globals::Score >= 320 && Globals::NumberEnemies <= 8)
				{
			intialiseEnemy();
		} else if(Globals::Score >= 400 && Globals::NumberEnemies <= 9)
				{
			intialiseEnemy();
		} else if(Globals::Score >= 500 && Globals::NumberEnemies <= 10)
				{
			intialiseEnemy();
		} else if(Globals::Score >= 600 && Globals::NumberEnemies <= 11)
				{
			intialiseEnemy();
		}

		//Moves the enemies
		moveEnemies();
		for(int i = 0; i < Globals::Enemies->Length; i++)
		{
			Globals::Enemies[i]->Fire();
			Globals::Enemies[i]->MoveBullets();
		}

		if(Globals::Player->Health > 0)
		{
			//Moves the plane
			if(KeyLeft && !KeyRight && Globals::Player->Location.X - Globals::PlaneSpeed >= 0)
			{
				Globals::Player->Location.X -= Globals::PlaneSpeed;
			} else if(KeyRight && !KeyLeft && Globals::Player->Location.X - Globals::PlaneSpeed <= Globals::DisplayGridUnits->Width)
			{
				Globals::Player->Location.X += Globals::PlaneSpeed;
			}
			if(KeyBelow && !KeyAbove && Globals::Player->Location.Y - Globals::PlaneSpeed <= Globals::DisplayGridUnits->Height)
			{
				Globals::Player->Location.Y += Globals::PlaneSpeed;
			} else if(KeyAbove && !KeyBelow && Globals::Player->Location.Y - Globals::PlaneSpeed >= 0)
			{
				Globals::Player->Location.Y -= Globals::PlaneSpeed;
			} 

		}
		
		if(Globals::IsPlayingLeveledGame && Globals::Player->Health > 0)
		{
			if(Globals::Player->Health + Globals::gRegenerateHealth > Globals::gMaxHealth)
			{
				Globals::Player->Health = Globals::gMaxHealth;
			} else {
				Globals::Player->Health += Globals::gRegenerateHealth;
			}
		}

		if(IsFired)
		{
			Globals::Player->Fire();
		}

		//Moves the bullets
		Globals::Player->MoveBullets();

		explodeEnemies();

		//Update the pickup item
		updatePickup();
	}
	//Checks whether the display needs to be drawn
	if(frmMain::WindowState != System::Windows::Forms::FormWindowState::Minimized)
	{
		//Redraw the display
		pctDisplay->Image = drawDisplay(pctDisplay->Size);
	}
	//System::Diagnostics::Debug::Print(Convert::ToString(Globals::NumberEnemies));
}

//When the mouse button is held down
System::Void frmMain::pctDisplay_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	//Cursor->Position = Point(100,100);

	// Determine which mouse button is clicked.
	if(e->Button == System::Windows::Forms::MouseButtons::Left)
    {
		IsFired = true;
	} else if(e->Button == System::Windows::Forms::MouseButtons::Right && Globals::Player->Health > 0)
	{
		IsPaused = !IsPaused;

		if(IsPaused)
		{
			 tempCurrent = Cursor->Position;
		} else {
			Cursor->Position = tempCurrent;
		}
	}
}

//When the move button is releasd
System::Void frmMain::pctDisplay_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    // Determine which mouse button is clicked.
	if(e->Button == System::Windows::Forms::MouseButtons::Left)
    {
		IsFired = false;
    }
}
//Starts a new game
System::Void frmMain::mnuNewSurvival_Click(System::Object^  sender, System::EventArgs^  e)
{
	IsPaused = false;
	Globals::IsPlayingLeveledGame = false;
	startSurvialGame();

	KeyAbove = false;
	KeyBelow = false;
	KeyLeft = false;
	KeyRight = false;
}

//Shows a message box
System::Void frmMain::mnuStatistics_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	String^ FilePath = Application::StartupPath + "\\Statistics.dat";
	//Checks for errors
	try
	{
		//Stores data
		int High;
		int Average;
		int Count;

		//Get the data
		readStatFile(High, Average, Count);

		MessageBox::Show(
			"Highest Score: " + Convert::ToString(High) + "\n" +
			"Average Score: " + Convert::ToString(Average) + "\n" +
			"Number of Games Played: " + Convert::ToString(Count), 
			"Statistics for Survival Games",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information);
	} catch (...)
	{
		MessageBox::Show("There is an error in loading the statistics."
			, "Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}

}

//
System::Void frmMain::mnuInstruction_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Where the license file is stored
	String^ FilePath = Application::StartupPath + "\\Instructions.txt";
	//If the license file exists...
	if(System::IO::File::Exists(FilePath))
	{
		//Open up the file with notepad
		System::Diagnostics::Process::Start("notepad.exe", FilePath);
	} else {
		//Otherwise display an error message
		MessageBox::Show(
			"The instructions file cannot be found.",
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}
}

//Shows the about form
System::Void frmMain::mnuAbout_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	frmHelp ^ dlg = gcnew frmHelp;
    dlg->ShowDialog();
	delete dlg;
}

//Closes the game
System::Void frmMain::mnuExit_Click(System::Object^  sender, System::EventArgs^  e)
{
	frmMain::Close();
}

//
System::Void frmMain::frmMain_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	switch(e->KeyCode)
	{
	case Keys::A:
		KeyLeft = true;
		break;
	case Keys::W:
		KeyAbove = true;
		break;
	case Keys::D:
		KeyRight = true;
		break;
	case Keys::S:
		KeyBelow = true;
		break;
	case Keys::Space:
		IsFired = true;
		break;
	case Keys::P:
		if(Globals::Player->Health > 0)
		{
			IsPaused = !IsPaused;
			if(IsPaused)
			{
				 tempCurrent = Cursor->Position;
			} else {
				Cursor->Position = tempCurrent;
			}
		}
		break;
	};
}

//
System::Void frmMain::frmMain_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	switch(e->KeyCode)
	{
	case Keys::A:
		KeyLeft = false;
		break;
	case Keys::W:
		KeyAbove = false;
		break;
	case Keys::D:
		KeyRight = false;
		break;
	case Keys::S:
		KeyBelow = false;
		break;
	case Keys::Space:
		IsFired = false;
		break;
	};
}

//Additional menu events
System::Void frmMain::mnuNewLeveled_Click(System::Object^  sender, System::EventArgs^  e)
{
	IsPaused = false;
	clearCurrentGame();
	Globals::IsPlayerCrashed = false;
	Globals::IsPlayingLeveledGame = true;
	newLeveledGame();

	KeyAbove = false;
	KeyBelow = false;
	KeyLeft = false;
	KeyRight = false;
}

//Open
System::Void frmMain::mnuOpenLeveled_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgOpen->ShowDialog();
	if(dlgOpen->FileName == "")
	{
		return;
	}
	Globals::GameFilePath = dlgOpen->FileName;
	openLeveledGame();

	KeyAbove = false;
	KeyBelow = false;
	KeyLeft = false;
	KeyRight = false;
}

//Opens the option form

System::Void frmMain::mnuFullScreen_Click(System::Object^  sender, System::EventArgs^  e)
{
	frmMain::mnuFullScreen->Checked = !frmMain::mnuFullScreen->Checked;
	if(frmMain::mnuFullScreen->Checked)
	{
		frmMain::WindowState = System::Windows::Forms::FormWindowState::Normal;
		frmMain::FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		frmMain::WindowState = System::Windows::Forms::FormWindowState::Maximized;
		
	} else {
		frmMain::FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
		frmMain::WindowState = System::Windows::Forms::FormWindowState::Normal;
		
	}
}
System::Void frmMain::mnuCustomise_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the form
	frmOptions ^ dlg = gcnew frmOptions;
    dlg->ShowDialog();
	delete dlg;
}

System::Void frmMain::frmMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	writeOptionFile();
}