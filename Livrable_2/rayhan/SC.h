#pragma once
#include "pch.h"
#include "UserControle.h"


namespace NS_SuperC {

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	using namespace UsrContrl;
	public ref class SuperC : public System::Windows::Forms::Form //
	{
	public:
		SuperC(void)
		{
			InitializeComponent(nullptr);
			//Fermeture = false;
		}

		SuperC(Form^ Prece)
		{
			//Fermeture = true;
			InitializeComponent(Prece);
		}

		~SuperC()
		{

			if (components)
			{
				delete components;
			}
			
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
	//============================================================================
	//	MYSQL* database;
	//	MYSQL_RES* result;
	//	MYSQL_ROW row;
	//	Form^ Precedent;
	//	bool Fermeture;
	//============================================================================
	protected:
		System::ComponentModel::IContainer^ components;
		UsrContrle^ UsrCont;

	private: System::Void InitializeComponent(Form^ Ancien) {
		this->SuspendLayout();
		//
		//COntainer
		//
		this->components = (gcnew System::ComponentModel::Container());
		//
		//UsrCont
		//
		this->UsrCont = (gcnew  UsrContrle(Ancien));

		this->UsrCont->But_Precedent->Click += gcnew  System::EventHandler(this, &SuperC::But_Precedent_Click);
		this->FormClosing += gcnew FormClosingEventHandler(this, &SuperC::Personnel_FormClosing);
		this->Load += gcnew System::EventHandler(this, &SuperC::Personnel_Load);

		this->UsrCont->Location = System::Drawing::Point(10, 10);
		this->Controls->Add(this->UsrCont);
		// 
		// SuperC
		// 
		//this->ClientSize = System::Drawing::Size(282, 253);
		this->Name = L"SuperC";
		this->ResumeLayout(false);
		

	}

	public:
		System::Void Personnel_Load(System::Object^ sender, System::EventArgs^ e) {

		   if (mysql_real_connect(UsrCont->database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
			   UsrCont->errorProvider1->SetError((Control^)sender, "Connection impossible a la base");
		   }
		   else {
			   UsrCont->errorProvider1->Clear();
			   }
		   this->UsrCont->Show();



		   }

	 System::Void But_Precedent_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	 System::Void Personnel_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		 if (UsrCont->Precedent != nullptr) {
			 if (UsrCont->Fermeture) {

				 UsrCont->Precedent->Close();

			 }
			 else {

				 UsrCont->Precedent->Show();

			 }
		 }

	}


	};
}
