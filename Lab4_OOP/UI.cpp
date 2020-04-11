#include "UI.h"
#include <iostream>

using namespace std;


DrugstoreUI::DrugstoreUI(Controller _ctrl) : ctrl(_ctrl) {
}


void Infos() {

	cout << "\n\n";
	cout << "0 Exit\n";
	cout << "1 Add Drug\n";
	cout << "2 Delete Drug\n";
	cout << "3 Edit Drug\n";
	cout << "4 Search Drug containing string\n";
	cout << "5 Search Drug which has a smaller Quantity than the one given\n";
	cout << "6 Group Drugs by price\n";
	cout << "7 UNDO\n";
	cout << "8 REDO\n";
}


void DrugstoreUI::UI() {

	Infos();
	int input;
	string name, new_name, sign;
	double concentration, quantity, price, new_concentration, new_quantity, new_price;
	cout << "\nInput: "; cin >> input;
	while (input != 0) {
		if (input == 1) {
			cout << "Drug add: name,concentration,quantity,price:\n";
			cout << "name: "; cin >> name;
			cout << "concentration: "; cin >> concentration;
			cout << "quantity: "; cin >> quantity;
			cout << "price: "; cin >> price;
			Drug med = Drug(name, concentration, quantity, price);
			ctrl.repo.add_drug(med);
		}
		else if (input == 2) {
			cout << "Drug delete: name,concentration,quantity,price:\n";
			cout << "name: "; cin >> name;
			cout << "concentration: "; cin >> concentration;
			cout << "quantity: "; cin >> quantity;
			cout << "price: "; cin >> price;
			Drug med = Drug(name, concentration, quantity, price);
			ctrl.repo.delete_drug(med);
		}
		else if (input == 3) {
			cout << "Drug change: old name,concentration,quantity,price + new name,concentration,quantity,price:\n";
			cout << "name: "; cin >> name;
			cout << "concentration: "; cin >> concentration;
			cout << "quantity: "; cin >> quantity;
			cout << "price: "; cin >> price;
			cout << "new_name: "; cin >> new_name;
			cout << "new_concentration: "; cin >> new_concentration;
			cout << "new_quantity: "; cin >> new_quantity;
			cout << "new_price: "; cin >> new_price;
			Drug med = Drug(name, concentration, quantity, price);
			Drug med2 = Drug(new_name, new_concentration, new_quantity, new_price);
			ctrl.repo.edit_drug(med, med2);
		}
		else if (input == 4) {
			cout << "See all drugs sorted by a sign(enter sign):";
			cout << "\nsign: "; cin >> sign;
			ctrl.strFind(sign);
		}
		else if (input == 5) {
			cout << "Search the drug which has a smaller quantity than the number you type in:\n";
			double var;
			cout << "number: "; cin >> var;
			ctrl.amount_s_than(var);
		}
		else if (input == 6) {
			cout << "Drugs grouped by price:\n";
			ctrl.groupPrice();
		}
		else if (input == 7) {
			cout << "UNDO\n";
			ctrl.repo.undo();
		}
		else if (input == 8) {
			cout << "REDO\n";
			ctrl.repo.redo();
		}
		else if (input == 0)
			exit(0);
		else cout << "wrong input\n";

		Infos();
		cout << "\nInput: "; cin >> input;
	}
}