#pragma once
#include <mysql.h>
#include <vcclr.h>
#include "IHM_Stats.h"
#include "SC.h"

namespace NS_Stats {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NS_SuperC;
	/*using namespace std;*/
	
	/// <summary>
	/// Description résumée de Stats
	/// </summary>
	public ref class Stats : public SuperC
	{
	public:
		Stats(Form^ InpPrecedent):SuperC(InpPrecedent)
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
	private: System::Windows::Forms::TextBox^ TextTVA;
	private: System::Windows::Forms::TextBox^ TextRemise;
	private: System::Windows::Forms::TextBox^ TextMarge;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

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
			   this->TextTVA = (gcnew System::Windows::Forms::TextBox());
			   this->TextRemise = (gcnew System::Windows::Forms::TextBox());
			   this->TextMarge = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Bouton_precedent
			   // 
			   this->Bouton_precedent->Location = System::Drawing::Point(16, 15);
			   this->Bouton_precedent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_precedent->Name = L"Bouton_precedent";
			   this->Bouton_precedent->Size = System::Drawing::Size(33, 31);
			   this->Bouton_precedent->TabIndex = 21;
			   this->Bouton_precedent->Text = L"<";
			   this->Bouton_precedent->UseVisualStyleBackColor = true;
			   this->Bouton_precedent->Click += gcnew System::EventHandler(this, &Stats::Bouton_precedent_Click);
			   // 
			   // Bouton_Panier_moyen
			   // 
			   this->Bouton_Panier_moyen->Location = System::Drawing::Point(309, 86);
			   this->Bouton_Panier_moyen->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Panier_moyen->Name = L"Bouton_Panier_moyen";
			   this->Bouton_Panier_moyen->Size = System::Drawing::Size(133, 28);
			   this->Bouton_Panier_moyen->TabIndex = 0;
			   this->Bouton_Panier_moyen->Text = L"Panier moyen";
			   this->Bouton_Panier_moyen->Click += gcnew System::EventHandler(this, &Stats::Bouton_Panier_moyen_Click);
			   // 
			   // Bouton_Total_achat_client
			   // 
			   this->Bouton_Total_achat_client->Location = System::Drawing::Point(309, 122);
			   this->Bouton_Total_achat_client->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Total_achat_client->Name = L"Bouton_Total_achat_client";
			   this->Bouton_Total_achat_client->Size = System::Drawing::Size(133, 28);
			   this->Bouton_Total_achat_client->TabIndex = 0;
			   this->Bouton_Total_achat_client->Text = L"Total achat client";
			   this->Bouton_Total_achat_client->Click += gcnew System::EventHandler(this, &Stats::Bouton_Total_achat_client_Click);
			   // 
			   // Bouton_Chiffre
			   // 
			   this->Bouton_Chiffre->Location = System::Drawing::Point(539, 50);
			   this->Bouton_Chiffre->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Chiffre->Name = L"Bouton_Chiffre";
			   this->Bouton_Chiffre->Size = System::Drawing::Size(133, 28);
			   this->Bouton_Chiffre->TabIndex = 0;
			   this->Bouton_Chiffre->Text = L"Chiffre";
			   this->Bouton_Chiffre->Click += gcnew System::EventHandler(this, &Stats::Bouton_Chiffre_Click);
			   // 
			   // Bouton_Plus_vendu
			   // 
			   this->Bouton_Plus_vendu->Location = System::Drawing::Point(77, 16);
			   this->Bouton_Plus_vendu->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Plus_vendu->Name = L"Bouton_Plus_vendu";
			   this->Bouton_Plus_vendu->Size = System::Drawing::Size(140, 28);
			   this->Bouton_Plus_vendu->TabIndex = 0;
			   this->Bouton_Plus_vendu->Text = L"Plus vendu";
			   this->Bouton_Plus_vendu->Click += gcnew System::EventHandler(this, &Stats::Bouton_Plus_vendu_Click);
			   // 
			   // Bouton_Moins_vendu
			   // 
			   this->Bouton_Moins_vendu->Location = System::Drawing::Point(77, 50);
			   this->Bouton_Moins_vendu->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Moins_vendu->Name = L"Bouton_Moins_vendu";
			   this->Bouton_Moins_vendu->Size = System::Drawing::Size(140, 28);
			   this->Bouton_Moins_vendu->TabIndex = 0;
			   this->Bouton_Moins_vendu->Text = L"Moins vendu";
			   this->Bouton_Moins_vendu->Click += gcnew System::EventHandler(this, &Stats::Bouton_Moins_vendu_Click);
			   // 
			   // Bouton_Achat_stock
			   // 
			   this->Bouton_Achat_stock->Location = System::Drawing::Point(77, 86);
			   this->Bouton_Achat_stock->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Achat_stock->Name = L"Bouton_Achat_stock";
			   this->Bouton_Achat_stock->Size = System::Drawing::Size(140, 28);
			   this->Bouton_Achat_stock->TabIndex = 0;
			   this->Bouton_Achat_stock->Text = L"Achat stock";
			   this->Bouton_Achat_stock->Click += gcnew System::EventHandler(this, &Stats::Bouton_Achat_stock_Click);
			   // 
			   // Bouton_Valeur_stock
			   // 
			   this->Bouton_Valeur_stock->Location = System::Drawing::Point(77, 122);
			   this->Bouton_Valeur_stock->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Valeur_stock->Name = L"Bouton_Valeur_stock";
			   this->Bouton_Valeur_stock->Size = System::Drawing::Size(140, 28);
			   this->Bouton_Valeur_stock->TabIndex = 0;
			   this->Bouton_Valeur_stock->Text = L"Valeur stock";
			   this->Bouton_Valeur_stock->Click += gcnew System::EventHandler(this, &Stats::Bouton_Valeur_stock_Click);
			   // 
			   // Bouton_Estimation
			   // 
			   this->Bouton_Estimation->Location = System::Drawing::Point(726, 50);
			   this->Bouton_Estimation->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Bouton_Estimation->Name = L"Bouton_Estimation";
			   this->Bouton_Estimation->Size = System::Drawing::Size(133, 28);
			   this->Bouton_Estimation->TabIndex = 0;
			   this->Bouton_Estimation->Text = L"Estimation";
			   this->Bouton_Estimation->Click += gcnew System::EventHandler(this, &Stats::Bouton_Estimation_Click);
			   // 
			   // Label_Nom
			   // 
			   this->Label_Nom->AutoSize = true;
			   this->Label_Nom->Location = System::Drawing::Point(263, 22);
			   this->Label_Nom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Label_Nom->Name = L"Label_Nom";
			   this->Label_Nom->Size = System::Drawing::Size(37, 17);
			   this->Label_Nom->TabIndex = 18;
			   this->Label_Nom->Text = L"Nom";
			   // 
			   // Label_Prenom
			   // 
			   this->Label_Prenom->AutoSize = true;
			   this->Label_Prenom->Location = System::Drawing::Point(244, 54);
			   this->Label_Prenom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Label_Prenom->Name = L"Label_Prenom";
			   this->Label_Prenom->Size = System::Drawing::Size(57, 17);
			   this->Label_Prenom->TabIndex = 18;
			   this->Label_Prenom->Text = L"Prenom";
			   // 
			   // Label_Date
			   // 
			   this->Label_Date->AutoSize = true;
			   this->Label_Date->Location = System::Drawing::Point(491, 22);
			   this->Label_Date->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Label_Date->Name = L"Label_Date";
			   this->Label_Date->Size = System::Drawing::Size(38, 17);
			   this->Label_Date->TabIndex = 18;
			   this->Label_Date->Text = L"Date";
			   // 
			   // TextBox_Nom
			   // 
			   this->TextBox_Nom->Location = System::Drawing::Point(309, 18);
			   this->TextBox_Nom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TextBox_Nom->Name = L"TextBox_Nom";
			   this->TextBox_Nom->Size = System::Drawing::Size(132, 22);
			   this->TextBox_Nom->TabIndex = 15;
			   // 
			   // TextBox_Prenom
			   // 
			   this->TextBox_Prenom->Location = System::Drawing::Point(309, 53);
			   this->TextBox_Prenom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TextBox_Prenom->Name = L"TextBox_Prenom";
			   this->TextBox_Prenom->Size = System::Drawing::Size(132, 22);
			   this->TextBox_Prenom->TabIndex = 15;
			   // 
			   // TextBox_Date
			   // 
			   this->TextBox_Date->Location = System::Drawing::Point(539, 18);
			   this->TextBox_Date->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TextBox_Date->Name = L"TextBox_Date";
			   this->TextBox_Date->Size = System::Drawing::Size(132, 22);
			   this->TextBox_Date->TabIndex = 15;
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->AllowUserToResizeColumns = false;
			   this->dataGridView1->AllowUserToResizeRows = false;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(16, 165);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->Size = System::Drawing::Size(989, 230);
			   this->dataGridView1->TabIndex = 33;
			   // 
			   // Nom
			   // 
			   this->Nom->HeaderText = L"Nom";
			   this->Nom->MinimumWidth = 6;
			   this->Nom->Name = L"Nom";
			   this->Nom->Width = 125;
			   // 
			   // Stock
			   // 
			   this->Stock->HeaderText = L"Stock";
			   this->Stock->MinimumWidth = 6;
			   this->Stock->Name = L"Stock";
			   this->Stock->Width = 125;
			   // 
			   // Valeur_achat
			   // 
			   this->Valeur_achat->HeaderText = L"Valeur_achat";
			   this->Valeur_achat->MinimumWidth = 6;
			   this->Valeur_achat->Name = L"Valeur_achat";
			   this->Valeur_achat->Width = 125;
			   // 
			   // Chiffre
			   // 
			   this->Chiffre->HeaderText = L"Chiffre";
			   this->Chiffre->MinimumWidth = 6;
			   this->Chiffre->Name = L"Chiffre";
			   this->Chiffre->Width = 125;
			   // 
			   // Panier_moyen
			   // 
			   this->Panier_moyen->HeaderText = L"Valeur panier moyen";
			   this->Panier_moyen->MinimumWidth = 6;
			   this->Panier_moyen->Name = L"Panier_moyen";
			   this->Panier_moyen->Width = 125;
			   // 
			   // Total_achat_client
			   // 
			   this->Total_achat_client->HeaderText = L"Total_achat_client";
			   this->Total_achat_client->MinimumWidth = 6;
			   this->Total_achat_client->Name = L"Total_achat_client";
			   this->Total_achat_client->Width = 125;
			   // 
			   // Valeur_commerciale
			   // 
			   this->Valeur_commerciale->HeaderText = L"Valeur_commerciale";
			   this->Valeur_commerciale->MinimumWidth = 6;
			   this->Valeur_commerciale->Name = L"Valeur_commerciale";
			   this->Valeur_commerciale->Width = 125;
			   // 
			   // Total_quantite
			   // 
			   this->Total_quantite->MinimumWidth = 6;
			   this->Total_quantite->Name = L"Total_quantite";
			   this->Total_quantite->Width = 125;
			   // 
			   // TextTVA
			   // 
			   this->TextTVA->Location = System::Drawing::Point(880, 136);
			   this->TextTVA->Name = L"TextTVA";
			   this->TextTVA->Size = System::Drawing::Size(100, 22);
			   this->TextTVA->TabIndex = 34;
			   // 
			   // TextRemise
			   // 
			   this->TextRemise->Location = System::Drawing::Point(880, 76);
			   this->TextRemise->Name = L"TextRemise";
			   this->TextRemise->Size = System::Drawing::Size(100, 22);
			   this->TextRemise->TabIndex = 35;
			   // 
			   // TextMarge
			   // 
			   this->TextMarge->Location = System::Drawing::Point(880, 24);
			   this->TextMarge->Name = L"TextMarge";
			   this->TextMarge->Size = System::Drawing::Size(100, 22);
			   this->TextMarge->TabIndex = 36;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(886, 116);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(46, 17);
			   this->label1->TabIndex = 37;
			   this->label1->Text = L"Marge";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(886, 56);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(55, 17);
			   this->label2->TabIndex = 38;
			   this->label2->Text = L"Remise";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(886, 4);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(35, 17);
			   this->label3->TabIndex = 39;
			   this->label3->Text = L"TVA";
			   // 
			   // Stats
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1023, 410);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->TextMarge);
			   this->Controls->Add(this->TextRemise);
			   this->Controls->Add(this->TextTVA);
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
			   this->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
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


	

private: System::Void Bouton_Estimation_Click(System::Object^ sender, System::EventArgs^ e) {

	this->dataGridView1->Rows->Clear();
	this->dataGridView1->Columns->Clear();
	this->dataGridView1->Refresh();

	this->dataGridView1->Columns->Add("Nom","Nom Article");
	this->dataGridView1->Columns->Add("Stock","Stock");
	this->dataGridView1->Columns->Add("Valeur","Valeur Stock Simule");
	this->dataGridView1->Columns->Add("Valeur", "Valeur Unitaire Simule");




	svc_Estimation^ obj = gcnew svc_Estimation();
	MYSQL_RES* res = obj->svc5_1(TextTVA->Text, TextRemise->Text, TextMarge->Text);
	MYSQL_ROW row;
	int i = 0;
	while (row = mysql_fetch_row(res)) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
		dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[1]);
		dataGridView1->Rows[i]->Cells[2]->Value = gcnew String(row[2]);
		dataGridView1->Rows[i]->Cells[3]->Value = gcnew String(row[3]);
		i++;
	}
}
};
}
