//
//  Patient.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#ifndef Patient_hpp
#define Patient_hpp

#include <iostream>
#include <string>
#include <random>
using namespace std;

class Patient
{
public:
	///// VARIABLES /////
	int ssn;
	string f_name;
	string l_name;
	string blood_type;
	string adr_state;
	int adr_zipcode;
	unsigned long pair_id; // defaults to 0 meaning no pair
	
	///// CONSTRUCTORS /////
	Patient(): ssn(123456789), f_name("none"), l_name("none"), blood_type("none"), adr_state("none"), adr_zipcode(12345), pair_id(0){}
	Patient(int ssn, string f_name, string l_name, string blood_type="O+");
	
	/// OVERLOADED OPERATORS ///
	friend ostream & operator << (ostream &out_stream, const Patient &p)
	{
		out_stream << p.f_name << " " << p.l_name << " " << p.ssn <<
					  "\nPair ID: " << p.pair_id << " Blood Type: " << p.blood_type;
					// << "\nState: " << p.adr_state << " Zip Code: " << p.adr_zipcode;
		return(out_stream);
	}
	bool operator==(const Patient &rhs) const {return (ssn == rhs.ssn);}
};

#endif /* Patient_hpp */
