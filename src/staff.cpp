#include <staff.hpp>
#include <utils.hpp>

/*  *   *   *   *   *   *   OverAll   *   *   *   *   *   */

void Staff::import() {
    system("chmod +x import.sh");
    
    //Get list of class
    system("./import.sh classes");

    //Import students of a class from csv file
    ifstream fin("data/classes_list");
    string fname;
    while (fin >> fname) {
        Classes::import("data/init/classes/" + fname + ".csv", fname);
    }
    fin.close();
    system("rm -r data/classes_list");

    //Get list of courses
    system("./import courses");

    //Import courses information from csv file
    fin.open("data/courses_list");
    while (fin >> fname) {
        Courses::import("data/init/courses/" + fname + ".csv", fname);
    }
    system("rm -r data/courses_list");
}

/*  *   *   *   *   *   *   Classes   *   *   *   *   *   */

void Staff::Classes::import(string path, string class_name) {
    Utils::Tool::createFolder("data/classes/" + class_name);

    ifstream fin(path);

    if (!fin.is_open()) {
        system(("echo file " + path + " does not exist > Output.log").c_str());
        exit(1);
    }

    string s; getline(fin, s);
    ofstream fileout("data/classes/" + class_name + "_list.txt");
    while (getline(fin, s)) {
        vector <string> cur = Utils::Tool::getElement(s + ",", ','); 
        //No[0], Student ID[1], Last name[2], First name[3], gender[4], DoB[5]
        
        ofstream fout("data/classes/" + class_name + "/" + cur[1] + ".txt");
        fileout << cur[2] << "\n";
        fout << cur[2] << "\n" << cur[3] << "\n" << cur[4] << "\n";
        vector <string> dob = Utils::Tool::getElement(cur[5] + "-", '-');
        fout << dob[2] << "-" << dob[1] << "-" << dob[0] << endl;
        fout.close();
    }
    fileout.close();
    fin.close();
}

/*  *   *   *   *   *   *   Courses   *   *   *   *   *   */

void Staff::Courses::import(string path, string raw) {
    raw = Utils::Tool::createFolder("data/courses/", raw);

    ifstream fin(path);

    if (!fin.is_open()) {
        system(("echo file " + path + " does not exist > Output.log").c_str());
        exit(1);
    }

    string s; getline(fin, s);
    while (getline(fin, s)) {
        vector <string> cur = Utils::Tool::getElement(s + ",", ',');
        //No[0], Course ID[1], Course Name[2], Class[3], LecturerAcount[4], Start Date[5],End Date[6],Day of Week[7],Start Hour[8],End Hour[9],Room[10]
        Utils::Tool::createFolder(raw + "/" + cur[1]);

        ofstream fout(raw + "/" + cur[1] + "/info");
        for (int i = 4; i < cur.size(); ++i) fout << cur[i] << "\n";
        
    }  
}
