//
//  Donor.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
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
	///// VARIABLES /////
	string contact_name;
	int contact_number;
	
	///// CONSTRUCTORS /////
	Donor(): contact_name("none"), contact_number(1234567){}
	Donor(int ssn, string f_name, string l_name, string blood_type) : Patient(ssn, f_name, l_name, blood_type)
	{
		contact_number = rand()%10000000;
		contact_name = "Bob";
	}
	
	/// OVERLOADED OPERATORS ///
	friend ostream & operator << (ostream &out_stream, const Donor &d)
	{
		out_stream << static_cast<Patient>(d) <<
				"\nContact Name: " << d.contact_name << " Contact #: " << d.contact_number;
		return(out_stream);
	}
};

#endif /* Donor_hpp */
