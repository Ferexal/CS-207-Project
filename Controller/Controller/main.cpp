#include "controllerForm.h"

using namespace Controller;

[STAThreadAttribute]

int main() {

	controllerForm fm;

	fm.ShowDialog();

	return 0;
}