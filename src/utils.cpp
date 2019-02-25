#include <utils.hpp>

void Utils::Tool::createFolder(string path) {
    system(("mkdir -p " + path).c_str());
}

int Utils::Tool::findNext(string s, int i, char value) {
    return find(s.begin() + i, s.end(), value) - s.begin();
}

vector <string> Utils::Tool::getElement(string s, char value) {
    vector <string> result;
    for (int i = 0; i < s.size(); ) {
        int j = findNext(s, i, value);
        result.push_back(s.substr(i, j - i));
        i = j + 1;
    }
    return result;
}
