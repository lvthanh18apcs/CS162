//
//  main.cpp
//  Student Management
//
//  Created by Khoa Nguyen on 2/25/19.
//  Copyright © 2019 Khoa Nguyen. All rights reserved.
//

#include <stdio.h>
#include "student_node.hpp"


int main() {
    cout << "hell\n";
    StudentNode a(18125037,"Nguyen","Khoa","Male","01-01-2000","18CLC1");
    
    //a.editfirstname();
    
    //a.classRemove();
    
    //a.classAdd();
    
    a.classChange();
    
    return 0;
}
