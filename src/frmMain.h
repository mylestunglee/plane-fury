#pragma once

namespace PlaneFury {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMain
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Timer^  tmrTick;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::MenuStrip^  mnu;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuGame;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuNewSurvival;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuNewLeveled;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOpenLeveled;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuExit;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOptions;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuInstruction;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuAbout;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuStatistics;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::OpenFileDialog^  dlgOpen;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFullScreen;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuCustomise;

	public: System::Windows::Forms::PictureBox^  pctDisplay;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->pctDisplay = (gcnew System::Windows::Forms::PictureBox());
			this->tmrTick = (gcnew System::Windows::Forms::Timer(this->components));
			this->mnu = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuNewSurvival = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuNewLeveled = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOpenLeveled = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuStatistics = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOptions = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuFullScreen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCustomise = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuInstruction = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dlgOpen = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctDisplay))->BeginInit();
			this->mnu->SuspendLayout();
			this->SuspendLayout();
			// 
			// pctDisplay
			// 
			this->pctDisplay->BackColor = System::Drawing::Color::Black;
			this->pctDisplay->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pctDisplay->Location = System::Drawing::Point(0, 24);
			this->pctDisplay->Name = L"pctDisplay";
			this->pctDisplay->Size = System::Drawing::Size(284, 238);
			this->pctDisplay->TabIndex = 1;
			this->pctDisplay->TabStop = false;
			this->pctDisplay->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pctDisplay_MouseMove);
			this->pctDisplay->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pctDisplay_MouseDown);
			this->pctDisplay->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pctDisplay_MouseUp);
			// 
			// tmrTick
			// 
			this->tmrTick->Enabled = true;
			this->tmrTick->Interval = 42;
			this->tmrTick->Tick += gcnew System::EventHandler(this, &frmMain::tmrTick_Tick);
			// 
			// mnu
			// 
			this->mnu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuGame, this->mnuOptions, 
				this->mnuHelp});
			this->mnu->Location = System::Drawing::Point(0, 0);
			this->mnu->Name = L"mnu";
			this->mnu->Size = System::Drawing::Size(284, 24);
			this->mnu->TabIndex = 2;
			this->mnu->Text = L"Menu";
			// 
			// mnuGame
			// 
			this->mnuGame->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->mnuNewSurvival, 
				this->toolStripMenuItem1, this->mnuNewLeveled, this->mnuOpenLeveled, this->toolStripMenuItem2, this->mnuStatistics, this->toolStripMenuItem3, 
				this->mnuExit});
			this->mnuGame->Name = L"mnuGame";
			this->mnuGame->Size = System::Drawing::Size(50, 20);
			this->mnuGame->Text = L"&Game";
			// 
			// mnuNewSurvival
			// 
			this->mnuNewSurvival->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuNewSurvival.Image")));
			this->mnuNewSurvival->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->mnuNewSurvival->Name = L"mnuNewSurvival";
			this->mnuNewSurvival->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->mnuNewSurvival->Size = System::Drawing::Size(231, 22);
			this->mnuNewSurvival->Text = L"&New Survival";
			this->mnuNewSurvival->Click += gcnew System::EventHandler(this, &frmMain::mnuNewSurvival_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(228, 6);
			// 
			// mnuNewLeveled
			// 
			this->mnuNewLeveled->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuNewLeveled.Image")));
			this->mnuNewLeveled->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->mnuNewLeveled->Name = L"mnuNewLeveled";
			this->mnuNewLeveled->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::N));
			this->mnuNewLeveled->Size = System::Drawing::Size(231, 22);
			this->mnuNewLeveled->Text = L"New &Levelled ...";
			this->mnuNewLeveled->Click += gcnew System::EventHandler(this, &frmMain::mnuNewLeveled_Click);
			// 
			// mnuOpenLeveled
			// 
			this->mnuOpenLeveled->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuOpenLeveled.Image")));
			this->mnuOpenLeveled->Name = L"mnuOpenLeveled";
			this->mnuOpenLeveled->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->mnuOpenLeveled->Size = System::Drawing::Size(231, 22);
			this->mnuOpenLeveled->Text = L"&Open Levelled ...";
			this->mnuOpenLeveled->Click += gcnew System::EventHandler(this, &frmMain::mnuOpenLeveled_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(228, 6);
			// 
			// mnuStatistics
			// 
			this->mnuStatistics->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuStatistics.Image")));
			this->mnuStatistics->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->mnuStatistics->Name = L"mnuStatistics";
			this->mnuStatistics->Size = System::Drawing::Size(231, 22);
			this->mnuStatistics->Text = L"Statistics ...";
			this->mnuStatistics->Click += gcnew System::EventHandler(this, &frmMain::mnuStatistics_Click_1);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(228, 6);
			// 
			// mnuExit
			// 
			this->mnuExit->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuExit.Image")));
			this->mnuExit->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->mnuExit->Name = L"mnuExit";
			this->mnuExit->Size = System::Drawing::Size(231, 22);
			this->mnuExit->Text = L"E&xit";
			this->mnuExit->Click += gcnew System::EventHandler(this, &frmMain::mnuExit_Click);
			// 
			// mnuOptions
			// 
			this->mnuOptions->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mnuFullScreen, 
				this->mnuCustomise});
			this->mnuOptions->Name = L"mnuOptions";
			this->mnuOptions->Size = System::Drawing::Size(61, 20);
			this->mnuOptions->Text = L"&Options";
			// 
			// mnuFullScreen
			// 
			this->mnuFullScreen->Name = L"mnuFullScreen";
			this->mnuFullScreen->ShortcutKeys = System::Windows::Forms::Keys::F11;
			this->mnuFullScreen->Size = System::Drawing::Size(156, 22);
			this->mnuFullScreen->Text = L"&Full Screen";
			this->mnuFullScreen->Click += gcnew System::EventHandler(this, &frmMain::mnuFullScreen_Click);
			// 
			// mnuCustomise
			// 
			this->mnuCustomise->Name = L"mnuCustomise";
			this->mnuCustomise->Size = System::Drawing::Size(156, 22);
			this->mnuCustomise->Text = L"Customise...";
			this->mnuCustomise->Click += gcnew System::EventHandler(this, &frmMain::mnuCustomise_Click);
			// 
			// mnuHelp
			// 
			this->mnuHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mnuInstruction, 
				this->mnuAbout});
			this->mnuHelp->Name = L"mnuHelp";
			this->mnuHelp->Size = System::Drawing::Size(44, 20);
			this->mnuHelp->Text = L"&Help";
			// 
			// mnuInstruction
			// 
			this->mnuInstruction->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuInstruction.Image")));
			this->mnuInstruction->ImageTransparentColor = System::Drawing::Color::Fuchsia;
			this->mnuInstruction->Name = L"mnuInstruction";
			this->mnuInstruction->Size = System::Drawing::Size(148, 22);
			this->mnuInstruction->Text = L"&Instructions ...";
			this->mnuInstruction->Click += gcnew System::EventHandler(this, &frmMain::mnuInstruction_Click);
			// 
			// mnuAbout
			// 
			this->mnuAbout->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuAbout.Image")));
			this->mnuAbout->Name = L"mnuAbout";
			this->mnuAbout->Size = System::Drawing::Size(148, 22);
			this->mnuAbout->Text = L"&About ...";
			this->mnuAbout->Click += gcnew System::EventHandler(this, &frmMain::mnuAbout_Click_1);
			// 
			// dlgOpen
			// 
			this->dlgOpen->Filter = L"Plane Fury Save Files|*.pfs";
			// 
			// frmMain
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->pctDisplay);
			this->Controls->Add(this->mnu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->mnu;
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"frmMain";
			this->Text = L"Plane Fury";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMain::frmMain_Paint);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::frmMain_KeyUp);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMain::frmMain_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::frmMain_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctDisplay))->EndInit();
			this->mnu->ResumeLayout(false);
			this->mnu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMain::frmMain_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::frmMain_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void frmMain::pctDisplay_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void frmMain::tmrTick_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::pctDisplay_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void frmMain::pctDisplay_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void frmMain::frmMain_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void frmMain::frmMain_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	 //Menu events	
	private: System::Void frmMain::mnuNewSurvival_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuStatistics_Click_1(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuExit_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuAbout_Click_1(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuNewLeveled_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuOpenLeveled_Click(System::Object^  sender, System::EventArgs^  e);	
	private: System::Void frmMain::mnuInstruction_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuFullScreen_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::mnuCustomise_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmMain::frmMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
};
}
