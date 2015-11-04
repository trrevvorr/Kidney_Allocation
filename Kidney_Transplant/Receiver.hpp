//
//  Receiver.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#ifndef Receiver_hpp
#define Receiver_hpp

#include <iostream>
#include <string>
#include "Patient.hpp"
using namespace std;

class Receiver : public Patient
{
public:
	string date_added_to_waitlist;
	int weeks_left_to_live;
	
	Receiver(): date_added_to_waitlist("00/00/0000"), weeks_left_to_live(-1){}
	
	Receiver(int ssn, string f_name, string l_name, string blood_type) : Patient(ssn, f_name, l_name, blood_type)
	{
		weeks_left_to_live = rand()%104;
		date_added_to_waitlist = "12/25/1993";
	}
	
	
	bool operator<(const Receiver &rhs) const {
		if (weeks_left_to_live < rhs.weeks_left_to_live) {
			return true;
		}
		return false;
	}
	
};

#endif /* Receiver_hpp */
