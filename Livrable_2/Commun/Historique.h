#pragma once
#include <mysql.h>
#include <iostream>
#include"Facture.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Facture
	/// </summary>
	public ref class Historique : public System::Windows::Forms::Form
	{
		System::String^ nom;
		System::String^ prenom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_Emission;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Reference;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ prix_ht;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ prix_tva;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ remise;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_Livraison;
	private: System::Windows::Forms::DataGridViewButtonColumn^ facture;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;

	private: Label^ id_Client = gcnew Label;
	public:
		Historique(String^ id)
		{
			InitializeComponent();
			//std::cout << "Début de connexion\n";
			id_Client->Text = id;
			ConnexionBase();
			//
			//TODO: ajoutez ici le code du constructeur
			//
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
			MYSQL* con;
			MYSQL_RES* res;
			MYSQL_ROW row;
			con = mysql_init(NULL);
			int qstate;
			String^ query;
			if (con == NULL)
			{
				//std::cout << "Echec\n";
			}
			else {
				//std::cout << "Success!\n";
			}

			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				//std::cout << "Echec\n";
			}
			else {
				//std::cout << "Success!\n";
			}

			query = gcnew String("SELECT date_emission, reference, prix_ht, prix_tva, remise, date_livraison_prevue, ID_commande FROM Commande WHERE ID_client =");
			query += id_Client->Text;
			query += ("; SELECT nom, prenom FROM Client WHERE ID_client = ");
			query += id_Client->Text;
			query += (";");

			pin_ptr<const wchar_t> wch = PtrToStringChars(query);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((query->Length + 1) * 2);
			errno_t err = 0;
			char* ch = (char*)malloc(sizeInBytes);
			err = wcstombs_s(&convertedChars,
				ch, sizeInBytes,
				wch, sizeInBytes);

			qstate = mysql_query(con, ch);

			if (!qstate)
			{
				res = mysql_store_result(con);
				while (row = mysql_fetch_row(res))
				{
					int n = dataGridView1->Rows->Add();

					dataGridView1->Rows[n]->Cells[0]->Value = gcnew String(row[0]);
					dataGridView1->Rows[n]->Cells[1]->Value = gcnew String(row[1]);
					dataGridView1->Rows[n]->Cells[2]->Value = gcnew String(row[2]);
					dataGridView1->Rows[n]->Cells[3]->Value = gcnew String(row[3]);
					dataGridView1->Rows[n]->Cells[4]->Value = gcnew String(row[4]);
					dataGridView1->Rows[n]->Cells[5]->Value = gcnew String(row[5]);
					dataGridView1->Rows[n]->Cells[7]->Value = gcnew String(row[6]);

				}
				mysql_free_result(res);

				mysql_next_result(con);
				res = mysql_store_result(con);

				while (row = mysql_fetch_row(res))
				{
					nom = gcnew String(row[0]);
					prenom = gcnew String(row[1]);
				}

			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Historique()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ Precedent;
	private: System::Windows::Forms::Button^ Suivant;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: Client::Facture^ factu;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Precedent = (gcnew System::Windows::Forms::Button());
			this->Suivant = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Date_Emission = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Reference = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->prix_ht = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->prix_tva = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->remise = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date_Livraison = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->facture = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Precedent
			// 
			this->Precedent->Location = System::Drawing::Point(12, 12);
			this->Precedent->Name = L"Precedent";
			this->Precedent->Size = System::Drawing::Size(25, 25);
			this->Precedent->TabIndex = 1;
			this->Precedent->Text = L"<";
			this->Precedent->UseVisualStyleBackColor = true;
			// 
			// Suivant
			// 
			this->Suivant->Location = System::Drawing::Point(44, 12);
			this->Suivant->Name = L"Suivant";
			this->Suivant->Size = System::Drawing::Size(25, 25);
			this->Suivant->TabIndex = 2;
			this->Suivant->Text = L">";
			this->Suivant->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Date_Emission,
					this->Reference, this->prix_ht, this->prix_tva, this->remise, this->Date_Livraison, this->facture, this->ID
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(777, 397);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Historique::dataGridView1_CellContentClick);
			// 
			// Date_Emission
			// 
			this->Date_Emission->HeaderText = L"Date_Emission";
			this->Date_Emission->Name = L"Date_Emission";
			this->Date_Emission->ReadOnly = true;
			this->Date_Emission->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Date_Emission->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Reference
			// 
			this->Reference->HeaderText = L"Reference";
			this->Reference->Name = L"Reference";
			this->Reference->ReadOnly = true;
			this->Reference->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Reference->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// prix_ht
			// 
			this->prix_ht->HeaderText = L"Prix HT";
			this->prix_ht->Name = L"prix_ht";
			this->prix_ht->ReadOnly = true;
			// 
			// prix_tva
			// 
			this->prix_tva->HeaderText = L"Prix TVA";
			this->prix_tva->Name = L"prix_tva";
			this->prix_tva->ReadOnly = true;
			// 
			// remise
			// 
			this->remise->HeaderText = L"Remise";
			this->remise->Name = L"remise";
			this->remise->ReadOnly = true;
			// 
			// Date_Livraison
			// 
			this->Date_Livraison->HeaderText = L"Date_Livraison";
			this->Date_Livraison->Name = L"Date_Livraison";
			this->Date_Livraison->ReadOnly = true;
			this->Date_Livraison->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Date_Livraison->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// facture
			// 
			this->facture->HeaderText = L"Facture";
			this->facture->Name = L"facture";
			this->facture->Text = L"Voir Facture";
			this->facture->UseColumnTextForButtonValue = true;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Visible = false;
			// 
			// Historique
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(820, 491);
			this->Controls->Add(this->Precedent);
			this->Controls->Add(this->Suivant);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Historique";
			this->Text = L"Historique des commandes";
			this->Load += gcnew System::EventHandler(this, &Historique::Historique_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int i = e->RowIndex;
	int j = e->ColumnIndex;

	if (j == 6 && i >= 0)
	{
		System::String^ id = dataGridView1->Rows[i]->Cells[7]->Value->ToString();
		for (int n = 0; n < dataGridView1->RowCount; n++)
		this->Hide();
		factu = gcnew Client::Facture(id, this, nom, prenom);
		factu->Show();
	}
}
private: System::Void Historique_Load(System::Object^ sender, System::EventArgs^ e) {
	for (int n = 0; n < dataGridView1->RowCount; n++)
	{
		dataGridView1->Rows[n]->Cells[6]->Value = "Voir Facture";
	}
}
};
}