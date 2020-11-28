#pragma once
#include <mysql.h>
#include <iostream>

namespace NS_Facture {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Facture
	/// </summary>
	public ref class Facture : public System::Windows::Forms::Form
	{
	public:
		Facture(void)
		{
			InitializeComponent();
			std::cout << "Début de connexion\n";
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

			qstate = mysql_query(con, "SELECT date_emission, reference, prix, date_livraison_prevue FROM Commande; ");

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

				}

			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Facture()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ Precedent;
	private: System::Windows::Forms::Button^ Suivant;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_Emission;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Reference;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Total_Paiement;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_Livraison;
	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::IContainer ^components;


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
			this->Total_Paiement = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date_Livraison = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Date_Emission,
					this->Reference, this->Total_Paiement, this->Date_Livraison
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(443, 397);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Facture::dataGridView1_CellContentClick);
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
			// Total_Paiement
			// 
			this->Total_Paiement->HeaderText = L"Total_Paiement";
			this->Total_Paiement->Name = L"Total_Paiement";
			this->Total_Paiement->ReadOnly = true;
			this->Total_Paiement->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Total_Paiement->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Date_Livraison
			// 
			this->Date_Livraison->HeaderText = L"Date_Livraison";
			this->Date_Livraison->Name = L"Date_Livraison";
			this->Date_Livraison->ReadOnly = true;
			this->Date_Livraison->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Date_Livraison->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Facture
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 452);
			this->Controls->Add(this->Precedent);
			this->Controls->Add(this->Suivant);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Facture";
			this->Text = L"Facture";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Facture_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
