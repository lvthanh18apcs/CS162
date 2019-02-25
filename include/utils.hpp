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

        void openInputFile(ifstream &fin, string path) {
            fin.open(path);
            if (!fin.is_open()) 
        }
        
        void openOutputFile(ifstream &fout, string path);
        
        void 
        
        int findNext(string s, int i, char value);
        
        vector <string> getElement(string s, char value);
    };
};

#endif
