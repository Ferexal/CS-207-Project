using namespace System;
using namespace System::Windows::Forms;

#include "controllerForm.h"

[STAThreadAttribute()]
void Main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Controller::controllerForm());
}