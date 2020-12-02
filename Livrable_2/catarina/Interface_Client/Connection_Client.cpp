#include "Connection_Client.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Client::Connection_Client monFormulaire;
	Application::Run(% monFormulaire);
	return 0;
}
