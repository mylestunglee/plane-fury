#include "StdAfx.h"
#include "Core.h"
#include "frmMain.h"
#include "frmOptions.h"

using namespace PlaneFury;
using namespace System;

//Form load
System::Void frmOptions::frmOptions_Load(System::Object^  sender, System::EventArgs^  e)
{
	pctPlayer->BackColor = Globals::cPlayer;
	pctSprayer->BackColor = Globals::cSprayer;
	pctSmasher->BackColor = Globals::cSmasher;
	pctStriker->BackColor = Globals::cStriker;
	pctPowerUp->BackColor = Globals::cPickup;
	pctBackground->BackColor = Globals::cBackground;
	pctMisc->BackColor = Globals::cMisc;
}

//Change Player Colour
System::Void frmOptions::bttPlayer_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctPlayer->BackColor;
	dlgColour->ShowDialog();
	pctPlayer->BackColor = dlgColour->Color;
	Globals::cPlayer = dlgColour->Color;
}

//Change Sprayer Colour
System::Void frmOptions::bttSprayer_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctSprayer->BackColor;
	dlgColour->ShowDialog();
	pctSprayer->BackColor = dlgColour->Color;
	Globals::cSprayer = dlgColour->Color;
}

//Change Smasher Colour
System::Void frmOptions::bttSmasher_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctSmasher->BackColor;
	dlgColour->ShowDialog();
	pctSmasher->BackColor = dlgColour->Color;
	Globals::cSmasher = dlgColour->Color;
}

//Change Striker Colour
System::Void frmOptions::bttStriker_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctStriker->BackColor;
	dlgColour->ShowDialog();
	pctStriker->BackColor = dlgColour->Color;
	Globals::cStriker = dlgColour->Color;
}

//Change Power Up Colour
System::Void frmOptions::bttPowerUp_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctPowerUp->BackColor;
	dlgColour->ShowDialog();
	pctPowerUp->BackColor = dlgColour->Color;
	Globals::cPickup = dlgColour->Color;
}

//Change Background Colour
System::Void frmOptions::bttBackground_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctBackground->BackColor;
	dlgColour->ShowDialog();
	pctBackground->BackColor = dlgColour->Color;
	Globals::cBackground = dlgColour->Color;
}

//Change Misc Colour
System::Void frmOptions::bttMiscellaneous_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgColour->Color = pctMisc->BackColor;
	dlgColour->ShowDialog();
	pctMisc->BackColor = dlgColour->Color;
	Globals::cMisc = dlgColour->Color;
}

//Closes the form
System::Void frmOptions::bttOk_Click(System::Object^  sender, System::EventArgs^  e)
{
	Close();
}