//
//  main.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/1/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include <iostream>
#include <random>
#include "Database.hpp"
using namespace std;

int main() {
	srand(time(NULL));
	
	Database d;
	Receiver r1 ("Tom", "Smith");
	Donor d1 ("Larry", "Hill");
	Receiver r2 ("Tim", "Ross");
	Donor d2 ("Rebeka", "Ghosh");
	Receiver r3 ("Lucy", "Marter");
	Donor d3 ("Brandon", "Chruize");
	Receiver r4 ("Neo", "Etch");
	Donor d4 ("Effie", "Sweet");
	
	d.add_s_donor(d1);
	d.add_s_receiver(r1);
	d.add_pair(d2, r2);
	d.add_pair(d3, r3);
	d.add_pair(d4, r4);
	
	d.print_patients(1);
	
	d.build_system();
	cout << "\n-------------------------------------------------\n\n";
	d.print_patients();
	d.print_bal_sys();
	
    return 0;
}
