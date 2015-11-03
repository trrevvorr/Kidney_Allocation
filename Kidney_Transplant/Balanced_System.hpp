//
//  Balanced_System.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/1/15.
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
	Receiver single_receiver;
	list<Pair> d_r_pairs;
	Donor single_donor;
	// type 1 = s_receiver <- (d_r_pairs*) <- s_donor
	// type 2 = circut of d_r_pairs (s donor and reciever not used)
	int type;
	bool balanced;
	
	Balanced_Sys():balanced(false),type(0){}
	
//	bool add_pair(const Donor &d);
//	bool compatible(const Receiver &r, const Donor &d);
	
	void find_match(list<Pair> d_r_pairs, list<Donor> &single_donors);
	list<Pair> find_match(const Pair &last_pair, list<Pair> d_r_pairs, list<Donor> &single_donors);
	list<Pair> find_compatible(const Receiver &r, list<Pair> &d_r_pairs);
	list<Pair> remove_from_list(const Pair &p, list<Pair> pairs);
	bool compatible(const Receiver &r, Donor &d);

};

#endif /* Balanced_System_hpp */
