//
//  Database.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
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
	///// VARIABLES /////
	list<Pair> d_r_pairs;
	list<Donor> single_donors;
	list<Receiver> single_receivers;
	list<Balanced_Sys> balanced_systems;
	
	///// FUNCTIONS /////
	void add_s_donor(Donor d);
	void add_s_receiver(Receiver r);
	void add_pair(Donor d, Receiver r);
	
	void print_patients();
	void print_s_receivers();
	void print_s_donors();
	void print_pairs();
	void print_bal_sys();
	Pair lookup_pair(unsigned long pair_id);
	
	void build_system();
	void update_database(Balanced_Sys &bal_sys);
};

#endif /* Database_hpp */
