#include "StdAfx.h"
#include "frmHelp.h"

using namespace PlaneFury;

//Closes the form with the ok button
System::Void frmHelp::cmdOk_Click(System::Object^  sender, System::EventArgs^  e)
{
	frmHelp::Close();
}

//Trys to open the license file
System::Void frmHelp::cmdLicense_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Where the license file is stored
	String^ FilePath = Application::StartupPath + "\\License.txt";
	//If the license file exists...
	if(System::IO::File::Exists(FilePath))
	{
		//Open up the file with notepad
		System::Diagnostics::Process::Start("notepad.exe", FilePath);
	} else {
		//Otherwise display an error message
		MessageBox::Show(
			"The license file cannot be found.",
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}
}

//Trys to open the change log file
System::Void frmHelp::cmdChange_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Where the change log file is stored
	String^ FilePath = Application::StartupPath + "\\Change Log.txt";
	//If the license file exists...
	if(System::IO::File::Exists(FilePath))
	{
		//Open up the file with notepad
		System::Diagnostics::Process::Start("notepad.exe", FilePath);
	} else {
		//Otherwise display an error message
		MessageBox::Show(
			"The change log file cannot be found.",
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}
}