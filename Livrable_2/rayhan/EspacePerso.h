#pragma once
#include "pch.h"
#include "UserControle.h"
#include "SC.h"
namespace NS_EspacePersonnel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class EspPerso : public System::Windows::Forms::Form
	{
	public:
		EspPerso(Form^ Precedent,int indice)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~EspPerso()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RadioButton^ Rb_Personnel;
	private: System::Windows::Forms::RadioButton^ Rb_Client;
	private: System::Windows::Forms::Label^ LDate;

	private: System::Windows::Forms::DateTimePicker^ Date;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	



	private:
		System::ComponentModel::Container^ components;
		EventHandler^ f;


#pragma region Windows Choix Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->LDate = (gcnew System::Windows::Forms::Label());
			   this->Date = (gcnew System::Windows::Forms::DateTimePicker());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->Rb_Personnel = (gcnew System::Windows::Forms::RadioButton());
			   this->Rb_Client = (gcnew System::Windows::Forms::RadioButton());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->groupBox1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->LDate);
			   this->groupBox1->Controls->Add(this->Date);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->textBox2);
			   this->groupBox1->Controls->Add(this->textBox1);
			   this->groupBox1->Controls->Add(this->Rb_Personnel);
			   this->groupBox1->Controls->Add(this->Rb_Client);
			   this->groupBox1->Location = System::Drawing::Point(12, 34);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(575, 202);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"groupBox1";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(263, 251);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(60, 17);
			   this->label3->TabIndex = 9;
			   this->label3->Text = L"Adresse";
			   // 
			   // LDate
			   // 
			   this->LDate->AutoSize = true;
			   this->LDate->Location = System::Drawing::Point(213, 117);
			   this->LDate->Name = L"LDate";
			   this->LDate->Size = System::Drawing::Size(131, 17);
			   this->LDate->TabIndex = 7;
			   this->LDate->Text = L"Date d\'anniversaire";
			   // 
			   // Date
			   // 
			   this->Date->Location = System::Drawing::Point(145, 137);
			   this->Date->Name = L"Date";
			   this->Date->Size = System::Drawing::Size(267, 22);
			   this->Date->TabIndex = 1;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(447, 48);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(57, 17);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"Prenom";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(37, 48);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(37, 17);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Nom";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(404, 68);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(100, 22);
			   this->textBox2->TabIndex = 3;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(40, 68);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 22);
			   this->textBox1->TabIndex = 2;
			   // 
			   // Rb_Personnel
			   // 
			   this->Rb_Personnel->AutoSize = true;
			   this->Rb_Personnel->Location = System::Drawing::Point(372, 165);
			   this->Rb_Personnel->Name = L"Rb_Personnel";
			   this->Rb_Personnel->Size = System::Drawing::Size(93, 21);
			   this->Rb_Personnel->TabIndex = 1;
			   this->Rb_Personnel->Text = L"Personnel";
			   this->Rb_Personnel->UseVisualStyleBackColor = true;
			   // 
			   // Rb_Client
			   // 
			   this->Rb_Client->AutoSize = true;
			   this->Rb_Client->Checked = true;
			   this->Rb_Client->Location = System::Drawing::Point(102, 165);
			   this->Rb_Client->Name = L"Rb_Client";
			   this->Rb_Client->Size = System::Drawing::Size(64, 21);
			   this->Rb_Client->TabIndex = 0;
			   this->Rb_Client->TabStop = true;
			   this->Rb_Client->Text = L"Client";
			   this->Rb_Client->UseVisualStyleBackColor = true;
			   this->Rb_Client->CheckedChanged += gcnew System::EventHandler(this, &EspPerso::Rb_Client_CheckedChanged);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(114, 499);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(132, 28);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"Rechercher";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += f;
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(345, 499);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(132, 28);
			   this->button2->TabIndex = 2;
			   this->button2->Text = L"Creer";
			   this->button2->UseVisualStyleBackColor = true;
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(114, 271);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(363, 205);
			   this->dataGridView1->TabIndex = 3;
			   // 
			   // EspPerso
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(615, 567);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->groupBox1);
			   this->Name = L"EspPerso";
			   this->Text = L"Espace Personelle";
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void Personnel_Click(System::Object^ sender, System::EventArgs^ e) {




	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	


	
	private: System::Void Rb_Client_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		f = gcnew EventHandler(this,&EspPerso::RechercheClient); //Equivalent a ointeur de fonction
		LDate->Text = "Date d'anniversaire";
	}

	private: System::Void Rb_Personnel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		f = gcnew EventHandler(this , &EspPerso::RecherchePersonnel); //Equivalent a ointeur de fonction
		LDate->Text = "Date d'embauche";
	}

	System::Void RechercheClient(System::Object^ sender, System::EventArgs^ e) {

		label3->Text = "Client";


	}

	System::Void RecherchePersonnel(System::Object^ sender, System::EventArgs^ e) {

		label3->Text = "Personnel";

	}
};
}