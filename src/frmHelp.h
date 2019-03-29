#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PlaneFury {

	/// <summary>
	/// Summary for frmHelp
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmHelp : public System::Windows::Forms::Form
	{
	public:
		frmHelp(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmHelp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  cmdOk;
	protected: 
	private: System::Windows::Forms::Button^  cmdLicense;
	private: System::Windows::Forms::TextBox^  txtInfo;
	private: System::Windows::Forms::Button^  cmdChange;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmHelp::typeid));
			this->cmdOk = (gcnew System::Windows::Forms::Button());
			this->cmdLicense = (gcnew System::Windows::Forms::Button());
			this->txtInfo = (gcnew System::Windows::Forms::TextBox());
			this->cmdChange = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cmdOk
			// 
			this->cmdOk->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cmdOk->Location = System::Drawing::Point(227, 177);
			this->cmdOk->Name = L"cmdOk";
			this->cmdOk->Size = System::Drawing::Size(75, 23);
			this->cmdOk->TabIndex = 0;
			this->cmdOk->Text = L"&Ok";
			this->cmdOk->UseVisualStyleBackColor = true;
			this->cmdOk->Click += gcnew System::EventHandler(this, &frmHelp::cmdOk_Click);
			// 
			// cmdLicense
			// 
			this->cmdLicense->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cmdLicense->Location = System::Drawing::Point(146, 177);
			this->cmdLicense->Name = L"cmdLicense";
			this->cmdLicense->Size = System::Drawing::Size(75, 23);
			this->cmdLicense->TabIndex = 1;
			this->cmdLicense->Text = L"&License";
			this->cmdLicense->UseVisualStyleBackColor = true;
			this->cmdLicense->Click += gcnew System::EventHandler(this, &frmHelp::cmdLicense_Click);
			// 
			// txtInfo
			// 
			this->txtInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtInfo->BackColor = System::Drawing::SystemColors::Window;
			this->txtInfo->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txtInfo->Location = System::Drawing::Point(12, 12);
			this->txtInfo->Multiline = true;
			this->txtInfo->Name = L"txtInfo";
			this->txtInfo->ReadOnly = true;
			this->txtInfo->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtInfo->Size = System::Drawing::Size(290, 159);
			this->txtInfo->TabIndex = 2;
			this->txtInfo->Text = L"Plane Fury\r\n\r\nVersion 1.2.65.284\r\n\r\nMyles Lee\r\n\r\nA game made in Visual C++ using " 
				L"the .NET Framework 3.5 SP1.\r\nThis program is protected by a license. The license" 
				L" can be located alongside the progam.";
			// 
			// cmdChange
			// 
			this->cmdChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cmdChange->Location = System::Drawing::Point(65, 177);
			this->cmdChange->Name = L"cmdChange";
			this->cmdChange->Size = System::Drawing::Size(75, 23);
			this->cmdChange->TabIndex = 3;
			this->cmdChange->Text = L"&Change Log";
			this->cmdChange->UseVisualStyleBackColor = true;
			this->cmdChange->Click += gcnew System::EventHandler(this, &frmHelp::cmdChange_Click);
			// 
			// frmHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 212);
			this->Controls->Add(this->cmdChange);
			this->Controls->Add(this->txtInfo);
			this->Controls->Add(this->cmdLicense);
			this->Controls->Add(this->cmdOk);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmHelp";
			this->Text = L"About Plane Fury";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmHelp::cmdOk_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmHelp::cmdLicense_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void frmHelp::cmdChange_Click(System::Object^  sender, System::EventArgs^  e);
};
}
