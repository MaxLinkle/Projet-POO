#pragma once
#include "pch.h"
#include "UserControle.h"
#include "SC.h"
#include "Recherche.h"
#include "catalogue_perso.h"
namespace NS_EspacePersonnel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NS_Recherche;
	using namespace NS_SuperC;
	delegate System::Void PRecherche(System::Object^ sender, System::EventArgs^ e);
	

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class EspPerso : public SuperC
	{
	public:
		EspPerso(Form^ Precedent,int indice):SuperC(Precedent)
		{


			
			f = gcnew EventHandler(this, &EspPerso::Recherche);
			g = gcnew EventHandler(this, &EspPerso::CreerIndi);
			
			
			InitializeComponent();
			//prece = Precedent;
			this->Date->Format = DateTimePickerFormat::Custom;
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ CheckDate;
	private: System::Windows::Forms::GroupBox^ GroupSuperieur;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ TextNomSup;
	private: System::Windows::Forms::TextBox^ TextPrenomSup;
	public: delegate ArrayList^ Addrgetter();
	private : Addrgetter^ func;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ Stat;

	public:

	private :
		//Form^ prece;
	
	

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~EspPerso()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RadioButton^ Rb_Personnel;
	private: System::Windows::Forms::RadioButton^ Rb_Client;
	private: System::Windows::Forms::Label^ LDate;

	private: System::Windows::Forms::DateTimePicker^ Date;
	private: System::Windows::Forms::Button^ Rechercher;
	private: System::Windows::Forms::Button^ Creer;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	

	



	private:
		System::ComponentModel::Container^ components;
		//Event^ Cb;
		EventHandler^ f;
		EventHandler^ g;


#pragma region Windows Choix Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->GroupSuperieur = (gcnew System::Windows::Forms::GroupBox());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->TextNomSup = (gcnew System::Windows::Forms::TextBox());
			   this->TextPrenomSup = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->CheckDate = (gcnew System::Windows::Forms::CheckBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->LDate = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->Date = (gcnew System::Windows::Forms::DateTimePicker());
			   this->Rb_Personnel = (gcnew System::Windows::Forms::RadioButton());
			   this->Rb_Client = (gcnew System::Windows::Forms::RadioButton());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->Rechercher = (gcnew System::Windows::Forms::Button());
			   this->Creer = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->Stat = (gcnew System::Windows::Forms::Button());
			   this->groupBox1->SuspendLayout();
			   this->GroupSuperieur->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->GroupSuperieur);
			   this->groupBox1->Controls->Add(this->CheckDate);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->LDate);
			   this->groupBox1->Controls->Add(this->textBox2);
			   this->groupBox1->Controls->Add(this->textBox1);
			   this->groupBox1->Controls->Add(this->Date);
			   this->groupBox1->Controls->Add(this->Rb_Personnel);
			   this->groupBox1->Controls->Add(this->Rb_Client);
			   this->groupBox1->Location = System::Drawing::Point(12, 34);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(575, 202);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Individus";
			   // 
			   // GroupSuperieur
			   // 
			   this->GroupSuperieur->Controls->Add(this->checkBox1);
			   this->GroupSuperieur->Controls->Add(this->label5);
			   this->GroupSuperieur->Controls->Add(this->TextNomSup);
			   this->GroupSuperieur->Controls->Add(this->TextPrenomSup);
			   this->GroupSuperieur->Controls->Add(this->label4);
			   this->GroupSuperieur->Location = System::Drawing::Point(66, 111);
			   this->GroupSuperieur->Name = L"GroupSuperieur";
			   this->GroupSuperieur->Size = System::Drawing::Size(437, 77);
			   this->GroupSuperieur->TabIndex = 9;
			   this->GroupSuperieur->TabStop = false;
			   this->GroupSuperieur->Text = L"Supérieur";
			   this->GroupSuperieur->Visible = false;
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->Checked = true;
			   this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->checkBox1->Location = System::Drawing::Point(267, 29);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(139, 21);
			   this->checkBox1->TabIndex = 17;
			   this->checkBox1->Text = L"As-un supérieur\?";
			   this->checkBox1->UseVisualStyleBackColor = true;
			   this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &EspPerso::checkBox1_CheckedChanged);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(142, 29);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(57, 17);
			   this->label5->TabIndex = 16;
			   this->label5->Text = L"Prenom";
			   // 
			   // TextNomSup
			   // 
			   this->TextNomSup->Location = System::Drawing::Point(6, 49);
			   this->TextNomSup->Name = L"TextNomSup";
			   this->TextNomSup->Size = System::Drawing::Size(100, 22);
			   this->TextNomSup->TabIndex = 13;
			   // 
			   // TextPrenomSup
			   // 
			   this->TextPrenomSup->Location = System::Drawing::Point(145, 49);
			   this->TextPrenomSup->Name = L"TextPrenomSup";
			   this->TextPrenomSup->Size = System::Drawing::Size(100, 22);
			   this->TextPrenomSup->TabIndex = 15;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(3, 29);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(37, 17);
			   this->label4->TabIndex = 14;
			   this->label4->Text = L"Nom";
			   // 
			   // CheckDate
			   // 
			   this->CheckDate->AutoSize = true;
			   this->CheckDate->Checked = true;
			   this->CheckDate->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->CheckDate->Location = System::Drawing::Point(345, 82);
			   this->CheckDate->Name = L"CheckDate";
			   this->CheckDate->Size = System::Drawing::Size(18, 17);
			   this->CheckDate->TabIndex = 8;
			   this->CheckDate->UseVisualStyleBackColor = true;
			   this->CheckDate->CheckedChanged += gcnew System::EventHandler(this, &EspPerso::CheckDate_CheckedChanged);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(208, 58);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(57, 17);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"Prenom";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(63, 60);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(37, 17);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Nom";
			   // 
			   // LDate
			   // 
			   this->LDate->AutoSize = true;
			   this->LDate->Location = System::Drawing::Point(366, 60);
			   this->LDate->Name = L"LDate";
			   this->LDate->Size = System::Drawing::Size(131, 17);
			   this->LDate->TabIndex = 7;
			   this->LDate->Text = L"Date d\'anniversaire";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(211, 78);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(100, 22);
			   this->textBox2->TabIndex = 3;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(66, 78);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 22);
			   this->textBox1->TabIndex = 2;
			   // 
			   // Date
			   // 
			   this->Date->CustomFormat = L"yyyy-MM-dd";
			   this->Date->Location = System::Drawing::Point(369, 78);
			   this->Date->Name = L"Date";
			   this->Date->Size = System::Drawing::Size(128, 22);
			   this->Date->TabIndex = 1;
			   // 
			   // Rb_Personnel
			   // 
			   this->Rb_Personnel->AutoSize = true;
			   this->Rb_Personnel->Location = System::Drawing::Point(404, 36);
			   this->Rb_Personnel->Name = L"Rb_Personnel";
			   this->Rb_Personnel->Size = System::Drawing::Size(93, 21);
			   this->Rb_Personnel->TabIndex = 1;
			   this->Rb_Personnel->Text = L"Personnel";
			   this->Rb_Personnel->UseVisualStyleBackColor = true;
			   this->Rb_Personnel->CheckedChanged += gcnew System::EventHandler(this, &EspPerso::Rb_Personnel_CheckedChanged);
			   // 
			   // Rb_Client
			   // 
			   this->Rb_Client->AutoSize = true;
			   this->Rb_Client->Checked = true;
			   this->Rb_Client->Location = System::Drawing::Point(59, 36);
			   this->Rb_Client->Name = L"Rb_Client";
			   this->Rb_Client->Size = System::Drawing::Size(64, 21);
			   this->Rb_Client->TabIndex = 0;
			   this->Rb_Client->TabStop = true;
			   this->Rb_Client->Text = L"Client";
			   this->Rb_Client->UseVisualStyleBackColor = true;
			   this->Rb_Client->CheckedChanged += gcnew System::EventHandler(this, &EspPerso::Rb_Client_CheckedChanged);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(263, 251);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(60, 17);
			   this->label3->TabIndex = 9;
			   this->label3->Text = L"Adresse";
			   // 
			   // Rechercher
			   // 
			   this->Rechercher->Location = System::Drawing::Point(114, 499);
			   this->Rechercher->Name = L"Rechercher";
			   this->Rechercher->Size = System::Drawing::Size(132, 28);
			   this->Rechercher->TabIndex = 1;
			   this->Rechercher->Text = L"Rechercher";
			   this->Rechercher->UseVisualStyleBackColor = true;
			   this->Rechercher->Click += gcnew System::EventHandler(this, &EspPerso::Recherche);
			   // 
			   // Creer
			   // 
			   this->Creer->Location = System::Drawing::Point(345, 499);
			   this->Creer->Name = L"Creer";
			   this->Creer->Size = System::Drawing::Size(132, 28);
			   this->Creer->TabIndex = 2;
			   this->Creer->Text = L"Creer";
			   this->Creer->UseVisualStyleBackColor = true;
			   this->Creer->Click += gcnew System::EventHandler(this, &EspPerso::CreerIndi);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(114, 271);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(363, 205);
			   this->dataGridView1->TabIndex = 3;
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(512, 3);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 25);
			   this->button1->TabIndex = 10;
			   this->button1->Text = L"Article >>";
			   this->button1->UseVisualStyleBackColor = true;
			   // 
			   // Stat
			   // 
			   this->Stat->Location = System::Drawing::Point(223, 5);
			   this->Stat->Name = L"Stat";
			   this->Stat->Size = System::Drawing::Size(152, 33);
			   this->Stat->TabIndex = 11;
			   this->Stat->Text = L"Statistique";
			   this->Stat->UseVisualStyleBackColor = true;
			   //this->Stat->Click += gcnew System::EventHandler(this, &EspPerso::Stat_Click);
			   // 
			   // EspPerso
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(609, 551);
			   this->Controls->Add(this->Stat);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->Creer);
			   this->Controls->Add(this->Rechercher);
			   this->Controls->Add(this->groupBox1);
			   this->Name = L"EspPerso";
			   this->Text = L"Espace Personelle";
			   this->Load += gcnew System::EventHandler(this, &EspPerso::EspPerso_Load);
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->GroupSuperieur->ResumeLayout(false);
			   this->GroupSuperieur->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	}


	


	
	private: System::Void Rb_Client_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		//this->Rechercher->Click -= f;
		//f = gcnew EventHandler(this,&EspPerso::RechercheClient); 
		//this->Rechercher->Click += f;

		//this->Creer->Click -= g;
		//g = gcnew EventHandler(this, &EspPerso::CreerClient);
		//this->Creer->Click += g;

		TextNomSup->Text = "";
		TextPrenomSup->Text = "";
		func = gcnew Addrgetter(this, &EspPerso::AddrClient);
		dataGridView1->AllowUserToAddRows = true;
		dataGridView1->AllowUserToDeleteRows = true;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();

		dataGridView1->Columns->Add("Adresse", "Adresse");
		dataGridView1->Columns->Add("Ville", "Ville");
		

		array<String^>^ Valcl = gcnew array<String^>(3);
		Valcl[0] = ("livraison");
		Valcl[1] = ("facturation");
		Valcl[2] = ("livraison et facturation");


		DataGridViewComboBoxCell^ cl = gcnew DataGridViewComboBoxCell();

		cl->DataSource = Valcl;
		cl->Value = Valcl[0];
		

		DataGridViewComboBoxColumn^ temp = gcnew DataGridViewComboBoxColumn();
		temp->CellTemplate = cl;
		
		dataGridView1->Columns->Add(temp);
		

		CheckDate->Visible = true;
		GroupSuperieur->Visible = false;

		LDate->Text = "Date d\'anniversaire";
	}

	private: System::Void Rb_Personnel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		//this->Rechercher->Click -= f;
		//f = gcnew EventHandler(this , &EspPerso::RecherchePersonnel);
		//this->Rechercher->Click += f;
		//
		//this->Creer->Click -= g;
		//g = gcnew EventHandler(this, &EspPerso::CreerPersonnel);
		//this->Creer->Click += g;


		func = gcnew Addrgetter(this, &EspPerso::AddrPersonnel);
		dataGridView1->AllowUserToAddRows = false;
		dataGridView1->AllowUserToDeleteRows = false;
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();

		dataGridView1->Columns->Add("Adresse", "Adresse");
		dataGridView1->Columns->Add("Ville", "Ville");
		
				
				

		dataGridView1->Rows->Add();
		CheckDate->Checked = true;
		CheckDate->Visible = false;
		GroupSuperieur->Visible = true;
		checkBox1->Checked = false;

		LDate->Text = "Date d\'embauche";
	}

	private: 
	System::Void Recherche(System::Object^ sender, System::EventArgs^ e) {
		Individu^ Steve;

		if(Rb_Client->Checked)
		{
			String^ PDate = "";
			if (CheckDate->Checked) {
				PDate = Date->Value.ToString(Date->CustomFormat);
			}
			Steve = gcnew CLClient(func(), textBox1->Text, textBox2->Text, PDate);

		}
		else 
		{
			
			String^ PDate = Date->Value.ToString(Date->CustomFormat);
			
			Steve = gcnew Personnel(func(), textBox1->Text, textBox2->Text, PDate);

		

		}

		MYSQL_RES* Test = executerQuery(Steve->MapId());

		if (Test->row_count > 0) {
			MYSQL_ROW row = mysql_fetch_row(Test);
			Steve->SetID(gcnew String(row[0]));
			this->Hide();
			CLRecherche^ PageSuivante = gcnew CLRecherche(this, Steve);
			PageSuivante->Show();
		}
		else {

			EspPerso_Load(this, gcnew EventArgs);
		}
		

	}


	System::Void CreerIndi(System::Object^ sender, System::EventArgs^ e) {

	
		StartTransactionSC();
		String^ Client = (Rb_Client->Checked) ? "1" : "0";
		String^ PDate;
		if (Client == "1" && !(CheckDate->Checked)) {

			PDate = "null";

		}
		else {
			PDate = "'"+Date->Value.ToString(Date->CustomFormat)+"'";

		}

		String^ Query = "SELECT  AjoutIndividus(" + Client + ",'" + textBox1->Text + "','" + textBox2->Text + "'," + PDate + ",'" + TextNomSup->Text + "','" + TextPrenomSup->Text + "');";
		String^ QueryTest = "CALL VerifIndividus(" + Client + ",'" + textBox1->Text + "','" + textBox2->Text + "'," + PDate+ ",'" + TextNomSup->Text + "','" + TextPrenomSup->Text + "');";
		MYSQL_RES* result;
		MYSQL_RES* test;
		MYSQL_ROW Qrow;
		result = executerQuery(Query);

		if (result != NULL) {
			Qrow = mysql_fetch_row(result);
			String^ ID = gcnew String(Qrow[0]);
			mysql_free_result(result);
			result = executerQuery(QueryTest);
			this->Text = QueryTest;

			if (result->row_count > 0) {
				CommitSC();
			}
			else {
				RollbackSC();
				errorProvider1->SetError(Actualiser, "Envoie Echouer");
				return;
			}

			for each (DataGridViewRow ^ row in dataGridView1->Rows) {

				bool Valide = true;

				for each (DataGridViewCell ^ cell in row->Cells) {

					if (cell->Value == nullptr) {
						Valide = false;
					}
					else if (cell->Value->ToString() == "") {
						Valide = false;
					}

				}

				if (Valide) {
					StartTransactionSC();
					if (Client == "1") {

						Query = "CALL ajout_Adresse_client(" + ID + ",'" + row->Cells[0]->Value->ToString() + "','" + row->Cells[1]->Value->ToString() + "','" + row->Cells[2]->Value->ToString() + "');";
						QueryTest = "SELECT * FROM (SELECT * FROM Ville NATURAL JOIN Adresse_client ) AS T2 NATURAL JOIN Type_adresse WHERE ID_client = " + ID + " AND adresse_client = '" + row->Cells[0]->Value->ToString() + "' AND  ville ='"+row->Cells[1]->Value->ToString()+"' AND type_adresse ='"+ row->Cells[2]->Value->ToString()+ "';";
					}
					else {

						Query = "CALL Ajouter_Adresse_Perso(" + ID + ",'" + row->Cells[1]->Value->ToString() + "','" + row->Cells[0]->Value->ToString() + "');";
						QueryTest = "SELECT * FROM  Ville NATURAL JOIN Adresse_personnel WHERE ID_personnel = " + ID + " AND adresse_personnel = '" + row->Cells[0]->Value->ToString() + "' AND  ville ='" + row->Cells[1]->Value->ToString() + "';";

					}


					executerNonQuery(Query);
					test = executerQuery(QueryTest);
					
					if (test->row_count > 0) { CommitSC(); this->Text = Convert::ToString(test->row_count);
					}
					else { RollbackSC(); errorProvider1->SetError(Actualiser, "Envoie Echouer"); return; }


				}
			}
		}
		else { errorProvider1->SetError(Actualiser, "Envoie Echouer"); }
		EspPerso_Load(this, gcnew EventArgs());
	}

private: System::Void EspPerso_Load(System::Object^ sender, System::EventArgs^ e) {
	func = gcnew Addrgetter(this, &EspPerso::AddrClient);


	executerNonQuery("CALL delete_Commande();CALL delete_Adresse_client_deref()");

	

	Rb_Client_CheckedChanged(this,gcnew EventArgs());
	Rb_Client->Checked = true;
	textBox1->Text = "";
	textBox2->Text = "";
	dataGridView1->AllowUserToAddRows = true;
	dataGridView1->AllowUserToDeleteRows = true;
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	dataGridView1->Columns->Add("Adresse", "Adresse");
	dataGridView1->Columns->Add("Ville", "Ville");


	array<String^>^ Valcl = gcnew array<String^>(3);
	Valcl[0] = ("livraison");
	Valcl[1] = ("facturation");
	Valcl[2] = ("livraison et facturation");


	DataGridViewComboBoxCell^ cl = gcnew DataGridViewComboBoxCell();

	cl->DataSource = Valcl;
	cl->Value = Valcl[0];


	DataGridViewComboBoxColumn^ temp = gcnew DataGridViewComboBoxColumn();
	temp->CellTemplate = cl;

	dataGridView1->Columns->Add(temp);
	dataGridView1->Columns[2]->Name = "Type_adresse";
	dataGridView1->Columns[2]->HeaderText = "Type adresse";

}
private: System::Void CheckDate_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	Date->Enabled = CheckDate->Checked;

}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	TextNomSup->Text = "";
	TextPrenomSup->Text = "";
	TextNomSup->Enabled = checkBox1->Checked;
	TextPrenomSup->Enabled = checkBox1->Checked;
}


	   ArrayList^ AddrClient() {
		   ArrayList^ Adr = gcnew ArrayList();
		   Struct_Adresse^ cont = nullptr;

		   for each (DataGridViewRow^ row in dataGridView1->Rows) {
			   
			   bool Valide = true;

			   for each (DataGridViewCell^ cell in row->Cells) {

				   if (cell->Value == nullptr) {
					   Valide = false;
				   }
				   else if (cell->Value->ToString() == "") {
					   Valide = false;
				   }

			   }
			   if (Valide) {
					   cont = gcnew Struct_Adresse;
					   cont->ID = "";
					   cont->Adresse = row->Cells[0]->Value->ToString();
					   cont->Ville = row->Cells[1]->Value->ToString();
					   cont->Type_adresse = row->Cells[2]->Value->ToString();
				       cont->Pays = "France";
					   Adr->Add(cont);
			   }
		   }
		   return Adr;
	   }

	   ArrayList^ AddrPersonnel() {
		   ArrayList^ Adr = gcnew ArrayList();
		   Struct_Adresse^ cont;

		   
		   
			   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
				   bool Valide = true;

				   for each (DataGridViewCell ^ cell in row->Cells) {
					   if (cell->Value == nullptr){
						 Valide = false;
					 }
					   else if (cell->Value->ToString() == "" ) {
						   Valide = false;
					   }

				   }
				   if (Valide) {

					   cont = gcnew Struct_Adresse;
					   cont->ID = "";
					   cont->Adresse = row->Cells[0]->Value->ToString();
					   cont->Ville = row->Cells[1]->Value->ToString();
					   cont->Pays = "France";
					   cont->Type_adresse = "";
					   Adr->Add(cont);

				   }
			   
			   }
		   
	   
		   return Adr;
	   }


};
}