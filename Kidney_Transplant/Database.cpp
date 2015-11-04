//
//  Database.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Database.hpp"

void Database::add_s_donor(Donor d)
{
	//patient_list.push_back(d);
	single_donors.push_back(d);
}

void Database::add_s_receiver(Receiver r)
{
	//patient_list.push_back(r);
	single_receivers.push_back(r);
}

void Database::add_pair(Donor d, Receiver r)
{
	d.pair_id = d_r_pairs.size()+1;
	r.pair_id = d_r_pairs.size()+1;
	
	//patient_list.push_back(d);
	//patient_list.push_back(r);
	d_r_pairs.push_back(Pair(d, r));
}

void Database::print_patients()
{
	cout << "\n==== PRINTING ALL PATIENTS IN DB ====\n\n";
	cout << "\n- Single Reciver -\n";
	print_s_receivers();
	cout << "\n- Single Donor -\n";
	print_s_donors();
	cout << "\n- D_R_Pairs -\n";
	print_pairs();
	return;
}

void Database::print_s_receivers()
{
	list<Receiver>::iterator r_iter = single_receivers.begin();
	
	for (int i = 0; i < single_receivers.size(); i++) {
		cout << *r_iter << endl;
		r_iter++;
	}
	return;
}

void Database::print_s_donors()
{
	list<Donor>::iterator d_iter = single_donors.begin();
	
	for (int i = 0; i < single_donors.size(); i++) {
		cout << *d_iter << endl;
		d_iter++;
	}
	return;
}

void Database::print_pairs()
{
	list<Pair>::iterator p_iter = d_r_pairs.begin();
	for (int i = 0; i < d_r_pairs.size(); i++) {
		cout << *p_iter << endl;
		p_iter++;
	}
	return;
}

void Database::print_bal_sys()
{
	cout << "\n==== PRINTING BALANCED SYSTEMS ====\n\n";
	list<Balanced_Sys>::iterator bs_iter = balanced_systems.begin();
	for (int i = 0; i < balanced_systems.size(); i++) {
		bs_iter->print();
		bs_iter++;
	}
}

Pair Database::lookup_pair(unsigned long id)
{
	list<Pair>::iterator p_iter = d_r_pairs.begin();
	for (int i = 0; i < d_r_pairs.size(); i++) {
		if (p_iter->r.pair_id == id) {
			return *p_iter;
		}
		p_iter++;
	}
	cout << "ERROR!!! PAIR ID NOT FOUND: " << id << endl;
	return *p_iter;
}

// Purpose: iterate though all single receivers and find balanced system for
// each, the most urgent receivers are serviced first
// Input: Accepts three lists, each list being the rows of corresponding tables
// Output: A list of balanced systems, each taking the form:
// s_receicer <- (p_donor | p_receiver)* <- s_donor
// where s_receiver is a single receiver, s_donor is single donor
// p_receiver is paired receiver, paired with the paired donor on other side of "|"
// "*" means there can be any number of [D/R Pairs], regular expression notation

// Balanced systems can take two forms
// [s_r] <- [p_d | p_r]* <- [s_d]
// this is the form this algorithm handles
// /-<- [p_d | p_r]* <- [p_d | p_r] <-\
// \---->--->--->--->--->--->--->-->--/
// this is the loop variety and should be attainable with slight modifications
// to this algorithm

// This only finds balanced systems that start with a single receiver
// and end with a single donor
void Database::build_system()
{
	Balanced_Sys bal_sys;

	single_receivers.sort();
	d_r_pairs.sort();
	
	// iterate through all receivers, making a system for each
	list<Receiver>::iterator r_iter = single_receivers.begin();
	unsigned long original_length = single_receivers.size();
	for (int i = 0; i < original_length; i++)
	{
		bal_sys = Balanced_Sys();
		// get the next receiver in list
		bal_sys.single_receiver = *r_iter;
		r_iter++;
		// find system for receiver
		bal_sys.find_match(d_r_pairs, single_donors);
		if (bal_sys.balanced) {
			balanced_systems.push_back(bal_sys);
			update_database(bal_sys);
		}
	}
	return;
}


void Database::update_database(Balanced_Sys &bal_sys)
{
	// remove single receiver
	single_receivers.remove(bal_sys.single_receiver);
	// remove all the pairs
	list<Pair>::iterator p_iter = bal_sys.pair_list.begin();
	for (int i = 0; i < bal_sys.pair_list.size(); i++) {
		d_r_pairs.remove(*p_iter);
		p_iter++;
	}
	// remove single donor
	single_donors.remove(bal_sys.single_donor);
	return;
}










