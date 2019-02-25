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
/*
    //Get list of courses
    system("./import courses");

    //Import courses information from csv file
    fin.open("data/courses_list");
    while (fin >> fname) {
        Courses::import("data/init/courses/", fname);
    }*/
}

/*  *   *   *   *   *   *   Classes   *   *   *   *   *   */

void Staff::Classes::import(string path, string class_name) {
    Utils::Tool::createFolder("data/classes/" + class_name);

    ifstream fin(path);

    if (!fin.is_open()) {
        system(("echo file " + path + " does not exist > Output.log").c_str());
        exit(0);
    }

    string s; getline(fin, s);
    while (getline(fin, s)) {
        vector <string> cur = Utils::Tool::getElement(s + ",", ','); 
        //No[0], Student ID[1], Last name[2], First name[3], gender[4], DoB[5]
        
        ofstream fout("data/classes/" + class_name + "/" + cur[1]);
        fout << cur[2] << "\n" << cur[3] << "\n" << cur[4] << "\n";
        vector <string> dob = Utils::Tool::getElement(cur[5] + "-", '-');
        fout << dob[2] << "-" << dob[1] << "-" << dob[0] << endl;
        fout.close();
    }
    fin.close();
}

/*  *   *   *   *   *   *   Courses   *   *   *   *   *   */

