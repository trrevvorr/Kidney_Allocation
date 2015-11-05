//
//  Balanced_System.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#ifndef Balanced_System_hpp
#define Balanced_System_hpp

#include <list>
#include <iostream>
#include <string>
#include "Donor.hpp"
#include "Receiver.hpp"
#include "D_R_Pair.hpp"
using namespace std;

class Balanced_Sys
{
public:
	///// VARIABLES /////
	Receiver single_receiver;
	list<Pair> pair_list;
	Donor single_donor;
	// int type;
	bool balanced;
	
	///// FUNCTIONS /////
	// default constructor
	Balanced_Sys():balanced(false){}
	
	// Prints out the balanced system
	void print();
	void print_simple();
	
	// Step 1: iterate thorugh all compatible pairs to single_receiver,
	// tries to find system starting with each one of the c-pairs
	void find_match(list<Pair> d_r_pairs, list<Donor> &single_donors);
	// Step 2: recursivly search for longest string of pairs that results
	// in a balanced system
	list<Pair> find_match(const Pair &last_pair, list<Pair> d_r_pairs, list<Donor> &single_donors);
	// Returns a list of compatible pairs for the given receiver
	list<Pair> find_compatible(const Receiver &r, list<Pair> &d_r_pairs);
	// removes pair from list and returns the modified list
	list<Pair> remove_from_list(const Pair &p, list<Pair> pairs);
	// returns true if the given donor and receiver are compatible
	bool compatible(const Receiver &r, Donor &d);

};

#endif /* Balanced_System_hpp */
