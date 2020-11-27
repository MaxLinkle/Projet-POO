#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NS_Catalogue::MyForm monFormulaire;
	Application::Run(% monFormulaire);
	return 0;
}