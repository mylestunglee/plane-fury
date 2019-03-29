#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PlaneFury {

	/// <summary>
	/// Summary for frmOptions
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmOptions : public System::Windows::Forms::Form
	{
	public:
		frmOptions(void)
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
		~frmOptions()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  bttPlayer;
	private: System::Windows::Forms::PictureBox^  pctPlayer;
	private: System::Windows::Forms::PictureBox^  pctSprayer;
	protected: 




	private: System::Windows::Forms::Button^  bttSprayer;
	private: System::Windows::Forms::PictureBox^  pctSmasher;


	private: System::Windows::Forms::Button^  bttSmasher;
	private: System::Windows::Forms::PictureBox^  pctStriker;


	private: System::Windows::Forms::Button^  bttStriker;
	private: System::Windows::Forms::PictureBox^  pctBackground;


	private: System::Windows::Forms::Button^  bttBackground;
	private: System::Windows::Forms::PictureBox^  pctPowerUp;
	private: System::Windows::Forms::Button^  bttPowerUp;
	private: System::Windows::Forms::PictureBox^  pctMisc;





	private: System::Windows::Forms::Button^  bttMiscellaneous;
	private: System::Windows::Forms::Button^  bttOk;

	private: System::Windows::Forms::ColorDialog^  dlgColour;
	private: System::Windows::Forms::ToolTip^  tltInfo;
	private: System::ComponentModel::IContainer^  components;



	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmOptions::typeid));
			this->bttPlayer = (gcnew System::Windows::Forms::Button());
			this->pctPlayer = (gcnew System::Windows::Forms::PictureBox());
			this->pctSprayer = (gcnew System::Windows::Forms::PictureBox());
			this->bttSprayer = (gcnew System::Windows::Forms::Button());
			this->pctSmasher = (gcnew System::Windows::Forms::PictureBox());
			this->bttSmasher = (gcnew System::Windows::Forms::Button());
			this->pctStriker = (gcnew System::Windows::Forms::PictureBox());
			this->bttStriker = (gcnew System::Windows::Forms::Button());
			this->pctBackground = (gcnew System::Windows::Forms::PictureBox());
			this->bttBackground = (gcnew System::Windows::Forms::Button());
			this->pctPowerUp = (gcnew System::Windows::Forms::PictureBox());
			this->bttPowerUp = (gcnew System::Windows::Forms::Button());
			this->pctMisc = (gcnew System::Windows::Forms::PictureBox());
			this->bttMiscellaneous = (gcnew System::Windows::Forms::Button());
			this->bttOk = (gcnew System::Windows::Forms::Button());
			this->dlgColour = (gcnew System::Windows::Forms::ColorDialog());
			this->tltInfo = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctPlayer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctSprayer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctSmasher))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctStriker))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctPowerUp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctMisc))->BeginInit();
			this->SuspendLayout();
			// 
			// bttPlayer
			// 
			this->bttPlayer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttPlayer->Location = System::Drawing::Point(12, 12);
			this->bttPlayer->Name = L"bttPlayer";
			this->bttPlayer->Size = System::Drawing::Size(240, 23);
			this->bttPlayer->TabIndex = 1;
			this->bttPlayer->Text = L"Change &Player Colour";
			this->tltInfo->SetToolTip(this->bttPlayer, L"Change the Player\'s colour.");
			this->bttPlayer->UseVisualStyleBackColor = true;
			this->bttPlayer->Click += gcnew System::EventHandler(this, &frmOptions::bttPlayer_Click);
			// 
			// pctPlayer
			// 
			this->pctPlayer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctPlayer->BackColor = System::Drawing::Color::White;
			this->pctPlayer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctPlayer->Location = System::Drawing::Point(258, 12);
			this->pctPlayer->Name = L"pctPlayer";
			this->pctPlayer->Size = System::Drawing::Size(23, 23);
			this->pctPlayer->TabIndex = 2;
			this->pctPlayer->TabStop = false;
			// 
			// pctSprayer
			// 
			this->pctSprayer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctSprayer->BackColor = System::Drawing::Color::White;
			this->pctSprayer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctSprayer->Location = System::Drawing::Point(258, 41);
			this->pctSprayer->Name = L"pctSprayer";
			this->pctSprayer->Size = System::Drawing::Size(23, 23);
			this->pctSprayer->TabIndex = 4;
			this->pctSprayer->TabStop = false;
			// 
			// bttSprayer
			// 
			this->bttSprayer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttSprayer->Location = System::Drawing::Point(12, 41);
			this->bttSprayer->Name = L"bttSprayer";
			this->bttSprayer->Size = System::Drawing::Size(240, 23);
			this->bttSprayer->TabIndex = 2;
			this->bttSprayer->Text = L"Change Spra&yer Colour";
			this->tltInfo->SetToolTip(this->bttSprayer, L"Change the Sprayer\'s colour.");
			this->bttSprayer->UseVisualStyleBackColor = true;
			this->bttSprayer->Click += gcnew System::EventHandler(this, &frmOptions::bttSprayer_Click);
			// 
			// pctSmasher
			// 
			this->pctSmasher->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctSmasher->BackColor = System::Drawing::Color::White;
			this->pctSmasher->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctSmasher->Location = System::Drawing::Point(258, 70);
			this->pctSmasher->Name = L"pctSmasher";
			this->pctSmasher->Size = System::Drawing::Size(23, 23);
			this->pctSmasher->TabIndex = 6;
			this->pctSmasher->TabStop = false;
			// 
			// bttSmasher
			// 
			this->bttSmasher->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttSmasher->Location = System::Drawing::Point(12, 70);
			this->bttSmasher->Name = L"bttSmasher";
			this->bttSmasher->Size = System::Drawing::Size(240, 23);
			this->bttSmasher->TabIndex = 3;
			this->bttSmasher->Text = L"Change Smas&her Colour";
			this->tltInfo->SetToolTip(this->bttSmasher, L"Change the Smasher\'s colour.");
			this->bttSmasher->UseVisualStyleBackColor = true;
			this->bttSmasher->Click += gcnew System::EventHandler(this, &frmOptions::bttSmasher_Click);
			// 
			// pctStriker
			// 
			this->pctStriker->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctStriker->BackColor = System::Drawing::Color::White;
			this->pctStriker->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctStriker->Location = System::Drawing::Point(258, 99);
			this->pctStriker->Name = L"pctStriker";
			this->pctStriker->Size = System::Drawing::Size(23, 23);
			this->pctStriker->TabIndex = 8;
			this->pctStriker->TabStop = false;
			// 
			// bttStriker
			// 
			this->bttStriker->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttStriker->Location = System::Drawing::Point(12, 99);
			this->bttStriker->Name = L"bttStriker";
			this->bttStriker->Size = System::Drawing::Size(240, 23);
			this->bttStriker->TabIndex = 4;
			this->bttStriker->Text = L"Change Stri&ker Colour";
			this->tltInfo->SetToolTip(this->bttStriker, L"Change the Striker\'s colour.\r\n");
			this->bttStriker->UseVisualStyleBackColor = true;
			this->bttStriker->Click += gcnew System::EventHandler(this, &frmOptions::bttStriker_Click);
			// 
			// pctBackground
			// 
			this->pctBackground->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctBackground->BackColor = System::Drawing::Color::White;
			this->pctBackground->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctBackground->Location = System::Drawing::Point(258, 157);
			this->pctBackground->Name = L"pctBackground";
			this->pctBackground->Size = System::Drawing::Size(23, 23);
			this->pctBackground->TabIndex = 10;
			this->pctBackground->TabStop = false;
			// 
			// bttBackground
			// 
			this->bttBackground->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttBackground->Location = System::Drawing::Point(12, 157);
			this->bttBackground->Name = L"bttBackground";
			this->bttBackground->Size = System::Drawing::Size(240, 23);
			this->bttBackground->TabIndex = 6;
			this->bttBackground->Text = L"Change &Background Colour";
			this->tltInfo->SetToolTip(this->bttBackground, L"Change the colour of the background.");
			this->bttBackground->UseVisualStyleBackColor = true;
			this->bttBackground->Click += gcnew System::EventHandler(this, &frmOptions::bttBackground_Click);
			// 
			// pctPowerUp
			// 
			this->pctPowerUp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctPowerUp->BackColor = System::Drawing::Color::White;
			this->pctPowerUp->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctPowerUp->Location = System::Drawing::Point(258, 128);
			this->pctPowerUp->Name = L"pctPowerUp";
			this->pctPowerUp->Size = System::Drawing::Size(23, 23);
			this->pctPowerUp->TabIndex = 12;
			this->pctPowerUp->TabStop = false;
			// 
			// bttPowerUp
			// 
			this->bttPowerUp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttPowerUp->Location = System::Drawing::Point(12, 128);
			this->bttPowerUp->Name = L"bttPowerUp";
			this->bttPowerUp->Size = System::Drawing::Size(240, 23);
			this->bttPowerUp->TabIndex = 5;
			this->bttPowerUp->Text = L"Change &Power-Up Colour";
			this->tltInfo->SetToolTip(this->bttPowerUp, L"Change the colour of the Power-Ups.\r\n");
			this->bttPowerUp->UseVisualStyleBackColor = true;
			this->bttPowerUp->Click += gcnew System::EventHandler(this, &frmOptions::bttPowerUp_Click);
			// 
			// pctMisc
			// 
			this->pctMisc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pctMisc->BackColor = System::Drawing::Color::White;
			this->pctMisc->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pctMisc->Location = System::Drawing::Point(258, 186);
			this->pctMisc->Name = L"pctMisc";
			this->pctMisc->Size = System::Drawing::Size(23, 23);
			this->pctMisc->TabIndex = 14;
			this->pctMisc->TabStop = false;
			// 
			// bttMiscellaneous
			// 
			this->bttMiscellaneous->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->bttMiscellaneous->Location = System::Drawing::Point(12, 186);
			this->bttMiscellaneous->Name = L"bttMiscellaneous";
			this->bttMiscellaneous->Size = System::Drawing::Size(240, 23);
			this->bttMiscellaneous->TabIndex = 7;
			this->bttMiscellaneous->Text = L"Change &Miscellaneous Colour";
			this->tltInfo->SetToolTip(this->bttMiscellaneous, L"Changes the miscellaneous item\'s colours such as the text and the border around t" 
				L"he health.");
			this->bttMiscellaneous->UseVisualStyleBackColor = true;
			this->bttMiscellaneous->Click += gcnew System::EventHandler(this, &frmOptions::bttMiscellaneous_Click);
			// 
			// bttOk
			// 
			this->bttOk->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bttOk->Location = System::Drawing::Point(206, 215);
			this->bttOk->Name = L"bttOk";
			this->bttOk->Size = System::Drawing::Size(75, 23);
			this->bttOk->TabIndex = 9;
			this->bttOk->Text = L"&Ok";
			this->tltInfo->SetToolTip(this->bttOk, L"Closes the form.");
			this->bttOk->UseVisualStyleBackColor = true;
			this->bttOk->Click += gcnew System::EventHandler(this, &frmOptions::bttOk_Click);
			// 
			// frmOptions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 250);
			this->Controls->Add(this->bttOk);
			this->Controls->Add(this->pctMisc);
			this->Controls->Add(this->bttMiscellaneous);
			this->Controls->Add(this->pctPowerUp);
			this->Controls->Add(this->bttPowerUp);
			this->Controls->Add(this->pctBackground);
			this->Controls->Add(this->bttBackground);
			this->Controls->Add(this->pctStriker);
			this->Controls->Add(this->bttStriker);
			this->Controls->Add(this->pctSmasher);
			this->Controls->Add(this->bttSmasher);
			this->Controls->Add(this->pctSprayer);
			this->Controls->Add(this->bttSprayer);
			this->Controls->Add(this->pctPlayer);
			this->Controls->Add(this->bttPlayer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmOptions";
			this->Text = L"Options";
			this->Load += gcnew System::EventHandler(this, &frmOptions::frmOptions_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctPlayer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctSprayer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctSmasher))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctStriker))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctPowerUp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctMisc))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmOptions::frmOptions_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttPlayer_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttSprayer_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttSmasher_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttStriker_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttPowerUp_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttBackground_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttMiscellaneous_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmOptions::bttOk_Click(System::Object^  sender, System::EventArgs^  e);
};
}
