#pragma once
#include <mysql.h>
#include <iostream>
#include "individu.h"

namespace NS_Recherche {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Recherche
	/// </summary>
	public ref class CLRecherche : public System::Windows::Forms::Form
	{
	public:
		CLRecherche(Form^ InpPrecedent, Individu^ ESteve)
		{
			SteveInter = ESteve;
			Precedent = InpPrecedent;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~CLRecherche()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form^ Precedent;

	Individu^ SteveInter;

	private:
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;

	private: System::Windows::Forms::Button^ Button;
	private: System::Windows::Forms::TextBox^ Nom;
	private: System::Windows::Forms::TextBox^ Prenom;
	private: System::Windows::Forms::TextBox^ Date_naissance;
	private: System::Windows::Forms::TextBox^ Date_premier_achat;
	private: System::Windows::Forms::TextBox^ Date_embauche;
	private: System::Windows::Forms::TextBox^ Nom_superieur;
	private: System::Windows::Forms::TextBox^ Prenom_Superieur;
	private: System::Windows::Forms::TextBox^ Id_client;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id_adresse;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adresse;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ville;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Pays;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Adresse_livraison;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Adresse_facturation;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Delete;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Update;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ Supprimer;
	private: System::Windows::Forms::Button^ Sauvegarder;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		   /// le contenu de cette méthode avec l'éditeur de code.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->Button = (gcnew System::Windows::Forms::Button());
			   this->Nom = (gcnew System::Windows::Forms::TextBox());
			   this->Prenom = (gcnew System::Windows::Forms::TextBox());
			   this->Date_naissance = (gcnew System::Windows::Forms::TextBox());
			   this->Date_premier_achat = (gcnew System::Windows::Forms::TextBox());
			   this->Date_embauche = (gcnew System::Windows::Forms::TextBox());
			   this->Nom_superieur = (gcnew System::Windows::Forms::TextBox());
			   this->Prenom_Superieur = (gcnew System::Windows::Forms::TextBox());
			   this->Id_client = (gcnew System::Windows::Forms::TextBox());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Id_adresse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Adresse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Ville = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Pays = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Adresse_livraison = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			   this->Adresse_facturation = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			   this->Update = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			   this->Delete = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->Supprimer = (gcnew System::Windows::Forms::Button());
			   this->Sauvegarder = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Button
			   // 
			   this->Button->Location = System::Drawing::Point(16, 15);
			   this->Button->Margin = System::Windows::Forms::Padding(4);
			   this->Button->Name = L"Button";
			   this->Button->Size = System::Drawing::Size(33, 31);
			   this->Button->TabIndex = 1;
			   this->Button->Text = L"<";
			   this->Button->UseVisualStyleBackColor = true;
			   this->Button->Click += gcnew System::EventHandler(this, &CLRecherche::Button_Click);
			   // 
			   // Nom
			   // 
			   this->Nom->Location = System::Drawing::Point(28, 108);
			   this->Nom->Margin = System::Windows::Forms::Padding(4);
			   this->Nom->Name = L"Nom";
			   this->Nom->Size = System::Drawing::Size(132, 22);
			   this->Nom->TabIndex = 2;
			   this->Nom->Text = L"Nom";
			   // 
			   // Prenom
			   // 
			   this->Prenom->Location = System::Drawing::Point(28, 174);
			   this->Prenom->Margin = System::Windows::Forms::Padding(4);
			   this->Prenom->Name = L"Prenom";
			   this->Prenom->Size = System::Drawing::Size(132, 22);
			   this->Prenom->TabIndex = 3;
			   this->Prenom->Text = L"Prenom";
			   // 
			   // Date_naissance
			   // 
			   this->Date_naissance->Location = System::Drawing::Point(214, 108);
			   this->Date_naissance->Margin = System::Windows::Forms::Padding(4);
			   this->Date_naissance->Name = L"Date_naissance";
			   this->Date_naissance->Size = System::Drawing::Size(132, 22);
			   this->Date_naissance->TabIndex = 4;
			   this->Date_naissance->Text = L"Date de naissance";
			   // 
			   // Date_premier_achat
			   // 
			   this->Date_premier_achat->Location = System::Drawing::Point(373, 108);
			   this->Date_premier_achat->Margin = System::Windows::Forms::Padding(4);
			   this->Date_premier_achat->Name = L"Date_premier_achat";
			   this->Date_premier_achat->Size = System::Drawing::Size(132, 22);
			   this->Date_premier_achat->TabIndex = 5;
			   this->Date_premier_achat->Text = L"Date pre achat";
			   // 
			   // Date_embauche
			   // 
			   this->Date_embauche->Location = System::Drawing::Point(214, 174);
			   this->Date_embauche->Margin = System::Windows::Forms::Padding(4);
			   this->Date_embauche->Name = L"Date_embauche";
			   this->Date_embauche->Size = System::Drawing::Size(132, 22);
			   this->Date_embauche->TabIndex = 6;
			   this->Date_embauche->Text = L"Date embau";
			   // 
			   // Nom_superieur
			   // 
			   this->Nom_superieur->Location = System::Drawing::Point(373, 174);
			   this->Nom_superieur->Margin = System::Windows::Forms::Padding(4);
			   this->Nom_superieur->Name = L"Nom_superieur";
			   this->Nom_superieur->Size = System::Drawing::Size(132, 22);
			   this->Nom_superieur->TabIndex = 7;
			   // 
			   // Prenom_Superieur
			   // 
			   this->Prenom_Superieur->Location = System::Drawing::Point(545, 174);
			   this->Prenom_Superieur->Name = L"Prenom_Superieur";
			   this->Prenom_Superieur->Size = System::Drawing::Size(150, 22);
			   this->Prenom_Superieur->TabIndex = 15;
			   // 
			   // Id_client
			   // 
			   this->Id_client->Location = System::Drawing::Point(0, 0);
			   this->Id_client->Name = L"Id_client";
			   this->Id_client->Size = System::Drawing::Size(100, 22);
			   this->Id_client->TabIndex = 8;
			   this->Id_client->Text = L"Id_client";
			   this->Id_client->Visible = false;
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				   this->Id_adresse,
					   this->Adresse, this->Ville, this->Pays, this->Adresse_livraison, this->Adresse_facturation, this->Update, this->Delete
			   });
			   this->dataGridView1->Location = System::Drawing::Point(13, 216);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->Size = System::Drawing::Size(1003, 308);
			   this->dataGridView1->TabIndex = 9;
			   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CLRecherche::dataGridView1_CellContentClick);
			   this->dataGridView1->UserAddedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &CLRecherche::dataGridView1_UserAddedRow);
			   // 
			   // Id_adresse
			   // 
			   this->Id_adresse->HeaderText = L"Id_adresse";
			   this->Id_adresse->MinimumWidth = 6;
			   this->Id_adresse->Name = L"Id_adresse";
			   this->Id_adresse->Visible = false;
			   this->Id_adresse->Width = 125;
			   // 
			   // Adresse
			   // 
			   this->Adresse->HeaderText = L"Adresse";
			   this->Adresse->MinimumWidth = 6;
			   this->Adresse->Name = L"Adresse";
			   this->Adresse->Width = 125;
			   // 
			   // Ville
			   // 
			   this->Ville->HeaderText = L"Ville";
			   this->Ville->MinimumWidth = 6;
			   this->Ville->Name = L"Ville";
			   this->Ville->Width = 125;
			   // 
			   // Pays
			   // 
			   this->Pays->HeaderText = L"Pays";
			   this->Pays->MinimumWidth = 6;
			   this->Pays->Name = L"Pays";
			   this->Pays->Width = 125;
			   // 
			   // Adresse_livraison
			   // 
			   this->Adresse_livraison->MinimumWidth = 6;
			   this->Adresse_livraison->Name = L"Adresse_livraison";
			   this->Adresse_livraison->Width = 125;
			   // 
			   // Adresse_facturation
			   // 
			   this->Adresse_facturation->MinimumWidth = 6;
			   this->Adresse_facturation->Name = L"Adresse_facturation";
			   this->Adresse_facturation->Width = 125;
			   // 
			   // Update
			   // 
			   this->Update->HeaderText = L"";
			   this->Update->MinimumWidth = 6;
			   this->Update->Name = L"Update";
			   this->Update->Width = 125;
			   // 
			   // Delete
			   // 
			   this->Delete->HeaderText = L"";
			   this->Delete->MinimumWidth = 6;
			   this->Delete->Name = L"Delete";
			   this->Delete->Width = 125;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(211, 153);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(119, 17);
			   this->label1->TabIndex = 9;
			   this->label1->Text = L"Date d\'embauche";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(25, 153);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(57, 17);
			   this->label2->TabIndex = 10;
			   this->label2->Text = L"Prenom";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(370, 87);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(102, 17);
			   this->label3->TabIndex = 11;
			   this->label3->Text = L"Date pre achat";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(25, 87);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(37, 17);
			   this->label4->TabIndex = 12;
			   this->label4->Text = L"Nom";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(370, 153);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(101, 17);
			   this->label5->TabIndex = 13;
			   this->label5->Text = L"Nom superieur";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(211, 87);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(126, 17);
			   this->label6->TabIndex = 14;
			   this->label6->Text = L"Date de naissance";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(545, 152);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(123, 17);
			   this->label7->TabIndex = 16;
			   this->label7->Text = L"Prenom Superieur";
			   // 
			   // Supprimer
			   // 
			   this->Supprimer->Location = System::Drawing::Point(735, 108);
			   this->Supprimer->Name = L"Supprimer";
			   this->Supprimer->Size = System::Drawing::Size(140, 23);
			   this->Supprimer->TabIndex = 17;
			   this->Supprimer->Text = L"Supprimer";
			   this->Supprimer->UseVisualStyleBackColor = true;
			   this->Supprimer->Click += gcnew System::EventHandler(this, &CLRecherche::Supprimer_Click);
			   // 
			   // Sauvegarder
			   // 
			   this->Sauvegarder->Location = System::Drawing::Point(735, 174);
			   this->Sauvegarder->Name = L"Sauvegarder";
			   this->Sauvegarder->Size = System::Drawing::Size(140, 23);
			   this->Sauvegarder->TabIndex = 18;
			   this->Sauvegarder->Text = L"Sauvegarder";
			   this->Sauvegarder->UseVisualStyleBackColor = true;
			   this->Sauvegarder->Click += gcnew System::EventHandler(this, &CLRecherche::Sauvegarder_Click);
			   // 
			   // CLRecherche
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1427, 534);
			   this->Controls->Add(this->Supprimer);
			   this->Controls->Add(this->Sauvegarder);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->Prenom_Superieur);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->Button);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->Nom);
			   this->Controls->Add(this->Prenom);
			   this->Controls->Add(this->Date_naissance);
			   this->Controls->Add(this->Date_premier_achat);
			   this->Controls->Add(this->Date_embauche);
			   this->Controls->Add(this->Nom_superieur);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"CLRecherche";
			   this->Text = L"Recherche";
			   this->Load += gcnew System::EventHandler(this, &CLRecherche::Recherche_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	//void finish_with_error(MYSQL* con)
	//	{
	//		//std::cout << "Error: " << mysql_error(con);
	//		mysql_close(con);
	//		exit(1);
	//	}

	//void ConnectDatabase() {
	//		con = mysql_init(NULL);
	//		if (con == NULL) {
	//			//label1->Text = "Base inexistante";
	//		}
	//		else {
	//			//label1->Text = "Base existante";
	//		}

	//		if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
	//			//if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, 0) == NULL) {
	//				//label2->Text = "Erreur de connection a la base";
	//		}
	//		else {
	//			//label2->Text = "Connection a la base";
	//		}
	//	}

	private: System::Void Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		Precedent->Show();
	}

	private: System::Void Recherche_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Columns->Clear();

		if (SteveInter->IsClient()) {

			this->Date_embauche->Visible = false;
			this->Nom_superieur->Visible = false;
			this->Prenom_Superieur->Visible = false;
			this->label1->Visible = false;
			this->label5->Visible = false;
			this->label7->Visible = false;
			this->Supprimer->Visible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				   this->Id_adresse,
					   this->Adresse, this->Ville, this->Pays, this->Adresse_livraison, this->Adresse_facturation, this->Update, this->Delete
			});

			int i = 0;

			//Struct_Adresse^ current = SteveInter->Adresse;
			dataGridView1->Columns[1]->Width = 254;
			Nom->Text = SteveInter->GetNom();
			Prenom->Text = SteveInter->GetPrenom();
			Date_naissance->Text = SteveInter->GetDate();
			Date_premier_achat->Text = SteveInter->GetDPA();
			Id_client->Text = SteveInter->GetId();

			for each(Struct_Adresse^ current in SteveInter->GetAdresse()){
				dataGridView1->Rows[i]->Cells[0]->Value = current->ID;
				dataGridView1->Rows[i]->Cells[1]->Value = current->Adresse;
				dataGridView1->Rows[i]->Cells[2]->Value = current->Ville;
				dataGridView1->Rows[i]->Cells[3]->Value = "France";
				//dataGridView1->Rows[i]->Cells[3]->Value = SteveInter->GetAdresse()->Pays; 
				if (current->Type_adresse == "livraison" || current->Type_adresse == "livraison et facturation"){
					dataGridView1->Rows[i]->Cells[4]->Value = true;
				}
				else if (current->Type_adresse == "facturation" || current->Type_adresse == "livraison et facturation"){
					dataGridView1->Rows[i]->Cells[5]->Value = true;
				}
				dataGridView1->Rows[i]->Cells[6]->Value = "supprimer";
				dataGridView1->Rows[i]->Cells[7]->Value = "sauvegarder";
				i++;
				
			}

		}
		else {

			this->Date_naissance->Visible = false;
			this->Date_premier_achat->Visible = false;
			this->label3->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				   this->Id_adresse,
					   this->Adresse, this->Ville, this->Pays, this->Update, this->Delete
			   });

			//Struct_Adresse^ current = SteveInter->Adresse;

			Nom->Text = SteveInter->GetNom();
			Prenom->Text = SteveInter->GetPrenom();
			Date_embauche->Text = SteveInter->GetDate();
			Id_client->Text = SteveInter->GetId();


			int i = 0;

			for each(Struct_Adresse^ current in SteveInter->GetAdresse()){
				dataGridView1->Rows[i]->Cells[0]->Value = current->ID;
				dataGridView1->Rows[i]->Cells[1]->Value = current->Adresse;
				dataGridView1->Rows[i]->Cells[2]->Value = current->Ville;
				//dataGridView1->Rows[i]->Cells[3]->Value = "France";
				dataGridView1->Rows[i]->Cells[3]->Value = current->Pays; 
				dataGridView1->Rows[i]->Cells[6]->Value = "supprimer";
				dataGridView1->Rows[i]->Cells[7]->Value = "sauvegarder";
				i++;
				
			}

		}
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = e->RowIndex;
		int j = e->ColumnIndex;

		System::String^ query;

		if (SteveInter->IsClient()){
			if (j == 6 && dataGridView1->Rows[i]->Cells[6]->Value->ToString() == "supprimer") {
				query = "START TRANSACTION; CALL delete_Adresse_client('";
				query += dataGridView1->Rows[i]->Cells[6]->Value->ToString();
				query += "'); CALL verification_Adresse_client('";
				query += dataGridView1->Rows[i]->Cells[8]->Value->ToString();
				query += "'); COMMIT;";
			}
			else if (j == 6 && dataGridView1->Rows[i]->Cells[6]->Value->ToString() == "ajout") {

				if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[2]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[3]->Value->ToString() != "" && (dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "True" || dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "True")) {

					query = "START TRANSACTION; CALL ajout_Adresse_client('";
					query += dataGridView1->Rows[i]->Cells[8]->Value->ToString();
					query += "', '";
					query += dataGridView1->Rows[i]->Cells[1]->Value->ToString();
					query += "', '";
					query += dataGridView1->Rows[i]->Cells[2]->Value->ToString();
					query += "', '";
					query += dataGridView1->Rows[i]->Cells[3]->Value->ToString();

					if ((dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "True") && (dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "True")) {
						query += "', 'livraison et facturation');";
					}
					else if (dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "True") {
						query += "', 'livraison'); ";
					}
					else if (dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "True") {
						query += "', 'facturation'); ";
					}

					query += " CALL verification_Adresse_client('";
					query += SteveInter->GetId();
					query += "'); COMMIT;";
				}
			}
			else if (j == 7) {

				if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[2]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[3]->Value->ToString() != "" && (dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "True" || dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[5]->Value->ToString() == "True")) {
					
					query = "START TRANSACTION; CALL update_Adresse_client('";
					query += dataGridView1->Rows[i]->Cells[8]->Value->ToString();
					query += "', '";
					query += dataGridView1->Rows[i]->Cells[0]->Value->ToString();
					query += "', '";
					query += dataGridView1->Rows[i]->Cells[1]->Value->ToString();
					query += "', '";
					query += dataGridView1->Rows[i]->Cells[2]->Value->ToString();

					if ((dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "True") && (dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "True")) {
						query += "', 'livraison et facturation');";
					}
					else if (dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "True") {
						query += "', 'livraison'); ";
					}
					else if (dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "True") {
						query += "', 'facturation'); ";
					}

					query += " CALL verification_Adresse_client('";
					query += dataGridView1->Rows[i]->Cells[8]->Value->ToString();
					query += "'); COMMIT;";
				}
			}
			else {
				return;
			}

			pin_ptr<const wchar_t> wch = PtrToStringChars(query);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((query->Length + 1) * 2);
			errno_t err = 0;

			char* ch = (char*)malloc(sizeInBytes);
			err = wcstombs_s(&convertedChars,
				ch, sizeInBytes,
				wch, sizeInBytes);

			bool qstate;

			qstate = mysql_query(con, ch);
		}

	}

	private: System::Void dataGridView1_UserAddedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[7]->Value = "ajout";
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[4]->Value = false;
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[5]->Value = false;
	}


	private: System::Void Supprimer_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ query;

		query = "CALL Suppr_Perso(";
		query += Convert::ToInt32(SteveInter->GetId());
		query += ");";

		pin_ptr<const wchar_t> wch = PtrToStringChars(query);
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((query->Length + 1) * 2);
		errno_t err = 0;

		char* ch = (char*)malloc(sizeInBytes);
		err = wcstombs_s(&convertedChars,
			ch, sizeInBytes,
			wch, sizeInBytes);

		bool qstate;

		qstate = mysql_query(con, ch);

		this->Close();
		Precedent->Show();
	}

	private: System::Void Sauvegarder_Click(System::Object^ sender, System::EventArgs^ e) {
		if(SteveInter->IsClient()){
			
		}
	}
};
	
}
