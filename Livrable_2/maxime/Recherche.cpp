#include "Recherche.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //Facture::Facture monFormulaire;
    Application::Run(gcnew NS_Recherche::Recherche());
    return 0;
}
