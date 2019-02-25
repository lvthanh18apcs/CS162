#include <utils.hpp>

void Utils::Tool::createFolder(string path) {
    system(("mkdir -p" + path).c_str());
}

void Utils::Tool::openInputFile(ifstream &fin, string path) {
    fin.open(path);
    if (!fin.is_open()) {
        cout << "Error: " << path << " doesn't exist!\n";
    }
}

void Utils::Tool::openOutputFile(ifstream &fout, string path) {
    fout.open(path);
}


int Utils::Tool::findNext(string s, int i, int value) {
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