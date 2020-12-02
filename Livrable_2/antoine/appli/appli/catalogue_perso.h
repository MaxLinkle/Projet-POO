#pragma once
#include <mysql.h>
#include <vcclr.h>

namespace Perso {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Catalogue_Perso : public System::Windows::Forms::Form
	{
	public:
		Catalogue_Perso(void) {
			ConnectDatabase();
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Catalogue_Perso()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;

	private:
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::DataGridView^ dataGridView1;









	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_ref;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_prixht;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_tva;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_coeff;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_stock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ data_seuil;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ data_actif;
	private: System::Windows::Forms::DataGridViewButtonColumn^ data_save;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;




#pragma region Windows Choix Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->data_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_ref = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_prixht = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_tva = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_coeff = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_seuil = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->data_actif = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			   this->data_save = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				   this->data_id,
					   this->data_nom, this->data_ref, this->data_prixht, this->data_tva, this->data_coeff, this->data_stock, this->data_seuil, this->data_actif,
					   this->data_save
			   });
			   this->dataGridView1->Location = System::Drawing::Point(9, 46);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(1204, 214);
			   this->dataGridView1->TabIndex = 0;
			   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Catalogue_Perso::dataGridView1_CellContentClick);
			   this->dataGridView1->UserAddedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &Catalogue_Perso::dataGridView1_UserAddedRow);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(303, 376);
			   this->textBox1->Margin = System::Windows::Forms::Padding(2);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(458, 20);
			   this->textBox1->TabIndex = 1;
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->Location = System::Drawing::Point(773, 347);
			   this->richTextBox1->Margin = System::Windows::Forms::Padding(2);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->Size = System::Drawing::Size(440, 106);
			   this->richTextBox1->TabIndex = 2;
			   this->richTextBox1->Text = L"";
			   // 
			   // data_id
			   // 
			   this->data_id->HeaderText = L"data_id";
			   this->data_id->MinimumWidth = 6;
			   this->data_id->Name = L"data_id";
			   this->data_id->Visible = false;
			   this->data_id->Width = 125;
			   // 
			   // data_nom
			   // 
			   this->data_nom->HeaderText = L"nom";
			   this->data_nom->MinimumWidth = 6;
			   this->data_nom->Name = L"data_nom";
			   this->data_nom->Width = 125;
			   // 
			   // data_ref
			   // 
			   this->data_ref->HeaderText = L"Reference";
			   this->data_ref->MinimumWidth = 6;
			   this->data_ref->Name = L"data_ref";
			   this->data_ref->Width = 125;
			   // 
			   // data_prixht
			   // 
			   this->data_prixht->HeaderText = L"prix_HT";
			   this->data_prixht->MinimumWidth = 6;
			   this->data_prixht->Name = L"data_prixht";
			   this->data_prixht->Width = 125;
			   // 
			   // data_tva
			   // 
			   this->data_tva->HeaderText = L"TVA";
			   this->data_tva->MinimumWidth = 6;
			   this->data_tva->Name = L"data_tva";
			   this->data_tva->Width = 125;
			   // 
			   // data_coeff
			   // 
			   this->data_coeff->HeaderText = L"Coeff_reduc";
			   this->data_coeff->MinimumWidth = 6;
			   this->data_coeff->Name = L"data_coeff";
			   this->data_coeff->Width = 125;
			   // 
			   // data_stock
			   // 
			   this->data_stock->HeaderText = L"Stock";
			   this->data_stock->MinimumWidth = 6;
			   this->data_stock->Name = L"data_stock";
			   this->data_stock->Width = 125;
			   // 
			   // data_seuil
			   // 
			   this->data_seuil->HeaderText = L"Seuil";
			   this->data_seuil->MinimumWidth = 6;
			   this->data_seuil->Name = L"data_seuil";
			   this->data_seuil->Width = 125;
			   // 
			   // data_actif
			   // 
			   this->data_actif->FalseValue = L"0";
			   this->data_actif->HeaderText = L"Actif";
			   this->data_actif->MinimumWidth = 6;
			   this->data_actif->Name = L"data_actif";
			   this->data_actif->TrueValue = L"1";
			   this->data_actif->Width = 125;
			   // 
			   // data_save
			   // 
			   this->data_save->HeaderText = L"Save";
			   this->data_save->MinimumWidth = 6;
			   this->data_save->Name = L"data_save";
			   this->data_save->Width = 125;
			   // 
			   // Catalogue_Perso
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1290, 461);
			   this->Controls->Add(this->richTextBox1);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->dataGridView1);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"Catalogue_Perso";
			   this->Text = L"Choix";
			   this->Load += gcnew System::EventHandler(this, &Catalogue_Perso::Catalogue_Perso_Load);
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
			   query = "SELECT ID_article, nom, reference, prix_ht, taux_tva, coefficient_economie, stock, seuil_reapprovisionnement, actif FROM Catalogue;";

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

					   dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(row[0]);
					   dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(row[1]);
					   dataGridView1->Rows[i]->Cells[2]->Value = gcnew String(row[2]);
					   dataGridView1->Rows[i]->Cells[3]->Value = gcnew String(row[3]);
					   dataGridView1->Rows[i]->Cells[4]->Value = gcnew String(row[4]);
					   dataGridView1->Rows[i]->Cells[5]->Value = gcnew String(row[5]);
					   dataGridView1->Rows[i]->Cells[6]->Value = gcnew String(row[6]);
					   dataGridView1->Rows[i]->Cells[7]->Value = gcnew String(row[7]);

					   System::String^ mensonge;
					   mensonge = "oui ";
					   mensonge += gcnew String(row[8]);

					   textBox1->Text = mensonge;


					   if (gcnew String(row[8]) == "1") {
						   dataGridView1->Rows[i]->Cells[8]->Value = true;
					   }
					   else if (gcnew String(row[8]) == "0") {
						   dataGridView1->Rows[i]->Cells[8]->Value = false;
					   }

					   dataGridView1->Rows[i]->Cells[9]->Value = "save";

				   }
			   }
			   else {

			   }
		   }

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = e->RowIndex;
		int j = e->ColumnIndex;

		System::String^ query;

		if (j == 9 && dataGridView1->Rows[i]->Cells[9]->Value->ToString() == "save") {

			if (dataGridView1->Rows[i]->Cells[0]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[1]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[2]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[3]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[4]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[5]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[6]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[7]->Value->ToString() != "") {
				query = "START TRANSACTION; CALL update_Catalogue_perso('";
				query += dataGridView1->Rows[i]->Cells[0]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[1]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[2]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[3]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[4]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[5]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[6]->Value->ToString();
				query += "', '";
				query += dataGridView1->Rows[i]->Cells[7]->Value->ToString();


				if (dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "True" || dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "1") {
					query += "', '1');";
				}
				else if (dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "False" || dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "0") {
					query += "', '0');";
				}

				query += " CALL verification_Catalogue_perso('";
				query += dataGridView1->Rows[i]->Cells[0]->Value->ToString();
				query += "'); COMMIT;";
			}
		}
		else if (j == 9 && dataGridView1->Rows[i]->Cells[9]->Value->ToString() == "ajout") {

			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[2]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[3]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[4]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[5]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[6]->Value->ToString() != "" && dataGridView1->Rows[i]->Cells[7]->Value->ToString() != "") {
				System::String^ parametre;

				parametre = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
				parametre += "', '";
				parametre += dataGridView1->Rows[i]->Cells[2]->Value->ToString();
				parametre += "', '";
				parametre += dataGridView1->Rows[i]->Cells[3]->Value->ToString();
				parametre += "', '";
				parametre += dataGridView1->Rows[i]->Cells[4]->Value->ToString();
				parametre += "', '";
				parametre += dataGridView1->Rows[i]->Cells[5]->Value->ToString();
				parametre += "', '";
				parametre += dataGridView1->Rows[i]->Cells[6]->Value->ToString();
				parametre += "', '";
				parametre += dataGridView1->Rows[i]->Cells[7]->Value->ToString();


				if (dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "True" || dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "1") {
					parametre += "', '1');";
				}
				else if (dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "False" || dataGridView1->Rows[i]->Cells[8]->Value->ToString() == "0") {
					parametre += "', '0');";
				}

				query = "START TRANSACTION; CALL ajout_Catalogue_perso('";
				query += parametre;
				query += " CALL verification_ajout_Catalogue_perso('";
				query += parametre;
				query += " COMMIT;";
			}
		}
		else {
			return;
		}

		richTextBox1->Text = query;

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
			//erreur
		}
		else {
			//cool
		}

		load_query();
	}


	private: System::Void Catalogue_Perso_Load(System::Object^ sender, System::EventArgs^ e) {
		load_query();
	}

	private: System::Void dataGridView1_UserAddedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[9]->Value = "ajout";
		dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[8]->Value = false;
	}
	};
}