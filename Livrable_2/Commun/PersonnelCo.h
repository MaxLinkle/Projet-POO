#pragma once
#include "pch.h"
#include "SC.h"
#include "EspacePerso.h"
#include <iostream>

namespace NS_Personnel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NS_EspacePersonnel;
	using namespace NS_SuperC;
	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Personnel :public /*System::Windows::Forms::Form*/ SuperC
	{
	public:
		Personnel(Form^ Prece):SuperC(Prece)
		{
			InitializeComponent();	
			//Precedent = Prece;
			//Fermeture = true;
		}

		Personnel():SuperC(nullptr)
		{
			InitializeComponent();
			//Precedent = nullptr;
			//Fermeture = true;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Personnel()
		{
			/*if (components)
			{
				delete components;
			}*/
		}

	private:
	private: System::Windows::Forms::TextBox^ Nom;

	private: System::Windows::Forms::TextBox^ Prenom;

	EspPerso^ Suivant;
//============================================================================
//		   MYSQL* database;
//		   MYSQL_RES* result;
//		   MYSQL_ROW row;
//		   Form^ Precedent;
//		   bool Fermeture;
//============================================================================
	private: System::Windows::Forms::Label^ LabNom;
	private: System::Windows::Forms::Label^ LabPrenom;
	private: System::Windows::Forms::Label^ LabDate;


	//private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::Button^ Connexion;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::DateTimePicker^ PickDate;
	//private: System::Windows::Forms::Button^ But_Precedent;
	//private: System::Windows::Forms::Button^ Actualiser;

	//private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Choix Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Nom = (gcnew System::Windows::Forms::TextBox());
			this->Prenom = (gcnew System::Windows::Forms::TextBox());
			this->LabNom = (gcnew System::Windows::Forms::Label());
			this->LabPrenom = (gcnew System::Windows::Forms::Label());
			this->LabDate = (gcnew System::Windows::Forms::Label());
			this->Connexion = (gcnew System::Windows::Forms::Button());
			this->PickDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// Nom
			// 
			this->Nom->Location = System::Drawing::Point(39, 135);
			this->Nom->Name = L"Nom";
			this->Nom->Size = System::Drawing::Size(120, 22);
			this->Nom->TabIndex = 0;
			// 
			// Prenom
			// 
			this->Prenom->Location = System::Drawing::Point(245, 135);
			this->Prenom->Name = L"Prenom";
			this->Prenom->Size = System::Drawing::Size(100, 22);
			this->Prenom->TabIndex = 1;
			// 
			// LabNom
			// 
			this->LabNom->AutoSize = true;
			this->LabNom->Location = System::Drawing::Point(75, 95);
			this->LabNom->Name = L"LabNom";
			this->LabNom->Size = System::Drawing::Size(37, 17);
			this->LabNom->TabIndex = 3;
			this->LabNom->Text = L"Nom";
			// 
			// LabPrenom
			// 
			this->LabPrenom->AutoSize = true;
			this->LabPrenom->Location = System::Drawing::Point(269, 95);
			this->LabPrenom->Name = L"LabPrenom";
			this->LabPrenom->Size = System::Drawing::Size(57, 17);
			this->LabPrenom->TabIndex = 4;
			this->LabPrenom->Text = L"Prenom";
			// 
			// LabDate
			// 
			this->LabDate->AutoSize = true;
			this->LabDate->Location = System::Drawing::Point(455, 95);
			this->LabDate->Name = L"LabDate";
			this->LabDate->Size = System::Drawing::Size(38, 17);
			this->LabDate->TabIndex = 5;
			this->LabDate->Text = L"Date";
			// 
			// Connexion
			// 
			this->Connexion->Location = System::Drawing::Point(245, 278);
			this->Connexion->Name = L"Connexion";
			this->Connexion->Size = System::Drawing::Size(100, 54);
			this->Connexion->TabIndex = 6;
			this->Connexion->Text = L"Valider";
			this->Connexion->UseVisualStyleBackColor = true;
			this->Connexion->Click += gcnew System::EventHandler(this, &Personnel::Connexion_Click);
			// 
			// PickDate
			// 
			this->PickDate->CustomFormat = L"yyyy-MM-dd";
			this->PickDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->PickDate->Location = System::Drawing::Point(430, 135);
			this->PickDate->Name = L"PickDate";
			this->PickDate->Size = System::Drawing::Size(120, 22);
			this->PickDate->TabIndex = 7;
			this->PickDate->Enabled = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(406, 139);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(18, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew EventHandler(this,&Personnel::Check);
			
			// 
			// Personnel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(606, 403);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->PickDate);
			this->Controls->Add(this->Connexion);
			this->Controls->Add(this->LabDate);
			this->Controls->Add(this->LabPrenom);
			this->Controls->Add(this->LabNom);
			this->Controls->Add(this->Prenom);
			this->Controls->Add(this->Nom);
			this->Name = L"Personnel";
			this->Text = L"Personnel";			





			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//void InitializeComponent(Form ^ Prece)
		//{
		//	/*database = mysql_init(NULL);
		//	if(database == NULL) {
		//		errorProvider1->SetError(Connexion , "Impossible d'accées a la base de donnée");
		//	}*/



		//	//this->components = (gcnew System::ComponentModel::Container());
		//	this->Nom = (gcnew System::Windows::Forms::TextBox());
		//	this->Prenom = (gcnew System::Windows::Forms::TextBox());
		//	this->LabNom = (gcnew System::Windows::Forms::Label());
		//	this->LabPrenom = (gcnew System::Windows::Forms::Label());
		//	this->LabDate = (gcnew System::Windows::Forms::Label());
		//	//this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
		//	this->Connexion = (gcnew System::Windows::Forms::Button());
		//	this->PickDate = (gcnew System::Windows::Forms::DateTimePicker());
		//	//this->UsrCont = (gcnew  UsrContrle(Prece));

		//	this->SuspendLayout();
		//	// 
		//	// Nom
		//	// 
		//	this->Nom->Location = System::Drawing::Point(39, 135);
		//	this->Nom->Name = L"Nom";
		//	this->Nom->Size = System::Drawing::Size(120, 22);
		//	this->Nom->TabIndex = 0;
		//	// 
		//	// Prenom
		//	// 
		//	this->Prenom->Location = System::Drawing::Point(247, 134);
		//	this->Prenom->Name = L"Prenom";
		//	this->Prenom->Size = System::Drawing::Size(100, 22);
		//	this->Prenom->TabIndex = 1;
		//	// 
		//	// LabNom
		//	// 
		//	this->LabNom->AutoSize = true;
		//	this->LabNom->Location = System::Drawing::Point(75, 95);
		//	this->LabNom->Name = L"LabNom";
		//	this->LabNom->Size = System::Drawing::Size(37, 17);
		//	this->LabNom->TabIndex = 3;
		//	this->LabNom->Text = L"Nom";
		//	// 
		//	// LabPrenom
		//	// 
		//	this->LabPrenom->AutoSize = true;
		//	this->LabPrenom->Location = System::Drawing::Point(269, 95);
		//	this->LabPrenom->Name = L"LabPrenom";
		//	this->LabPrenom->Size = System::Drawing::Size(57, 17);
		//	this->LabPrenom->TabIndex = 4;
		//	this->LabPrenom->Text = L"Prenom";
		//	// 
		//	// LabDate
		//	// 
		//	this->LabDate->AutoSize = true;
		//	this->LabDate->Location = System::Drawing::Point(455, 95);
		//	this->LabDate->Name = L"LabDate";
		//	this->LabDate->Size = System::Drawing::Size(38, 17);
		//	this->LabDate->TabIndex = 5;
		//	this->LabDate->Text = L"Date";
		//	this->UsrCont->Name = L"UsrCont";
		//	this->UsrCont->Location = System::Drawing::Point(10,10);
		//	this->UsrCont->But_Precedent->Click += gcnew  System::EventHandler(this, &Personnel::But_Precedent_Click);
		//	// 
		//	// Connexion
		//	// 
		//	this->Connexion->Location = System::Drawing::Point(245, 278);
		//	this->Connexion->Name = L"Connexion";
		//	this->Connexion->Size = System::Drawing::Size(100, 54);
		//	this->Connexion->TabIndex = 6;
		//	this->Connexion->Text = L"Valider";
		//	this->Connexion->UseVisualStyleBackColor = true;
		//	this->Connexion->Click += gcnew System::EventHandler(this, &Personnel::Connexion_Click);
		//	// 
		//	// PickDate
		//	// 
		//	this->PickDate->CustomFormat = L"yyyy-MM-dd";
		//	this->PickDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
		//	this->PickDate->Location = System::Drawing::Point(430, 132);
		//	this->PickDate->Name = L"PickDate";
		//	this->PickDate->Size = System::Drawing::Size(120, 22);
		//	this->PickDate->TabIndex = 7;
		//	// 
		//	// Personnel
		//	// 
		//	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		//	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		//	this->ClientSize = System::Drawing::Size(606, 403);
		//	this->Controls->Add(this->PickDate);
		//	this->Controls->Add(this->Connexion);
		//	this->Controls->Add(this->LabDate);
		//	this->Controls->Add(this->LabPrenom);
		//	this->Controls->Add(this->LabNom);
		//	this->Controls->Add(this->Prenom);
		//	this->Controls->Add(this->Nom);
		//	this->Controls->Add(this->UsrCont);
		//	this->Name = L"Personnel";
		//	this->Text = L"Personnel";
		//	this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Personnel::Personnel_FormClosing);
		//	this->Load += gcnew System::EventHandler(this, &Personnel::Personnel_Load);
		//	this->ResumeLayout(false);
		//	this->PerformLayout();

		//}


#pragma endregion

private:
	/* System::Void Personnel_Load(System::Object^ sender, System::EventArgs^ e) {
	
	if (mysql_real_connect(UsrCont->database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
		UsrCont->errorProvider1->SetError((Control^)sender, "Connection impossible a la base");
	}
	else {
		UsrCont->errorProvider1->Clear();
	}
	this->UsrCont->Show();
	

	
}*/




	System::Void Check(System::Object^ sender, System::EventArgs^ e) {

		PickDate->Enabled = checkBox1->Checked;

	}

	private: System::Void Connexion_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ query = "SELECT ID_personnel FROM Personnel WHERE (nom ='";
		query += Nom->Text;
		query += "')*(prenom ='";
		query += Prenom->Text;
		query += "')";


		if(checkBox1->Checked){
		query += "*(date_embauche ='";
		query += PickDate->Text;
		query += "');";
		}

		int state = 0;
		/*UsrCont->database = mysql_init(NULL);
		
			if (mysql_real_connect(UsrCont->database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				UsrCont->errorProvider1->SetError((Control^)sender, "Connection impossible a la base");
			}
			else {
				UsrCont->errorProvider1->Clear();
			}*/

			
			MYSQL_RES* result = executerQuery(ToStringQuery(query));

			//LabDebug->Text = executerQuery(ToStringQuery(query));

			if (result != NULL) {
				if (result->row_count == 1) {
					row = mysql_fetch_row(result);
					this->Hide();
					this->Suivant = gcnew EspPerso(this, Convert::ToInt16(row[0]));
					this->Suivant->Show();

				}
				else {
					errorProvider1->SetError((Control^)sender, "Individus inconnue");
				}
			}
			else {

				errorProvider1->SetError((Control^)sender, "Erreur BDD");
			}



			
		
}




/*private: System::Void But_Precedent_Click(System::Object^ sender, System::EventArgs^ e) {

	
	this->Close();

}*/



/*private: System::Void Actualiser_Click(System::Object^ sender, System::EventArgs^ e) {

	if (mysql_real_connect(database, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
		errorProvider1->SetError((Control^)sender, "Connection impossible a la base");
	}
	else {

		errorProvider1->Clear();

	}

}*/

};
}

