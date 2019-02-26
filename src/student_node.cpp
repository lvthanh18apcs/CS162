//
//  student_node.cpp
//  Student Management
//
//  Created by Khoa Nguyen on 2/25/19.
//  Copyright © 2019 Khoa Nguyen. All rights reserved.
//

#include "student_node.hpp"

StudentNode::StudentNode(int ID, string firstname, string lastname, string gender, string DoB, string classtmp) {
    this -> ID = ID;
    this -> firstname = firstname;
    this -> lastname = lastname;
    this -> gender = gender;
    this -> DoB = DoB;
    this -> classtmp = classtmp;
}

void StudentNode::editSave() {
    ofstream fileOutput;
    fileOutput.open("data/classes/" + classtmp +  "/" + to_string(ID) + ".txt");
    
    if (!fileOutput.is_open())
        cout << "Cannot load the data!" << endl;
    else {
        fileOutput << firstname << endl;
        fileOutput << lastname << endl;
        fileOutput << gender << endl;
        fileOutput << DoB << endl;
    }
    
    fileOutput.close();
}

void StudentNode::editfirstname() {
    cin >> firstname;
    //firstname = newfirstname;
    editSave();
}

void StudentNode::editlastname() {
    cin >> lastname;
    //lastname = newlastname;
    editSave();
}

void StudentNode::editgender() {
    cin >> gender;
    //gender = newgender;
    editSave();
}

void StudentNode::editDoB() {
    cin >> DoB;
    //DoB = newDoB;
    editSave();
}

void StudentNode::classAdd() {
    editSave();
}

void StudentNode::classRemove() {
    if (remove(("data/classes/" + classtmp +  "/" + to_string(ID) + ".txt").c_str()) != 0)
        cout << "Not exist this student!" << endl;
    else
        cout << "Deleted successfully!" << endl;
    
}

void StudentNode::classChange() {
    string newclass;
    cin >> newclass;
    classRemove();
    classtmp = newclass;
    editSave();
}
