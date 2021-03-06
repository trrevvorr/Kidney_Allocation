//
//  D_R_Pair.hpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
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
	///// VARIABLES /////
	Donor d;
	Receiver r;
	unsigned long id;
	
	///// CONSTRUCTOR /////
	Pair(Donor given_d, Receiver given_r);
	
	/// OVERLOADED OPERATORS ///
	friend ostream & operator << (ostream &out_stream, const Pair &p)
	{
		out_stream << "Donor: \n" << p.d << "\nReceiver: \n" << p.r;
		return(out_stream);
	}
	bool operator==(const Pair &rhs) const {
		if (id == rhs.id) {
			return true;
		}
		return false;
	}
	// used to sort pair lists with .sort()
	bool operator<(const Pair &rhs) const {
		return (r < rhs.r);
	}
};

#endif /* D_R_Pair_hpp */
