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
		EspPerso(void)
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
	delegate System::Void ptrf();



	private:
		System::ComponentModel::Container^ components;



#pragma region Windows Choix Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
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
			   this->groupBox1->SuspendLayout();
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
			   this->groupBox1->Location = System::Drawing::Point(12, 12);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(486, 252);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"groupBox1";
			   // 
			   // LDate
			   // 
			   this->LDate->AutoSize = true;
			   this->LDate->Location = System::Drawing::Point(173, 163);
			   this->LDate->Name = L"LDate";
			   this->LDate->Size = System::Drawing::Size(131, 17);
			   this->LDate->TabIndex = 7;
			   this->LDate->Text = L"Date d\'anniversaire";
			   // 
			   // Date
			   // 
			   this->Date->Location = System::Drawing::Point(110, 183);
			   this->Date->Name = L"Date";
			   this->Date->Size = System::Drawing::Size(267, 22);
			   this->Date->TabIndex = 1;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(301, 48);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(57, 17);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"Prenom";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(135, 49);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(37, 17);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Nom";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(277, 68);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(100, 22);
			   this->textBox2->TabIndex = 3;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(110, 68);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 22);
			   this->textBox1->TabIndex = 2;
			   // 
			   // Rb_Personnel
			   // 
			   this->Rb_Personnel->AutoSize = true;
			   this->Rb_Personnel->Location = System::Drawing::Point(337, 111);
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
			   this->Rb_Client->Location = System::Drawing::Point(40, 111);
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
			   this->button1->Location = System::Drawing::Point(110, 270);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(110, 110);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"Rechercher";
			   this->button1->UseVisualStyleBackColor = true;
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(279, 270);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(110, 110);
			   this->button2->TabIndex = 2;
			   this->button2->Text = L"Creer";
			   this->button2->UseVisualStyleBackColor = true;
			   // 
			   // EspPerso
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(505, 475);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->groupBox1);
			   this->Name = L"EspPerso";
			   this->Text = L"Espace Personelle";
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void Personnel_Click(System::Object^ sender, System::EventArgs^ e) {




	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	


	
	private: System::Void Rb_Client_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ptrf^ f = gcnew ptrf(this,&EspPerso::RechercheClient); //Equivalent a ointeur de fonction
		LDate->Text = "Date d'anniversaire";
	}

	private: System::Void Rb_Personnel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ptrf^ f = gcnew ptrf(this, &EspPerso::RechercheClient); //Equivalent a ointeur de fonction
		LDate->Text = "Date d'embauche";
	}

	System::Void RechercheClient() {


	}

	System::Void RecherchePersonnel() {


	}
};
}