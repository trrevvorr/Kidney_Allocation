//
//  Patient.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Patient.hpp"

Patient::Patient(string first, string last, string b_type, string state, int zipcode, int p_id)
{
	// verify that ssn is 9 digits
	ssn = rand()%1000000000;
	f_name = first;
	l_name = last;
	// verify blood type is acceptible
	blood_type = b_type;
	// verify that adr_state is acceptable
	adr_state = state;
	// verify that adr_zipcode is acceptable
	adr_zipcode = zipcode;
	pair_id = p_id;
}

void Patient::print(int detail)
{
	cout << "SSN: " << ssn <<endl;
	cout << "Name: " << f_name << " " << l_name << endl;
	
	if (detail > 0) {
		cout << "Paired to: ";
		if (pair_id == -1) {cout << "no one\n";}
		else{cout << pair_id << endl;}
		
		cout << "Blood Type: " << blood_type << endl;
	}
	
	if (detail > 1) {
		cout << "Location: " << adr_state << " " << adr_zipcode << endl;
	}
	
	return;
}