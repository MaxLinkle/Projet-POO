#pragma once
#pragma once
#include "pch.h"
#include "Client.h"
#include "PersonnelCO.h"

namespace NS_Recherche {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class FormRecherche : public System::Windows::Forms::Form
	{
	public:
		FormRecherche(Form^ Precedent, Individu^* Rechercher)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~FormRecherche()
		{
			if (components)
			{
				delete components;
			}
		}




	private:
		System::ComponentModel::Container^ components;




#pragma region Windows Choix Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->SuspendLayout();
			   // 
			   // FormRecherche
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(468, 268);
			   this->Name = L"FormRecherche";
			   this->Text = L"Choix";
			   this->Load += gcnew System::EventHandler(this, &FormRecherche::Choix_Load);
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void Choix_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}

	};
}
