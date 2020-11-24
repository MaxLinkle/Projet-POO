#pragma once
#include "pch.h"
#include "SC.h"
namespace NS_Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Client : public System::Windows::Forms::Form
	{
	public:
		Client(Form^ Prece)
		{
			InitializeComponent();
			Precedent = Prece;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Client()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Form^ Precedent;
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
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
			// Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Name = L"Client";
			this->Text = L"Client";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Client::Client_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Client_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

		Precedent->Close();

	}
	};
}
