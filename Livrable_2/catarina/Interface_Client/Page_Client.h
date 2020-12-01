#pragma once
#include "Modifier_Client.h"
#include "MyForm.h"
#include "Historique.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Page_Client : public System::Windows::Forms::Form
	{
	public:
		Page_Client(Form^ InpPrecedent, System::String^ i_id) {
			id = i_id;
			Precedent = InpPrecedent;
			InitializeComponent();
		}

	private: System::String^ id;

	private: System::Windows::Forms::Form^ Precedent;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button4;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(10, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(25, 25);
			this->button3->TabIndex = 8;
			this->button3->Text = L"<";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Page_Client::but_Retour_Page_Cli_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Catalogue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Page_Client::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(85, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Facture précédente";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Page_Client::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(85, 110);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(131, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Modifier le compte";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Page_Client::button4_Click);
			// 
			// Page_Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(304, 160);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Name = L"Page_Client";
			this->Text = L"Page_Client";
			this->ResumeLayout(false);

		}


#pragma endregion




	private: System::Void but_Retour_Page_Cli_Click(System::Object^ sender, System::EventArgs^ e) {
		//fermeture = false;
		this->Close();
		Precedent->Show();
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Client::Modifier_Client^ Page = gcnew Client::Modifier_Client(this, id);
		Page->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm^ Page = gcnew MyForm(id);
		Page->Show();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Client::Historique^ Page = gcnew Client::Historique(id);
	Page->Show();
}
};
}