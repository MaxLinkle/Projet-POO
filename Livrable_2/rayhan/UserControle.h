#pragma once
#include "pch.h"



namespace UsrContrl {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class UsrContrle :public UserControl
	{
	public: System::Windows::Forms::ErrorProvider^ errorProvider1;
	System::Windows::Forms::Button^ But_Precedent;
	System::Windows::Forms::Button^ Actualiser;
	private: System::ComponentModel::IContainer^ components;
	public:

	public:
		//============================================================================
		MYSQL* database;
		MYSQL_RES* result;
		MYSQL_ROW row;
		bool Fermeture;
		Form^ Precedent;
		//============================================================================

	int executerQuery(char* query) {
		return mysql_query(database,query);
	}

		
	UsrContrle() {
		this->InitializeComponent();
		Precedent = nullptr;
		database = mysql_init(NULL);
		if (database == NULL) {
			errorProvider1->SetIconAlignment(Actualiser,ErrorIconAlignment::MiddleRight);
			errorProvider1->SetError(Actualiser, "Impossible d'accées a la base de donnée");
		}
		Fermeture = true;
	}


	UsrContrle(Form^ Prece) {
		this->InitializeComponent();
		Precedent = Prece;
		database = mysql_init(NULL);
		if (database == NULL) {
			errorProvider1->SetIconAlignment(Actualiser, ErrorIconAlignment::MiddleRight);
			errorProvider1->SetError(Actualiser, "Impossible d'accées a la base de donnée");	
			database = mysql_init(NULL);
		}
		Fermeture = true;
	}

	~UsrContrle() {

		if (components) {

			delete components;

		}

	}


	private: System::Void InitializeComponent() {
		this->components = (gcnew System::ComponentModel::Container());
		this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
		this->But_Precedent = (gcnew System::Windows::Forms::Button());
		this->Actualiser = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
		this->SuspendLayout();
		// 
		// errorProvider1
		// 
		this->errorProvider1->ContainerControl = this;
		// 
		// But_Precedent
		// 
		this->But_Precedent->Location = System::Drawing::Point(0, 0);
		this->But_Precedent->Name = L"But_Precedent";
		this->But_Precedent->Size = System::Drawing::Size(25, 25);
		this->But_Precedent->TabIndex = 1;
		this->But_Precedent->Text = L"<";
		this->But_Precedent->UseVisualStyleBackColor = true;
		this->But_Precedent->Click += gcnew System::EventHandler(this, &UsrContrle::But_Precedent_Click);
		// 
		// Actualiser
		// 
		this->Actualiser->Location = System::Drawing::Point(35, 0);
		this->Actualiser->Name = L"Actualiser";
		this->Actualiser->Size = System::Drawing::Size(25, 25);
		this->Actualiser->TabIndex = 0;
		this->Actualiser->Text = L"!";
		this->Actualiser->UseVisualStyleBackColor = true;
		this->Actualiser->Click += gcnew System::EventHandler(this, &UsrContrle::Actualiser_Click);
		// 
		// UsrContrle
		// 
		this->Controls->Add(this->But_Precedent);
		this->Controls->Add(this->Actualiser);
		this->Name = L"UsrContrle";
		this->Size = System::Drawing::Size(89, 28);
		this->Load += gcnew System::EventHandler(this, &UsrContrle::UsrContrle_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
		this->ResumeLayout(false);

	}

	
	private: System::Void UsrContrle_Load(System::Object^ sender, System::EventArgs^ e) {
		

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

	private: System::Void But_Precedent_Click(System::Object^ sender, System::EventArgs^ e) {
			 Fermeture = !Fermeture;
		 	 Precedent->Show();
	}

	};
}

