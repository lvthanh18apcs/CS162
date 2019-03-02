//
//  student_node.cpp
//  Student Management
//
//  Created by Khoa Nguyen on 2/25/19.
//  Copyright © 2019 Khoa Nguyen. All rights reserved.
//

#include "student_node.hpp"

StudentNode::StudentNode() {}

StudentNode::StudentNode(int ID, string firstname, string lastname, string gender, string DoB, string classtmp) {
    this -> ID = ID;
    this -> firstname = firstname;
    this -> lastname = lastname;
    this -> gender = gender;
    this -> DoB = DoB;
    this -> classtmp = classtmp;
}

void StudentNode::infoImport() {
    cout << "Input ID and Class respectively: " << endl;
    cin >> ID;
    cin >> classtmp;
    
    // After having ID and Class, access to the txt of that information and read the remaining infor
    ifstream fileInput;
    fileInput.open("data/classes/" + classtmp +  "/" + to_string(ID));
    
    if (!fileInput.is_open())
        cout << "This student does not exist" << endl;
    else {
        fileInput >> firstname;
        fileInput >> lastname;
        fileInput >> gender;
        fileInput >> DoB;
    }
    
    fileInput.close();
}

//After editing infor of a student, write down it into that or a new txt whose name is "ID".txt
void StudentNode::editSave() {
    ofstream fileOutput;
    fileOutput.open("data/classes/" + classtmp +  "/" + to_string(ID));
    
    if (!fileOutput.is_open())
        cout << "Cannot load the data!" << endl;
    else {
        fileOutput << firstname << endl;
        fileOutput << lastname << endl;
        fileOutput << gender << endl;
        fileOutput << DoB << endl;
    }
    
    fileOutput.close();
}

void StudentNode::editfirstname() {
    cin >> firstname;
    //firstname = newfirstname;
    editSave();
}

void StudentNode::editlastname() {
    cin >> lastname;
    //lastname = newlastname;
    editSave();
}

void StudentNode::editgender() {
    cin >> gender;
    //gender = newgender;
    editSave();
}

void StudentNode::editDoB() {
    cin >> DoB;
    //DoB = newDoB;
    editSave();
}

void StudentNode::classAdd() {
    editSave();
}

void StudentNode::classRemove() {
    if (remove(("data/classes/" + classtmp +  "/" + to_string(ID)).c_str()) != 0)
        cout << "Not exist this student!" << endl;
    else
        cout << "Deleted successfully!" << endl;
    
}

void StudentNode::classChange() {
    string newclass;
    cin >> newclass;
    
    //Remove that student out of his/her old class and add to a new one.
    classRemove();
    classtmp = newclass;
    classAdd();
}

void classDisplay() {
    ifstream fin("data/classes_list");
    
    if (!fin.is_open())
        cout << "There is no class!\n";
    else {
        vector <string> classes;
        string classSub;
        while (getline(fin,classSub)) {
            classes.push_back(classSub);
        }
        
        for (int i = 0; i <= classes.size()-1; ++i)
            cout << classes[i] << endl;
        
        // After displaying the list of classes,
        // ask the users whether they would like to see the detail of class or not
        cout << "\nWould you like to view detail of class? (0 for No, and the others for the rest)\n";
        int input;
        cin >> input;
        
        //cout << classes[input-1];
        if (input == 0)
            return;
        else {
            cout << "\n" << setw(3) << "No" << setw(15) << "Last name" << setw(15) << "First name" << setw(15) << "Gender" << setw(20) << "Date of birth" << endl;
            
            ifstream fileInput("data/classes/" + classes[input-1] + "_list");
            
            if (!fileInput.is_open())
                cout << "The class is not available!\n";
            else {
                vector <int> IDtmp;
                int IDSub;
                
                while (fileInput >> IDSub) {
                    IDtmp.push_back(IDSub);
                }
                
                for (int i = 0; i <= IDtmp.size()-1; ++i) {
                    //cout << IDtmp[i] << endl << endl;
                    
                    ifstream studentInput("data/classes/" + classes[input-1] + "/" + to_string(IDtmp[i]));
                    
                    vector <string> studentInfo;
                    string studentInfoSub;
                    while (getline(studentInput,studentInfoSub)) {
                        studentInfo.push_back(studentInfoSub);
                    }
                    
                    cout << "\n" << setw(3) << i+1;
                    for (int j = 0; j <= studentInfo.size()-1; ++j) {
                        if (j == 3)
                            cout << setw(20) << studentInfo[j];
                        else
                            cout << setw(15) << studentInfo[j];
                    }
                    cout << endl;
                    
                    studentInput.close();
                }
            }
            
            fileInput.close();
        }
    }
    
    fin.close();
    
    
}


