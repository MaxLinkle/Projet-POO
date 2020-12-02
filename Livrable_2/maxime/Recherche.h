#pragma once
#include <mysql.h>
#include <iostream>

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
	public ref class Recherche : public System::Windows::Forms::Form
	{
	public:
		Recherche(Form^ InpPrecedent, System::String^ i_id)
		{
			id = i_id;
			Precedent = InpPrecedent;
			InitializeComponent();
			ConnexionBase();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Recherche()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form^ Precedent;

	private:
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;

	private: System::String^ id;

	private: System::Windows::Forms::Button^ Button;
	private: System::Windows::Forms::Label^ Label1;
	private: System::Windows::Forms::Label^ Label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nom_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Prenom_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_naissance;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_premier_achat;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adresse_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ville_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Pays_client;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Adresse_livraison;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Adresse_facturation;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id_personnel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nom_personnel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Prenom_personnel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_embauche;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adresse_personnel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ville_personnel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Pays_personnel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id_superieur;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Button = (gcnew System::Windows::Forms::Button());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Id_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nom_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prenom_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date_naissance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date_premier_achat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adresse_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ville_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pays_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adresse_livraison = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Adresse_facturation = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Id_personnel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nom_personnel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prenom_personnel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date_embauche = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adresse_personnel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ville_personnel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pays_personnel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Id_superieur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// Button
			// 
			this->Button->Location = System::Drawing::Point(12, 12);
			this->Button->Name = L"Button";
			this->Button->Size = System::Drawing::Size(25, 25);
			this->Button->TabIndex = 1;
			this->Button->Text = L"<";
			this->Button->UseVisualStyleBackColor = true;
			this->Button->Click += gcnew System::EventHandler(this, &Recherche::Button_Click);
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->Location = System::Drawing::Point(12, 49);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(38, 13);
			this->Label1->TabIndex = 2;
			this->Label1->Text = L"Clients";
			// 
			// Label2
			// 
			this->Label2->Location = System::Drawing::Point(9, 317);
			this->Label2->Name = L"Label2";
			this->Label2->Size = System::Drawing::Size(100, 17);
			this->Label2->TabIndex = 3;
			this->Label2->Text = L"Personnel";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->Id_client,
					this->Nom_client, this->Prenom_client, this->Date_naissance, this->Date_premier_achat, this->Adresse_client, this->Ville_client,
					this->Pays_client, this->Adresse_livraison, this->Adresse_facturation
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 65);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1039, 227);
			this->dataGridView1->TabIndex = 4;
			// 
			// Id_client
			// 
			this->Id_client->HeaderText = L"Id_client";
			this->Id_client->Name = L"Id_client";
			this->Id_client->Visible = false;
			// 
			// Nom_client
			// 
			this->Nom_client->HeaderText = L"Nom";
			this->Nom_client->Name = L"Nom_client";
			// 
			// Prenom_client
			// 
			this->Prenom_client->HeaderText = L"Prenom";
			this->Prenom_client->Name = L"Prenom_client";
			// 
			// Date_naissance
			// 
			this->Date_naissance->HeaderText = L"Date_naissance";
			this->Date_naissance->Name = L"Date_naissance";
			// 
			// Date_premier_achat
			// 
			this->Date_premier_achat->HeaderText = L"Date_premier_achat";
			this->Date_premier_achat->Name = L"Date_premier_achat";
			// 
			// Adresse_client
			// 
			this->Adresse_client->HeaderText = L"Adresse";
			this->Adresse_client->Name = L"Adresse_client";
			// 
			// Ville_client
			// 
			this->Ville_client->HeaderText = L"Ville";
			this->Ville_client->Name = L"Ville_client";
			// 
			// Pays_client
			// 
			this->Pays_client->HeaderText = L"Pays";
			this->Pays_client->Name = L"Pays_client";
			// 
			// Adresse_livraison
			// 
			this->Adresse_livraison->Name = L"Adresse_livraison";
			// 
			// Adresse_facturation
			// 
			this->Adresse_facturation->Name = L"Adresse_facturation";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Id_personnel,
					this->Nom_personnel, this->Prenom_personnel, this->Date_embauche, this->Adresse_personnel, this->Ville_personnel, this->Pays_personnel
			});
			this->dataGridView2->Location = System::Drawing::Point(12, 337);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(706, 227);
			this->dataGridView2->TabIndex = 5;
			// 
			// Id_personnel
			// 
			this->Id_personnel->HeaderText = L"Id_personnel";
			this->Id_personnel->Name = L"Id_personnel";
			this->Id_personnel->Visible = false;
			// 
			// Nom_personnel
			// 
			this->Nom_personnel->HeaderText = L"Nom";
			this->Nom_personnel->Name = L"Nom_personnel";
			// 
			// Prenom_personnel
			// 
			this->Prenom_personnel->HeaderText = L"Prenom";
			this->Prenom_personnel->Name = L"Prenom_personnel";
			// 
			// Date_embauche
			// 
			this->Date_embauche->HeaderText = L"Date_embauche";
			this->Date_embauche->Name = L"Date_embauche";
			// 
			// Adresse_personnel
			// 
			this->Adresse_personnel->HeaderText = L"Adresse";
			this->Adresse_personnel->Name = L"Adresse_personnel";
			// 
			// Ville_personnel
			// 
			this->Ville_personnel->HeaderText = L"Ville";
			this->Ville_personnel->Name = L"Ville_personnel";
			// 
			// Pays_personnel
			// 
			this->Pays_personnel->HeaderText = L"Pays";
			this->Pays_personnel->Name = L"Pays_personnel";
			// 
			// Id_superieur
			// 
			this->Id_superieur->HeaderText = L"Id_superieur";
			this->Id_superieur->Name = L"Id_superieur";
			// 
			// Recherche
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 582);
			this->Controls->Add(this->Button);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->Label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dataGridView2);
			this->Name = L"Recherche";
			this->Text = L"Recherche";
			this->Load += gcnew System::EventHandler(this, &Recherche::Recherche_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Button_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			Precedent->Show();
		}
		private: System::Void Recherche_Load(System::Object^ sender, System::EventArgs^ e) {
			this->load_query();
		}

		void finish_with_error(MYSQL* con)
		{
			//std::cout << "Error: " << mysql_error(con);
			mysql_close(con);
			exit(1);
		}

		void ConnexionBase()
		{
			//std::cout << "Début de connexion\n";
			con = mysql_init(NULL);
			if (con == NULL)
			{
				//std::cout << "Echec\n";
			}
			else {
				//std::cout << "Success!\n";
			}

			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, 0) == NULL) {
				//std::cout << "Echec\n";
			}
			else {
				//std::cout << "Success!\n";
			}
		}

		void load_query() {
			ConnexionBase();

			this->dataGridView1->Rows->Clear();
			this->dataGridView1->Refresh();

			con = mysql_init(NULL);
			int qstateClient;
			qstateClient = mysql_query(con, "SELECT Client.*, Adresse_client.adresse_client, Adresse_client.ID_type_adresse FROM Client INNER JOIN Adresse_client ON Client.ID_client = Adresse_client.ID_client;");

			if (!qstateClient) {
				res = mysql_store_result(con);
				while (row = mysql_fetch_row(res)) {

				}
			}
		}
};
}
