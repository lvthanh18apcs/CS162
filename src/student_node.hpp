//
//  student_node.hpp
//  Student Management
//
//  Created by Khoa Nguyen on 2/25/19.
//  Copyright © 2019 Khoa Nguyen. All rights reserved.
//

#ifndef student_node_hpp
#define student_node_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class StudentNode {
public :
    StudentNode() {};
    
    StudentNode(int ID, string firstname, string lastname, string gender, string DoB, string classtmp);
    
    void editSave();
    
    void editID (int newID);
    
    void editfirstname();
    
    void editlastname();
    
    void editgender();
    
    void editDoB();
    
    void classAdd();
    
    void classRemove();
    
    void classChange();
private :
    int ID;
    string firstname;
    string lastname;
    string gender;
    string DoB;
    string classtmp;
    
};



#endif /* student_node_hpp */
