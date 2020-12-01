#include "pch.h"

using namespace System;



//#include "catalogue_perso.h"
#include "Connection_Client.h"


using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Client::Connection_Client());
	//Application::Run(gcnew Perso::Catalogue_Perso());
	return 0;
}
