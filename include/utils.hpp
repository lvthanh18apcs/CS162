#ifndef UTILS_H_DEFINED
#define UTILS_H_DEFINED

#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

namespace Utils {
    namespace Tool {
        void createFolder(string path) {
            system(("mkdir -p" + path).c_str());
        }

        void openFile(fstream );
        int findNext(string s, int i, char value);
        vector <string> getElement(string s, char value);
    };
};

#endif