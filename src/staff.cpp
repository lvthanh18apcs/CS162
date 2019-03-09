#include <staff.hpp>
#include <utils.hpp>

/*  *   *   *   *   *   *   OverAll   *   *   *   *   *   */

void Staff::import() {
    system("> data/account"); // Delete content of file "account"
    system("> data/classes_list"); // Delete content of file "class_list"
    system("> data/courses_list"); // Delete content of file "courses_list"

    system("chmod +x import.sh"); //Excute import.sh
    system("./import.sh classes"); //Get list of class
    system("./import.sh courses"); //Get list of courses

    //Import students of a class from csv file
    ifstream fin("data/classes_list");
    string fname;
    while (fin >> fname) {
        Classes::import("data/init/classes/" + fname + ".csv", fname);
    }
    fin.close();

    //Import courses information from csv file
    fin.open("data/courses_list");
    while (fin >> fname) {
        Courses::import("data/init/courses/" + fname + ".csv", fname);
    }
}

/*  *   *   *   *   *   *   Classes   *   *   *   *   *   */

void Staff::Classes::import(string path, string class_name) {
    Utils::Tool::createFolder("data/classes/" + class_name);

    ifstream fin(path);
    string s; getline(fin, s);
    while (getline(fin, s)) {
        //No[0], Student ID[1], Last name[2], First name[3], gender[4], DoB[5]
        vector <string> cur = Utils::Tool::getElement(s + ",", ','); 

        ofstream fout("data/classes/" + class_name + "/" + cur[1], ios::trunc);
        ofstream ffout("data/account",ios::app);
        
        vector <string> dob = Utils::Tool::getElement(cur[5] + "-", '-');

        fout << cur[2] << "\n" << cur[3] << "\n" << cur[4] << "\n";
        fout << dob[2] << "-" << dob[1] << "-" << dob[0] << endl;

        ffout << cur[1] << " " << dob[0] << dob[1] << dob[2] << " " << class_name << endl;

        fout.close();
        ffout.close();
    }
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

vector <string> Staff::Classes::getClassList() {
    vector <string> result;
    ifstream fin("data/classes_list");
    string s; while (fin >> s) result.push_back(s);
    return result;
}

vector <string> Staff::Classes::getStudentListOf(string classtmp) {
    struct dirent *entry;
    vector <string> result;

    DIR *dir = opendir(("data/classes/" + classtmp).c_str());
    if (dir == NULL) {
        system(("echo file " + classtmp + " does not exist!!!").c_str());
        exit(0);
    }
    while ((entry = readdir(dir)) != NULL && entry->d_type == 32) {
        result.push_back(string(entry->d_name));
    }
    return result;
}