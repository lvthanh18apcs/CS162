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
#include <string>
#include <fstream>

using namespace std;

class StudentNode {
public :
    StudentNode() {};
    
    void editSave();
    
    void editID (int newID);
    
    void editfirstname (string newfirstname);
    
    void editlastname (string newlastname);
    
    void editgender (string newgender);
    
    void editDoB (string newDoB);
    
    void classAdd();
    
    void classRemove();
    
    void classChange(string newclass);
private :
    int ID;
    string firstname;
    string lastname;
    string gender;
    string DoB;
    string classtmp;
    
};



#endif /* student_node_hpp */
