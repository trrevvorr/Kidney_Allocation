//
//  Balanced_System.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "Balanced_System.hpp"

// PURPOSE: prints the contents of this balanced system (detailed print) (for debugging)
void Balanced_Sys::print()
{
	cout << "\n-- PRINTING BALANCED SYSTEM --\n\n";
	// print single receiver info
	cout << "\n- Single Reciver -\n";
	cout << single_receiver << endl;
	// print all pairs in system
	cout << "\n- D_R_Pairs -\n";
	list<Pair>::iterator p_iter = pair_list.begin();
	for (int i = 0; i < pair_list.size(); i++) {
		cout << *p_iter << endl;
		p_iter++;
	}
	// print single donor info
	cout << "\n- Single Donor -\n";
	cout << single_donor << endl;
	return;
}

// PURPOSE: print the contents of the balanced sysyem (simple print)
// FORMAT: [s_r] <- [p_d_1 | p_r_1] <- ... <- [p_d_n | p_r_n] <- [s_d]
void Balanced_Sys::print_simple()
{
	cout << "\n-- SIMPLE PRINTING BALANCED SYSTEM --\n\n";
	cout << "[" << single_receiver.f_name[0] << single_receiver.l_name[0] << "] <- ";
	list<Pair>::iterator p_iter = pair_list.begin();
	for (int i = 0; i < pair_list.size(); i++) {
		cout << "[" << p_iter->d.f_name[0] << p_iter->d.l_name[0] << "|" <<
			p_iter->r.f_name[0] << p_iter->r.l_name[0] << "] <- ";
		p_iter++;
	}
	cout << "[" << single_donor.f_name[0] << single_donor.l_name[0] << "]\n";
}

// PURPOSE: finds all balanced systems for the single_receiver
// PROCESS: finds all compatible pairs then calls the other find_match funtion
// to determine if the each compatible pair leads to a balanced system
// RESULT: the optimal balanced system will be stored in the member variables
void Balanced_Sys::find_match(list<Pair> d_r_pairs, list<Donor> &single_donors)
{
	// list of all pairs compatible with single_receiver
	list<Pair> compatible_pairs = find_compatible(single_receiver, d_r_pairs);
	list<Pair> child_pairs;
	list<Pair> max_child_pairs;
	
	Receiver last_receiver = single_receiver;
	unsigned long pairs_found = 0;
	
	// if there is a pair that could dontate to single_receiver
	if (compatible_pairs.size() > 0) {
		// iterate though all compatible pairs, try to find balanced system for each
		list<Pair>::iterator p_iter = compatible_pairs.begin();
		for (int i = 0; i < compatible_pairs.size(); i++, p_iter++)
		{
			child_pairs = find_match(*p_iter, remove_from_list(*p_iter, d_r_pairs), single_donors);
			// if the pair has a better balanced sytem then the max, make it the new max
			if (child_pairs.size() > max_child_pairs.size()) {
				max_child_pairs = child_pairs;
			}
		}
		// if a balanced system was found
		if (max_child_pairs.size() > 0) {
			// add pairs to d_r_pairs!
			pair_list = max_child_pairs;
			Pair last_pair = pair_list.back();
			last_receiver = last_pair.r;
			pairs_found = pair_list.size();
		}
	}
	// find a single donor to finish off the balanced sytem
	// NOTE: if a balanced sytem was found then there will be a single donor for it
	list<Donor>::iterator d_iter = single_donors.begin();
	for (int i = 0; i < single_donors.size(); i++, d_iter++) {
		if (compatible(last_receiver, *d_iter)) {
			// a single donor was found
			single_donor = *d_iter;
			balanced = true;
			break;
		}
	}
	// print results, if pairs_found > 0 then the system is balanced, if not: ERROR
	// however, pairs_found may == 0 and the system still be balanced
	cout << pairs_found << " PAIRS FOUND!\n";
	cout << "THIS SYSTEM IS ";
	if (!balanced) { cout << "NOT ";}
	cout << " BALANCED!!!\n";
	return;
}

// PURPOSE: finds all pairs that can donate to this_pair AND lead to a balanced sytem
// CASE 1: no valid* pairs found, no single donor found: return empty list
// CASE 2: no valid* pairs found, single donor found: return list containing only this_pair
// CASE 3: at least one valid* pair found: return list containng valid* pair + this_pair
// * valid pairs are those which lead to a balanced system, if a pair is found which has none
// of its own pairs nor a single donor then it is not valid
list<Pair> Balanced_Sys::find_match(const Pair &this_pair, list<Pair> d_r_pairs, list<Donor> &single_donors)
{
	// list of all pairs compatible with this_pair.r
	list<Pair> compatible_pairs = find_compatible(this_pair.r, d_r_pairs);
	list<Pair> child_pairs;
	list<Pair> max_child_pairs;
	
	// if there are any compatible pairs
	if (compatible_pairs.size() > 0) {
		list<Pair>::iterator p_iter = compatible_pairs.begin();
		for (int i = 0; i < compatible_pairs.size(); i++, p_iter++)
		{
			// find list of all valid* pairs
			child_pairs = find_match(*p_iter, remove_from_list(*p_iter, d_r_pairs), single_donors);
			// if the pair has a better balanced sytem then the max, make it the new max
			if (child_pairs.size() > max_child_pairs.size()) {
				max_child_pairs = child_pairs;
			}
		}
		// if any valid* pairs were found
		if (max_child_pairs.size() > 0) {
			// return this_pair + valid_pair and all its valid pairs
			max_child_pairs.push_front(this_pair);
			return max_child_pairs;
		}
	}
	// parent has no valid* pairs, try and find a matching single donor
	list<Donor>::iterator d_iter = single_donors.begin();
	for (int i = 0; i < single_donors.size(); i++, d_iter++) {
		if (compatible(this_pair.r, *d_iter)) {
			// green leaf
			// return list containing only this_pair
			max_child_pairs.push_front(this_pair);
			return max_child_pairs;
		}
	}
	// dead leaf
	// return an empty list {}
	return max_child_pairs;
}

// PURPOSE: finds all compatible pairs to the passed receiver (r)
// pair is compatible if the pair's donor can donate to the receiver
// RETURNS: list of compatible pairs (not nessisarily valid*)
list<Pair> Balanced_Sys::find_compatible(const Receiver &r, list<Pair> &d_r_pairs)
{
	list<Pair> compatible_pairs;
	// iterate though all d_r_pairs
	list<Pair>::iterator pair_iter = d_r_pairs.begin();
	for (int i = 0; i < d_r_pairs.size(); i++, pair_iter++)
	{
		if (compatible(r, pair_iter->d)) {
			// pair is compatible, add it to the list
			compatible_pairs.push_back(*pair_iter);
		}
	}
	return compatible_pairs;
}

// PURPOSE: determines if the receiver (r) and the donor (d) are compatible
bool Balanced_Sys::compatible(const Receiver &r, Donor &d)
{
	// if bloot types match
	// (I know, that's not how blood type compatibility works but whatever, this is simpler)
	if (r.blood_type == d.blood_type) {
		return true;
	}
	return false;
}

// removes a pair from the pairs list without affecting pair_list (member variable)
// this is to be used with the recursice function so that the same pair does not appear
// multiple times in one balanced system
list<Pair> Balanced_Sys::remove_from_list(const Pair &p, list<Pair> pairs)
{
	pairs.remove(p);
	return pairs;
}
