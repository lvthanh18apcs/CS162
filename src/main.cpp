<<<<<<< HEAD
//
//  main.cpp
//  Student Management
//
//  Created by Khoa Nguyen on 2/26/19.
//  Copyright © 2019 Khoa Nguyen. All rights reserved.
//

#include <stdio.h>
#include "student_node.hpp"

int main() {
    classDisplay();
    
    return 0;
=======
#include <global.hpp>

int main() {
	
	Global::load();
	Global::process();
	Global::finish();

	return 0;
>>>>>>> san-test
}
