//
//  Donor.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#ifndef Donor_hpp
#define Donor_hpp

#include <iostream>
#include <string>
#include "Patient.hpp"
using namespace std;

class Donor : public Patient
{
public:
	string contact_name;
	int contact_number;
	
	Donor(): contact_name("none"), contact_number(1234567){}
//	Donor(string f_name, string l_name) : Patient(f_name, l_name)
//	{
//		contact_number = rand()%10000000;
//		contact_name = "Bob";
//	}
	Donor(int ssn, string f_name, string l_name, string blood_type) : Patient(ssn, f_name, l_name, blood_type)
	{
		contact_number = rand()%10000000;
		contact_name = "Bob";
	}
	
	
};

#endif /* Donor_hpp */
