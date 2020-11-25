#pragma once
#include <mysql.h>
#include <iostream>

namespace Catalogue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			ConnexionBase();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

		void finish_with_error(MYSQL* con)
		{
			std::cout << "Error: " << mysql_error(con);
			mysql_close(con);
			exit(1);
		}

		void ConnexionBase()
		{
			MYSQL* con;
			MYSQL_RES* res;
			MYSQL_ROW row;
			const char username[] = "root";
			const char password[] = "toor";
			con = mysql_init(NULL);
			int qstate;
			if (con == NULL)
			{
				finish_with_error(con);
				exit(1);
			}
			else {
				std::cout << "Success!\n";
			}

			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, 0) == NULL) {
				finish_with_error(con);
			}
			else {
				std::cout << "Success!\n";
			}
			
			CheckBox^ Nom = gcnew CheckBox();
			qstate = mysql_query(con, "SELECT nom, prix_ht, stock, taux_tva FROM Catalogue");
			
			if (!qstate)
			{
				res = mysql_store_result(con);
				while (row = mysql_fetch_row(res))
				{
					int n = dataGridView1->Rows->Add();
					double ht = atof(row[1]);
					double tva = atof(row[3]);
					double ttc = ht * ((tva/100)+1);
					
					dataGridView1->Rows[n]->Cells[1]->Value = gcnew String(row[0]);
					dataGridView1->Rows[n]->Cells[2]->Value = ttc;
					dataGridView1->Rows[n]->Cells[4]->Value = gcnew String(row[2]);
					dataGridView1->Rows[n]->Cells[3]->Value = 0;
					
				}

			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ retour;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ acheter;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Check;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Prix;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantite;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Max;
	private: System::Windows::Forms::Label^ label2;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->retour = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->acheter = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Check = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prix = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantite = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Max = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// retour
			// 
			this->retour->Location = System::Drawing::Point(12, 12);
			this->retour->Name = L"retour";
			this->retour->Size = System::Drawing::Size(25, 25);
			this->retour->TabIndex = 1;
			this->retour->Text = L"<";
			this->retour->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(25, 25);
			this->button2->TabIndex = 2;
			this->button2->Text = L"!";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// acheter
			// 
			this->acheter->Location = System::Drawing::Point(593, 467);
			this->acheter->Name = L"acheter";
			this->acheter->Size = System::Drawing::Size(75, 23);
			this->acheter->TabIndex = 3;
			this->acheter->Text = L"Acheter";
			this->acheter->UseVisualStyleBackColor = true;
			this->acheter->Click += gcnew System::EventHandler(this, &MyForm::acheter_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Check,
					this->Nom, this->Prix, this->Quantite, this->Max
			});
			this->dataGridView1->Location = System::Drawing::Point(75, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(593, 397);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellValidated);
			// 
			// Check
			// 
			this->Check->HeaderText = L"";
			this->Check->Name = L"Check";
			this->Check->Width = 50;
			// 
			// Nom
			// 
			this->Nom->HeaderText = L"Nom";
			this->Nom->Name = L"Nom";
			this->Nom->ReadOnly = true;
			this->Nom->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Nom->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Nom->Width = 300;
			// 
			// Prix
			// 
			this->Prix->HeaderText = L"Prix TTC";
			this->Prix->Name = L"Prix";
			this->Prix->ReadOnly = true;
			// 
			// Quantite
			// 
			this->Quantite->HeaderText = L"Quantite";
			this->Quantite->Name = L"Quantite";
			// 
			// Max
			// 
			this->Max->HeaderText = L"Quantite Max";
			this->Max->Name = L"Max";
			this->Max->ReadOnly = true;
			this->Max->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(376, 483);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Total : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(376, 454);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Nombre d\'article(s) : ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 527);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->acheter);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->retour);
			this->Location = System::Drawing::Point(333, 36);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}

	private: System::Void acheter_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int n = 0; n < dataGridView1->RowCount; n++)
		{
			if (Convert::ToInt32(dataGridView1->Rows[n]->Cells[3]->Value) > Convert::ToInt32(dataGridView1->Rows[n]->Cells[4]->Value))
			{	
				dataGridView1->Rows[n]->DefaultCellStyle->BackColor = System::Drawing::Color::PaleVioletRed;
				MessageBox::Show("Quantite Indisponible. \n Quantite Max : " + dataGridView1->Rows[n]->Cells[4]->Value, "Info", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else if (Convert::ToInt32(dataGridView1->Rows[n]->Cells[3]->Value) <= Convert::ToInt32(dataGridView1->Rows[n]->Cells[4]->Value))
			{
				dataGridView1->Rows[n]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			}
		}
		
	}
private: System::Void dataGridView1_CellValidated(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	double total = 0;
	double totAr = 0;
	for (int n = 0; n < dataGridView1->RowCount; n++)
	{
		bool isSelected = Convert::ToBoolean(dataGridView1->Rows[n]->Cells["Check"]->Value);
		if (isSelected == true)
		{
			total += (Convert::ToDouble(dataGridView1->Rows[n]->Cells["Prix"]->Value)) * (Convert::ToDouble(dataGridView1->Rows[n]->Cells["Quantite"]->Value));
			totAr += Convert::ToDouble(dataGridView1->Rows[n]->Cells["Quantite"]->Value);
		}
	}
	label1->Text = "Total : " + total.ToString() + " €";
	label2->Text = "Nombre d'article(s) : " + totAr.ToString();
}
};
}