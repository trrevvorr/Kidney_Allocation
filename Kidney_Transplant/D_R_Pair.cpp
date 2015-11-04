//
//  D_R_Pair.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include "D_R_Pair.hpp"

Pair::Pair(Donor given_d, Receiver given_r)
{
	d = given_d;
	r = given_r;
	id = d.pair_id;
}
