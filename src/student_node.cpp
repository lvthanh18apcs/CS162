//
//  student_node.cpp
//  Student Management
//
//  Created by Khoa Nguyen on 2/25/19.
//  Copyright © 2019 Khoa Nguyen. All rights reserved.
//

#include "student_node.hpp"
void StudentNode::editSave() {
    ofstream fileOutput;
    fileOutput.open("data/classes" + classtmp +  "/" + to_string(ID) + ".txt");
    
    fileOutput << firstname << endl;
    fileOutput << lastname << endl;
    fileOutput << gender << endl;
    fileOutput << DoB << endl;
    
    fileOutput.close();
}

void StudentNode::editfirstname(string newfirstname) {
    firstname = newfirstname;
    editSave();
}

void StudentNode::editlastname(string newlastname) {
    lastname = newlastname;
    editSave();
}

void StudentNode::editgender(string newgender) {
    gender = newgender;
    editSave();
}

void StudentNode::editDoB(string newDoB) {
    DoB = newDoB;
    editSave();
}

void StudentNode::classAdd() {
    editSave();
}

void StudentNode::classRemove() {
    system(("rm -f data/classes" + classtmp +  "/" + to_string(ID) + ".txt").c_str());
}

void StudentNode::classChange(string newclass) {
    system(("mv data/classes/" + this->classtmp + "/" + to_string(this->ID) + ".txt data/classes/" + newclass + "/" + to_string(ID) + ".txt").c_str());
    this->classtmp = newclass;
}
