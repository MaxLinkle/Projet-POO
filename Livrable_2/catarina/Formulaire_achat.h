#pragma once
#include <mysql.h>
#include<vcclr.h>
#include "Facture.h"


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
		Formulaire_achat(String^ achat, String^ nb, String^ total)
		{
			InitializeComponent();
			ConnexionBase();
			recap->Text = achat;
			nb_txt->Text = nb;
			tot_txt->Text = total;
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
			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				finish_with_error(con);
			}

			String^ query = gcnew String("SELECT * FROM Paiement;\
									   SELECT adresse_adresses_clients FROM Adresses_clients WHERE ID_type_adresse = 1;\
									   SELECT adresse_adresses_clients FROM Adresses_clients WHERE ID_type_adresse = 2 OR ID_type_adresse = 1;\
									   SELECT ID_client, nom, prenom FROM Client;");

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
					id_client->Text = gcnew String(row[0]);
					nom->Text = gcnew String(row[1]);
					prenom->Text = gcnew String(row[2]);
				}
			}
		}

	private: NS_Facture::Facture^ facture;


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


private: System::Windows::Forms::TextBox^ nom;
private: System::Windows::Forms::TextBox^ prenom;
private: System::Windows::Forms::TextBox^ id_client;
private: System::Windows::Forms::TextBox^ recap;

private: System::Windows::Forms::GroupBox^ Récapitulatif;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ nb_txt;

private: System::Windows::Forms::Label^ lbl_NombArt;
private: System::Windows::Forms::TextBox^ tot_txt;

private: System::Windows::Forms::Label^ lbl_tot;
private: System::Windows::Forms::Label^ quantite;
private: System::Windows::Forms::Label^ Prix;
private: System::Windows::Forms::Label^ NomArt;





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
			this->Num_Cli = (gcnew System::Windows::Forms::Label());
			this->Nom_Cli = (gcnew System::Windows::Forms::Label());
			this->Prenom_Cli = (gcnew System::Windows::Forms::Label());
			this->Precedent = (gcnew System::Windows::Forms::Button());
			this->warni = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->nom = (gcnew System::Windows::Forms::TextBox());
			this->prenom = (gcnew System::Windows::Forms::TextBox());
			this->id_client = (gcnew System::Windows::Forms::TextBox());
			this->recap = (gcnew System::Windows::Forms::TextBox());
			this->Récapitulatif = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nb_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_NombArt = (gcnew System::Windows::Forms::Label());
			this->tot_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_tot = (gcnew System::Windows::Forms::Label());
			this->quantite = (gcnew System::Windows::Forms::Label());
			this->Prix = (gcnew System::Windows::Forms::Label());
			this->NomArt = (gcnew System::Windows::Forms::Label());
			this->addLivraison->SuspendLayout();
			this->addFacturation->SuspendLayout();
			this->Récapitulatif->SuspendLayout();
			this->SuspendLayout();
			// 
			// addLivraison
			// 
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
			this->Liv_Nouv_Btn->TabStop = true;
			this->Liv_Nouv_Btn->UseVisualStyleBackColor = true;
			this->Liv_Nouv_Btn->CheckedChanged += gcnew System::EventHandler(this, &Formulaire_achat::Liv_Nouv_Btn_CheckedChanged);
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
			this->addFacturation->Location = System::Drawing::Point(421, 488);
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
			this->Fact_Nouv_Btn->TabStop = true;
			this->Fact_Nouv_Btn->UseVisualStyleBackColor = true;
			this->Fact_Nouv_Btn->CheckedChanged += gcnew System::EventHandler(this, &Formulaire_achat::Fact_Nouv_Btn_CheckedChanged);
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
			this->button1->Location = System::Drawing::Point(542, 646);
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
			this->id_client->Location = System::Drawing::Point(100, 415);
			this->id_client->Name = L"id_client";
			this->id_client->ReadOnly = true;
			this->id_client->Size = System::Drawing::Size(45, 20);
			this->id_client->TabIndex = 13;
			// 
			// recap
			// 
			this->recap->Location = System::Drawing::Point(16, 61);
			this->recap->Multiline = true;
			this->recap->Name = L"recap";
			this->recap->ReadOnly = true;
			this->recap->Size = System::Drawing::Size(589, 186);
			this->recap->TabIndex = 14;
			// 
			// Récapitulatif
			// 
			this->Récapitulatif->Controls->Add(this->label2);
			this->Récapitulatif->Controls->Add(this->nb_txt);
			this->Récapitulatif->Controls->Add(this->lbl_NombArt);
			this->Récapitulatif->Controls->Add(this->tot_txt);
			this->Récapitulatif->Controls->Add(this->lbl_tot);
			this->Récapitulatif->Controls->Add(this->quantite);
			this->Récapitulatif->Controls->Add(this->Prix);
			this->Récapitulatif->Controls->Add(this->NomArt);
			this->Récapitulatif->Controls->Add(this->recap);
			this->Récapitulatif->Location = System::Drawing::Point(12, 63);
			this->Récapitulatif->Name = L"Récapitulatif";
			this->Récapitulatif->Size = System::Drawing::Size(630, 317);
			this->Récapitulatif->TabIndex = 15;
			this->Récapitulatif->TabStop = false;
			this->Récapitulatif->Text = L"Récapitulatif";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(501, 285);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"€";
			// 
			// nb_txt
			// 
			this->nb_txt->Location = System::Drawing::Point(394, 259);
			this->nb_txt->Name = L"nb_txt";
			this->nb_txt->ReadOnly = true;
			this->nb_txt->Size = System::Drawing::Size(100, 20);
			this->nb_txt->TabIndex = 21;
			// 
			// lbl_NombArt
			// 
			this->lbl_NombArt->AutoSize = true;
			this->lbl_NombArt->Location = System::Drawing::Point(291, 262);
			this->lbl_NombArt->Name = L"lbl_NombArt";
			this->lbl_NombArt->Size = System::Drawing::Size(108, 13);
			this->lbl_NombArt->TabIndex = 20;
			this->lbl_NombArt->Text = L"Nombres d\'article(s) : ";
			// 
			// tot_txt
			// 
			this->tot_txt->Location = System::Drawing::Point(394, 282);
			this->tot_txt->Name = L"tot_txt";
			this->tot_txt->ReadOnly = true;
			this->tot_txt->Size = System::Drawing::Size(100, 20);
			this->tot_txt->TabIndex = 19;
			// 
			// lbl_tot
			// 
			this->lbl_tot->AutoSize = true;
			this->lbl_tot->Location = System::Drawing::Point(359, 285);
			this->lbl_tot->Name = L"lbl_tot";
			this->lbl_tot->Size = System::Drawing::Size(40, 13);
			this->lbl_tot->TabIndex = 18;
			this->lbl_tot->Text = L"Total : ";
			// 
			// quantite
			// 
			this->quantite->AutoSize = true;
			this->quantite->Location = System::Drawing::Point(556, 42);
			this->quantite->Name = L"quantite";
			this->quantite->Size = System::Drawing::Size(47, 13);
			this->quantite->TabIndex = 17;
			this->quantite->Text = L"Quantité";
			// 
			// Prix
			// 
			this->Prix->AutoSize = true;
			this->Prix->Location = System::Drawing::Point(406, 42);
			this->Prix->Name = L"Prix";
			this->Prix->Size = System::Drawing::Size(24, 13);
			this->Prix->TabIndex = 16;
			this->Prix->Text = L"Prix";
			// 
			// NomArt
			// 
			this->NomArt->AutoSize = true;
			this->NomArt->Location = System::Drawing::Point(20, 42);
			this->NomArt->Name = L"NomArt";
			this->NomArt->Size = System::Drawing::Size(29, 13);
			this->NomArt->TabIndex = 15;
			this->NomArt->Text = L"Nom";
			// 
			// Formulaire_achat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 684);
			this->Controls->Add(this->Récapitulatif);
			this->Controls->Add(this->id_client);
			this->Controls->Add(this->prenom);
			this->Controls->Add(this->nom);
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
			this->Récapitulatif->ResumeLayout(false);
			this->Récapitulatif->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Formulaire_achat_Load(System::Object^ sender, System::EventArgs^ e) {
		Liv_Txt->ReadOnly = true;
		Fact_Txt->ReadOnly = true;
	}

	private: System::Void Liv_Nouv_Btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Liv_Nouv_Btn->Checked)
		{
			Liv_Txt->ReadOnly = false;
			Select_Liv_Combo->Enabled = false;
		}
		else
		{
			Liv_Txt->ReadOnly = true;
			Select_Liv_Combo->Enabled = true;
		}
	}
private: System::Void Fact_Nouv_Btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Fact_Nouv_Btn->Checked)
	{
		Fact_Txt->ReadOnly = false;
		Select_Fact_Combo->Enabled = false;
	}
	else
	{
		Fact_Txt->ReadOnly = true;
		Select_Fact_Combo->Enabled = true;
	}
}
	   String^ adresse_de_liv;
	   String^ adresse_de_fact;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	this->facture = gcnew NS_Facture::Facture(recap->Text, tot_txt->Text, nb_txt->Text, nom->Text, prenom->Text, id_client->Text, Metho_achat->SelectedItem->ToString(), adresse_de_liv, adresse_de_fact);
	this->facture->Show();
}
private: System::Void Select_Liv_Combo_Validated(System::Object^ sender, System::EventArgs^ e) {
	adresse_de_liv = ((Control^)sender)->Text;
}

private: System::Void Select_Fact_Combo_Validated(System::Object^ sender, System::EventArgs^ e) {
	adresse_de_fact = ((Control^)sender)->Text;
}
};
}