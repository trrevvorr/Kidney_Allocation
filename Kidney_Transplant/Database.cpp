//
//  Database.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Database.hpp"

//Database::Database(int num_patients)
//{
//	for (int i = 0; i < num_patients; i++) {
//		patient_list.push_back(Patient());
//	}
//}

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
	d.pair_id = d_r_pairs.size();
	r.pair_id = d_r_pairs.size();
	
	//patient_list.push_back(d);
	//patient_list.push_back(r);
	d_r_pairs.push_back(Pair(d, r));
}

void Database::print_patients(int detail)
{
	cout << "\n==== PRINTING ALL PATIENTS IN DB ====\n\n";
	cout << "\n- Single Reciver -\n";
	print_s_receivers(detail);
	cout << "\n- Single Donor -\n";
	print_s_donors(detail);
	cout << "\n- D_R_Pairs -\n";
	print_pairs();
	return;
}

void Database::print_s_receivers(int detail)
{
	list<Receiver>::iterator r_iter = single_receivers.begin();
	
	for (int i = 0; i < single_receivers.size(); i++) {
		cout << "SSN: " << r_iter->ssn <<endl;
		cout << "Name: " << r_iter->f_name << " " << r_iter->l_name << endl;
		
		if (detail > 0) {
			cout << "Paired to: ";
			if (r_iter->pair_id == -1) {cout << "no one\n";}
			else
			{
				Pair p = lookup_pair(r_iter->pair_id);
				if (p.d.ssn == r_iter->ssn)
					cout << p.r.f_name << " " << p.r.l_name << endl;
				else
					cout << p.d.f_name << " " << p.d.l_name << endl;
			}
			cout << "Blood Type: " << r_iter->blood_type << endl;
		}
		if (detail > 1) {
			cout << "Location: " << r_iter->adr_state << " " << r_iter->adr_zipcode << endl;
		}
		r_iter++;
	}
	return;
}

void Database::print_s_donors(int detail)
{
	list<Donor>::iterator d_iter = single_donors.begin();
	
	for (int i = 0; i < single_donors.size(); i++) {
		cout << "SSN: " << d_iter->ssn <<endl;
		cout << "Name: " << d_iter->f_name << " " << d_iter->l_name << endl;
		
		if (detail > 0) {
			cout << "Paired to: ";
			if (d_iter->pair_id == -1) {cout << "no one\n";}
			else
			{
				Pair p = lookup_pair(d_iter->pair_id);
				if (p.d.ssn == d_iter->ssn)
					cout << p.r.f_name << " " << p.r.l_name << endl;
				else
					cout << p.d.f_name << " " << p.d.l_name << endl;
			}
			cout << "Blood Type: " << d_iter->blood_type << endl;
		}
		if (detail > 1) {
			cout << "Location: " << d_iter->adr_state << " " << d_iter->adr_zipcode << endl;
		}
		d_iter++;
	}
	return;
}

void Database::print_pairs()
{
	list<Pair>::iterator p_iter = d_r_pairs.begin();
	for (int i = 0; i < d_r_pairs.size(); i++) {
		p_iter->print();
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
	for (int i = 0; i < single_receivers.size(); i++)
	{
		bal_sys = Balanced_Sys();
		// get the next receiver in list
		bal_sys.single_receiver = *r_iter;
		// find system for receiver
		bal_sys.find_match(d_r_pairs, single_donors);
		if (bal_sys.balanced) {
			balanced_systems.push_back(bal_sys);
			update_database(bal_sys);
		}
		r_iter++;
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










