//
//  Database.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include <stdio.h>
#include "Patient.hpp"
#include "Receiver.hpp"
#include "Donor.hpp"
#include "D_R_Pair.hpp"
#include "Balanced_System.hpp"

class Database
{
public:
	
	list<Patient> patient_list;
	list<Pair> d_r_pairs;
	list<Donor> single_donors;
	list<Receiver> single_receivers;
	list<Balanced_Sys> balanced_systems;
	
//	Database(int num_patients);
	
	void add_s_donor(Donor d);
	void add_s_receiver(Receiver r);
	void add_pair(Donor d, Receiver r);
	
	void print(int detail=0);
	Pair lookup_pair(unsigned long pair_id);
	
	void build_system();
	void update_database(Balanced_Sys &bal_sys);
//	void find_match(const Receiver &last_receiver);
//	list<Pair> find_compatible(const Receiver &r);
};

#endif /* Database_hpp */
