#include "pch.h"
#include "Choix.h"

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
	Application::Run(gcnew NS_Choix::Choix()); 
	return 0;
}