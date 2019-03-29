// Plane Fury.cpp : main project file.

#include "stdafx.h"
#include "frmMain.h"
#include "Core.h"

using namespace PlaneFury;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	if(String::Join("",args) != "")
	{
		Globals::GameFilePath = args[0];
	}
	Application::Run(gcnew frmMain());
	return 0;
}
