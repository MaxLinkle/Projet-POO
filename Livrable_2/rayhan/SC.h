#pragma once
#include "pch.h"
//#include "UserControle.h"
#include "Individu.h"
#include <consoleapi.h>
#include <iostream> 

namespace NS_SuperC {

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	
	public ref class SuperC : public System::Windows::Forms::Form
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
			Precedent = Prece;
			database = mysql_init(NULL);
			if (database == NULL) {
				errorProvider1->SetIconAlignment(Actualiser, ErrorIconAlignment::MiddleRight);
				errorProvider1->SetError(Actualiser, "Impossible d'accées a la base de donnée");
				database = mysql_init(NULL);
			}
			Fermeture = true;


		}

		~SuperC()
		{

			if (components)
			{
				delete components;
			}
			
		}

	public:
		System::Windows::Forms::ErrorProvider^ errorProvider1;
		System::Windows::Forms::Button^ But_Precedent;
		System::Windows::Forms::Button^ Actualiser;

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
	//============================================================================
		MYSQL* database;
		MYSQL_RES* result;
		MYSQL_ROW row;
		bool Fermeture;
		Form^ Precedent;
	//============================================================================

	protected:
		System::ComponentModel::IContainer^ components;


	private: System::Void InitializeComponent(Form^ Ancien) {

		this->components = (gcnew System::ComponentModel::Container());
		this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
		this->But_Precedent = (gcnew System::Windows::Forms::Button());
		this->Actualiser = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();

		this->Controls->Add(this->But_Precedent);
		this->Controls->Add(this->Actualiser);

		this->SuspendLayout();
		// 
		// errorProvider1
		// 
		this->errorProvider1->ContainerControl = this;
		// 
		// But_Precedent
		// 
		this->But_Precedent->Location = System::Drawing::Point(10, 10);
		this->But_Precedent->Name = L"But_Precedent";
		this->But_Precedent->Size = System::Drawing::Size(25, 25);
		this->But_Precedent->TabIndex = 1;
		this->But_Precedent->Text = L"<";
		this->But_Precedent->UseVisualStyleBackColor = true;
		this->But_Precedent->Click += gcnew  System::EventHandler(this, &SuperC::But_Precedent_Click);
		// 
		// Actualiser
		// 
		this->Actualiser->Location = System::Drawing::Point(45, 10);
		this->Actualiser->Name = L"Actualiser";
		this->Actualiser->Size = System::Drawing::Size(25, 25);
		this->Actualiser->TabIndex = 0;
		this->Actualiser->Text = L"!";
		this->Actualiser->UseVisualStyleBackColor = true;
		this->Actualiser->Click += gcnew System::EventHandler(this, &SuperC::Actualiser_Click);


		//this->FormClosing += gcnew FormClosingEventHandler(this, &SuperC::Personnel_FormClosing);
		this->Load += gcnew System::EventHandler(this, &SuperC::Personnel_Load);
		// 
		// SuperC
		// 
		//this->ClientSize = System::Drawing::Size(282, 253);
		this->Name = L"SuperC";
//		this->FormClosing += gcnew FormClosingEventHandler(this, &SuperC::Personnel_FormClosing);
		this->FormClosing += gcnew FormClosingEventHandler(this, &SuperC::Personnel_FormClosing);
		this->Load += gcnew System::EventHandler(this, &SuperC::Personnel_Load);
		this->ResumeLayout(false);
		this->PerformLayout();

		

	}



	public:
	System::Void Personnel_Load(System::Object^ sender, System::EventArgs^ e) {
		if (mysql_real_connect(database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
			errorProvider1->SetError((Control^)sender, "Connection impossible a la base");
		}
		else {
			errorProvider1->Clear();
		}
	}

	private: System::Void Actualiser_Click(System::Object^ sender, System::EventArgs^ e) {
		if (mysql_real_connect(database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
			errorProvider1->SetError((Control^)sender, "Connection impossible a la base");
		}
		else {
			errorProvider1->Clear();
		}
	}


	System::Void But_Precedent_Click(System::Object^ sender, System::EventArgs^ e) {
		Fermeture = !Fermeture;
		Precedent->Show();
		this->Close();
	}

	 System::Void Personnel_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		 if (Precedent != nullptr) {
			 if (Fermeture) {
				 Precedent->Close();
			 }
			 else {
				 Precedent->Show();
			 }
		 }
	}


protected:
	 MYSQL_RES* executerQuery(char* query) {

		 while(mysql_real_connect(database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) { }

		 int state = mysql_query(database, query);
		  //mysql_error(database) ;
		 if (!state) {

			 return mysql_store_result(database);

		 }else{
		 
			 return NULL;
		 
		 }
	 }


	};
}
