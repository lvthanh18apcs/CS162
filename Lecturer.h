//
//  lecturer.hpp
//  Student Management
//


#ifndef lecturer_hpp
#define lecturer_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct arr
{
	int ch[20];
	char id[9];
};

class Attendance
{
public:
	arr check;
	void Import_Attendance(vector <arr> &check);
	void View_Attendance(vector <arr> &check);
	void Edit_Attendance(vector <arr> &check);
	void Save_Attendance(vector <arr> &check);
	void Generate();
};

struct score
{
	double mid, fin, overall;
	char id[9];
};

class Scoreboard
{
public:
	score p;
	void Import_Scoreboard(vector <score> &p);
	void View_Scoreboard(vector <score> &p);
	void Edit_Scoreboard(vector <score> &p);
	void Save_Scoreboard(vector <score> &p);
	void Generate();
};

void Course_lists();
void Course_students();

#endif 
