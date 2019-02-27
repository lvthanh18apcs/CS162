#ifndef STAFF_H_DEFINED
#define STAFF_H_DEFINED

#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Staff {
    void import();

    namespace Classes {
        void import(string, string);

        vector <string> getClassList();

        vector <string> getStudentListOf(string classtmp);
    };
    
    namespace Courses {
        void import(string, string);
    }
};

#endif