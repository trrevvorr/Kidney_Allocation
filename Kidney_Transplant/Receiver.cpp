//
//  Receiver.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Receiver.hpp"

// Overloaded copy constructor
//void Receiver::copy(const Receiver &to_copy)
//{
//	ssn = to_copy.ssn;
//	f_name = to_copy.f_name;
//	l_name = to_copy.l_name;
//	blood_type = to_copy.blood_type;
//	adr_state = to_copy.adr_state;
//	adr_zipcode = to_copy.adr_zipcode;
//	pair_id = to_copy.pair_id;
//	date_added_to_waitlist = to_copy.date_added_to_waitlist;
//	weeks_left_to_live = to_copy.weeks_left_to_live;
//}

//Receiver::Receiver(string waitlist_date, int weeks_to_live, int ssn, string f_name, string l_name, string blood_type, string adr_state, int adr_zipcode, int pair_id)
//{
//	date_added_to_waitlist = waitlist_date;
//	weeks_left_to_live = rand()%104;
//	
//	Patient(f_name, l_name, blood_type, adr_state, adr_zipcode, pair_id);
//}


//Receiver& Receiver::operator=(const Receiver &rhs) {
//	
//	// Only do assignment if RHS is a different object from this.
////	if (this != &rhs) {
//	this->ssn = rhs.ssn;
//	this->f_name = rhs.f_name;
//	this->l_name = rhs.l_name;
//	this->blood_type = rhs.blood_type;
//	this->adr_state = rhs.adr_state;
//	this->adr_zipcode = rhs.adr_zipcode;
//	this->pair_id = rhs.pair_id;
//	this->date_added_to_waitlist = rhs.date_added_to_waitlist;
//	this->weeks_left_to_live = rhs.weeks_left_to_live;
////	}
//	return *this;
//}