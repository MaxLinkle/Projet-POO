#pragma once
//#include <mysql.h>
//#include <vcclr.h>
#include "SC.h"
#include "Creation_Client.h"
#include "Page_Client.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NS_SuperC;

	public ref class Connection_Client :  public NS_SuperC::SuperC
	{
	public:
		Connection_Client(Form^ inpPrecedent): SuperC(inpPrecedent) {
			ConnectDatabase();
			InitializeComponent();
		}


	private: System::Windows::Forms::TextBox^ textBox_nom;
	private: System::Windows::Forms::TextBox^ textBox_prenom;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox_date;

	private: System::Windows::Forms::Label^ label3;

	private:
		MYSQL* con;
		MYSQL_RES* res;
		MYSQL_ROW row;
		
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->textBox_nom = (gcnew System::Windows::Forms::TextBox());
			this->textBox_prenom = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox_date = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox_nom
			// 
			this->textBox_nom->Location = System::Drawing::Point(15, 56);
			this->textBox_nom->Name = L"textBox_nom";
			this->textBox_nom->Size = System::Drawing::Size(100, 20);
			this->textBox_nom->TabIndex = 0;
			// 
			// textBox_prenom
			// 
			this->textBox_prenom->Location = System::Drawing::Point(140, 56);
			this->textBox_prenom->Name = L"textBox_prenom";
			this->textBox_prenom->Size = System::Drawing::Size(100, 20);
			this->textBox_prenom->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(415, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Ce Connecter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Connection_Client::button1_Click);
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
			this->button2->Location = System::Drawing::Point(415, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Crée un compte";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Connection_Client::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(10, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(25, 25);
			this->button3->TabIndex = 8;
			this->button3->Text = L"<";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Connection_Client::but_Retour_Connection_Click);
			// 
			// textBox_date
			// 
			this->textBox_date->Location = System::Drawing::Point(262, 56);
			this->textBox_date->Name = L"textBox_date";
			this->textBox_date->Size = System::Drawing::Size(100, 20);
			this->textBox_date->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(262, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Date";
			// 
			// Connection_Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 143);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_date);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox_prenom);
			this->Controls->Add(this->textBox_nom);
			this->Name = L"Connection_Client";
			this->Text = L"Connection_Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
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
	
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			Client::Creation_Client^ Creation = gcnew Client::Creation_Client(this);
			Creation->Show();
		}

		private: System::Void but_Retour_Connection_Click(System::Object^ sender, System::EventArgs^ e) {
			//fermeture = false;
			this->Close();
		}
	
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			if (textBox_nom->Text != "" && textBox_prenom->Text != "") {
				System::String^ id;

				System::String^ query;
				query = "SELECT ID_client FROM Client WHERE nom = '";
				query += textBox_nom->Text;
				query += "' AND prenom = '";
				query += textBox_prenom->Text;

				if (textBox_date->Text != "") {
					query += "' AND date_naissance = '";
					query += textBox_date->Text;
					query += "';";
				}
				else {
					query += "';";
				}

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
				if (!qstate) {
					res = mysql_store_result(con);

					if (res != NULL) {
						if (res->row_count == 1) {
							row = mysql_fetch_row(res);
							this->Hide();
							System::String^ id = gcnew String(row[0]);
							Client::Page_Client^ Page = gcnew Client::Page_Client(this, id);
							Page->Show();
						}
					}
					else {
						// probleme de connetion
					}
				}
			}
		}
	};
}
