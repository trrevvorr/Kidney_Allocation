//
//  Balanced_System.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/1/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Balanced_System.hpp"

void Balanced_Sys::print()
{
	cout << "\n-- PRINTING BALANCED SYSTEM --\n\n";
	cout << "\n- Single Reciver -\n";
	single_receiver.print();
	cout << "\n- D_R_Pairs -\n";
	list<Pair>::iterator p_iter = pair_list.begin();
	for (int i = 0; i < pair_list.size(); i++) {
		p_iter->print();
		p_iter++;
	}
	cout << "\n- Single Donor -\n";
	single_donor.print();
	return;
}

// Accepts a single reciever and returns a list of pairs if
void Balanced_Sys::find_match(list<Pair> d_r_pairs, list<Donor> &single_donors)
{
	list<Pair> compatible_pairs = find_compatible(single_receiver, d_r_pairs);
	list<Pair> child_pairs;
	list<Pair> max_child_pairs;
	
	Receiver last_receiver = single_receiver;
	unsigned long pairs_found = 0;
	
	// if there is a pair for the reciever
	if (compatible_pairs.size() > 0) {
		list<Pair>::iterator p_iter = compatible_pairs.begin();
		for (int i = 0; i < compatible_pairs.size(); i++)
		{
			child_pairs = find_match(*p_iter, remove_from_list(*p_iter, d_r_pairs), single_donors);
			if (child_pairs.size() > max_child_pairs.size()) {
				max_child_pairs = child_pairs;
			}
			p_iter++;
		}
		if (max_child_pairs.size() > 0) {
			// add pairs to d_r_pairs!
			pair_list = max_child_pairs;
			Pair last_pair = pair_list.back();
			last_receiver = last_pair.r;
			pairs_found = pair_list.size();
		}
	}
	
	list<Donor>::iterator d_iter = single_donors.begin();
	for (int i = 0; i < single_donors.size(); i++) {
		if (compatible(last_receiver, *d_iter)) {
			single_donor = *d_iter;
			balanced = true;
		}
		d_iter++;
	}
	
	cout << pairs_found << " PAIRS FOUND! SUCESS!!!\n";
	cout << "THIS SYSTEM IS ";
	if (!balanced) { cout << "NOT ";}
	cout << " BALANCED!!!\n";
	return;
}

list<Pair> Balanced_Sys::find_match(const Pair &this_pair, list<Pair> d_r_pairs, list<Donor> &single_donors)
{
	list<Pair> compatible_pairs = find_compatible(this_pair.r, d_r_pairs);
	list<Pair> child_pairs;
	list<Pair> max_child_pairs;
	
	// if there are more nodes to go
	if (compatible_pairs.size() > 0) {
		// WE CAN GO DEEPER!
		list<Pair>::iterator p_iter = compatible_pairs.begin();
		for (int i = 0; i < compatible_pairs.size(); i++)
		{
			child_pairs = find_match(*p_iter, remove_from_list(*p_iter, d_r_pairs), single_donors);
			if (child_pairs.size() > max_child_pairs.size()) {
				max_child_pairs = child_pairs;
			}
			p_iter++;
		}
		if (max_child_pairs.size() > 0) {
			// this parent has a living child
			max_child_pairs.push_front(this_pair);
			return max_child_pairs;
		}
	}
	// else, we have reached a leaf or parent has no living children
	list<Donor>::iterator d_iter = single_donors.begin();
	for (int i = 0; i < single_donors.size(); i++) {
		if (compatible(this_pair.r, *d_iter)) {
			// green leaf
			max_child_pairs.push_front(this_pair);
			return max_child_pairs;
		}
		d_iter++;
	}
	// dead leaf
	return max_child_pairs;
}

list<Pair> Balanced_Sys::find_compatible(const Receiver &r, list<Pair> &d_r_pairs)
{
	list<Pair> compatible_pairs;
	list<Pair>::iterator pair_iter = d_r_pairs.begin();
	for (int i = 0; i < d_r_pairs.size(); i++)
	{
		if (compatible(r, pair_iter->d)) {
			compatible_pairs.push_back(*pair_iter);
		}
		pair_iter++;
	}
	return compatible_pairs;
}

bool Balanced_Sys::compatible(const Receiver &r, Donor &d)
{
	if (r.blood_type == d.blood_type) {
		return true;
	}
	return false;
}
	
list<Pair> Balanced_Sys::remove_from_list(const Pair &p, list<Pair> pairs)
{
	pairs.remove(p);
	return pairs;
}
