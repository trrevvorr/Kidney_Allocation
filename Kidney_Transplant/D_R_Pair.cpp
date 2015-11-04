//
//  D_R_Pair.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/2/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "D_R_Pair.hpp"

Pair::Pair(Donor given_d, Receiver given_r)
{
	d = given_d;
	r = given_r;
	id = d.pair_id;
}

void Pair::print()
{
	cout << "Donor: \n";
	d.print(1);
	cout << "Receiver: \n";
	r.print(1);
	return;
}