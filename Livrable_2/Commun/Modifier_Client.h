#pragma once
#include "SC.h"
//#include "Creation_Client.h"
#include <mysql.h>
#include <vcclr.h>

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Modifier_Client : public NS_SuperC::SuperC // public System::Windows::Forms::Form
	{
	public:
		Modifier_Client(Form^ InpPrecedent, System::String^ i_id): SuperC(inpPrecedent) {
			id = i_id;
			// Precedent = InpPrecedent;
			ConnectDatabase();
			InitializeComponent();
		}


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_date;
	private: System::Windows::Forms::TextBox^ textBox_prenom;
	private: System::Windows::Forms::TextBox^ textBox_nom;


	public:

	private: System::String^ id;

	// private: System::Windows::Forms::Form^ Precedent;

	private:
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;


	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_adresse;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_ville;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ data_livr;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ data_fact;
	private: System::Windows::Forms::DataGridViewButtonColumn^ data_supr;
	private: System::Windows::Forms::DataGridViewButtonColumn^ data_upda;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ancienne_adresse;


	private: System::ComponentModel::IContainer^ components;

	private:



#pragma region Windows Form Designer generated code


		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_date = (gcnew System::Windows::Forms::TextBox());
			this->textBox_prenom = (gcnew System::Windows::Forms::TextBox());
			this->textBox_nom = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->data_adresse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_ville = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->data_livr = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->data_fact = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->data_supr = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->data_upda = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->data_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ancienne_adresse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			//
			// button2
			//
			// this->button2->Location = System::Drawing::Point(16, 15);
			// this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			// this->button2->Name = L"button2";
			// this->button2->Size = System::Drawing::Size(33, 31);
			// this->button2->TabIndex = 21;
			// this->button2->Text = L"<";
			// this->button2->UseVisualStyleBackColor = true;
			// this->button2->Click += gcnew System::EventHandler(this, &Modifier_Client::button2_Click);
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(375, 71);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 17);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Date";
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(203, 71);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 17);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Prenom";
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 71);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 17);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Nom";
			//
			// textBox_date
			//
			this->textBox_date->Location = System::Drawing::Point(379, 91);
			this->textBox_date->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_date->Name = L"textBox_date";
			this->textBox_date->Size = System::Drawing::Size(132, 22);
			this->textBox_date->TabIndex = 17;
			//
			// textBox_prenom
			//
			this->textBox_prenom->Location = System::Drawing::Point(207, 91);
			this->textBox_prenom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_prenom->Name = L"textBox_prenom";
			this->textBox_prenom->Size = System::Drawing::Size(132, 22);
			this->textBox_prenom->TabIndex = 16;
			//
			// textBox_nom
			//
			this->textBox_nom->Location = System::Drawing::Point(31, 91);
			this->textBox_nom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_nom->Name = L"textBox_nom";
			this->textBox_nom->Size = System::Drawing::Size(132, 22);
			this->textBox_nom->TabIndex = 15;
			//
			// dataGridView1
			//
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->data_adresse,
					this->data_ville, this->data_livr, this->data_fact, this->data_supr, this->data_upda, this->data_id, this->ancienne_adresse
			});
			this->dataGridView1->Location = System::Drawing::Point(545, 63);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(936, 180);
			this->dataGridView1->TabIndex = 33;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Modifier_Client::dataGridView1_CellContentClick);
			this->dataGridView1->UserAddedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &Modifier_Client::dataGridView1_UserAddedRow);
			//
			// data_adresse
			//
			this->data_adresse->HeaderText = L"adresse";
			this->data_adresse->MinimumWidth = 6;
			this->data_adresse->Name = L"data_adresse";
			this->data_adresse->Width = 125;
			//
			// data_ville
			//
			this->data_ville->HeaderText = L"ville";
			this->data_ville->MinimumWidth = 6;
			this->data_ville->Name = L"data_ville";
			this->data_ville->Width = 125;
			//
			// data_livr
			//
			this->data_livr->FalseValue = L"0";
			this->data_livr->HeaderText = L"livraison";
			this->data_livr->MinimumWidth = 6;
			this->data_livr->Name = L"data_livr";
			this->data_livr->TrueValue = L"1";
			this->data_livr->Width = 125;
			//
			// data_fact
			//
			this->data_fact->FalseValue = L"0";
			this->data_fact->HeaderText = L"facturation";
			this->data_fact->MinimumWidth = 6;
			this->data_fact->Name = L"data_fact";
			this->data_fact->TrueValue = L"1";
			this->data_fact->Width = 125;
			//
			// data_supr
			//
			this->data_supr->HeaderText = L"";
			this->data_supr->MinimumWidth = 6;
			this->data_supr->Name = L"data_supr";
			this->data_supr->Width = 125;
			//
			// data_upda
			//
			this->data_upda->HeaderText = L"";
			this->data_upda->MinimumWidth = 6;
			this->data_upda->Name = L"data_upda";
			this->data_upda->Width = 125;
			//
			// data_id
			//
			this->data_id->HeaderText = L"id";
			this->data_id->MinimumWidth = 6;
			this->data_id->Name = L"data_id";
			this->data_id->Visible = false;
			this->data_id->Width = 125;
			//
			// ancienne_adresse
			//
			this->ancienne_adresse->HeaderText = L"data_old_adr";
			this->ancienne_adresse->MinimumWidth = 6;
			this->ancienne_adresse->Name = L"ancienne_adresse";
			this->ancienne_adresse->Visible = false;
			this->ancienne_adresse->Width = 125;
			//
			// Modifier_Client
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1721, 471);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_date);
			this->Controls->Add(this->textBox_prenom);
			this->Controls->Add(this->textBox_nom);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Modifier_Client";
			this->Text = L"Creation_Client";
			this->Load += gcnew System::EventHandler(this, &Modifier_Client::Modifier_Client_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		void ConnectDatabase() {
			con = mysql_init(NULL);
			if (con == NULL) {
				//label1->Text = "Base inexistante";
			}
			else {
				//label1->Text = "Base existante";
			}

			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				//if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, 0) == NULL) {
					//label2->Text = "Erreur de connection a la base";
			}
			else {
				//label2->Text = "Connection a la base";
			}
		}

		void load_query() {
			ConnectDatabase();

			this->dataGridView1->Rows->Clear();
			this->dataGridView1->Refresh();


			System::String^ query;
			query = "SELECT Client.nom, Client.prenom, Client.date_naissance, adresse_client, Ville.ville, Type_adresse.type_adresse, ID_adresse_client FROM Adresse_client INNER JOIN Client ON Adresse_client.ID_client = Client.ID_client INNER JOIN Type_adresse ON Adresse_client.ID_type_adresse = Type_adresse.ID_type_adresse INNER JOIN Ville ON Adresse_client.ID_ville = Ville.ID_ville WHERE Adresse_client.ID_client = '";
			query += id;
			query += "';";

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
			if (!qstate) {
				res = mysql_store_result(con);
				while (row = mysql_fetch_row(res)) {
					int i = 0;
					i = dataGridView1->Rows->Add();

					if (i == 0) {
						textBox_nom->Text = gcnew String(row[0]);
						textBox_prenom->Text = gcnew String(row[1]);
						textBox_date->Text = gcnew String(row[2]);
					}

					dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[3]);
					dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[4]);

					dataGridView1->Rows[i]->Cells[7]->Value = gcnew String(row[3]);


					if (gcnew String(row[5]) == "livraison et facturation") {
						dataGridView1->Rows[i]->Cells[2]->Value = true;
						dataGridView1->Rows[i]->Cells[3]->Value = true;
					}
					else if (gcnew String(row[5]) == "livraison") {
						dataGridView1->Rows[i]->Cells[2]->Value = true;
						dataGridView1->Rows[i]->Cells[3]->Value = false;
					}
					else if (gcnew String(row[5]) == "facturation") {
						dataGridView1->Rows[i]->Cells[2]->Value = false;
						dataGridView1->Rows[i]->Cells[3]->Value = true;
					}

					dataGridView1->Rows[i]->Cells[4]->Value = "suprimer";
					dataGridView1->Rows[i]->Cells[5]->Value = "save";

					dataGridView1->Rows[i]->Cells[6]->Value = gcnew  String(row[6]);
				}
			}
			else {
				//textBox_retour->Text = "erreur de requ�te";
			}
		}

	private: System::Void Modifier_Client_Load(System::Object^ sender, System::EventArgs^ e) {
		this->load_query();
	}

	// private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// 	this->Close();
	// 	Precedent->Show();
	// }


	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = e->RowIndex;
		int j = e->ColumnIndex;


		System::String^ query;

		if (j == 4 && dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "suprimer") {
			query = "START TRANSACTION; CALL delete_Adresse_client('";
			query += dataGridView1->Rows[i]->Cells[6]->Value->ToString();
			query += "'); CALL verification_Adresse_client('";
			query += id;
			query += "'); COMMIT;";
		}
		else if (j == 4 && dataGridView1->Rows[i]->Cells[4]->Value->ToString() == "ajout") {

			if (dataGridView1->Rows[i]->Cells[0]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[1]->Value->ToString() != "" && (dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "True" || dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "True")) {

				query = "START TRANSACTION; CALL ajout_Adresse_client('";
				query += id;
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[0]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[1]->Value->ToString();

				System::String^ exit;
				exit = dataGridView1->Rows[i]->Cells[2]->Value->ToString();
				exit += "   ";
				exit += dataGridView1->Rows[i]->Cells[3]->Value->ToString();


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
				query += id;
				query += "'); COMMIT;";

			}
		}
		else if (j == 5) {

			if (dataGridView1->Rows[i]->Cells[0]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[1]->Value->ToString() != "" && (dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "True" || dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "1" || dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "True")) {
				query = "START TRANSACTION; CALL update_Adresse_client('";
				query += id;
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[6]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[0]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[7]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[1]->Value->ToString();

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
				query += id;
				query += "'); COMMIT;";

			}
		}
		else {
			return;
		}

		//richTextBox1->Text = query;

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
		if (qstate) {
			//textBox_retour->Text = "Erreur";
		}
		else {
			//textBox_retour->Text = "requete effectuer";
		}


		this->load_query();
	}

	private: System::Void dataGridView1_UserAddedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[4]->Value = "ajout";
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[2]->Value = false;
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[3]->Value = false;
	}
};
}
