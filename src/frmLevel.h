#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PlaneFury {

	/// <summary>
	/// Summary for frmLevel
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmLevel : public System::Windows::Forms::Form
	{
	public:
		frmLevel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmLevel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  rdbDamage;
	private: System::Windows::Forms::RadioButton^  rdbSpeed;
	private: System::Windows::Forms::RadioButton^  rdbRate;
	private: System::Windows::Forms::RadioButton^  rdbHealth;
	private: System::Windows::Forms::RadioButton^  rdbGenHealth;
	protected: 

	protected: 





	private: System::Windows::Forms::Label^  lblFScore;
	private: System::Windows::Forms::Label^  lblFPoints;




	private: System::Windows::Forms::Label^  lblDScore;
	private: System::Windows::Forms::Label^  lblDPoints;
	private: System::Windows::Forms::Label^  lblDamage;

	private: System::Windows::Forms::Label^  lblSpeed;
	private: System::Windows::Forms::Label^  lblRate;
	private: System::Windows::Forms::Label^  lblHealth;
	private: System::Windows::Forms::Label^  lblGenHealth;











	private: System::Windows::Forms::Label^  lblInfoCost;
	private: System::Windows::Forms::Button^  bttSave;
	private: System::Windows::Forms::Button^  bttUpgrade;
	private: System::Windows::Forms::Button^  bttOk;




	private: System::Windows::Forms::TableLayoutPanel^  tblLayout;
	private: System::Windows::Forms::Label^  lblInfoRadio;
	private: System::Windows::Forms::Label^  lblDLevels;
	private: System::Windows::Forms::Label^  lblFLevels;
	private: System::Windows::Forms::Label^  lblInfoStat;
	private: System::Windows::Forms::Label^  lblGenHealthStat;


	private: System::Windows::Forms::Label^  lblHealthStat;

	private: System::Windows::Forms::Label^  lblRateStat;

	private: System::Windows::Forms::Label^  lblSpeedStat;

	private: System::Windows::Forms::Label^  lblDamageStat;
	private: System::Windows::Forms::SaveFileDialog^  dlgSave;
	private: System::Windows::Forms::Label^  lblInfoClose;
	private: System::Windows::Forms::ToolTip^  tltInfo;
	private: System::ComponentModel::IContainer^  components;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmLevel::typeid));
			this->rdbDamage = (gcnew System::Windows::Forms::RadioButton());
			this->rdbSpeed = (gcnew System::Windows::Forms::RadioButton());
			this->rdbRate = (gcnew System::Windows::Forms::RadioButton());
			this->rdbHealth = (gcnew System::Windows::Forms::RadioButton());
			this->rdbGenHealth = (gcnew System::Windows::Forms::RadioButton());
			this->lblFScore = (gcnew System::Windows::Forms::Label());
			this->lblFPoints = (gcnew System::Windows::Forms::Label());
			this->lblDScore = (gcnew System::Windows::Forms::Label());
			this->lblDPoints = (gcnew System::Windows::Forms::Label());
			this->lblDamage = (gcnew System::Windows::Forms::Label());
			this->lblSpeed = (gcnew System::Windows::Forms::Label());
			this->lblRate = (gcnew System::Windows::Forms::Label());
			this->lblHealth = (gcnew System::Windows::Forms::Label());
			this->lblGenHealth = (gcnew System::Windows::Forms::Label());
			this->lblInfoCost = (gcnew System::Windows::Forms::Label());
			this->bttSave = (gcnew System::Windows::Forms::Button());
			this->bttUpgrade = (gcnew System::Windows::Forms::Button());
			this->bttOk = (gcnew System::Windows::Forms::Button());
			this->tblLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblDLevels = (gcnew System::Windows::Forms::Label());
			this->lblFLevels = (gcnew System::Windows::Forms::Label());
			this->lblInfoRadio = (gcnew System::Windows::Forms::Label());
			this->lblInfoStat = (gcnew System::Windows::Forms::Label());
			this->lblGenHealthStat = (gcnew System::Windows::Forms::Label());
			this->lblHealthStat = (gcnew System::Windows::Forms::Label());
			this->lblRateStat = (gcnew System::Windows::Forms::Label());
			this->lblSpeedStat = (gcnew System::Windows::Forms::Label());
			this->lblDamageStat = (gcnew System::Windows::Forms::Label());
			this->dlgSave = (gcnew System::Windows::Forms::SaveFileDialog());
			this->lblInfoClose = (gcnew System::Windows::Forms::Label());
			this->tltInfo = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tblLayout->SuspendLayout();
			this->SuspendLayout();
			// 
			// rdbDamage
			// 
			this->rdbDamage->Dock = System::Windows::Forms::DockStyle::Top;
			this->rdbDamage->Location = System::Drawing::Point(3, 84);
			this->rdbDamage->Name = L"rdbDamage";
			this->rdbDamage->Size = System::Drawing::Size(116, 17);
			this->rdbDamage->TabIndex = 0;
			this->rdbDamage->TabStop = true;
			this->rdbDamage->Text = L"Laser Damge";
			this->tltInfo->SetToolTip(this->rdbDamage, L"The amount of damage per laser.");
			this->rdbDamage->UseVisualStyleBackColor = true;
			// 
			// rdbSpeed
			// 
			this->rdbSpeed->Dock = System::Windows::Forms::DockStyle::Top;
			this->rdbSpeed->Location = System::Drawing::Point(3, 107);
			this->rdbSpeed->Name = L"rdbSpeed";
			this->rdbSpeed->Size = System::Drawing::Size(116, 17);
			this->rdbSpeed->TabIndex = 1;
			this->rdbSpeed->TabStop = true;
			this->rdbSpeed->Text = L"Laser Speed";
			this->tltInfo->SetToolTip(this->rdbSpeed, L"The speed the laser travels.");
			this->rdbSpeed->UseVisualStyleBackColor = true;
			// 
			// rdbRate
			// 
			this->rdbRate->Dock = System::Windows::Forms::DockStyle::Top;
			this->rdbRate->Location = System::Drawing::Point(3, 130);
			this->rdbRate->Name = L"rdbRate";
			this->rdbRate->Size = System::Drawing::Size(116, 17);
			this->rdbRate->TabIndex = 2;
			this->rdbRate->TabStop = true;
			this->rdbRate->Text = L"Rate Of Fire";
			this->tltInfo->SetToolTip(this->rdbRate, L"The rate of the lasers fired from the plane.");
			this->rdbRate->UseVisualStyleBackColor = true;
			// 
			// rdbHealth
			// 
			this->rdbHealth->Dock = System::Windows::Forms::DockStyle::Top;
			this->rdbHealth->Location = System::Drawing::Point(3, 153);
			this->rdbHealth->Name = L"rdbHealth";
			this->rdbHealth->Size = System::Drawing::Size(116, 17);
			this->rdbHealth->TabIndex = 3;
			this->rdbHealth->TabStop = true;
			this->rdbHealth->Text = L"Max Health";
			this->tltInfo->SetToolTip(this->rdbHealth, L"The maximum amount of health.");
			this->rdbHealth->UseVisualStyleBackColor = true;
			// 
			// rdbGenHealth
			// 
			this->rdbGenHealth->Dock = System::Windows::Forms::DockStyle::Top;
			this->rdbGenHealth->Location = System::Drawing::Point(3, 176);
			this->rdbGenHealth->Name = L"rdbGenHealth";
			this->rdbGenHealth->Size = System::Drawing::Size(116, 17);
			this->rdbGenHealth->TabIndex = 4;
			this->rdbGenHealth->TabStop = true;
			this->rdbGenHealth->Text = L"Regenerate Health";
			this->tltInfo->SetToolTip(this->rdbGenHealth, L"The amount of health being charged.");
			this->rdbGenHealth->UseVisualStyleBackColor = true;
			// 
			// lblFScore
			// 
			this->lblFScore->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblFScore->Location = System::Drawing::Point(3, 20);
			this->lblFScore->Name = L"lblFScore";
			this->lblFScore->Size = System::Drawing::Size(116, 22);
			this->lblFScore->TabIndex = 6;
			this->lblFScore->Text = L"Total Score:";
			this->lblFScore->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblFPoints
			// 
			this->lblFPoints->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblFPoints->Location = System::Drawing::Point(3, 42);
			this->lblFPoints->Name = L"lblFPoints";
			this->lblFPoints->Size = System::Drawing::Size(116, 22);
			this->lblFPoints->TabIndex = 7;
			this->lblFPoints->Text = L"Upgrade Points:";
			this->lblFPoints->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblDScore
			// 
			this->lblDScore->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDScore->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblDScore->Location = System::Drawing::Point(125, 20);
			this->lblDScore->Name = L"lblDScore";
			this->lblDScore->Size = System::Drawing::Size(116, 17);
			this->lblDScore->TabIndex = 8;
			this->lblDScore->Text = L"0";
			this->tltInfo->SetToolTip(this->lblDScore, L"Total Score over all levels played.");
			// 
			// lblDPoints
			// 
			this->lblDPoints->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDPoints->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblDPoints->Location = System::Drawing::Point(125, 42);
			this->lblDPoints->Name = L"lblDPoints";
			this->lblDPoints->Size = System::Drawing::Size(116, 17);
			this->lblDPoints->TabIndex = 9;
			this->lblDPoints->Text = L"0";
			this->tltInfo->SetToolTip(this->lblDPoints, L"Number of points to upgrade the plane.");
			// 
			// lblDamage
			// 
			this->lblDamage->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDamage->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblDamage->Location = System::Drawing::Point(125, 81);
			this->lblDamage->Name = L"lblDamage";
			this->lblDamage->Size = System::Drawing::Size(116, 17);
			this->lblDamage->TabIndex = 10;
			this->lblDamage->Text = L"40";
			// 
			// lblSpeed
			// 
			this->lblSpeed->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblSpeed->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblSpeed->Location = System::Drawing::Point(125, 104);
			this->lblSpeed->Name = L"lblSpeed";
			this->lblSpeed->Size = System::Drawing::Size(116, 17);
			this->lblSpeed->TabIndex = 11;
			this->lblSpeed->Text = L"40";
			// 
			// lblRate
			// 
			this->lblRate->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblRate->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblRate->Location = System::Drawing::Point(125, 127);
			this->lblRate->Name = L"lblRate";
			this->lblRate->Size = System::Drawing::Size(116, 17);
			this->lblRate->TabIndex = 12;
			this->lblRate->Text = L"80";
			// 
			// lblHealth
			// 
			this->lblHealth->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblHealth->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHealth->Location = System::Drawing::Point(125, 150);
			this->lblHealth->Name = L"lblHealth";
			this->lblHealth->Size = System::Drawing::Size(116, 17);
			this->lblHealth->TabIndex = 13;
			this->lblHealth->Text = L"200";
			// 
			// lblGenHealth
			// 
			this->lblGenHealth->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblGenHealth->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblGenHealth->Location = System::Drawing::Point(125, 173);
			this->lblGenHealth->Name = L"lblGenHealth";
			this->lblGenHealth->Size = System::Drawing::Size(116, 17);
			this->lblGenHealth->TabIndex = 14;
			this->lblGenHealth->Text = L"500";
			// 
			// lblInfoCost
			// 
			this->lblInfoCost->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblInfoCost->Location = System::Drawing::Point(125, 64);
			this->lblInfoCost->Name = L"lblInfoCost";
			this->lblInfoCost->Size = System::Drawing::Size(116, 17);
			this->lblInfoCost->TabIndex = 16;
			this->lblInfoCost->Text = L"Cost To Upgrade";
			// 
			// bttSave
			// 
			this->bttSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bttSave->Location = System::Drawing::Point(118, 222);
			this->bttSave->Name = L"bttSave";
			this->bttSave->Size = System::Drawing::Size(75, 23);
			this->bttSave->TabIndex = 17;
			this->bttSave->Text = L"&Save As...";
			this->tltInfo->SetToolTip(this->bttSave, L"Saves the current game.");
			this->bttSave->UseVisualStyleBackColor = true;
			this->bttSave->Click += gcnew System::EventHandler(this, &frmLevel::bttSave_Click);
			// 
			// bttUpgrade
			// 
			this->bttUpgrade->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bttUpgrade->Location = System::Drawing::Point(199, 222);
			this->bttUpgrade->Name = L"bttUpgrade";
			this->bttUpgrade->Size = System::Drawing::Size(75, 23);
			this->bttUpgrade->TabIndex = 18;
			this->bttUpgrade->Text = L"&Upgrade";
			this->tltInfo->SetToolTip(this->bttUpgrade, L"Upgrades the selected item.");
			this->bttUpgrade->UseVisualStyleBackColor = true;
			this->bttUpgrade->Click += gcnew System::EventHandler(this, &frmLevel::bttUpgrade_Click);
			// 
			// bttOk
			// 
			this->bttOk->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bttOk->Location = System::Drawing::Point(280, 222);
			this->bttOk->Name = L"bttOk";
			this->bttOk->Size = System::Drawing::Size(75, 23);
			this->bttOk->TabIndex = 19;
			this->bttOk->Text = L"&Ok";
			this->tltInfo->SetToolTip(this->bttOk, L"Saves the game, and closes the form to start playing.");
			this->bttOk->UseVisualStyleBackColor = true;
			this->bttOk->Click += gcnew System::EventHandler(this, &frmLevel::bttOk_Click);
			// 
			// tblLayout
			// 
			this->tblLayout->AutoSize = true;
			this->tblLayout->ColumnCount = 3;
			this->tblLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tblLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33334F)));
			this->tblLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33334F)));
			this->tblLayout->Controls->Add(this->lblDLevels, 1, 0);
			this->tblLayout->Controls->Add(this->lblFLevels, 0, 0);
			this->tblLayout->Controls->Add(this->lblInfoRadio, 0, 3);
			this->tblLayout->Controls->Add(this->lblDamage, 1, 4);
			this->tblLayout->Controls->Add(this->lblSpeed, 1, 5);
			this->tblLayout->Controls->Add(this->lblRate, 1, 6);
			this->tblLayout->Controls->Add(this->lblFPoints, 0, 2);
			this->tblLayout->Controls->Add(this->lblDPoints, 1, 2);
			this->tblLayout->Controls->Add(this->lblFScore, 0, 1);
			this->tblLayout->Controls->Add(this->lblHealth, 1, 7);
			this->tblLayout->Controls->Add(this->lblDScore, 1, 1);
			this->tblLayout->Controls->Add(this->lblGenHealth, 1, 8);
			this->tblLayout->Controls->Add(this->rdbDamage, 0, 4);
			this->tblLayout->Controls->Add(this->rdbSpeed, 0, 5);
			this->tblLayout->Controls->Add(this->rdbGenHealth, 0, 8);
			this->tblLayout->Controls->Add(this->rdbRate, 0, 6);
			this->tblLayout->Controls->Add(this->rdbHealth, 0, 7);
			this->tblLayout->Controls->Add(this->lblInfoCost, 1, 3);
			this->tblLayout->Controls->Add(this->lblInfoStat, 2, 3);
			this->tblLayout->Controls->Add(this->lblGenHealthStat, 2, 8);
			this->tblLayout->Controls->Add(this->lblHealthStat, 2, 7);
			this->tblLayout->Controls->Add(this->lblRateStat, 2, 6);
			this->tblLayout->Controls->Add(this->lblSpeedStat, 2, 5);
			this->tblLayout->Controls->Add(this->lblDamageStat, 2, 4);
			this->tblLayout->Dock = System::Windows::Forms::DockStyle::Top;
			this->tblLayout->Location = System::Drawing::Point(0, 0);
			this->tblLayout->Name = L"tblLayout";
			this->tblLayout->RowCount = 10;
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tblLayout->Size = System::Drawing::Size(367, 196);
			this->tblLayout->TabIndex = 20;
			// 
			// lblDLevels
			// 
			this->lblDLevels->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDLevels->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblDLevels->Location = System::Drawing::Point(125, 0);
			this->lblDLevels->Name = L"lblDLevels";
			this->lblDLevels->Size = System::Drawing::Size(116, 17);
			this->lblDLevels->TabIndex = 20;
			this->lblDLevels->Text = L"0";
			this->tltInfo->SetToolTip(this->lblDLevels, L"Number of levels completed.");
			// 
			// lblFLevels
			// 
			this->lblFLevels->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblFLevels->Location = System::Drawing::Point(3, 0);
			this->lblFLevels->Name = L"lblFLevels";
			this->lblFLevels->Size = System::Drawing::Size(116, 20);
			this->lblFLevels->TabIndex = 19;
			this->lblFLevels->Text = L"Levels Completed:";
			this->lblFLevels->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblInfoRadio
			// 
			this->lblInfoRadio->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblInfoRadio->Location = System::Drawing::Point(3, 64);
			this->lblInfoRadio->Name = L"lblInfoRadio";
			this->lblInfoRadio->Size = System::Drawing::Size(116, 17);
			this->lblInfoRadio->TabIndex = 17;
			this->lblInfoRadio->Text = L"Select A Upgrade";
			// 
			// lblInfoStat
			// 
			this->lblInfoStat->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblInfoStat->Location = System::Drawing::Point(247, 64);
			this->lblInfoStat->Name = L"lblInfoStat";
			this->lblInfoStat->Size = System::Drawing::Size(117, 17);
			this->lblInfoStat->TabIndex = 18;
			this->lblInfoStat->Text = L"Statistic:";
			// 
			// lblGenHealthStat
			// 
			this->lblGenHealthStat->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblGenHealthStat->Location = System::Drawing::Point(247, 173);
			this->lblGenHealthStat->Name = L"lblGenHealthStat";
			this->lblGenHealthStat->Size = System::Drawing::Size(111, 17);
			this->lblGenHealthStat->TabIndex = 25;
			this->lblGenHealthStat->Text = L"0";
			// 
			// lblHealthStat
			// 
			this->lblHealthStat->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblHealthStat->Location = System::Drawing::Point(247, 150);
			this->lblHealthStat->Name = L"lblHealthStat";
			this->lblHealthStat->Size = System::Drawing::Size(111, 17);
			this->lblHealthStat->TabIndex = 24;
			this->lblHealthStat->Text = L"0";
			// 
			// lblRateStat
			// 
			this->lblRateStat->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblRateStat->Location = System::Drawing::Point(247, 127);
			this->lblRateStat->Name = L"lblRateStat";
			this->lblRateStat->Size = System::Drawing::Size(111, 17);
			this->lblRateStat->TabIndex = 23;
			this->lblRateStat->Text = L"0";
			// 
			// lblSpeedStat
			// 
			this->lblSpeedStat->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblSpeedStat->Location = System::Drawing::Point(247, 104);
			this->lblSpeedStat->Name = L"lblSpeedStat";
			this->lblSpeedStat->Size = System::Drawing::Size(111, 17);
			this->lblSpeedStat->TabIndex = 22;
			this->lblSpeedStat->Text = L"0";
			// 
			// lblDamageStat
			// 
			this->lblDamageStat->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDamageStat->Location = System::Drawing::Point(247, 81);
			this->lblDamageStat->Name = L"lblDamageStat";
			this->lblDamageStat->Size = System::Drawing::Size(111, 17);
			this->lblDamageStat->TabIndex = 21;
			this->lblDamageStat->Text = L"0";
			// 
			// dlgSave
			// 
			this->dlgSave->Filter = L"Plane Fury Save Files|*.pfs";
			// 
			// lblInfoClose
			// 
			this->lblInfoClose->AutoSize = true;
			this->lblInfoClose->Location = System::Drawing::Point(12, 199);
			this->lblInfoClose->Name = L"lblInfoClose";
			this->lblInfoClose->Size = System::Drawing::Size(272, 13);
			this->lblInfoClose->TabIndex = 21;
			this->lblInfoClose->Text = L"When this form is closed, the game will start immediately.";
			// 
			// frmLevel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(367, 257);
			this->Controls->Add(this->lblInfoClose);
			this->Controls->Add(this->tblLayout);
			this->Controls->Add(this->bttOk);
			this->Controls->Add(this->bttUpgrade);
			this->Controls->Add(this->bttSave);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmLevel";
			this->Text = L"Levelled Game";
			this->Load += gcnew System::EventHandler(this, &frmLevel::frmLevel_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmLevel::frmLevel_FormClosing);
			this->tblLayout->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmLevel::frmLevel_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmLevel::bttSave_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmLevel::frmLevel_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void frmLevel::bttUpgrade_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmLevel::bttOk_Click(System::Object^  sender, System::EventArgs^  e);	
	private: void frmLevel::showStats();
};
}
