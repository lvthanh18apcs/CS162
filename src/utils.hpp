#ifndef UTILS_H_DEFINED
#define UTILS_H_DEFINED

#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Utils {
    namespace Tool {
        void createFolder(string path);
        
        string createFolder(string init, string raw);
        
        int findNext(string s, int i, char value);
        
        vector <string> getElement(string s, char value);
    };
};

#endif