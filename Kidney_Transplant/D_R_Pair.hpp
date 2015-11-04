//
//  D_R_Pair.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#ifndef D_R_Pair_hpp
#define D_R_Pair_hpp

#include <iostream>
#include <string>
#include "Receiver.hpp"
#include "Donor.hpp"
using namespace std;

class Pair
{
public:
	Donor d;
	Receiver r;
	unsigned long id;
	
	Pair(Donor given_d, Receiver given_r);
	
	void print();
//	friend bool operator < (Pair &lhs, Pair &rhs)
//	{
//		// simply compare receivers
//		return lhs.r < rhs.r;
//	}
	
	bool operator==(const Pair &rhs) const {
		if (id == rhs.id) {
			return true;
		}
		return false;
	}
	
	bool operator<(const Pair &rhs) const {
		if (r < rhs.r) {
			return true;
		}
		return false;
	}
};

#endif /* D_R_Pair_hpp */
