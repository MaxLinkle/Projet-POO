#include "pch.h"
//#include "EspacePerso.h"
#include "CataloguePersonnel.h"
using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}


using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Perso::Catalogue_Perso());
	
	return 0;
}