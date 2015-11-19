//
//  Receiver.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
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
	///// VARIABLES /////
	string date_added_to_waitlist;
	int weeks_left_to_live;
	
	///// CONSTRUCTORS /////
	Receiver(): date_added_to_waitlist("00/00/0000"), weeks_left_to_live(-1){}
	Receiver(int ssn, string f_name, string l_name, string blood_type, int to_live=-1) : Patient(ssn, f_name, l_name, blood_type)
	{
		if (to_live < 0) { weeks_left_to_live = rand()%104;}
		else {weeks_left_to_live = to_live;}
		
		date_added_to_waitlist = "12/25/1993";
	}
	
	/// OVERLOADED OPERATORS ///
	friend ostream & operator << (ostream &out_stream, const Receiver &r)
	{
		out_stream << static_cast<Patient>(r) <<
					"\nDate Added: " << r.date_added_to_waitlist << " Weeks to Live: " <<
					r.weeks_left_to_live;
		return(out_stream);
	}
	// used to sort receiver lists with .sort()
	bool operator<(const Receiver &rhs) const {
		return weeks_left_to_live < rhs.weeks_left_to_live;
	}
	
};

#endif /* Receiver_hpp */
