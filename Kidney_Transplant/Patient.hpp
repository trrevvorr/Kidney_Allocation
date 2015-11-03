//
//  Patient.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
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
	int ssn; // must be 9 digits long
	string f_name;
	string l_name;
	string blood_type;
	string adr_state;
	int adr_zipcode; // must be 5 digits long
	unsigned long pair_id; // defaults to -1 meaning no pair
	
	Patient(): ssn(123456789), f_name("none"), l_name("none"), blood_type("none"), adr_state("none"), adr_zipcode(12345), pair_id(-1){}
	Patient(string f_name, string l_name, string blood_type="O+", string adr_state="MO", int adr_zipcode=63755, int pair_id=-1);
	
	void print(int detail=0);
	
	bool operator==(const Patient &rhs) const {
		if (ssn == rhs.ssn) {
			return true;
		}
		return false;
	}
};

#endif /* Patient_hpp */
