//
//  main.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include <iostream>
#include <random>
#include "Database.hpp"
using namespace std;

void build_db1(Database & d);
void build_db2(Database & d);

int main() {
	srand(time(NULL));
	Database d;
	
	// fill the databse with patients
	build_db2(d);
	// print out the patients in the database
	d.print_patients();
	// build all possible balanced systems
	d.build_system();
	cout << "\n---------------------- Post - Build ---------------------------\n\n";
	// print out the patients STILL in the database (not part of balanced system)
	d.print_patients();
	// print all balanced systems
	d.print_bal_sys();
	
    return 0;
}

// builds a db with 5 single donors, 5 single receivers, and 10 pairs
// reciever urgentcy randomly generated
void build_db1(Database & d)
{
	Receiver r1 (212989282, "Tom", "Smith", "A+");
	Receiver r2 (555989252, "George", "Town", "O+");
	Receiver r3 (789989242, "Larry", "Mart", "B+");
	Receiver r4 (787989232, "Chuck", "Lake", "AB+");
	Receiver r5 (132989222, "Tim", "Hill", "A+");
	Receiver r6 (222989202, "Ryan", "Smith", "O+");
	Receiver r7 (333989912, "Nate", "Willis", "A-");
	Receiver r8 (454989812, "Seth", "Earty", "B-");
	Receiver r9 (890989712, "Luke", "Mackle", "A-");
	Receiver r10 (999989612, "Matt", "Celic", "B-");
	Receiver r11 (888989512, "Brianne", "Portage", "O+");
	Receiver r12 (289989412, "Taylor", "Sample", "B+");
	Receiver r13 (242989312, "Marry", "Wired", "O-");
	Receiver r14 (252989212, "Sandy", "Rever", "A-");
	Receiver r15 (292989012, "Shelby", "Christie", "AB+");
	
	Donor d1 (765599212, "Aubrey", "Elijah", "A-");
	Donor d2 (365599262, "Grace", "Town", "O+");
	Donor d3 (965599152, "Zoey", "Benjamin", "A-");
	Donor d4 (865599682, "Andrew", "Logan", "O+");
	Donor d5 (565599292, "Natalie", "William", "B+");
	Donor d6 (512882323, "Samuel", "Smith", "O-");
	Donor d7 (212882323, "Addison", "Willis", "B-");
	Donor d8 (612822323, "Gabriel", "Ethan", "A+");
	Donor d9 (299992323, "Lillian", "Mason", "B+");
	Donor d10 (912888212, "Joshua", "Liam", "A-");
	Donor d11 (273339212, "John", "Michael", "AB+");
	Donor d12 (812987912, "Lucas", "Mia", "B-");
	Donor d13 (112777772, "Victoria", "Madison", "O+");
	Donor d14 (888888889, "Harper", "James", "A+");
	Donor d15 (999999998, "Daniel", "Amelia", "AB+");
	
	d.add_s_donor(d1);
	d.add_s_donor(d2);
	d.add_s_donor(d3);
	d.add_s_donor(d4);
	d.add_s_donor(d5);
	
	d.add_s_receiver(r1);
	d.add_s_receiver(r2);
	d.add_s_receiver(r3);
	d.add_s_receiver(r4);
	d.add_s_receiver(r5);
	
	d.add_pair(d6, r6);
	d.add_pair(d7, r7);
	d.add_pair(d8, r8);
	d.add_pair(d9, r9);
	d.add_pair(d10, r10);
	d.add_pair(d11, r11);
	d.add_pair(d12, r12);
	d.add_pair(d13, r13);
	d.add_pair(d14, r14);
	d.add_pair(d15, r15);
	
	return;
}

// builds db with 3 single donors, 3 single receivers, and 7 pairs
// receiver urgentcy and blood types chosen to test specific edge cases
// optimal solution: [TS] <- [NW|TH] <- [AW|NW] <- [ZB] -AND- [GT] <- [AE]
void build_db2(Database & d)
{
	Receiver r1 (212989282, "Tom", "Smith", "A+", 1);
	Receiver r2 (555989252, "George", "Town", "A-", 2);
	Receiver r3 (789989242, "Larry", "Mart", "AB-", 3);
	
	Receiver r4 (787989232, "Chuck", "Lake", "A-", 4);
	Receiver r5 (132989222, "Tim", "Hill", "B+", 5);
	Receiver r6 (222989202, "Ryan", "Smith", "O+", 6);
	Receiver r7 (333989912, "Nate", "Willis", "O-", 7);
	Receiver r8 (454989812, "Seth", "Earty", "A-", 8);
	Receiver r9 (890989712, "Luke", "Mackle", "AB+", 9);
	Receiver r10 (999989612, "Matt", "Celic", "A-", 10);
	
	Donor d1 (765599212, "Aubrey", "Elijah", "A-");
	Donor d2 (365599262, "Grace", "Town", "A+");
	Donor d3 (965599152, "Zoey", "Benjamin", "O-");
	
	Donor d4 (865599682, "Andrew", "Logan", "A+");
	Donor d5 (565599292, "Natalie", "William", "A+");
	Donor d6 (512882323, "Samuel", "Smith", "A+");
	Donor d7 (212882323, "Addison", "Willis", "B+");
	Donor d8 (612822323, "Gabriel", "Ethan", "O+");
	Donor d9 (299992323, "Lillian", "Mason", "O-");
	Donor d10 (912888212, "Joshua", "Liam", "A+");
	
	d.add_s_donor(d1);
	d.add_s_donor(d2);
	d.add_s_donor(d3);
	
	d.add_s_receiver(r1);
	d.add_s_receiver(r2);
	d.add_s_receiver(r3);
	
	d.add_pair(d4, r4);
	d.add_pair(d5, r5);
	d.add_pair(d6, r6);
	d.add_pair(d7, r7);
	d.add_pair(d8, r8);
	d.add_pair(d9, r9);
	d.add_pair(d10, r10);

	return;
}



///////////////////////////////////////////////////////////////////////////
////// TO DO ////////
// add comments
// make everything constant that needs it
// remove unnessisary stuff