#pragma once
// a virer plus tard
#include <mysql.h>
#include <vcclr.h>

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Creation_Client : public System::Windows::Forms::Form //, public NS_SuperC::SuperC
	{
	public:
		Creation_Client(Form^ InpPrecedent) {
			Precedent = InpPrecedent;
			ConnectDatabase();
			InitializeComponent();
		}

	private: System::Windows::Forms::Form^ Precedent;

	private:
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;

	private: System::Windows::Forms::Button^ button1;
	public:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::CheckBox^ checkBox_livr;
	private: System::Windows::Forms::CheckBox^ checkBox_fact;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;






	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void ConnectDatabase() {
			con = mysql_init(NULL);
			if (con == NULL) {
				//label1->Text = "Base inexistante";
			}
			else {
				//label1->Text = "Base existante";
			}

			if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
				//if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, 0) == NULL) {
					//label2->Text = "Erreur de connection a la base";
			}
			else {
				//label2->Text = "Connection a la base";
			}
		}

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_livr = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_fact = (gcnew System::Windows::Forms::CheckBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(862, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Creation";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Creation_Client::But_Creation_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(21, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(153, 72);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(282, 72);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Nom";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(150, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Prenom";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(279, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Date";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(10, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(25, 25);
			this->button2->TabIndex = 7;
			this->button2->Text = L"<";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Creation_Client::But_Retour_Creation_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(862, 99);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(533, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Ville";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(404, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Adresse";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(536, 72);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(407, 72);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 9;
			// 
			// checkBox_livr
			// 
			this->checkBox_livr->AutoSize = true;
			this->checkBox_livr->Location = System::Drawing::Point(689, 69);
			this->checkBox_livr->Name = L"checkBox_livr";
			this->checkBox_livr->Size = System::Drawing::Size(119, 17);
			this->checkBox_livr->TabIndex = 13;
			this->checkBox_livr->Text = L"adresse de livraison";
			this->checkBox_livr->UseVisualStyleBackColor = true;
			// 
			// checkBox_fact
			// 
			this->checkBox_fact->AutoSize = true;
			this->checkBox_fact->Location = System::Drawing::Point(689, 93);
			this->checkBox_fact->Name = L"checkBox_fact";
			this->checkBox_fact->Size = System::Drawing::Size(131, 17);
			this->checkBox_fact->TabIndex = 14;
			this->checkBox_fact->Text = L"adresse de facturation";
			this->checkBox_fact->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(68, 180);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(533, 96);
			this->richTextBox1->TabIndex = 15;
			this->richTextBox1->Text = L"";
			// 
			// Creation_Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 334);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->checkBox_fact);
			this->Controls->Add(this->checkBox_livr);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Creation_Client";
			this->Text = L"Creation_Client";
			this->Load += gcnew System::EventHandler(this, &Creation_Client::Creation_Client_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion

	private: System::Void But_Creation_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "" && textBox2->Text != "" && textBox6->Text != "" && textBox5->Text != "" && (checkBox_livr->Checked == true || checkBox_fact->Checked == true)) {
			System::String^ parametre;
			parametre = textBox1->Text;
			parametre += "', '";
			parametre += textBox2->Text;

			if (textBox3->Text != "") {
				parametre += "', '";
				parametre += textBox3->Text;
				parametre += "', '";
			}
			else {
				parametre += "', NULL, '";
			}

			parametre += textBox6->Text;
			parametre += "', '";
			parametre += textBox5->Text;

			if (checkBox_livr->Checked == true && checkBox_fact->Checked == true) {
				parametre += "', 'livraison et facturation');";
			}
			else if (checkBox_livr->Checked == true) {
				parametre += "', 'livraison');";
			}
			else if (checkBox_fact->Checked == true) {
				parametre += "', 'facturation');";
			}

			System::String^ query;
			query = "START TRANSACTION; CALL remplissage_Client('";
			query += parametre;
			query += " CALL verification_Client('";
			query += parametre;
			query += "COMMIT;";

			richTextBox1->Text = query;

			pin_ptr<const wchar_t> wch = PtrToStringChars(query);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((query->Length + 1) * 2);
			errno_t err = 0;

			char* ch = (char*)malloc(sizeInBytes);
			err = wcstombs_s(&convertedChars,
				ch, sizeInBytes,
				wch, sizeInBytes);

			bool qstate;

			qstate = mysql_query(con, ch);
			if (qstate) {
				textBox4->Text = "Erreur 3";
			}





		}
		else {
			textBox4->Text = "Vous n'ete pas rentré dans la condition";
		}
		/*this->Close();
		Precedent->Show();*/
	}

	private: System::Void But_Retour_Creation_Click(System::Object^ sender, System::EventArgs^ e) {
		//fermeture = false;
		this->Close();
		Precedent->Show();
	}
	private: System::Void Creation_Client_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}