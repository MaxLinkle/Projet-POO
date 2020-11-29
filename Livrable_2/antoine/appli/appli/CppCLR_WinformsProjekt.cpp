#include "pch.h"

using namespace System;



#include "Connection_Client.h"


using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Client::Connection_Client());
	return 0;
}
