#pragma once
#include "Controller.h"


class DrugstoreUI {
private:
	Controller ctrl;
public:
	// Constructotr
	DrugstoreUI(Controller _ctrl);

	// Function with user input
	void UI();
};
 