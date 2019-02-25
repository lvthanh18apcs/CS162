#ifndef STAFF_H_DEFINED
#define STAFF_H_DEFINED

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Staff {
    void import();

    namespace Classes {
        void import(string path, string name);
    };
    
    namespace Courses {
        void import(string path, string name);
    }
};

#endif