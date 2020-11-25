#pragma once
#include "pch.h"
#include "UserControle.h"
/*#include "mysql.h"
#include <vcclr.h>
//#include "Individue.h"
char* ToStringQuery(System::String^ query) {
	pin_ptr<const wchar_t> wch = PtrToStringChars(query);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((query->Length + 1) * 2);
	errno_t err = 0;
	char* ch = (char*)malloc(sizeInBytes);
	err = wcstombs_s(&convertedChars,
		ch, sizeInBytes,
		wch, sizeInBytes);
	return ch;
}*/

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
	//============================================================================
		MYSQL* database;
		MYSQL_RES* result;
		MYSQL_ROW row;
		Form^ Precedent;
		bool Fermeture;
	//============================================================================
	private:


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
