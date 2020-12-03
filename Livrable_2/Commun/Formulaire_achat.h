#pragma once
#include <mysql.h>
#include<vcclr.h>
#include "Facture.h"
#include"Catalogue_Client.h"

namespace Client {

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
	private: System::Windows::Forms::TextBox^ Ville_liv;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ Ville_fact;

	public:
		Formulaire_achat(String^ nb, String^ total, String^ HT, String^ id, DataTable^ transfert, String^ remise, Form^ inpPrecedent, Form^ inpPageClient)
		{
			Precedent = inpPrecedent;
			PageClient = inpPageClient;
			InitializeComponent();
			nb_txt->Text = nb;
			tot_txt->Text = total;
			totHT_txt->Text = HT;
			id_client->Text = id;
			remise_txt->Text = remise;
			RecapData->DataSource = transfert;
			RecapData->Columns[3]->Visible = false;
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
			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				finish_with_error(con);
			}

			String^ query = gcnew String("SELECT * FROM Paiement; SELECT adresse_client FROM Adresse_client WHERE (ID_type_adresse = 1 OR ID_type_adresse = 3) AND ID_client =");
									   query += id_client->Text;
									   query += ("; SELECT adresse_client FROM Adresse_client WHERE (ID_type_adresse = 2 OR ID_type_adresse = 3) AND ID_client =");
									   query += id_client->Text;
									   query += ("; SELECT nom, prenom FROM Client WHERE ID_client =");
									   query += id_client->Text;
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
				mysql_free_result(res);

				mysql_next_result(con);
				res = mysql_store_result(con);

				while (row = mysql_fetch_row(res))
				{
					nom->Text = gcnew String(row[0]);
					prenom->Text = gcnew String(row[1]);
				}
			}
		}

	private: Client::Facture^ facture;


	private:  System::Windows::Forms::Form^ Precedent;
	private:  System::Windows::Forms::Form^ PageClient;


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
private: System::Windows::Forms::Button^ bouton_precedent;


	private: System::Windows::Forms::Button^ warni;
	private: System::Windows::Forms::Button^ button1;


private: System::Windows::Forms::TextBox^ nom;
private: System::Windows::Forms::TextBox^ prenom;
private: System::Windows::Forms::TextBox^ id_client;


private: System::Windows::Forms::GroupBox^ Récapitulatif;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ nb_txt;

private: System::Windows::Forms::Label^ lbl_NombArt;
private: System::Windows::Forms::TextBox^ tot_txt;



private: System::Windows::Forms::Label^ lbl_tot;



private: System::Windows::Forms::DateTimePicker^ dateLiv;
private: System::Windows::Forms::DateTimePicker^ datePaye;

private: System::Windows::Forms::Label^ LivPrev;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ totHT_txt;
private: System::Windows::Forms::TextBox^ totTVA_txt;

private: System::Windows::Forms::Label^ label5;


private: System::Windows::Forms::Label^ label6;

private: System::Windows::Forms::DataGridView^ RecapData;
private: System::Windows::Forms::Label^ remise_lbl;
private: System::Windows::Forms::Label^ euroRemise;
private: System::Windows::Forms::TextBox^ remise_txt;

private: System::Windows::Forms::Label^ label7;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->addLivraison = (gcnew System::Windows::Forms::GroupBox());
			this->Ville_liv = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Liv_Txt = (gcnew System::Windows::Forms::TextBox());
			this->Select_Liv_Combo = (gcnew System::Windows::Forms::ComboBox());
			this->Liv_Nouv_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->Liv_Existe_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->addFacturation = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Ville_fact = (gcnew System::Windows::Forms::TextBox());
			this->Fact_Txt = (gcnew System::Windows::Forms::TextBox());
			this->Select_Fact_Combo = (gcnew System::Windows::Forms::ComboBox());
			this->Fact_Nouv_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->Fact_Exist_Btn = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Metho_achat = (gcnew System::Windows::Forms::ComboBox());
			this->Num_Cli = (gcnew System::Windows::Forms::Label());
			this->Nom_Cli = (gcnew System::Windows::Forms::Label());
			this->Prenom_Cli = (gcnew System::Windows::Forms::Label());
			this->bouton_precedent = (gcnew System::Windows::Forms::Button());
			this->warni = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->nom = (gcnew System::Windows::Forms::TextBox());
			this->prenom = (gcnew System::Windows::Forms::TextBox());
			this->id_client = (gcnew System::Windows::Forms::TextBox());
			this->Récapitulatif = (gcnew System::Windows::Forms::GroupBox());
			this->remise_lbl = (gcnew System::Windows::Forms::Label());
			this->euroRemise = (gcnew System::Windows::Forms::Label());
			this->remise_txt = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->RecapData = (gcnew System::Windows::Forms::DataGridView());
			this->totTVA_txt = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->totHT_txt = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nb_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_NombArt = (gcnew System::Windows::Forms::Label());
			this->tot_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_tot = (gcnew System::Windows::Forms::Label());
			this->dateLiv = (gcnew System::Windows::Forms::DateTimePicker());
			this->datePaye = (gcnew System::Windows::Forms::DateTimePicker());
			this->LivPrev = (gcnew System::Windows::Forms::Label());
			this->addLivraison->SuspendLayout();
			this->addFacturation->SuspendLayout();
			this->Récapitulatif->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RecapData))->BeginInit();
			this->SuspendLayout();
			// 
			// addLivraison
			// 
			this->addLivraison->Controls->Add(this->Ville_liv);
			this->addLivraison->Controls->Add(this->label6);
			this->addLivraison->Controls->Add(this->Liv_Txt);
			this->addLivraison->Controls->Add(this->Select_Liv_Combo);
			this->addLivraison->Controls->Add(this->Liv_Nouv_Btn);
			this->addLivraison->Controls->Add(this->Liv_Existe_Btn);
			this->addLivraison->Location = System::Drawing::Point(180, 488);
			this->addLivraison->Name = L"addLivraison";
			this->addLivraison->Size = System::Drawing::Size(196, 143);
			this->addLivraison->TabIndex = 0;
			this->addLivraison->TabStop = false;
			this->addLivraison->Text = L"Addresse de Livraison";
			// 
			// Ville_liv
			// 
			this->Ville_liv->Location = System::Drawing::Point(26, 117);
			this->Ville_liv->Name = L"Ville_liv";
			this->Ville_liv->Size = System::Drawing::Size(141, 20);
			this->Ville_liv->TabIndex = 21;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(23, 100);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Ville :";
			// 
			// Liv_Txt
			// 
			this->Liv_Txt->Location = System::Drawing::Point(26, 70);
			this->Liv_Txt->Name = L"Liv_Txt";
			this->Liv_Txt->Size = System::Drawing::Size(168, 20);
			this->Liv_Txt->TabIndex = 3;
			this->Liv_Txt->Validated += gcnew System::EventHandler(this, &Formulaire_achat::Select_Liv_Combo_Validated);
			// 
			// Select_Liv_Combo
			// 
			this->Select_Liv_Combo->FormattingEnabled = true;
			this->Select_Liv_Combo->Location = System::Drawing::Point(26, 31);
			this->Select_Liv_Combo->Name = L"Select_Liv_Combo";
			this->Select_Liv_Combo->Size = System::Drawing::Size(121, 21);
			this->Select_Liv_Combo->TabIndex = 2;
			this->Select_Liv_Combo->Validated += gcnew System::EventHandler(this, &Formulaire_achat::Select_Liv_Combo_Validated);
			// 
			// Liv_Nouv_Btn
			// 
			this->Liv_Nouv_Btn->AutoSize = true;
			this->Liv_Nouv_Btn->Location = System::Drawing::Point(6, 73);
			this->Liv_Nouv_Btn->Name = L"Liv_Nouv_Btn";
			this->Liv_Nouv_Btn->Size = System::Drawing::Size(14, 13);
			this->Liv_Nouv_Btn->TabIndex = 1;
			this->Liv_Nouv_Btn->UseVisualStyleBackColor = true;
			this->Liv_Nouv_Btn->CheckedChanged += gcnew System::EventHandler(this, &Formulaire_achat::Liv_Nouv_Btn_CheckedChanged);
			// 
			// Liv_Existe_Btn
			// 
			this->Liv_Existe_Btn->AutoSize = true;
			this->Liv_Existe_Btn->Checked = true;
			this->Liv_Existe_Btn->Location = System::Drawing::Point(6, 34);
			this->Liv_Existe_Btn->Name = L"Liv_Existe_Btn";
			this->Liv_Existe_Btn->Size = System::Drawing::Size(14, 13);
			this->Liv_Existe_Btn->TabIndex = 0;
			this->Liv_Existe_Btn->TabStop = true;
			this->Liv_Existe_Btn->UseVisualStyleBackColor = true;
			// 
			// addFacturation
			// 
			this->addFacturation->Controls->Add(this->label8);
			this->addFacturation->Controls->Add(this->Ville_fact);
			this->addFacturation->Controls->Add(this->Fact_Txt);
			this->addFacturation->Controls->Add(this->Select_Fact_Combo);
			this->addFacturation->Controls->Add(this->Fact_Nouv_Btn);
			this->addFacturation->Controls->Add(this->Fact_Exist_Btn);
			this->addFacturation->Location = System::Drawing::Point(421, 488);
			this->addFacturation->Name = L"addFacturation";
			this->addFacturation->Size = System::Drawing::Size(196, 143);
			this->addFacturation->TabIndex = 1;
			this->addFacturation->TabStop = false;
			this->addFacturation->Text = L"Adresse de Facturation";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(25, 101);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 13);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Ville :";
			// 
			// Ville_fact
			// 
			this->Ville_fact->Location = System::Drawing::Point(28, 117);
			this->Ville_fact->Name = L"Ville_fact";
			this->Ville_fact->Size = System::Drawing::Size(141, 20);
			this->Ville_fact->TabIndex = 22;
			// 
			// Fact_Txt
			// 
			this->Fact_Txt->Location = System::Drawing::Point(28, 70);
			this->Fact_Txt->Name = L"Fact_Txt";
			this->Fact_Txt->Size = System::Drawing::Size(166, 20);
			this->Fact_Txt->TabIndex = 3;
			this->Fact_Txt->Validated += gcnew System::EventHandler(this, &Formulaire_achat::Select_Fact_Combo_Validated);
			// 
			// Select_Fact_Combo
			// 
			this->Select_Fact_Combo->FormattingEnabled = true;
			this->Select_Fact_Combo->Location = System::Drawing::Point(27, 31);
			this->Select_Fact_Combo->Name = L"Select_Fact_Combo";
			this->Select_Fact_Combo->Size = System::Drawing::Size(121, 21);
			this->Select_Fact_Combo->TabIndex = 2;
			this->Select_Fact_Combo->Validated += gcnew System::EventHandler(this, &Formulaire_achat::Select_Fact_Combo_Validated);
			// 
			// Fact_Nouv_Btn
			// 
			this->Fact_Nouv_Btn->AutoSize = true;
			this->Fact_Nouv_Btn->Location = System::Drawing::Point(7, 73);
			this->Fact_Nouv_Btn->Name = L"Fact_Nouv_Btn";
			this->Fact_Nouv_Btn->Size = System::Drawing::Size(14, 13);
			this->Fact_Nouv_Btn->TabIndex = 1;
			this->Fact_Nouv_Btn->UseVisualStyleBackColor = true;
			this->Fact_Nouv_Btn->CheckedChanged += gcnew System::EventHandler(this, &Formulaire_achat::Fact_Nouv_Btn_CheckedChanged);
			// 
			// Fact_Exist_Btn
			// 
			this->Fact_Exist_Btn->AutoSize = true;
			this->Fact_Exist_Btn->Checked = true;
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
			this->label1->Location = System::Drawing::Point(21, 488);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Méthode d\'achat";
			// 
			// Metho_achat
			// 
			this->Metho_achat->FormattingEnabled = true;
			this->Metho_achat->Location = System::Drawing::Point(28, 505);
			this->Metho_achat->Name = L"Metho_achat";
			this->Metho_achat->Size = System::Drawing::Size(117, 21);
			this->Metho_achat->TabIndex = 3;
			// 
			// Num_Cli
			// 
			this->Num_Cli->AutoSize = true;
			this->Num_Cli->Location = System::Drawing::Point(25, 418);
			this->Num_Cli->Name = L"Num_Cli";
			this->Num_Cli->Size = System::Drawing::Size(82, 13);
			this->Num_Cli->TabIndex = 4;
			this->Num_Cli->Text = L"Numero Client : ";
			// 
			// Nom_Cli
			// 
			this->Nom_Cli->AutoSize = true;
			this->Nom_Cli->Location = System::Drawing::Point(180, 418);
			this->Nom_Cli->Name = L"Nom_Cli";
			this->Nom_Cli->Size = System::Drawing::Size(38, 13);
			this->Nom_Cli->TabIndex = 5;
			this->Nom_Cli->Text = L"Nom : ";
			// 
			// Prenom_Cli
			// 
			this->Prenom_Cli->AutoSize = true;
			this->Prenom_Cli->Location = System::Drawing::Point(324, 418);
			this->Prenom_Cli->Name = L"Prenom_Cli";
			this->Prenom_Cli->Size = System::Drawing::Size(52, 13);
			this->Prenom_Cli->TabIndex = 6;
			this->Prenom_Cli->Text = L"Prénom : ";
			// 
			// bouton_precedent
			// 
			this->bouton_precedent->Location = System::Drawing::Point(13, 13);
			this->bouton_precedent->Name = L"bouton_precedent";
			this->bouton_precedent->Size = System::Drawing::Size(25, 25);
			this->bouton_precedent->TabIndex = 7;
			this->bouton_precedent->Text = L"<";
			this->bouton_precedent->UseVisualStyleBackColor = true;
			this->bouton_precedent->Click += gcnew System::EventHandler(this, &Formulaire_achat::Precedent_Click);
			// 
			// warni
			// 
			this->warni->Location = System::Drawing::Point(44, 13);
			this->warni->Name = L"warni";
			this->warni->Size = System::Drawing::Size(25, 25);
			this->warni->TabIndex = 8;
			this->warni->Text = L"!";
			this->warni->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(542, 703);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Confirmer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Formulaire_achat::button1_Click);
			// 
			// nom
			// 
			this->nom->Location = System::Drawing::Point(218, 415);
			this->nom->Name = L"nom";
			this->nom->ReadOnly = true;
			this->nom->Size = System::Drawing::Size(100, 20);
			this->nom->TabIndex = 11;
			// 
			// prenom
			// 
			this->prenom->Location = System::Drawing::Point(372, 415);
			this->prenom->Name = L"prenom";
			this->prenom->ReadOnly = true;
			this->prenom->Size = System::Drawing::Size(100, 20);
			this->prenom->TabIndex = 12;
			// 
			// id_client
			// 
			this->id_client->Location = System::Drawing::Point(104, 415);
			this->id_client->Name = L"id_client";
			this->id_client->ReadOnly = true;
			this->id_client->Size = System::Drawing::Size(45, 20);
			this->id_client->TabIndex = 13;
			// 
			// Récapitulatif
			// 
			this->Récapitulatif->Controls->Add(this->remise_lbl);
			this->Récapitulatif->Controls->Add(this->euroRemise);
			this->Récapitulatif->Controls->Add(this->remise_txt);
			this->Récapitulatif->Controls->Add(this->label7);
			this->Récapitulatif->Controls->Add(this->RecapData);
			this->Récapitulatif->Controls->Add(this->totTVA_txt);
			this->Récapitulatif->Controls->Add(this->label5);
			this->Récapitulatif->Controls->Add(this->label4);
			this->Récapitulatif->Controls->Add(this->label3);
			this->Récapitulatif->Controls->Add(this->totHT_txt);
			this->Récapitulatif->Controls->Add(this->label2);
			this->Récapitulatif->Controls->Add(this->nb_txt);
			this->Récapitulatif->Controls->Add(this->lbl_NombArt);
			this->Récapitulatif->Controls->Add(this->tot_txt);
			this->Récapitulatif->Controls->Add(this->lbl_tot);
			this->Récapitulatif->Location = System::Drawing::Point(44, 64);
			this->Récapitulatif->Name = L"Récapitulatif";
			this->Récapitulatif->Size = System::Drawing::Size(537, 317);
			this->Récapitulatif->TabIndex = 15;
			this->Récapitulatif->TabStop = false;
			this->Récapitulatif->Text = L"Récapitulatif";
			// 
			// remise_lbl
			// 
			this->remise_lbl->AutoSize = true;
			this->remise_lbl->Location = System::Drawing::Point(169, 289);
			this->remise_lbl->Name = L"remise_lbl";
			this->remise_lbl->Size = System::Drawing::Size(97, 13);
			this->remise_lbl->TabIndex = 32;
			this->remise_lbl->Text = L"Total avec remise :";
			// 
			// euroRemise
			// 
			this->euroRemise->AutoSize = true;
			this->euroRemise->Location = System::Drawing::Point(336, 289);
			this->euroRemise->Name = L"euroRemise";
			this->euroRemise->Size = System::Drawing::Size(13, 13);
			this->euroRemise->TabIndex = 31;
			this->euroRemise->Text = L"\?";
			// 
			// remise_txt
			// 
			this->remise_txt->Location = System::Drawing::Point(267, 286);
			this->remise_txt->Name = L"remise_txt";
			this->remise_txt->ReadOnly = true;
			this->remise_txt->Size = System::Drawing::Size(63, 20);
			this->remise_txt->TabIndex = 30;
			this->remise_txt->WordWrap = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(143, 289);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 29;
			this->label7->Text = L"\?";
			// 
			// RecapData
			// 
			this->RecapData->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->RecapData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->RecapData->Location = System::Drawing::Point(6, 35);
			this->RecapData->Name = L"RecapData";
			this->RecapData->ReadOnly = true;
			this->RecapData->Size = System::Drawing::Size(519, 185);
			this->RecapData->TabIndex = 28;
			// 
			// totTVA_txt
			// 
			this->totTVA_txt->Location = System::Drawing::Point(80, 286);
			this->totTVA_txt->Name = L"totTVA_txt";
			this->totTVA_txt->ReadOnly = true;
			this->totTVA_txt->Size = System::Drawing::Size(63, 20);
			this->totTVA_txt->TabIndex = 27;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 289);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 13);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Total  TVA: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Total  HT: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(143, 262);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"\?";
			// 
			// totHT_txt
			// 
			this->totHT_txt->Location = System::Drawing::Point(80, 259);
			this->totHT_txt->Name = L"totHT_txt";
			this->totHT_txt->ReadOnly = true;
			this->totHT_txt->Size = System::Drawing::Size(63, 20);
			this->totHT_txt->TabIndex = 23;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(306, 262);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"\?";
			// 
			// nb_txt
			// 
			this->nb_txt->Location = System::Drawing::Point(458, 259);
			this->nb_txt->Name = L"nb_txt";
			this->nb_txt->ReadOnly = true;
			this->nb_txt->Size = System::Drawing::Size(67, 20);
			this->nb_txt->TabIndex = 21;
			// 
			// lbl_NombArt
			// 
			this->lbl_NombArt->AutoSize = true;
			this->lbl_NombArt->Location = System::Drawing::Point(356, 262);
			this->lbl_NombArt->Name = L"lbl_NombArt";
			this->lbl_NombArt->Size = System::Drawing::Size(108, 13);
			this->lbl_NombArt->TabIndex = 20;
			this->lbl_NombArt->Text = L"Nombres d\'article(s) : ";
			// 
			// tot_txt
			// 
			this->tot_txt->Location = System::Drawing::Point(240, 259);
			this->tot_txt->Name = L"tot_txt";
			this->tot_txt->ReadOnly = true;
			this->tot_txt->Size = System::Drawing::Size(63, 20);
			this->tot_txt->TabIndex = 19;
			// 
			// lbl_tot
			// 
			this->lbl_tot->AutoSize = true;
			this->lbl_tot->Location = System::Drawing::Point(173, 262);
			this->lbl_tot->Name = L"lbl_tot";
			this->lbl_tot->Size = System::Drawing::Size(67, 13);
			this->lbl_tot->TabIndex = 18;
			this->lbl_tot->Text = L"Total  TTC : ";
			// 
			// dateLiv
			// 
			this->dateLiv->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dateLiv->CalendarForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dateLiv->CustomFormat = L"yyyy-MM-dd";
			this->dateLiv->DropDownAlign = System::Windows::Forms::LeftRightAlignment::Right;
			this->dateLiv->Enabled = false;
			this->dateLiv->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateLiv->Location = System::Drawing::Point(524, 655);
			this->dateLiv->Name = L"dateLiv";
			this->dateLiv->Size = System::Drawing::Size(91, 20);
			this->dateLiv->TabIndex = 16;
			this->dateLiv->Value = System::DateTime(2020, 11, 27, 22, 13, 23, 0);
			// 
			// datePaye
			// 
			this->datePaye->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->datePaye->CalendarForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->datePaye->CustomFormat = L"yyyy-MM-dd";
			this->datePaye->DropDownAlign = System::Windows::Forms::LeftRightAlignment::Right;
			this->datePaye->Enabled = false;
			this->datePaye->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->datePaye->Location = System::Drawing::Point(18, 655);
			this->datePaye->Name = L"datePaye";
			this->datePaye->Size = System::Drawing::Size(200, 20);
			this->datePaye->TabIndex = 17;
			this->datePaye->Visible = false;
			// 
			// LivPrev
			// 
			this->LivPrev->AutoSize = true;
			this->LivPrev->Location = System::Drawing::Point(386, 655);
			this->LivPrev->Name = L"LivPrev";
			this->LivPrev->Size = System::Drawing::Size(132, 13);
			this->LivPrev->TabIndex = 18;
			this->LivPrev->Text = L"Date de Livraison estimé : ";
			// 
			// Formulaire_achat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 753);
			this->Controls->Add(this->LivPrev);
			this->Controls->Add(this->datePaye);
			this->Controls->Add(this->dateLiv);
			this->Controls->Add(this->Récapitulatif);
			this->Controls->Add(this->id_client);
			this->Controls->Add(this->prenom);
			this->Controls->Add(this->nom);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->warni);
			this->Controls->Add(this->bouton_precedent);
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
			this->Récapitulatif->ResumeLayout(false);
			this->Récapitulatif->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RecapData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::String^ Remise;
	private: System::Void Formulaire_achat_Load(System::Object^ sender, System::EventArgs^ e) {

		Liv_Txt->ReadOnly = true;
		Ville_liv->ReadOnly = true;
		Fact_Txt->ReadOnly = true;
		Ville_fact->ReadOnly = true;
		dateLiv->Value = datePaye->Value.AddDays(7);

		double TVA;
		TVA = Convert::ToDouble(tot_txt->Text) - Convert::ToDouble(totHT_txt->Text);
		totTVA_txt->Text = TVA.ToString();

		if (remise_txt->Text == "0")
		{
			Remise = "0";
			remise_txt->Visible = false;
			euroRemise->Visible = false;
			remise_lbl->Visible = false;
		}
		else if (remise_txt->Text != "0")
		{
			double Reduc; 
			Reduc = Convert::ToDouble(tot_txt->Text) - Convert::ToDouble(remise_txt->Text); //Calcul de la Reduction total à rentrer dans la base de données
			Remise = Reduc.ToString();
		}

		RecapData->AutoResizeColumns();
	}

	private: System::Void Liv_Nouv_Btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Liv_Nouv_Btn->Checked)
		{
			Ville_liv->ReadOnly = false;
			Liv_Txt->ReadOnly = false;
			Select_Liv_Combo->Enabled = false;
		}
		else
		{
			Ville_liv->ReadOnly = true;
			Liv_Txt->ReadOnly = true;
			Select_Liv_Combo->Enabled = true;
		}
	}

	private: System::Void Fact_Nouv_Btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Fact_Nouv_Btn->Checked)
		{
			Ville_fact->ReadOnly = false;
			Fact_Txt->ReadOnly = false;
			Select_Fact_Combo->Enabled = false;
		}
		else
		{
			Ville_fact->ReadOnly = true;
			Fact_Txt->ReadOnly = true;
			Select_Fact_Combo->Enabled = true;
		}
	}
	 
	private:
		System::String^ adresse_de_liv;
		System::String^ adresse_de_fact;
		System::String^ type_addresse;


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//Création des calendrier pour obtenir les date de Paiement et de Solde
		DateTimePicker^ dateEmi = gcnew DateTimePicker();
		dateEmi->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
		dateEmi->CustomFormat = L"yyyy-MM-dd";
		DateTimePicker^ dateSolde = gcnew DateTimePicker();
		dateSolde->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
		dateSolde->CustomFormat = L"yyyy-MM-dd";

		dateEmi->Value = datePaye->Value.AddDays(1);
		dateSolde->Value = datePaye->Value.AddDays(3);

		//Conncextion à la base
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;
		con = mysql_init(NULL);
		int qstate;
		System::String^ query;

		if (con == NULL)
		{
			finish_with_error(con);
			exit(1);
		}

		if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
			finish_with_error(con);
		}

		System::String^ Liv;
		System::String^ Fact;


		//Si les adresses de livraison et de facturation existe déjà
		if (Liv_Existe_Btn->Checked == true && Fact_Exist_Btn->Checked == true)
		{
		
			query = "CALL ajout_Commande('";
			query += totHT_txt->Text;
			query += "', '";
			query += totTVA_txt->Text;
			query += "', '";
			query += Remise;
			query += "', '";
			query += dateLiv->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateEmi->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += datePaye->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateSolde->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += adresse_de_liv; //Select_Liv_Combo->SelectedItem->ToString();
			query += "', '";
			query += adresse_de_fact; //Select_Fact_Combo->SelectedItem->ToString();
			query += "', '";
			query += id_client->Text;
			query += "', '";
			query += Metho_achat->SelectedItem->ToString();
			query += "'); ";
		}
		else if (Fact_Nouv_Btn->Checked == true && Liv_Nouv_Btn->Checked == true)
		{

			if (Liv_Txt->Text == Fact_Txt->Text && Ville_liv->Text == Ville_fact->Text) {
				query += "CALL Ignorer('";
				query += id_client->Text;
				query += "', '";
				query += Liv_Txt->Text;
				query += "', '";
				query += Ville_liv->Text;
				query += "', 'livraison et facturation'); ";
			}
			else {
				query += "CALL Ignorer('";
				query += id_client->Text;
				query += "', '";
				query += Liv_Txt->Text;
				query += "', '";
				query += Ville_liv->Text;
				query += "', 'livraison'); ";

				query += "CALL Ignorer('";
				query += id_client->Text;
				query += "', '";
				query += Fact_Txt->Text;
				query += "', '";
				query += Ville_fact->Text;
				query += "', 'facturation'); ";
			}

			query += "CALL ajout_Commande('";
			query += totHT_txt->Text;
			query += "', '";
			query += totTVA_txt->Text;
			query += "', '";
			query += Remise;
			query += "', '";
			query += dateLiv->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateEmi->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += datePaye->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateSolde->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += Liv_Txt->Text;
			query += "', '";
			query += Fact_Txt->Text;
			query += "', '";
			query += id_client->Text;
			query += "', '";
			query += Metho_achat->SelectedItem->ToString();
			query += "'); ";

		}
		else if (Liv_Nouv_Btn->Checked == true)
		{

			query += "CALL Ignorer('";
			query += id_client->Text;
			query += "', '";
			query += Liv_Txt->Text;
			query += "', '";
			query += Ville_liv->Text;
			query += "', 'livraison'); CALL ajout_Commande('";
			query += totHT_txt->Text;
			query += "', '";
			query += totTVA_txt->Text;
			query += "', '";
			query += Remise;
			query += "', '";
			query += dateLiv->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateEmi->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += datePaye->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateSolde->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += Liv_Txt->Text;
			query += "', '";
			query += adresse_de_fact;
			query += "', '";
			query += id_client->Text;
			query += "', '";
			query += Metho_achat->SelectedItem->ToString();
			query += "');";
		
		}
		//Si l'utilisateur rentre une nouvelle adresse de facturation
		else if (Fact_Nouv_Btn->Checked == true)
		{
		
			query += "CALL Ignorer('";
			query += id_client->Text;
			query += "', '";
			query += Fact_Txt->Text;
			query += "', '";
			query += Ville_fact->Text;
			query += "', 'facturation'); CALL ajout_Commande('";
			query += totHT_txt->Text;
			query += "', '";
			query += totTVA_txt->Text;
			query += "', '";
			query += Remise;
			query += "', '";
			query += dateLiv->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateEmi->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += datePaye->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += dateSolde->Value.Date.ToString("yyyy/MM/dd");
			query += "', '";
			query += adresse_de_liv;
			query += "', '";
			query += Fact_Txt->Text;
			query += "', '";
			query += id_client->Text;
			query += "', '";
			query += Metho_achat->SelectedItem->ToString();
			query += "'); ";
		}


		pin_ptr<const wchar_t> wch = PtrToStringChars(query);
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((query->Length + 1) * 2);
		errno_t err = 0;
		char* ch = (char*)malloc(sizeInBytes);
		err = wcstombs_s(&convertedChars,
			ch, sizeInBytes,
			wch, sizeInBytes);


		std::cout << ch << std::endl << std::endl;


		System::String^ id_commande;
		
		//Execution de la requête
		qstate = mysql_query(con, ch);
		//std::cout << con->info << std::endl;
		std::cout << mysql_error(con) << std::endl;
		std::cin >> ch;
		if (!qstate)
		{
			std::cout << "prout" << std::endl;
			res = mysql_store_result(con);
			std::cout << res->row_count << std::endl;
			std::cin >> ch;
			while (row = mysql_fetch_row(res))
			{
				id_commande = gcnew String(row[0]);
			}
			//mysql_free_result(res);
		}


		System::String^ query_2;
		// STOCK
		for (int n = 0; n < RecapData->RowCount -1 ; n++)
		{
			query_2 += "CALL update_Catalogue_stock('";
			query_2 += RecapData->Rows[n]->Cells[3]->Value->ToString();
			query_2 += "', '";
			query_2 += RecapData->Rows[n]->Cells[2]->Value->ToString();
			query_2 += "'); ";
		}

		// Fournir
		for (int n = 0; n < RecapData->RowCount - 1; n++)
		{
			query_2 += "CALL ajout_Fournir('";
			query_2 += RecapData->Rows[n]->Cells[2]->Value->ToString();
			query_2 += "', '";
			query_2 += RecapData->Rows[n]->Cells[3]->Value->ToString();
			query_2 += "', '";
			query_2 += id_commande;
			query_2 += "'); ";
		}

		pin_ptr<const wchar_t> wch_2 = PtrToStringChars(query_2);
		size_t convertedChars_2 = 0;
		size_t  sizeInBytes_2 = ((query->Length + 1) * 2);
		errno_t err_2 = 0;
		char* ch_2 = (char*)malloc(sizeInBytes_2);
		err_2 = wcstombs_s(&convertedChars_2,
			ch_2, sizeInBytes_2,
			wch_2, sizeInBytes_2);


		std::cout << ch_2 << std::endl << std::endl;

		con = mysql_init(NULL);

		if (con == NULL)
		{
			finish_with_error(con);
			exit(1);
		}

		if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
			finish_with_error(con);
		}

		//Execution de la requête
		qstate = mysql_query(con, ch_2);
		if (!qstate)
		{
			res = mysql_store_result(con);
		}
	
		//Création d'une DataTable pour stocké les donnée à envoyer dans Facture.h	
		DataTable^ transfert = gcnew DataTable();
		transfert->Columns->Add("Nom");
		transfert->Columns->Add("Prix");
		transfert->Columns->Add("Quantite");
		transfert->Columns->Add("id_article");

		for (int n = 0; n < RecapData->RowCount; n++)
		{
			transfert->Rows->Add(RecapData->Rows[n]->Cells[0]->Value, RecapData->Rows[n]->Cells[1]->Value, RecapData->Rows[n]->Cells[2]->Value);
		}
		//Transition dans Facture
		this->facture = gcnew Client::Facture(id_commande, PageClient, nom->Text, prenom->Text);
		this->facture->Show();

		Precedent->Close();
		this->Close();
		//this->Hide();
	}

	private: System::Void Select_Liv_Combo_Validated(System::Object^ sender, System::EventArgs^ e) {
		adresse_de_liv = ((Control^)sender)->Text;
	}

	private: System::Void Select_Fact_Combo_Validated(System::Object^ sender, System::EventArgs^ e) {
		adresse_de_fact = ((Control^)sender)->Text;
	}

	private: System::Void Precedent_Click(System::Object^ sender, System::EventArgs^ e) {
		Precedent->Show();
		this->Close();
	}
};
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    