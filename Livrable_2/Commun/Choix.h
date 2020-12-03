#pragma once
#include "pch.h"
#include "Connection_Client.h"
#include "PersonnelCO.h"

namespace NS_Choix {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f�r Form1
	/// </summary>
	public ref class Choix : public System::Windows::Forms::Form
	{
	public:
		Choix(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Choix()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Client;
	private: System::Windows::Forms::Button^ Personnel;


	private:
		System::ComponentModel::Container^ components;
		//NS_Client::Client^ Inter_Client;
		NS_Personnel::Personnel^ Inter_Personnel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


#pragma region Windows Choix Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Choix::typeid));
			this->Client = (gcnew System::Windows::Forms::Button());
			this->Personnel = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			//
			// Client
			//
			this->Client->Location = System::Drawing::Point(264, 201);
			this->Client->Name = L"Client";
			this->Client->Size = System::Drawing::Size(174, 41);
			this->Client->TabIndex = 0;
			this->Client->Text = L" Espace Client";
			this->Client->UseVisualStyleBackColor = true;
			this->Client->Click += gcnew System::EventHandler(this, &Choix::button1_Click);
			//
			// Personnel
			//
			this->Personnel->Location = System::Drawing::Point(264, 72);
			this->Personnel->Name = L"Personnel";
			this->Personnel->Size = System::Drawing::Size(174, 38);
			this->Personnel->TabIndex = 1;
			this->Personnel->Text = L"Espace Personnel";
			this->Personnel->UseVisualStyleBackColor = true;
			this->Personnel->Click += gcnew System::EventHandler(this, &Choix::Personnel_Click);
			//
			// pictureBox1
			//
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
//			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(21, 72);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(170, 170);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			//
			// Choix
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 268);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Personnel);
			this->Controls->Add(this->Client);
			this->Name = L"Choix";
			this->Text = L"Choix";
			this->Load += gcnew System::EventHandler(this, &Choix::Choix_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Personnel_Click(System::Object^ sender, System::EventArgs^ e) {

			this->Hide();
			this->Inter_Personnel = gcnew NS_Personnel::Personnel(this);
			this->Inter_Personnel->Show();


	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		Client::Connection_Client^ connection_client = gcnew Client::Connection_Client(this);
		connection_client->Show();

	}
	private: System::Void Choix_Load(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Image = (gcnew System::Drawing::Bitmap("LOGO.png"));
	}
};
}
