#pragma once

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
	public:
		Facture(void)
		{
			InitializeComponent();
		//
		//TODO: ajoutez ici le code du constructeur
			//
		}
	public:
		Facture(String^ recap, String^ total, String^ nb, String^ nom, String^ prenom, String^ id, String^ metho, String^ adresse_de_liv, String^ adresse_de_fact)
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(54, 252);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(602, 434);
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
			this->label2->Location = System::Drawing::Point(631, 737);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 27;
			this->label2->Text = L"€";
			// 
			// nb_txt
			// 
			this->nb_txt->Location = System::Drawing::Point(524, 711);
			this->nb_txt->Name = L"nb_txt";
			this->nb_txt->ReadOnly = true;
			this->nb_txt->Size = System::Drawing::Size(100, 20);
			this->nb_txt->TabIndex = 26;
			// 
			// lbl_NombArt
			// 
			this->lbl_NombArt->AutoSize = true;
			this->lbl_NombArt->Location = System::Drawing::Point(421, 714);
			this->lbl_NombArt->Name = L"lbl_NombArt";
			this->lbl_NombArt->Size = System::Drawing::Size(108, 13);
			this->lbl_NombArt->TabIndex = 25;
			this->lbl_NombArt->Text = L"Nombres d\'article(s) : ";
			// 
			// tot_txt
			// 
			this->tot_txt->Location = System::Drawing::Point(524, 734);
			this->tot_txt->Name = L"tot_txt";
			this->tot_txt->ReadOnly = true;
			this->tot_txt->Size = System::Drawing::Size(100, 20);
			this->tot_txt->TabIndex = 24;
			// 
			// lbl_tot
			// 
			this->lbl_tot->AutoSize = true;
			this->lbl_tot->Location = System::Drawing::Point(489, 737);
			this->lbl_tot->Name = L"lbl_tot";
			this->lbl_tot->Size = System::Drawing::Size(40, 13);
			this->lbl_tot->TabIndex = 23;
			this->lbl_tot->Text = L"Total : ";
			// 
			// id_client
			// 
			this->id_client->Location = System::Drawing::Point(326, 39);
			this->id_client->Name = L"id_client";
			this->id_client->ReadOnly = true;
			this->id_client->Size = System::Drawing::Size(45, 20);
			this->id_client->TabIndex = 33;
			// 
			// prenom_txt
			// 
			this->prenom_txt->Location = System::Drawing::Point(297, 91);
			this->prenom_txt->Name = L"prenom_txt";
			this->prenom_txt->ReadOnly = true;
			this->prenom_txt->Size = System::Drawing::Size(100, 20);
			this->prenom_txt->TabIndex = 32;
			// 
			// nom_txt
			// 
			this->nom_txt->Location = System::Drawing::Point(282, 65);
			this->nom_txt->Name = L"nom_txt";
			this->nom_txt->ReadOnly = true;
			this->nom_txt->Size = System::Drawing::Size(100, 20);
			this->nom_txt->TabIndex = 31;
			// 
			// Prenom_Cli
			// 
			this->Prenom_Cli->AutoSize = true;
			this->Prenom_Cli->Location = System::Drawing::Point(248, 94);
			this->Prenom_Cli->Name = L"Prenom_Cli";
			this->Prenom_Cli->Size = System::Drawing::Size(52, 13);
			this->Prenom_Cli->TabIndex = 30;
			this->Prenom_Cli->Text = L"Prénom : ";
			// 
			// Nom_Cli
			// 
			this->Nom_Cli->AutoSize = true;
			this->Nom_Cli->Location = System::Drawing::Point(248, 68);
			this->Nom_Cli->Name = L"Nom_Cli";
			this->Nom_Cli->Size = System::Drawing::Size(38, 13);
			this->Nom_Cli->TabIndex = 29;
			this->Nom_Cli->Text = L"Nom : ";
			// 
			// Num_Cli
			// 
			this->Num_Cli->AutoSize = true;
			this->Num_Cli->Location = System::Drawing::Point(248, 42);
			this->Num_Cli->Name = L"Num_Cli";
			this->Num_Cli->Size = System::Drawing::Size(82, 13);
			this->Num_Cli->TabIndex = 28;
			this->Num_Cli->Text = L"Numero Client : ";
			// 
			// lbl_addFact
			// 
			this->lbl_addFact->AutoSize = true;
			this->lbl_addFact->Location = System::Drawing::Point(251, 164);
			this->lbl_addFact->Name = L"lbl_addFact";
			this->lbl_addFact->Size = System::Drawing::Size(116, 13);
			this->lbl_addFact->TabIndex = 34;
			this->lbl_addFact->Text = L"Adresse de Facturation";
			// 
			// lbl_addLiv
			// 
			this->lbl_addLiv->AutoSize = true;
			this->lbl_addLiv->Location = System::Drawing::Point(524, 39);
			this->lbl_addLiv->Name = L"lbl_addLiv";
			this->lbl_addLiv->Size = System::Drawing::Size(105, 13);
			this->lbl_addLiv->TabIndex = 35;
			this->lbl_addLiv->Text = L"Adresse de Livraison";
			// 
			// addFact_txt
			// 
			this->addFact_txt->Location = System::Drawing::Point(254, 181);
			this->addFact_txt->Multiline = true;
			this->addFact_txt->Name = L"addFact_txt";
			this->addFact_txt->ReadOnly = true;
			this->addFact_txt->Size = System::Drawing::Size(172, 51);
			this->addFact_txt->TabIndex = 36;
			// 
			// addLiv_txt
			// 
			this->addLiv_txt->Location = System::Drawing::Point(488, 55);
			this->addLiv_txt->Multiline = true;
			this->addLiv_txt->Name = L"addLiv_txt";
			this->addLiv_txt->ReadOnly = true;
			this->addLiv_txt->Size = System::Drawing::Size(172, 51);
			this->addLiv_txt->TabIndex = 37;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(489, 164);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 13);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Methode de Paiement :";
			// 
			// metho_txt
			// 
			this->metho_txt->Location = System::Drawing::Point(492, 181);
			this->metho_txt->Name = L"metho_txt";
			this->metho_txt->ReadOnly = true;
			this->metho_txt->Size = System::Drawing::Size(168, 20);
			this->metho_txt->TabIndex = 39;
			// 
			// Facture
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 847);
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
	}
};
}
