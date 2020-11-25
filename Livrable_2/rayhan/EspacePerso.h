#pragma once
namespace NS_Choix {

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
	private: System::Windows::Forms::Button^ Client;
	private: System::Windows::Forms::Button^ Personnel;


	private:
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


#pragma region Windows Choix Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
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
			   
			   // 
			   // Personnel
			   // 
			   this->Personnel->Location = System::Drawing::Point(264, 72);
			   this->Personnel->Name = L"Personnel";
			   this->Personnel->Size = System::Drawing::Size(174, 38);
			   this->Personnel->TabIndex = 1;
			   this->Personnel->Text = L"Espace Personnel";
			   this->Personnel->UseVisualStyleBackColor = true;
			   
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
			   // Espace Personelle
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(468, 268);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->Personnel);
			   this->Controls->Add(this->Client);
			   this->Name = L"EspPerso";
			   this->Text = L"Espace Personelle";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void Personnel_Click(System::Object^ sender, System::EventArgs^ e) {




	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Choix_Load(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Image = (gcnew System::Drawing::Bitmap("LOGO.png"));
	}
	};
}