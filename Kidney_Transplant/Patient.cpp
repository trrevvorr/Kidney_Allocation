//
//  Patient.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Patient.hpp"

Patient::Patient(int SSN, string first, string last, string b_type)
{
	// verify that ssn is 9 digits
	ssn = SSN;
	f_name = first;
	l_name = last;
	// verify blood type is acceptible
	blood_type = b_type;
	// verify that adr_state is acceptable
	adr_state = "MO";
	// verify that adr_zipcode is acceptable
	adr_zipcode = 63755;
	pair_id = 0;
}


