#pragma once
//#include "Individue.h"
namespace NS_SuperC {

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class SuperC : public System::Windows::Forms::Form //
	{
	public:
		SuperC(void)
		{
			//InitializeComponent();
			Fermeture = false;
		}

		SuperC(Form^ Prece)
		{
			//InitializeComponent();
			Fermeture = false;
			Precedent = Prece;
		}

		~SuperC()
		{

			/*if (components)
			{
				delete components;
			}
			*/
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		
		
		bool Fermeture;
		//Individu Joe;
		Form^ Precedent;
	private:
/*		System::ComponentModel::Container^ components;
#pragma region Windows SuperC Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// SuperC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Name = L"SuperC";
			this->Text = L"Titre";
			this->ResumeLayout(false);

		}
#pragma endregion*/

	private: System::Void InitializeComponent() {
		this->SuspendLayout();
		// 
		// SuperC
		// 
		this->ClientSize = System::Drawing::Size(282, 253);
		this->Name = L"SuperC";
		this->ResumeLayout(false);
	}
	};
}
