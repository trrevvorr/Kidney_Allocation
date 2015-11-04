//
//  main.cpp
//  Kidney_Transplant
//
//  Created by Trevor Ross on 11/1/15.
//  Copyright © 2015 Trevor Ross. All rights reserved.
//

#include <iostream>
#include <random>
#include "Database.hpp"
using namespace std;

int main() {
	srand(time(NULL));
	
	Database d;
	Receiver r1 (212989282, "Tom", "Smith", "A+");
	Receiver r2 (555989252, "George", "Town", "O+");
	Receiver r3 (789989242, "Larry", "Mart", "B+");
	Receiver r4 (787989232, "Chuck", "Lake", "AB+");
	Receiver r5 (132989222, "Tim", "Hill", "A+");
	Receiver r6 (222989202, "Ryan", "Smith", "O+");
	Receiver r7 (333989912, "Nate", "Willis", "A-");
	Receiver r8 (454989812, "Seth", "Earty", "B+");
	Receiver r9 (890989712, "Luke", "Mackle", "AB+");
	Receiver r10 (999989612, "Matt", "Celic", "B-");
	Receiver r11 (888989512, "Brianne", "Portage", "O-");
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
	Donor d9 (299992323, "Lillian", "Mason", "AB+");
	Donor d10 (912888212, "Joshua", "Liam", "A-");
	Donor d11 (273339212, "John", "Michael", "AB-");
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
	
	d.print_patients(1);
	
	cout << "\n-------------------------------------------------\n\n";
	d.build_system();
	d.print_patients(1);
	d.print_bal_sys();
	
    return 0;
}
