#pragma once
#include <mysql.h>
#include <vcclr.h>
#include "IHM_Stats.h"

namespace NS_Stats {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/*using namespace std;*/
	
	/// <summary>
	/// Description résumée de Stats
	/// </summary>
	public ref class Stats : public System::Windows::Forms::Form
	{
	public:
		Stats(Form^ InpPrecedent)
		{
			//Precedent = InpPrecedent;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form^ Precedent;

	private: System::Windows::Forms::Button^ Bouton_precedent;

	private: System::Windows::Forms::Button^ Bouton_Panier_moyen;
	private: System::Windows::Forms::Button^ Bouton_Total_achat_client;
	private: System::Windows::Forms::Button^ Bouton_Chiffre;
	private: System::Windows::Forms::Button^ Bouton_Plus_vendu;
	private: System::Windows::Forms::Button^ Bouton_Moins_vendu;
	private: System::Windows::Forms::Button^ Bouton_Achat_stock;
	private: System::Windows::Forms::Button^ Bouton_Valeur_stock;
	private: System::Windows::Forms::Button^ Bouton_Estimation;

	private: System::Windows::Forms::Label^ Label_Nom;
	private: System::Windows::Forms::Label^ Label_Prenom;
	private: System::Windows::Forms::Label^ Label_Date;

	private: System::Windows::Forms::TextBox^ TextBox_Nom;
	private: System::Windows::Forms::TextBox^ TextBox_Prenom;
	private: System::Windows::Forms::TextBox^ TextBox_Date;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Stock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Valeur_achat;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Chiffre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Total_quantite;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Panier_moyen;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Total_achat_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Valeur_commerciale;

	private: System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		   /// le contenu de cette méthode avec l'éditeur de code.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->Bouton_precedent = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Panier_moyen = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Total_achat_client = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Chiffre = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Plus_vendu = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Moins_vendu = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Achat_stock = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Valeur_stock = (gcnew System::Windows::Forms::Button());
			   this->Bouton_Estimation = (gcnew System::Windows::Forms::Button());
			   this->Label_Nom = (gcnew System::Windows::Forms::Label());
			   this->Label_Prenom = (gcnew System::Windows::Forms::Label());
			   this->Label_Date = (gcnew System::Windows::Forms::Label());
			   this->TextBox_Nom = (gcnew System::Windows::Forms::TextBox());
			   this->TextBox_Prenom = (gcnew System::Windows::Forms::TextBox());
			   this->TextBox_Date = (gcnew System::Windows::Forms::TextBox());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Valeur_achat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Chiffre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Panier_moyen = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Total_achat_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Valeur_commerciale = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Total_quantite = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Bouton_precedent
			   // 
			   this->Bouton_precedent->Location = System::Drawing::Point(12, 12);
			   this->Bouton_precedent->Name = L"Bouton_precedent";
			   this->Bouton_precedent->Size = System::Drawing::Size(25, 25);
			   this->Bouton_precedent->TabIndex = 21;
			   this->Bouton_precedent->Text = L"<";
			   this->Bouton_precedent->UseVisualStyleBackColor = true;
			   this->Bouton_precedent->Click += gcnew System::EventHandler(this, &Stats::Bouton_precedent_Click);
			   // 
			   // Bouton_Panier_moyen
			   // 
			   this->Bouton_Panier_moyen->Location = System::Drawing::Point(232, 70);
			   this->Bouton_Panier_moyen->Name = L"Bouton_Panier_moyen";
			   this->Bouton_Panier_moyen->Size = System::Drawing::Size(100, 23);
			   this->Bouton_Panier_moyen->TabIndex = 0;
			   this->Bouton_Panier_moyen->Text = L"Panier moyen";
			   this->Bouton_Panier_moyen->Click += gcnew System::EventHandler(this, &Stats::Bouton_Panier_moyen_Click);
			   // 
			   // Bouton_Total_achat_client
			   // 
			   this->Bouton_Total_achat_client->Location = System::Drawing::Point(232, 99);
			   this->Bouton_Total_achat_client->Name = L"Bouton_Total_achat_client";
			   this->Bouton_Total_achat_client->Size = System::Drawing::Size(100, 23);
			   this->Bouton_Total_achat_client->TabIndex = 0;
			   this->Bouton_Total_achat_client->Text = L"Total achat client";
			   this->Bouton_Total_achat_client->Click += gcnew System::EventHandler(this, &Stats::Bouton_Total_achat_client_Click);
			   // 
			   // Bouton_Chiffre
			   // 
			   this->Bouton_Chiffre->Location = System::Drawing::Point(404, 41);
			   this->Bouton_Chiffre->Name = L"Bouton_Chiffre";
			   this->Bouton_Chiffre->Size = System::Drawing::Size(100, 23);
			   this->Bouton_Chiffre->TabIndex = 0;
			   this->Bouton_Chiffre->Text = L"Chiffre";
			   this->Bouton_Chiffre->Click += gcnew System::EventHandler(this, &Stats::Bouton_Chiffre_Click);
			   // 
			   // Bouton_Plus_vendu
			   // 
			   this->Bouton_Plus_vendu->Location = System::Drawing::Point(58, 13);
			   this->Bouton_Plus_vendu->Name = L"Bouton_Plus_vendu";
			   this->Bouton_Plus_vendu->Size = System::Drawing::Size(105, 23);
			   this->Bouton_Plus_vendu->TabIndex = 0;
			   this->Bouton_Plus_vendu->Text = L"Plus vendu";
			   this->Bouton_Plus_vendu->Click += gcnew System::EventHandler(this, &Stats::Bouton_Plus_vendu_Click);
			   // 
			   // Bouton_Moins_vendu
			   // 
			   this->Bouton_Moins_vendu->Location = System::Drawing::Point(58, 41);
			   this->Bouton_Moins_vendu->Name = L"Bouton_Moins_vendu";
			   this->Bouton_Moins_vendu->Size = System::Drawing::Size(105, 23);
			   this->Bouton_Moins_vendu->TabIndex = 0;
			   this->Bouton_Moins_vendu->Text = L"Moins vendu";
			   this->Bouton_Moins_vendu->Click += gcnew System::EventHandler(this, &Stats::Bouton_Moins_vendu_Click);
			   // 
			   // Bouton_Achat_stock
			   // 
			   this->Bouton_Achat_stock->Location = System::Drawing::Point(58, 70);
			   this->Bouton_Achat_stock->Name = L"Bouton_Achat_stock";
			   this->Bouton_Achat_stock->Size = System::Drawing::Size(105, 23);
			   this->Bouton_Achat_stock->TabIndex = 0;
			   this->Bouton_Achat_stock->Text = L"Achat stock";
			   this->Bouton_Achat_stock->Click += gcnew System::EventHandler(this, &Stats::Bouton_Achat_stock_Click);
			   // 
			   // Bouton_Valeur_stock
			   // 
			   this->Bouton_Valeur_stock->Location = System::Drawing::Point(58, 99);
			   this->Bouton_Valeur_stock->Name = L"Bouton_Valeur_stock";
			   this->Bouton_Valeur_stock->Size = System::Drawing::Size(105, 23);
			   this->Bouton_Valeur_stock->TabIndex = 0;
			   this->Bouton_Valeur_stock->Text = L"Valeur stock";
			   this->Bouton_Valeur_stock->Click += gcnew System::EventHandler(this, &Stats::Bouton_Valeur_stock_Click);
			   // 
			   // Bouton_Estimation
			   // 
			   this->Bouton_Estimation->Location = System::Drawing::Point(598, 40);
			   this->Bouton_Estimation->Name = L"Bouton_Estimation";
			   this->Bouton_Estimation->Size = System::Drawing::Size(100, 23);
			   this->Bouton_Estimation->TabIndex = 0;
			   this->Bouton_Estimation->Text = L"Estimation";
			   // 
			   // Label_Nom
			   // 
			   this->Label_Nom->AutoSize = true;
			   this->Label_Nom->Location = System::Drawing::Point(197, 18);
			   this->Label_Nom->Name = L"Label_Nom";
			   this->Label_Nom->Size = System::Drawing::Size(29, 13);
			   this->Label_Nom->TabIndex = 18;
			   this->Label_Nom->Text = L"Nom";
			   // 
			   // Label_Prenom
			   // 
			   this->Label_Prenom->AutoSize = true;
			   this->Label_Prenom->Location = System::Drawing::Point(183, 44);
			   this->Label_Prenom->Name = L"Label_Prenom";
			   this->Label_Prenom->Size = System::Drawing::Size(43, 13);
			   this->Label_Prenom->TabIndex = 18;
			   this->Label_Prenom->Text = L"Prenom";
			   // 
			   // Label_Date
			   // 
			   this->Label_Date->AutoSize = true;
			   this->Label_Date->Location = System::Drawing::Point(368, 18);
			   this->Label_Date->Name = L"Label_Date";
			   this->Label_Date->Size = System::Drawing::Size(30, 13);
			   this->Label_Date->TabIndex = 18;
			   this->Label_Date->Text = L"Date";
			   // 
			   // TextBox_Nom
			   // 
			   this->TextBox_Nom->Location = System::Drawing::Point(232, 15);
			   this->TextBox_Nom->Name = L"TextBox_Nom";
			   this->TextBox_Nom->Size = System::Drawing::Size(100, 20);
			   this->TextBox_Nom->TabIndex = 15;
			   // 
			   // TextBox_Prenom
			   // 
			   this->TextBox_Prenom->Location = System::Drawing::Point(232, 43);
			   this->TextBox_Prenom->Name = L"TextBox_Prenom";
			   this->TextBox_Prenom->Size = System::Drawing::Size(100, 20);
			   this->TextBox_Prenom->TabIndex = 15;
			   // 
			   // TextBox_Date
			   // 
			   this->TextBox_Date->Location = System::Drawing::Point(404, 15);
			   this->TextBox_Date->Name = L"TextBox_Date";
			   this->TextBox_Date->Size = System::Drawing::Size(100, 20);
			   this->TextBox_Date->TabIndex = 15;
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->AllowUserToResizeColumns = false;
			   this->dataGridView1->AllowUserToResizeRows = false;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(12, 134);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->Size = System::Drawing::Size(742, 187);
			   this->dataGridView1->TabIndex = 33;
			   // 
			   // Nom
			   // 
			   this->Nom->HeaderText = L"Nom";
			   this->Nom->Name = L"Nom";
			   // 
			   // Stock
			   // 
			   this->Stock->HeaderText = L"Stock";
			   this->Stock->Name = L"Stock";
			   // 
			   // Valeur_achat
			   // 
			   this->Valeur_achat->HeaderText = L"Valeur_achat";
			   this->Valeur_achat->Name = L"Valeur_achat";
			   // 
			   // Chiffre
			   // 
			   this->Chiffre->HeaderText = L"Chiffre";
			   this->Chiffre->Name = L"Chiffre";
			   // 
			   // Panier_moyen
			   // 
			   this->Panier_moyen->HeaderText = L"Valeur panier moyen";
			   this->Panier_moyen->Name = L"Panier_moyen";
			   // 
			   // Total_achat_client
			   // 
			   this->Total_achat_client->HeaderText = L"Total_achat_client";
			   this->Total_achat_client->Name = L"Total_achat_client";
			   // 
			   // Valeur_commerciale
			   // 
			   this->Valeur_commerciale->HeaderText = L"Valeur_commerciale";
			   this->Valeur_commerciale->Name = L"Valeur_commerciale";
			   // 
			   // Total_quantite
			   // 
			   this->Total_quantite->Name = L"Total_quantite";
			   // 
			   // Stats
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(767, 333);
			   this->Controls->Add(this->Bouton_precedent);
			   this->Controls->Add(this->TextBox_Nom);
			   this->Controls->Add(this->TextBox_Prenom);
			   this->Controls->Add(this->TextBox_Date);
			   this->Controls->Add(this->Label_Nom);
			   this->Controls->Add(this->Label_Prenom);
			   this->Controls->Add(this->Label_Date);
			   this->Controls->Add(this->Bouton_Achat_stock);
			   this->Controls->Add(this->Bouton_Chiffre);
			   this->Controls->Add(this->Bouton_Estimation);
			   this->Controls->Add(this->Bouton_Moins_vendu);
			   this->Controls->Add(this->Bouton_Panier_moyen);
			   this->Controls->Add(this->Bouton_Plus_vendu);
			   this->Controls->Add(this->Bouton_Total_achat_client);
			   this->Controls->Add(this->Bouton_Valeur_stock);
			   this->Controls->Add(this->dataGridView1);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Stats";
			   this->Text = L"Stats";
			   this->Load += gcnew System::EventHandler(this, &Stats::Stats_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void Bouton_precedent_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		Precedent->Show();
	}

	private: System::Void Stats_Load(System::Object^ sender, System::EventArgs^ e) {
		//this->load_query();
	}

	private: System::Void Bouton_Panier_moyen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TextBox_Nom->Text == "") {
			TextBox_Nom->ForeColor = System::Drawing::Color::Black;
			TextBox_Nom->BackColor = System::Drawing::Color::IndianRed;	
		}

		if (TextBox_Prenom->Text == "") {
			TextBox_Prenom->ForeColor = System::Drawing::Color::Black;
			TextBox_Prenom->BackColor = System::Drawing::Color::IndianRed;
		}

		if (TextBox_Nom->Text != "" || TextBox_Prenom->Text != "") {
			System::String^ query;
			query = "SELECT * FROM Client WHERE Client.nom = '";
			query += TextBox_Nom->Text;
			query += "' AND Client.prenom = '";
			query += TextBox_Prenom->Text;
			query += "';";

			bool qstate = ConvertQuery(query);

			if (!qstate) {
				res = mysql_store_result(con);
				if (res->row_count == 0) {
					if (TextBox_Nom->Text != "") {
						TextBox_Nom->ForeColor = System::Drawing::Color::Red;
						TextBox_Nom->BackColor = System::Drawing::Color::White;
					}
					if (TextBox_Prenom->Text != "") {
						TextBox_Prenom->ForeColor = System::Drawing::Color::Red;
						TextBox_Prenom->BackColor = System::Drawing::Color::White;
					}
				}
				else {
					TextBox_Nom->ForeColor = System::Drawing::Color::Black;
					TextBox_Nom->BackColor = System::Drawing::Color::White;
					TextBox_Prenom->ForeColor = System::Drawing::Color::Black;
					TextBox_Prenom->BackColor = System::Drawing::Color::White;

					this->dataGridView1->Rows->Clear();
					this->dataGridView1->Columns->Clear();
					this->dataGridView1->Refresh();

					this->dataGridView1->Columns->Add(this->Panier_moyen);
					
					ConnectDatabase();
					
					svc_Client^ obj = gcnew svc_Client();
					MYSQL_RES* res = obj->svc1_1(TextBox_Nom->Text, TextBox_Prenom->Text);
					
					while (MYSQL_ROW row = mysql_fetch_row(res)) {
						int i = this->dataGridView1->Rows->Add();

						dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
					}
				}
			}
		}
	}
	private: System::Void Bouton_Total_achat_client_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TextBox_Nom->Text == "") {
			TextBox_Nom->ForeColor = System::Drawing::Color::Black;
			TextBox_Nom->BackColor = System::Drawing::Color::IndianRed;
		}

		if (TextBox_Prenom->Text == "") {
			TextBox_Prenom->ForeColor = System::Drawing::Color::Black;
			TextBox_Prenom->BackColor = System::Drawing::Color::IndianRed;
		}

		if (TextBox_Nom->Text != "" || TextBox_Prenom->Text != "") {
			System::String^ query;
			query = "SELECT * FROM Client WHERE Client.nom = '";
			query += TextBox_Nom->Text;
			query += "' AND Client.prenom = '";
			query += TextBox_Prenom->Text;
			query += "';";

			bool qstate = ConvertQuery(query);

			if (!qstate) {
				res = mysql_store_result(con);
				if (res->row_count == 0) {
					if (TextBox_Nom->Text != "") {
						TextBox_Nom->ForeColor = System::Drawing::Color::Red;
						TextBox_Nom->BackColor = System::Drawing::Color::White;
					}
					if (TextBox_Prenom->Text != "") {
						TextBox_Prenom->ForeColor = System::Drawing::Color::Red;
						TextBox_Prenom->BackColor = System::Drawing::Color::White;
					}
				}
				else {
					TextBox_Nom->ForeColor = System::Drawing::Color::Black;
					TextBox_Nom->BackColor = System::Drawing::Color::White;
					TextBox_Prenom->ForeColor = System::Drawing::Color::Black;
					TextBox_Prenom->BackColor = System::Drawing::Color::White;

					this->dataGridView1->Rows->Clear();
					this->dataGridView1->Columns->Clear();
					this->dataGridView1->Refresh();
					
					this->dataGridView1->Columns->Add(this->Total_achat_client);

					ConnectDatabase();

					svc_Client^ obj = gcnew svc_Client();
					MYSQL_RES* res = obj->svc1_2(TextBox_Nom->Text, TextBox_Prenom->Text);

					while (MYSQL_ROW row = mysql_fetch_row(res)) {
						int i = this->dataGridView1->Rows->Add();

						dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
					}
				}
			}
		}
	}

	private: System::Void Bouton_Plus_vendu_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->Rows->Clear();
		this->dataGridView1->Columns->Clear();
		this->dataGridView1->Refresh();

		this->dataGridView1->Columns->Add(this->Nom);
		this->dataGridView1->Columns->Add(this->Total_quantite);

		ConnectDatabase();
		
		svc_Vente^ obj = gcnew svc_Vente();
		MYSQL_RES* res = obj->svc3_2();

		while (MYSQL_ROW row = mysql_fetch_row(res)) {
			int i = dataGridView1->Rows->Add();

			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[1]);
		}
	}

	private: System::Void Bouton_Moins_vendu_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->Rows->Clear();
		this->dataGridView1->Columns->Clear();
		this->dataGridView1->Refresh();

		this->dataGridView1->Columns->Add(this->Nom);
		this->dataGridView1->Columns->Add(this->Total_quantite);

		ConnectDatabase();
		
		svc_Vente^ obj = gcnew svc_Vente();
		MYSQL_RES* res = obj->svc3_1();

		while (MYSQL_ROW row = mysql_fetch_row(res)) {
			int i = dataGridView1->Rows->Add();	

			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[1]);
		}
	}

	private: System::Void Bouton_Achat_stock_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->Rows->Clear();
		this->dataGridView1->Columns->Clear();
		this->dataGridView1->Refresh();

		this->dataGridView1->Columns->Add(this->Nom);
		this->dataGridView1->Columns->Add(this->Stock);
		this->dataGridView1->Columns->Add(this->Valeur_achat);

		ConnectDatabase();
		
		svc_Stock^ obj = gcnew svc_Stock();
		MYSQL_RES* res = obj->svc4_1();

		while (MYSQL_ROW row = mysql_fetch_row(res)) {
			int i = dataGridView1->Rows->Add();
			
			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[1]);
			dataGridView1->Rows[i]->Cells[2]->Value = gcnew String(row[2]);
		}
	}

	private: System::Void Bouton_Valeur_stock_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->Rows->Clear();
		this->dataGridView1->Columns->Clear();
		this->dataGridView1->Refresh();

		this->dataGridView1->Columns->Add(this->Nom);
		this->dataGridView1->Columns->Add(this->Stock);
		this->dataGridView1->Columns->Add(this->Valeur_commerciale);

		ConnectDatabase();
		
		svc_Stock^ obj = gcnew svc_Stock();
		MYSQL_RES* res = obj->svc4_2();

		while (MYSQL_ROW row = mysql_fetch_row(res)) {
			int i = dataGridView1->Rows->Add();
			
			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[1]);
			dataGridView1->Rows[i]->Cells[2]->Value = gcnew String(row[2]);
		}
	}	

	private: System::Void Bouton_Chiffre_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TextBox_Date->Text == "") {
			TextBox_Date->ForeColor = System::Drawing::Color::Black;
			TextBox_Date->BackColor = System::Drawing::Color::IndianRed;
		}
		if (TextBox_Date->Text != "") {
			TextBox_Date->ForeColor = System::Drawing::Color::Black;
			TextBox_Date->BackColor = System::Drawing::Color::White;

			this->dataGridView1->Rows->Clear();
			this->dataGridView1->Columns->Clear();
			this->dataGridView1->Refresh();

			this->dataGridView1->Columns->Add(this->Chiffre);

			ConnectDatabase();

			svc_Chiffre_affaire^ obj = gcnew svc_Chiffre_affaire();
			MYSQL_RES* res = obj->svc2_1(TextBox_Date->Text);

			while (MYSQL_ROW row = mysql_fetch_row(res)) {
				int i = this->dataGridView1->Rows->Add();

				dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
			}
		}
	}


	

};
}
