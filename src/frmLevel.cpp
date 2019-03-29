#include "StdAfx.h"
#include "frmLevel.h"
#include "frmMain.h"
#include "Core.h"

using namespace PlaneFury;
using namespace System;

System::Void frmLevel::frmLevel_Load(System::Object^  sender, System::EventArgs^  e)
{
	showStats();

	//Select the first radio button
	rdbDamage->Select();
};

System::Void frmLevel::bttSave_Click(System::Object^  sender, System::EventArgs^  e)
{
	dlgSave->ShowDialog();
	if(dlgSave->FileName == "")
	{
		return;
	}
	Globals::GameFilePath = dlgSave->FileName;
	saveLeveledGame();
}

System::Void frmLevel::frmLevel_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	startLeveledGame();
}

System::Void frmLevel::bttUpgrade_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(rdbDamage->Checked)
	{
		if(Globals::gUpgradePoints >= Convert::ToInt32(lblDamage->Text) && Globals::gBulletDamage < 1000)
		{
			Globals::gBulletDamage += 100;
			Globals::gUpgradePoints -= Convert::ToInt32(lblDamage->Text);
		}
	} else if(rdbSpeed->Checked)
	{
		if(Globals::gUpgradePoints >= Convert::ToInt32(lblSpeed->Text) && Globals::gBulletSpeed < 800)
		{
			Globals::gBulletSpeed += 100;
			Globals::gUpgradePoints -= Convert::ToInt32(lblSpeed->Text);
		}
	} else if(rdbRate->Checked)
	{
		if(Globals::gUpgradePoints >= Convert::ToInt32(lblRate->Text) && Globals::gRateOfFire > 0)
		{
			Globals::gRateOfFire -= 1;
			Globals::gUpgradePoints -= Convert::ToInt32(lblRate->Text);
		}
	} else if(rdbHealth->Checked)
	{
		if(Globals::gUpgradePoints >= Convert::ToInt32(lblHealth->Text) && Globals::gMaxHealth < 1000)
		{
			Globals::gMaxHealth += 100;
			Globals::gUpgradePoints -= Convert::ToInt32(lblHealth->Text);
		}
	} else if(rdbGenHealth->Checked)
	{
		if(Globals::gUpgradePoints >= Convert::ToInt32(lblGenHealth->Text))
		{
			Globals::gRegenerateHealth++;
			Globals::gUpgradePoints -= Convert::ToInt32(lblGenHealth->Text);
		}
	}

	showStats();
}

System::Void frmLevel::bttOk_Click(System::Object^  sender, System::EventArgs^  e)
{
	saveLeveledGame();
	Close();
}

void frmLevel::showStats()
{
	lblDLevels->Text = Globals::gLevelsCompleted.ToString();
	lblDScore->Text = Globals::gTotalScore.ToString();
	lblDPoints->Text = Globals::gUpgradePoints.ToString();
	lblDamageStat->Text = Globals::gBulletDamage.ToString();
	lblSpeedStat->Text = Globals::gBulletSpeed.ToString();
	lblRateStat->Text = Globals::gRateOfFire.ToString();
	lblHealthStat->Text = Globals::gMaxHealth.ToString();
	lblGenHealthStat->Text = Globals::gRegenerateHealth.ToString();
}