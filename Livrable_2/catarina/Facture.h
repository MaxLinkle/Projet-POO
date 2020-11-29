#pragma once
#include <mysql.h>
#include<vcclr.h>

namespace NS_Facture {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Facture
	/// </summary>
	public ref class Facture : public System::Windows::Forms::Form
	{
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
		Facture(String^ recap, String^ total, String^ nb, String^ nom, String^ prenom, String^ id, String^ metho, String^ adresse_de_liv, String^ adresse_de_fact, DateTime dateEmiss, DateTime dateLivr, String^ TVA, String^ id_paiement)
		{
			InitializeComponent();
			textBox1->Text = recap;
			tot_txt->Text = total;
			nb_txt->Text = nb;
			nom_txt->Text = nom;
			prenom_txt->Text = prenom;
			id_client->Text = id;
			metho_txt->Text = metho;
			addLiv_txt->Text = adresse_de_liv;
			addFact_txt->Text = adresse_de_fact;
			dateEmi->Value = dateEmiss;
			dateLiv->Value = dateLivr;
			totHT_txt->Text = TVA;
			id_paye->Text = id_paiement;
			
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
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

	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ nb_txt;
	private: System::Windows::Forms::Label^ lbl_NombArt;
	private: System::Windows::Forms::TextBox^ tot_txt;
	private: System::Windows::Forms::Label^ lbl_tot;
	private: System::Windows::Forms::TextBox^ id_client;
	private: System::Windows::Forms::TextBox^ prenom_txt;

	private: System::Windows::Forms::TextBox^ nom_txt;

	private: System::Windows::Forms::Label^ Prenom_Cli;
	private: System::Windows::Forms::Label^ Nom_Cli;
	private: System::Windows::Forms::Label^ Num_Cli;
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




	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::IContainer ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nb_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_NombArt = (gcnew System::Windows::Forms::Label());
			this->tot_txt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_tot = (gcnew System::Windows::Forms::Label());
			this->id_client = (gcnew System::Windows::Forms::TextBox());
			this->prenom_txt = (gcnew System::Windows::Forms::TextBox());
			this->nom_txt = (gcnew System::Windows::Forms::TextBox());
			this->Prenom_Cli = (gcnew System::Windows::Forms::Label());
			this->Nom_Cli = (gcnew System::Windows::Forms::Label());
			this->Num_Cli = (gcnew System::Windows::Forms::Label());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(18, 302);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(691, 434);
			this->textBox1->TabIndex = 1;
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
			// nb_txt
			// 
			this->nb_txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nb_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nb_txt->Location = System::Drawing::Point(164, 752);
			this->nb_txt->Name = L"nb_txt";
			this->nb_txt->ReadOnly = true;
			this->nb_txt->Size = System::Drawing::Size(100, 17);
			this->nb_txt->TabIndex = 26;
			// 
			// lbl_NombArt
			// 
			this->lbl_NombArt->AutoSize = true;
			this->lbl_NombArt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_NombArt->Location = System::Drawing::Point(15, 751);
			this->lbl_NombArt->Name = L"lbl_NombArt";
			this->lbl_NombArt->Size = System::Drawing::Size(154, 18);
			this->lbl_NombArt->TabIndex = 25;
			this->lbl_NombArt->Text = L"Nombres d\'article(s) : ";
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
			// id_client
			// 
			this->id_client->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->id_client->Location = System::Drawing::Point(340, 42);
			this->id_client->Name = L"id_client";
			this->id_client->ReadOnly = true;
			this->id_client->Size = System::Drawing::Size(45, 13);
			this->id_client->TabIndex = 33;
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
			// Num_Cli
			// 
			this->Num_Cli->AutoSize = true;
			this->Num_Cli->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Num_Cli->Location = System::Drawing::Point(248, 42);
			this->Num_Cli->Name = L"Num_Cli";
			this->Num_Cli->Size = System::Drawing::Size(98, 13);
			this->Num_Cli->TabIndex = 28;
			this->Num_Cli->Text = L"Numero Client : ";
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
			this->LivPrev->Text = L"Date de Livraison estimé : ";
			// 
			// dateEmi
			// 
			this->dateEmi->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dateEmi->CalendarForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dateEmi->CustomFormat = L"yyyy-MM-dd";
			this->dateEmi->DropDownAlign = System::Windows::Forms::LeftRightAlignment::Right;
			this->dateEmi->Enabled = false;
			this->dateEmi->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateEmi->Location = System::Drawing::Point(202, 262);
			this->dateEmi->Name = L"dateEmi";
			this->dateEmi->Size = System::Drawing::Size(84, 20);
			this->dateEmi->TabIndex = 42;
			// 
			// date_emi
			// 
			this->date_emi->AutoSize = true;
			this->date_emi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_emi->Location = System::Drawing::Point(88, 269);
			this->date_emi->Name = L"date_emi";
			this->date_emi->Size = System::Drawing::Size(108, 13);
			this->date_emi->TabIndex = 43;
			this->date_emi->Text = L"Date d\'émission : ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(337, 754);
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
			this->totHT_txt->Location = System::Drawing::Point(409, 754);
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
			this->label4->Location = System::Drawing::Point(360, 784);
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
			this->totTVA_txt->Location = System::Drawing::Point(409, 785);
			this->totTVA_txt->Name = L"totTVA_txt";
			this->totTVA_txt->ReadOnly = true;
			this->totTVA_txt->Size = System::Drawing::Size(100, 17);
			this->totTVA_txt->TabIndex = 47;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(453, 756);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 48;
			this->label5->Text = L"€";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(453, 788);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 49;
			this->label6->Text = L"€";
			// 
			// Facture
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 847);
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
			this->Controls->Add(this->id_client);
			this->Controls->Add(this->prenom_txt);
			this->Controls->Add(this->nom_txt);
			this->Controls->Add(this->Prenom_Cli);
			this->Controls->Add(this->Nom_Cli);
			this->Controls->Add(this->Num_Cli);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nb_txt);
			this->Controls->Add(this->lbl_NombArt);
			this->Controls->Add(this->tot_txt);
			this->Controls->Add(this->lbl_tot);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Facture";
			this->Text = L"Facture";
			this->Load += gcnew System::EventHandler(this, &Facture::Facture_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Facture_Load(System::Object^ sender, System::EventArgs^ e) {
	
		Bitmap^ test = (gcnew System::Drawing::Bitmap("LOGO.png"));
		this->pictureBox1->Image = test;

		int TVA;
		TVA = Convert::ToDouble(tot_txt->Text) - Convert::ToDouble(totHT_txt->Text);
		totTVA_txt->Text = TVA.ToString();

	}
};
}