#pragma once
#include <mysql.h>

namespace NS_Formulaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Formulaire_achat
	/// </summary>
	public ref class Formulaire_achat : public System::Windows::Forms::Form
	{
	public:
		Formulaire_achat()
		{
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
		~Formulaire_achat()
		{
			if (components)
			{
				delete components;
			}
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
			if ( mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				finish_with_error(con);
			}

			CheckBox^ Nom = gcnew CheckBox();
			qstate = mysql_query(con, "SELECT * FROM Paiement;\
									   SELECT adresse_adresses_clients FROM Adresses_clients WHERE ID_type_adresse = 1;\
									   SELECT adresse_adresses_clients FROM Adresses_clients WHERE ID_type_adresse = 2 OR ID_type_adresse = 1;\
									   INSERT INTO Adresse_clients (");

			if (!qstate)
			{
				res = mysql_store_result(con);
				
				while (row = mysql_fetch_row(res))
				{
					Metho_achat->Items->Add(gcnew String(row[1]));
				}
				mysql_free_result(res);


				mysql_next_result(con);
				res = mysql_store_result(con);

				while (row = mysql_fetch_row(res))
				{
					Select_Liv_Combo->Items->Add(gcnew String(row[0]));
				}
				mysql_free_result(res);


				mysql_next_result(con);
				res = mysql_store_result(con);

				while (row = mysql_fetch_row(res))
				{
					Select_Fact_Combo->Items->Add(gcnew String(row[0]));
				}	
			}
		}
	private: System::Windows::Forms::GroupBox^ addLivraison;
	protected:
	private: System::Windows::Forms::GroupBox^ addFacturation;
	private: System::Windows::Forms::TextBox^ Liv_Txt;
	private: System::Windows::Forms::ComboBox^ Select_Liv_Combo;
	private: System::Windows::Forms::RadioButton^ Liv_Nouv_Btn;
	private: System::Windows::Forms::RadioButton^ Liv_Existe_Btn;
	private: System::Windows::Forms::TextBox^ Fact_Txt;
	private: System::Windows::Forms::ComboBox^ Select_Fact_Combo;
	private: System::Windows::Forms::RadioButton^ Fact_Nouv_Btn;
	private: System::Windows::Forms::RadioButton^ Fact_Exist_Btn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ Metho_achat;
	private: System::Windows::Forms::Label^ Num_Cli;
	private: System::Windows::Forms::Label^ Nom_Cli;
	private: System::Windows::Forms::Label^ Prenom_Cli;
	private: System::Windows::Forms::Button^ Precedent;

	private: System::Windows::Forms::Button^ warni;
	private: System::Windows::Forms::Button^ button1;
private: System::Data::DataSet^ dataSet1;





	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->addLivraison = (gcnew System::Windows::Forms::GroupBox());
			this->Liv_Txt = (gcnew System::Windows::Forms::TextBox());
			this->Select_Liv_Combo = (gcnew System::Windows::Forms::ComboBox());
			this->Liv_Nouv_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->Liv_Existe_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->addFacturation = (gcnew System::Windows::Forms::GroupBox());
			this->Fact_Txt = (gcnew System::Windows::Forms::TextBox());
			this->Select_Fact_Combo = (gcnew System::Windows::Forms::ComboBox());
			this->Fact_Nouv_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->Fact_Exist_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Metho_achat = (gcnew System::Windows::Forms::ComboBox());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->Num_Cli = (gcnew System::Windows::Forms::Label());
			this->Nom_Cli = (gcnew System::Windows::Forms::Label());
			this->Prenom_Cli = (gcnew System::Windows::Forms::Label());
			this->Precedent = (gcnew System::Windows::Forms::Button());
			this->warni = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->addLivraison->SuspendLayout();
			this->addFacturation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->SuspendLayout();
			// 
			// addLivraison
			// 
			this->addLivraison->Controls->Add(this->Liv_Txt);
			this->addLivraison->Controls->Add(this->Select_Liv_Combo);
			this->addLivraison->Controls->Add(this->Liv_Nouv_Btn);
			this->addLivraison->Controls->Add(this->Liv_Existe_Btn);
			this->addLivraison->Location = System::Drawing::Point(179, 140);
			this->addLivraison->Name = L"addLivraison";
			this->addLivraison->Size = System::Drawing::Size(196, 143);
			this->addLivraison->TabIndex = 0;
			this->addLivraison->TabStop = false;
			this->addLivraison->Text = L"Addresse de Livraison";
			// 
			// Liv_Txt
			// 
			this->Liv_Txt->Location = System::Drawing::Point(26, 70);
			this->Liv_Txt->Name = L"Liv_Txt";
			this->Liv_Txt->Size = System::Drawing::Size(168, 20);
			this->Liv_Txt->TabIndex = 3;
			// 
			// Select_Liv_Combo
			// 
			this->Select_Liv_Combo->FormattingEnabled = true;
			this->Select_Liv_Combo->Location = System::Drawing::Point(26, 31);
			this->Select_Liv_Combo->Name = L"Select_Liv_Combo";
			this->Select_Liv_Combo->Size = System::Drawing::Size(121, 21);
			this->Select_Liv_Combo->TabIndex = 2;
			// 
			// Liv_Nouv_Btn
			// 
			this->Liv_Nouv_Btn->AutoSize = true;
			this->Liv_Nouv_Btn->Location = System::Drawing::Point(6, 73);
			this->Liv_Nouv_Btn->Name = L"Liv_Nouv_Btn";
			this->Liv_Nouv_Btn->Size = System::Drawing::Size(14, 13);
			this->Liv_Nouv_Btn->TabIndex = 1;
			this->Liv_Nouv_Btn->TabStop = true;
			this->Liv_Nouv_Btn->UseVisualStyleBackColor = true;
			// 
			// Liv_Existe_Btn
			// 
			this->Liv_Existe_Btn->AutoSize = true;
			this->Liv_Existe_Btn->Location = System::Drawing::Point(6, 34);
			this->Liv_Existe_Btn->Name = L"Liv_Existe_Btn";
			this->Liv_Existe_Btn->Size = System::Drawing::Size(14, 13);
			this->Liv_Existe_Btn->TabIndex = 0;
			this->Liv_Existe_Btn->TabStop = true;
			this->Liv_Existe_Btn->UseVisualStyleBackColor = true;
			// 
			// addFacturation
			// 
			this->addFacturation->Controls->Add(this->Fact_Txt);
			this->addFacturation->Controls->Add(this->Select_Fact_Combo);
			this->addFacturation->Controls->Add(this->Fact_Nouv_Btn);
			this->addFacturation->Controls->Add(this->Fact_Exist_Btn);
			this->addFacturation->Location = System::Drawing::Point(420, 140);
			this->addFacturation->Name = L"addFacturation";
			this->addFacturation->Size = System::Drawing::Size(196, 143);
			this->addFacturation->TabIndex = 1;
			this->addFacturation->TabStop = false;
			this->addFacturation->Text = L"Adresse de Facturation";
			// 
			// Fact_Txt
			// 
			this->Fact_Txt->Location = System::Drawing::Point(28, 70);
			this->Fact_Txt->Name = L"Fact_Txt";
			this->Fact_Txt->Size = System::Drawing::Size(166, 20);
			this->Fact_Txt->TabIndex = 3;
			// 
			// Select_Fact_Combo
			// 
			this->Select_Fact_Combo->FormattingEnabled = true;
			this->Select_Fact_Combo->Location = System::Drawing::Point(27, 31);
			this->Select_Fact_Combo->Name = L"Select_Fact_Combo";
			this->Select_Fact_Combo->Size = System::Drawing::Size(121, 21);
			this->Select_Fact_Combo->TabIndex = 2;
			// 
			// Fact_Nouv_Btn
			// 
			this->Fact_Nouv_Btn->AutoSize = true;
			this->Fact_Nouv_Btn->Location = System::Drawing::Point(7, 73);
			this->Fact_Nouv_Btn->Name = L"Fact_Nouv_Btn";
			this->Fact_Nouv_Btn->Size = System::Drawing::Size(14, 13);
			this->Fact_Nouv_Btn->TabIndex = 1;
			this->Fact_Nouv_Btn->TabStop = true;
			this->Fact_Nouv_Btn->UseVisualStyleBackColor = true;
			// 
			// Fact_Exist_Btn
			// 
			this->Fact_Exist_Btn->AutoSize = true;
			this->Fact_Exist_Btn->Location = System::Drawing::Point(7, 34);
			this->Fact_Exist_Btn->Name = L"Fact_Exist_Btn";
			this->Fact_Exist_Btn->Size = System::Drawing::Size(14, 13);
			this->Fact_Exist_Btn->TabIndex = 0;
			this->Fact_Exist_Btn->TabStop = true;
			this->Fact_Exist_Btn->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Méthode d\'achat";
			// 
			// Metho_achat
			// 
			this->Metho_achat->FormattingEnabled = true;
			this->Metho_achat->Location = System::Drawing::Point(27, 157);
			this->Metho_achat->Name = L"Metho_achat";
			this->Metho_achat->Size = System::Drawing::Size(117, 21);
			this->Metho_achat->TabIndex = 3;
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// Num_Cli
			// 
			this->Num_Cli->AutoSize = true;
			this->Num_Cli->Location = System::Drawing::Point(24, 70);
			this->Num_Cli->Name = L"Num_Cli";
			this->Num_Cli->Size = System::Drawing::Size(82, 13);
			this->Num_Cli->TabIndex = 4;
			this->Num_Cli->Text = L"Numero Client : ";
			// 
			// Nom_Cli
			// 
			this->Nom_Cli->AutoSize = true;
			this->Nom_Cli->Location = System::Drawing::Point(179, 70);
			this->Nom_Cli->Name = L"Nom_Cli";
			this->Nom_Cli->Size = System::Drawing::Size(38, 13);
			this->Nom_Cli->TabIndex = 5;
			this->Nom_Cli->Text = L"Nom : ";
			// 
			// Prenom_Cli
			// 
			this->Prenom_Cli->AutoSize = true;
			this->Prenom_Cli->Location = System::Drawing::Point(282, 70);
			this->Prenom_Cli->Name = L"Prenom_Cli";
			this->Prenom_Cli->Size = System::Drawing::Size(52, 13);
			this->Prenom_Cli->TabIndex = 6;
			this->Prenom_Cli->Text = L"Prénom : ";
			// 
			// Precedent
			// 
			this->Precedent->Location = System::Drawing::Point(13, 13);
			this->Precedent->Name = L"Precedent";
			this->Precedent->Size = System::Drawing::Size(25, 25);
			this->Precedent->TabIndex = 7;
			this->Precedent->Text = L"<";
			this->Precedent->UseVisualStyleBackColor = true;
			// 
			// warni
			// 
			this->warni->Location = System::Drawing::Point(44, 12);
			this->warni->Name = L"warni";
			this->warni->Size = System::Drawing::Size(25, 25);
			this->warni->TabIndex = 8;
			this->warni->Text = L"!";
			this->warni->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(541, 298);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Confirmer";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Formulaire_achat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 343);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->warni);
			this->Controls->Add(this->Precedent);
			this->Controls->Add(this->Prenom_Cli);
			this->Controls->Add(this->Nom_Cli);
			this->Controls->Add(this->Num_Cli);
			this->Controls->Add(this->Metho_achat);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->addFacturation);
			this->Controls->Add(this->addLivraison);
			this->Name = L"Formulaire_achat";
			this->Text = L"Formulaire_achat";
			this->Load += gcnew System::EventHandler(this, &Formulaire_achat::Formulaire_achat_Load);
			this->addLivraison->ResumeLayout(false);
			this->addLivraison->PerformLayout();
			this->addFacturation->ResumeLayout(false);
			this->addFacturation->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Formulaire_achat_Load(System::Object^ sender, System::EventArgs^ e) {
	}

};
}
