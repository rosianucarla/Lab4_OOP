#include "UI.h"
#include <iostream>


int main() {
	Repository repo;
	Controller ctrl = Controller(repo);
	DrugstoreUI drugs = DrugstoreUI(ctrl);
	drugs.UI();
}