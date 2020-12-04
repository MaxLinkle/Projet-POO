#pragma once
#include <mysql.h>
#include<vcclr.h>
#include "SC.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NS_SuperC;

	/// <summary>
	/// Description r�sum�e de Facture
	/// </summary>
	public ref class Facture : public NS_SuperC::SuperC // public System::Windows::Forms::Form
	{
	System::String^ id_commande;
	String^ Remise;
	private: System::Windows::Forms::TextBox^ remise;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ totRemise;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantite;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ total;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ HT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TVA;
	private: System::Windows::Forms::Button^ continuer;

	private: Label^ id_paye = gcnew Label();
	public:
		Facture(void)
		{
			InitializeComponent();
		//
		//TODO: ajoutez ici le code du constructeur
			//
		}
	public:
		Facture(String^ i_id_commande, Form^ inpPageClient, String^ i_nom, String^ i_prenom): SuperC(inpPageClient)
		{
			PageClient = inpPageClient;
			InitializeComponent();
			nom_txt->Text = i_nom;
			prenom_txt->Text = i_prenom;
			id_commande = i_id_commande;
			ConnexionBase();


			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~Facture()
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
			String^ query;
			if (con == NULL)
			{
				finish_with_error(con);
				exit(1);
			}
			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				finish_with_error(con);
			}

			query = ("SELECT * FROM Commande INNER JOIN Paiement ON Paiement.ID_paiement = Commande.ID_paiement INNER JOIN Adresse_client AS l ON l.ID_adresse_client = Commande.ID_adresse_livraison INNER JOIN Adresse_client AS f ON f.ID_adresse_client = Commande.ID_adresse_facturation WHERE Commande.ID_commande = '");
			query += id_commande;
			query += ("';SELECT * FROM Fournir INNER JOIN Catalogue ON Catalogue.ID_article = Fournir.ID_article WHERE Fournir.ID_commande = '");
			query += id_commande;
			query += ("';");

			pin_ptr<const wchar_t> wch = PtrToStringChars(query);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((query->Length + 1) * 2);
			errno_t err = 0;
			char* ch = (char*)malloc(sizeInBytes);
			err = wcstombs_s(&convertedChars,
				ch, sizeInBytes,
				wch, sizeInBytes);
			qstate = mysql_query(con, ch);

			std::cout << ch << std::endl;
			std::cout << qstate << std::endl;
			std::cout << mysql_error(con) << std::endl;

			if (!qstate)
			{
				res = mysql_store_result(con);
				std::cout << res->row_count;
				while (row = mysql_fetch_row(res))
				{
					Ref->Text = gcnew String(row[1]);
					totHT_txt->Text = gcnew String(row[2]);
					totTVA_txt->Text = gcnew String(row[3]);
					Remise = gcnew String(row[4]);
					dateLiv -> Value = DateTime::ParseExact(gcnew String(row[5]), "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
					dateEmi->Value = DateTime::ParseExact(gcnew String(row[6]), "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
					metho_txt->Text = gcnew String(row[14]);
					addLiv_txt -> Text = gcnew String(row[16]);
					addFact_txt -> Text = gcnew String(row[21]);
				}
				mysql_free_result(res);

				mysql_next_result(con);
				res = mysql_store_result(con);

				while (row = mysql_fetch_row(res))
				{

					int n = recap->Rows->Add();

					double ht = atof(row[7]);
					double tva = atof(row[8]);
					double ttc = ht * ((tva / 100) + 1);

					recap->Rows[n]->Cells[0]->Value = gcnew String(row[5]);
					recap->Rows[n]->Cells[1]->Value = gcnew String(row[1]);
					recap->Rows[n]->Cells[2]->Value = ttc;
					recap->Rows[n]->Cells[3]->Value = gcnew String(row[7]);
					recap->Rows[n]->Cells[4]->Value = gcnew String(row[8]);
				}
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Form^ PageClient;


	private: System::Windows::Forms::TextBox^ tot_txt;
	private: System::Windows::Forms::Label^ lbl_tot;
	private: System::Windows::Forms::TextBox^ Ref;
	private: System::Windows::Forms::TextBox^ prenom_txt;
	private: System::Windows::Forms::TextBox^ nom_txt;
	private: System::Windows::Forms::Label^ Prenom_Cli;
	private: System::Windows::Forms::Label^ Nom_Cli;
	private: System::Windows::Forms::Label^ reference;
	private: System::Windows::Forms::Label^ lbl_addFact;
	private: System::Windows::Forms::Label^ lbl_addLiv;
	private: System::Windows::Forms::TextBox^ addFact_txt;
	private: System::Windows::Forms::TextBox^ addLiv_txt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ metho_txt;
	private: System::Windows::Forms::DateTimePicker^ dateLiv;
	private: System::Windows::Forms::Label^ LivPrev;
	private: System::Windows::Forms::DateTimePicker^ dateEmi;
	private: System::Windows::Forms::Label^ date_emi;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ totHT_txt;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ totTVA_txt;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ recap;

	protected:

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::IContainer ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tot_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_tot = (gcnew System::Windows::Forms::Label());
			this->Ref = (gcnew System::Windows::Forms::TextBox());
			this->prenom_txt = (gcnew System::Windows::Forms::TextBox());
			this->nom_txt = (gcnew System::Windows::Forms::TextBox());
			this->Prenom_Cli = (gcnew System::Windows::Forms::Label());
			this->Nom_Cli = (gcnew System::Windows::Forms::Label());
			this->reference = (gcnew System::Windows::Forms::Label());
			this->lbl_addFact = (gcnew System::Windows::Forms::Label());
			this->lbl_addLiv = (gcnew System::Windows::Forms::Label());
			this->addFact_txt = (gcnew System::Windows::Forms::TextBox());
			this->addLiv_txt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->metho_txt = (gcnew System::Windows::Forms::TextBox());
			this->dateLiv = (gcnew System::Windows::Forms::DateTimePicker());
			this->LivPrev = (gcnew System::Windows::Forms::Label());
			this->dateEmi = (gcnew System::Windows::Forms::DateTimePicker());
			this->date_emi = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->totHT_txt = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->totTVA_txt = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->recap = (gcnew System::Windows::Forms::DataGridView());
			this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantite = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TVA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->remise = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->totRemise = (gcnew System::Windows::Forms::Label());
			this->continuer = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recap))->BeginInit();
			this->SuspendLayout();
			//
			// pictureBox1
			//
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Location = System::Drawing::Point(54, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(170, 170);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(659, 759);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 27;
			this->label2->Text = L"€";
			//
			// tot_txt
			//
			this->tot_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tot_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tot_txt->Location = System::Drawing::Point(609, 755);
			this->tot_txt->Name = L"tot_txt";
			this->tot_txt->ReadOnly = true;
			this->tot_txt->Size = System::Drawing::Size(63, 17);
			this->tot_txt->TabIndex = 24;
			//
			// lbl_tot
			//
			this->lbl_tot->AutoSize = true;
			this->lbl_tot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tot->Location = System::Drawing::Point(524, 754);
			this->lbl_tot->Name = L"lbl_tot";
			this->lbl_tot->Size = System::Drawing::Size(86, 18);
			this->lbl_tot->TabIndex = 23;
			this->lbl_tot->Text = L"Total TTC : ";
			//
			// Ref
			//
			this->Ref->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Ref->Location = System::Drawing::Point(393, 42);
			this->Ref->Name = L"Ref";
			this->Ref->ReadOnly = true;
			this->Ref->Size = System::Drawing::Size(90, 13);
			this->Ref->TabIndex = 33;
			//
			// prenom_txt
			//
			this->prenom_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->prenom_txt->Location = System::Drawing::Point(303, 94);
			this->prenom_txt->Name = L"prenom_txt";
			this->prenom_txt->ReadOnly = true;
			this->prenom_txt->Size = System::Drawing::Size(100, 13);
			this->prenom_txt->TabIndex = 32;
			//
			// nom_txt
			//
			this->nom_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nom_txt->Location = System::Drawing::Point(286, 68);
			this->nom_txt->Name = L"nom_txt";
			this->nom_txt->ReadOnly = true;
			this->nom_txt->Size = System::Drawing::Size(100, 13);
			this->nom_txt->TabIndex = 31;
			//
			// Prenom_Cli
			//
			this->Prenom_Cli->AutoSize = true;
			this->Prenom_Cli->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Prenom_Cli->Location = System::Drawing::Point(248, 94);
			this->Prenom_Cli->Name = L"Prenom_Cli";
			this->Prenom_Cli->Size = System::Drawing::Size(61, 13);
			this->Prenom_Cli->TabIndex = 30;
			this->Prenom_Cli->Text = L"Prénom : ";
			//
			// Nom_Cli
			//
			this->Nom_Cli->AutoSize = true;
			this->Nom_Cli->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_Cli->Location = System::Drawing::Point(248, 68);
			this->Nom_Cli->Name = L"Nom_Cli";
			this->Nom_Cli->Size = System::Drawing::Size(44, 13);
			this->Nom_Cli->TabIndex = 29;
			this->Nom_Cli->Text = L"Nom : ";
			//
			// reference
			//
			this->reference->AutoSize = true;
			this->reference->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reference->Location = System::Drawing::Point(248, 42);
			this->reference->Name = L"reference";
			this->reference->Size = System::Drawing::Size(139, 13);
			this->reference->TabIndex = 28;
			this->reference->Text = L"Référence Commande :";
			//
			// lbl_addFact
			//
			this->lbl_addFact->AutoSize = true;
			this->lbl_addFact->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_addFact->Location = System::Drawing::Point(248, 164);
			this->lbl_addFact->Name = L"lbl_addFact";
			this->lbl_addFact->Size = System::Drawing::Size(138, 13);
			this->lbl_addFact->TabIndex = 34;
			this->lbl_addFact->Text = L"Adresse de Facturation";
			//
			// lbl_addLiv
			//
			this->lbl_addLiv->AutoSize = true;
			this->lbl_addLiv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_addLiv->Location = System::Drawing::Point(489, 42);
			this->lbl_addLiv->Name = L"lbl_addLiv";
			this->lbl_addLiv->Size = System::Drawing::Size(125, 13);
			this->lbl_addLiv->TabIndex = 35;
			this->lbl_addLiv->Text = L"Adresse de Livraison";
			//
			// addFact_txt
			//
			this->addFact_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addFact_txt->Location = System::Drawing::Point(251, 181);
			this->addFact_txt->Multiline = true;
			this->addFact_txt->Name = L"addFact_txt";
			this->addFact_txt->ReadOnly = true;
			this->addFact_txt->Size = System::Drawing::Size(172, 51);
			this->addFact_txt->TabIndex = 36;
			//
			// addLiv_txt
			//
			this->addLiv_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addLiv_txt->Location = System::Drawing::Point(492, 58);
			this->addLiv_txt->Multiline = true;
			this->addLiv_txt->Name = L"addLiv_txt";
			this->addLiv_txt->ReadOnly = true;
			this->addLiv_txt->Size = System::Drawing::Size(172, 51);
			this->addLiv_txt->TabIndex = 37;
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(489, 164);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 13);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Methode de Paiement :";
			//
			// metho_txt
			//
			this->metho_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->metho_txt->Location = System::Drawing::Point(492, 181);
			this->metho_txt->Name = L"metho_txt";
			this->metho_txt->ReadOnly = true;
			this->metho_txt->Size = System::Drawing::Size(168, 13);
			this->metho_txt->TabIndex = 39;
			//
			// dateLiv
			//
			this->dateLiv->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dateLiv->CalendarForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dateLiv->CustomFormat = L"yyyy-MM-dd";
			this->dateLiv->DropDownAlign = System::Windows::Forms::LeftRightAlignment::Right;
			this->dateLiv->Enabled = false;
			this->dateLiv->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateLiv->Location = System::Drawing::Point(568, 262);
			this->dateLiv->Name = L"dateLiv";
			this->dateLiv->Size = System::Drawing::Size(92, 20);
			this->dateLiv->TabIndex = 40;
			//
			// LivPrev
			//
			this->LivPrev->AutoSize = true;
			this->LivPrev->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LivPrev->Location = System::Drawing::Point(406, 268);
			this->LivPrev->Name = L"LivPrev";
			this->LivPrev->Size = System::Drawing::Size(159, 13);
			this->LivPrev->TabIndex = 41;
			this->LivPrev->Text = L"Date de Livraison estim� : ";
			//
			// dateEmi
			//
			this->dateEmi->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dateEmi->CalendarForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dateEmi->CustomFormat = L"yyyy-MM-dd";
			this->dateEmi->DropDownAlign = System::Windows::Forms::LeftRightAlignment::Right;
			this->dateEmi->Enabled = false;
			this->dateEmi->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateEmi->Location = System::Drawing::Point(202, 261);
			this->dateEmi->Name = L"dateEmi";
			this->dateEmi->Size = System::Drawing::Size(84, 20);
			this->dateEmi->TabIndex = 42;
			//
			// date_emi
			//
			this->date_emi->AutoSize = true;
			this->date_emi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_emi->Location = System::Drawing::Point(103, 268);
			this->date_emi->Name = L"date_emi";
			this->date_emi->Size = System::Drawing::Size(93, 13);
			this->date_emi->TabIndex = 43;
			this->date_emi->Text = L"Date Emision : ";
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(277, 754);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 18);
			this->label3->TabIndex = 44;
			this->label3->Text = L"Total HT : ";
			//
			// totHT_txt
			//
			this->totHT_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->totHT_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totHT_txt->Location = System::Drawing::Point(349, 754);
			this->totHT_txt->Name = L"totHT_txt";
			this->totHT_txt->ReadOnly = true;
			this->totHT_txt->Size = System::Drawing::Size(100, 17);
			this->totHT_txt->TabIndex = 45;
			//
			// label4
			//
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(300, 784);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 18);
			this->label4->TabIndex = 46;
			this->label4->Text = L"TVA :";
			//
			// totTVA_txt
			//
			this->totTVA_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->totTVA_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totTVA_txt->Location = System::Drawing::Point(349, 785);
			this->totTVA_txt->Name = L"totTVA_txt";
			this->totTVA_txt->ReadOnly = true;
			this->totTVA_txt->Size = System::Drawing::Size(100, 17);
			this->totTVA_txt->TabIndex = 47;
			//
			// label5
			//
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(406, 757);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 48;
			this->label5->Text = L"€";
			//
			// label6
			//
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(406, 789);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 49;
			this->label6->Text = L"€";
			//
			// recap
			//
			this->recap->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->recap->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->recap->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Nom, this->Quantite,
					this->total, this->HT, this->TVA
			});
			this->recap->Location = System::Drawing::Point(24, 316);
			this->recap->Name = L"recap";
			this->recap->ReadOnly = true;
			this->recap->Size = System::Drawing::Size(675, 406);
			this->recap->TabIndex = 50;
			//
			// Nom
			//
			this->Nom->HeaderText = L"Nom";
			this->Nom->Name = L"Nom";
			this->Nom->ReadOnly = true;
			//
			// Quantite
			//
			this->Quantite->HeaderText = L"Quantit�";
			this->Quantite->Name = L"Quantite";
			this->Quantite->ReadOnly = true;
			//
			// total
			//
			this->total->HeaderText = L"Total";
			this->total->Name = L"total";
			this->total->ReadOnly = true;
			//
			// HT
			//
			this->HT->HeaderText = L"HT";
			this->HT->Name = L"HT";
			this->HT->ReadOnly = true;
			this->HT->Visible = false;
			//
			// TVA
			//
			this->TVA->HeaderText = L"TVA";
			this->TVA->Name = L"TVA";
			this->TVA->ReadOnly = true;
			this->TVA->Visible = false;
			//
			// remise
			//
			this->remise->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->remise->Location = System::Drawing::Point(609, 786);
			this->remise->Name = L"remise";
			this->remise->ReadOnly = true;
			this->remise->Size = System::Drawing::Size(51, 13);
			this->remise->TabIndex = 51;
			this->remise->Visible = false;
			//
			// label7
			//
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(666, 789);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 52;
			this->label7->Text = L"�";
			this->label7->Visible = false;
			//
			// totRemise
			//
			this->totRemise->AutoSize = true;
			this->totRemise->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totRemise->Location = System::Drawing::Point(433, 782);
			this->totRemise->Name = L"totRemise";
			this->totRemise->Size = System::Drawing::Size(170, 18);
			this->totRemise->TabIndex = 53;
			this->totRemise->Text = L" Total TTC avec remise :";
			this->totRemise->Visible = false;
			//
			// continuer
			//
			this->continuer->Location = System::Drawing::Point(624, 832);
			this->continuer->Name = L"continuer";
			this->continuer->Size = System::Drawing::Size(75, 23);
			this->continuer->TabIndex = 54;
			this->continuer->Text = L"Ok";
			this->continuer->UseVisualStyleBackColor = true;
			this->continuer->Click += gcnew System::EventHandler(this, &Facture::continuer_Click);
			//
			// Facture
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 867);
			this->Controls->Add(this->continuer);
			this->Controls->Add(this->totRemise);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->remise);
			this->Controls->Add(this->recap);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->totTVA_txt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->totHT_txt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->date_emi);
			this->Controls->Add(this->dateEmi);
			this->Controls->Add(this->LivPrev);
			this->Controls->Add(this->dateLiv);
			this->Controls->Add(this->metho_txt);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->addLiv_txt);
			this->Controls->Add(this->addFact_txt);
			this->Controls->Add(this->lbl_addLiv);
			this->Controls->Add(this->lbl_addFact);
			this->Controls->Add(this->Ref);
			this->Controls->Add(this->prenom_txt);
			this->Controls->Add(this->nom_txt);
			this->Controls->Add(this->Prenom_Cli);
			this->Controls->Add(this->Nom_Cli);
			this->Controls->Add(this->reference);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tot_txt);
			this->Controls->Add(this->lbl_tot);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Facture";
			this->Text = L"Facture";
			this->Load += gcnew System::EventHandler(this, &Facture::Facture_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recap))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Facture_Load(System::Object^ sender, System::EventArgs^ e) {

		Bitmap^ test = (gcnew System::Drawing::Bitmap("LOGO.png"));
		this->pictureBox1->Image = test;

		double Tot;
		Tot = Convert::ToDouble(totHT_txt->Text) + Convert::ToDouble(totTVA_txt->Text);
		tot_txt->Text = Convert::ToString(Tot);

		double Reduc;
		Reduc = Convert::ToDouble(tot_txt->Text) - Convert::ToDouble(Remise);
		remise->Text = Convert::ToString(Reduc);

		if (remise->Text != tot_txt->Text)
		{
			label7->Visible = true;
			remise->Visible = true;
			totRemise->Visible = true;

		}
	}

	private: System::Void continuer_Click(System::Object^ sender, System::EventArgs^ e) {
		PageClient->Show();
		this->Close();
	}
};
}
