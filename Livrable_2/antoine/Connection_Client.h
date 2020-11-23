#pragma once
#include "Creation_Client.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Connection_Client : public System::Windows::Forms::Form
	{
	public:
		Connection_Client(void) {
			InitializeComponent();
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	public:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			//
			// textBox1
			//
			this->textBox1->Location = System::Drawing::Point(15, 56);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			//
			// textBox2
			//
			this->textBox2->Location = System::Drawing::Point(140, 56);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			//
			// button1
			//
			this->button1->Location = System::Drawing::Point(262, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Ce Connecter";
			this->button1->UseVisualStyleBackColor = true;
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nom";
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(137, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Prenom";
			//
			// button2
			//
			this->button2->Location = System::Drawing::Point(262, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Crée un compte";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Connection_Client::button2_Click);
			//
			// but_Retour_Connection
			//
			this->button3->Location = System::Drawing::Point(10, 10);
			this->button3->Name = L"but_Retour_Connection";
			this->button3->Size = System::Drawing::Size(25, 25);
			this->button3->TabIndex = 8;
			this->button3->Text = L"<";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Connection_Client::but_Retour_Connection_Click);
			//
			// Connection_Client
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(381, 143);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Connection_Client";
			this->Text = L"Connection_Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion


		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			Client::Creation_Client^ Creation = gcnew Client::Creation_Client(this);
			Creation->Show();
		}

		private: System::Void but_Retour_Connection_Click(System::Object^ sender, System::EventArgs^ e) {
			//fermeture = false;
			this->Close();
		}
	};
}
