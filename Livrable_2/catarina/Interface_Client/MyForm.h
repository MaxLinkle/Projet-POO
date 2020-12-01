#pragma once
#include <mysql.h>
#include <iostream>
//#include <string>
//#include <msclr\marshal_cppstd.h>
#include"Formulaire_achat.h"

namespace Client {

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
	private:String^ id;
	private: System::Windows::Forms::Label^ remise;
	private: System::Windows::Forms::Label^ TTCremise;

	private: System::Windows::Forms::TextBox^ remise_txt;
	private: System::Windows::Forms::Label^ euroRemise;

	private:DateTimePicker^ dateAchat = gcnew DateTimePicker();
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Check;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Prix;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantite;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Max;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TVA;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDarticle;








	public:DateTimePicker^ dateAnniv = gcnew DateTimePicker();
		MyForm(String^ i_id)
		{
			InitializeComponent();
			
			id = i_id;
			//
			//TODO: ajoutez ici le code du constructeur
			//
			ConnexionBase();
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

			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				finish_with_error(con);
			}
			else {
				std::cout << "Success!\n";
			}
			
			CheckBox^ Nom = gcnew CheckBox();
			String^ query = gcnew String("SELECT nom, prix_ht, stock, taux_tva, ID_article FROM Catalogue WHERE actif = 1; SELECT date_naissance, date_premier_achat FROM Client WHERE ID_client =");
			query += id;
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
					double ht = atof(row[1]);
					double tva = atof(row[3]);
					double ttc = ht * ((tva/100)+1);
					
					dataGridView1->Rows[n]->Cells[1]->Value = gcnew String(row[0]);
					dataGridView1->Rows[n]->Cells[2]->Value = ttc;
					dataGridView1->Rows[n]->Cells[4]->Value = gcnew String(row[2]);
					dataGridView1->Rows[n]->Cells[3]->Value = "0";
					dataGridView1->Rows[n]->Cells[5]->Value = gcnew String(row[1]);
					dataGridView1->Rows[n]->Cells[6]->Value = gcnew String(row[4]);
					
				}
				mysql_free_result(res);

				mysql_next_result(con);
				res = mysql_store_result(con);

				while (row = mysql_fetch_row(res))
				{
					dateAnniv->Value = DateTime::ParseExact(gcnew String(row[0]), "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
					dateAchat->Value = DateTime::ParseExact(gcnew String(row[1]), "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
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
	private: System::Windows::Forms::Button^ Precedent;
	protected:



	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ acheter;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Label^ label1;





	private: System::Windows::Forms::Label^ label2;


	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TextBox^ nb_txt;

	private: System::Windows::Forms::TextBox^ total_txt;
	private: System::Windows::Forms::Label^ label3;




	private: Client::Formulaire_achat^ formu ;
private: System::Windows::Forms::TextBox^ HT;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label5;














	private: Client::Facture^ facture;

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
			this->Precedent = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->acheter = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nb_txt = (gcnew System::Windows::Forms::TextBox());
			this->total_txt = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->HT = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->remise = (gcnew System::Windows::Forms::Label());
			this->TTCremise = (gcnew System::Windows::Forms::Label());
			this->remise_txt = (gcnew System::Windows::Forms::TextBox());
			this->euroRemise = (gcnew System::Windows::Forms::Label());
			this->Check = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prix = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantite = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Max = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TVA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IDarticle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->acheter->Location = System::Drawing::Point(593, 555);
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Check,
					this->Nom, this->Prix, this->Quantite, this->Max, this->TVA, this->IDarticle
			});
			this->dataGridView1->Location = System::Drawing::Point(75, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(593, 397);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellValidated);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(501, 475);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Total TTC : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(249, 443);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Nombre d\'article(s) :";
			// 
			// nb_txt
			// 
			this->nb_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nb_txt->Location = System::Drawing::Point(388, 440);
			this->nb_txt->Name = L"nb_txt";
			this->nb_txt->ReadOnly = true;
			this->nb_txt->Size = System::Drawing::Size(54, 24);
			this->nb_txt->TabIndex = 7;
			// 
			// total_txt
			// 
			this->total_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->total_txt->Location = System::Drawing::Point(584, 472);
			this->total_txt->Name = L"total_txt";
			this->total_txt->ReadOnly = true;
			this->total_txt->Size = System::Drawing::Size(70, 24);
			this->total_txt->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(660, 478);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 18);
			this->label3->TabIndex = 9;
			this->label3->Text = L"€";
			// 
			// HT
			// 
			this->HT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HT->Location = System::Drawing::Point(584, 440);
			this->HT->Name = L"HT";
			this->HT->ReadOnly = true;
			this->HT->Size = System::Drawing::Size(70, 24);
			this->HT->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(507, 443);
			this->label4->Margin = System::Windows::Forms::Padding(3, 0, 1, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Total HT :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(660, 443);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 18);
			this->label5->TabIndex = 11;
			this->label5->Text = L"€";
			// 
			// remise
			// 
			this->remise->AutoSize = true;
			this->remise->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remise->ForeColor = System::Drawing::Color::Red;
			this->remise->Location = System::Drawing::Point(12, 512);
			this->remise->Name = L"remise";
			this->remise->Size = System::Drawing::Size(0, 18);
			this->remise->TabIndex = 13;
			this->remise->Visible = false;
			// 
			// TTCremise
			// 
			this->TTCremise->AutoSize = true;
			this->TTCremise->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TTCremise->Location = System::Drawing::Point(404, 512);
			this->TTCremise->Name = L"TTCremise";
			this->TTCremise->Size = System::Drawing::Size(176, 18);
			this->TTCremise->TabIndex = 14;
			this->TTCremise->Text = L"Total TTC après remise : ";
			this->TTCremise->Visible = false;
			// 
			// remise_txt
			// 
			this->remise_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remise_txt->Location = System::Drawing::Point(584, 509);
			this->remise_txt->Name = L"remise_txt";
			this->remise_txt->ReadOnly = true;
			this->remise_txt->Size = System::Drawing::Size(70, 24);
			this->remise_txt->TabIndex = 15;
			this->remise_txt->Visible = false;
			// 
			// euroRemise
			// 
			this->euroRemise->AutoSize = true;
			this->euroRemise->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->euroRemise->Location = System::Drawing::Point(660, 515);
			this->euroRemise->Name = L"euroRemise";
			this->euroRemise->Size = System::Drawing::Size(16, 18);
			this->euroRemise->TabIndex = 16;
			this->euroRemise->Text = L"€";
			this->euroRemise->Visible = false;
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
			// TVA
			// 
			this->TVA->HeaderText = L"TVA";
			this->TVA->Name = L"TVA";
			this->TVA->ReadOnly = true;
			this->TVA->Visible = false;
			// 
			// IDarticle
			// 
			this->IDarticle->HeaderText = L"IDarticle";
			this->IDarticle->Name = L"IDarticle";
			this->IDarticle->ReadOnly = true;
			this->IDarticle->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 634);
			this->Controls->Add(this->euroRemise);
			this->Controls->Add(this->remise_txt);
			this->Controls->Add(this->TTCremise);
			this->Controls->Add(this->remise);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->HT);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->total_txt);
			this->Controls->Add(this->nb_txt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->acheter);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Precedent);
			this->Location = System::Drawing::Point(333, 36);
			this->Name = L"MyForm";
			this->Text = L"Catalogue";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	DateTimePicker^ dateActuel = gcnew DateTimePicker();
			

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		nb_txt->Text = "0";
		dateActuel->Value.Today;

		if ((dateActuel->Value.Day == dateAnniv->Value.Day) && (dateActuel->Value.Month == dateAnniv->Value.Month))
		{
			TTCremise->Visible = true;
			remise_txt->Visible = true;
			euroRemise->Visible = true;
			remise->Visible = true;
			remise->Text = "Vous avez une remise de 10%";
		}
		else if ((dateActuel->Value.Day == dateAchat->Value.Day) && (dateActuel->Value.Month == dateAchat->Value.Month))
		{
			TTCremise->Visible = true;
			remise_txt->Visible = true;
			euroRemise->Visible = true;
			remise->Visible = true;
			remise->Text = "Vous avez une remise de 5%";
		}
		

		}

	private: System::Void acheter_Click(System::Object^ sender, System::EventArgs^ e) {

		DataTable^ transfert = gcnew DataTable();
		transfert->Columns->Add("Nom");
		transfert->Columns->Add("Prix");
		transfert->Columns->Add("Quantite");
		transfert->Columns->Add("id_Article");

		for (int n = 0; n < dataGridView1->RowCount; n++)
		{
			bool isSelected = Convert::ToBoolean(dataGridView1->Rows[n]->Cells["Check"]->Value);
			if (isSelected == true)
			{
				transfert->Rows->Add(dataGridView1->Rows[n]->Cells[1]->Value, dataGridView1->Rows[n]->Cells[2]->Value, dataGridView1->Rows[n]->Cells[3]->Value, dataGridView1->Rows[n]->Cells[6]->Value);
			}
		}

		if (Convert::ToInt32(nb_txt->Text) == 0)
		{
			MessageBox::Show("Vous n'avez ajouter au panier ", "Info", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (Convert::ToInt32(nb_txt->Text) <= 0)
		{
			MessageBox::Show("Vous ne pouvez pas demander des quantitées négatives ", "Info", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			this->Hide();
			this->formu = gcnew Client::Formulaire_achat(nb_txt->Text, total_txt->Text, HT->Text, id, transfert, remise_txt->Text, dateAnniv->Value, dateAchat->Value);
			this->formu->Show();
			
		}
	}
private: System::Void dataGridView1_CellValidated(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	double total = 0;
	double totAr = 0;
	double totHT = 0;
	double Reduc;
	dateActuel->Value.Today;
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

		bool isSelected = Convert::ToBoolean(dataGridView1->Rows[n]->Cells["Check"]->Value);
		if (isSelected == true)
		{
			total += (Convert::ToDouble(dataGridView1->Rows[n]->Cells["Prix"]->Value)) * (Convert::ToDouble(dataGridView1->Rows[n]->Cells["Quantite"]->Value));
			totAr += Convert::ToDouble(dataGridView1->Rows[n]->Cells["Quantite"]->Value);
			totHT += Convert::ToDouble(dataGridView1->Rows[n]->Cells["TVA"]->Value) * (Convert::ToDouble(dataGridView1->Rows[n]->Cells["Quantite"]->Value));

			if ((dateActuel->Value.Day == dateActuel->Value.Month) && (dateAnniv->Value.Day == dateAnniv->Value.Month))
			{
				Reduc = (total - (total * 0.1));
			}
			else if ((dateActuel->Value.Day == dateAchat->Value.Day) && (dateActuel->Value.Month == dateAchat->Value.Month))
			{
				Reduc = (total - (total * 0.05));
			}
			else if ((dateActuel->Value.Day != dateAchat->Value.Day) && (dateActuel->Value.Month != dateAchat->Value.Month))
			{
				Reduc = 0;
			}
		}
		total_txt->Text = total.ToString();
		nb_txt->Text = totAr.ToString();
		HT->Text = totHT.ToString();
		remise_txt->Text = Reduc.ToString();

		
	}
}
};
}