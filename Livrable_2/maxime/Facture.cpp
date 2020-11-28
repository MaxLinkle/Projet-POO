//MyForm.cpp
#include "Facture.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //Facture::Facture monFormulaire;
    Application::Run(gcnew NS_Facture::Facture());
    return 0;
}