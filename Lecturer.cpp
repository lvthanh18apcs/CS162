
#include "lecturer.h"

void Course_lists()
{
	ifstream in;
	int count = 0;
	string line;
	char temp[10];
	in.open("path.txt");
	if (!in.is_open())
	{
		cout << "Couldnt load file!" << endl;
		return;
	}
	// cout name of the folders such as cs161(1) cs161(2)
	while (!in.eof())
	{
		cin.ignore();
		in.get(temp, 9, '\n');
		cout << temp;
	}
	in.close();
}

void Course_students()
{
	ifstream in;
	int count = 0;
	string line;
	char temp[30];
	in.open("path.txt");
	if (!in.is_open())
	{
		cout << "Couldnt load file!" << endl;
		return;
	}
	// cout name of the folders such as cs161(1) cs161(2)
	while (getline(in, line))
		++count; // count how many lines in the text file
	cin.ignore();
	in.get(temp, 30, '\n');
	for (int i = 0; i < count - 1; ++i)
	{
		cin.ignore();
		in.get(temp, 30, ',');
		cout << temp; // cout first name of the student
		cin.ignore();
		in.get(temp, 30, ',');
		cout << " " << temp; // cout last name of the student
	}
	in.close();
}

void Scoreboard::Import_Scoreboard(vector <score> &p)
{
	ifstream in;
	char year[5], semester[8], mclass[8];
	cin.ignore();
	cout << "input year: ";     cin.ignore(); cin.get(year, 4, '\n');
	cout << "input semester: "; cin.ignore(); cin.get(semester, 8, '\n');
	cout << "input class: ";    cin.ignore(); cin.get(mclass, 8, '\n');
	in.open("path.txt"); // path can be changed
	if (!in.is_open()) return;
	// files formation : ID mid final overall...
	while (!in.eof())
	{
		int count = 0;
		char temp[9];
		in.ignore();
		in.get(temp, 8, ' ');
		p.push_back(score());
		strcpy(p[count].id, temp);
		double mi, fi, ov;
		in >> mi; in >> fi; in >> ov;
		p[count].mid = mi;
		p[count].fin = fi;
		p[count].overall = ov;
	}
	in.close();
}

void Scoreboard::View_Scoreboard(vector <score> &p)
{
	int size = p.size;
	for (int i = 0; i < size; ++i)
	{
		cout << p[i].id << " ";
		cout << p[i].mid << " ";
		cout << p[i].fin << " ";
		cout << p[i].overall << " ";
		cout << endl;
	}
}

void Scoreboard::Save_Scoreboard(vector <score> &p)
{
	int size = p.size;
	ofstream out;
	char year[5], semester[8], mclass[8];
	cin.ignore();
	cout << "input year: ";     cin.ignore(); cin.get(year, 4, '\n');
	cout << "input semester: "; cin.ignore(); cin.get(semester, 8, '\n');
	cout << "input class: ";    cin.ignore(); cin.get(mclass, 8, '\n');
	out.open("path.txt"); // path can be changed
	for (int i = 0; i < size; ++i)
	{
		out << p[i].id << " ";
		out << p[i].mid << " ";
		out << p[i].fin << " ";
		out << p[i].overall << " ";
		out << endl;
	}
	out.close();
}

void Scoreboard::Edit_Scoreboard(vector <score> &p)
{
	char ID[9];
	cin.ignore();
	cin.get(ID, 8, '\n'); // pass ID of student to edit
	int x;
	cin >> x; // which point you want to edit? midterm? final? overall? 
			  // 0 is midterm, 1 is final, 2 is overall
	int size = p.size;
	int i = 0;
	double edit; cin >> edit; // new point
	while (strcmp(p[i].id, ID) != 0)
		++i; // find student
	if (x == 0) p[i].mid = edit;
	else if (x == 1) p[i].fin = edit;
	else if (x == 2) p[i].overall = edit;
}

void Scoreboard::Generate()
{
	// generate a new scoreboard for a class to do something
	ofstream out;
	char ID[9];
	cout << "How many student you want to input: ";
	int n; cin >> n;
	out.open("path.txt"); // path is where the text filem is stored
	for (int i = 0; i < n; ++i)
	{
		cout << "input #" << i << " student: ";
		cin.ignore();
		cin.get(ID, 8, '\n');
		out << ID << " ";
		for (int j = 0; j < 3; ++j)
			out << 0 << " ";
		cout << endl;
	}
	out.close();
}


void Attendance::Import_Attendance(vector <arr> &check)
{
	ifstream in;
	char year[5], semester[8], mclass[8];
	cin.ignore();
	cout << "input year: ";     cin.ignore(); cin.get(year, 4, '\n');
	cout << "input semester: "; cin.ignore(); cin.get(semester, 8, '\n');
	cout << "input class: ";    cin.ignore(); cin.get(mclass, 8, '\n');
	in.open("path.txt"); // path can be changed
	if (!in.is_open()) return;
	// files formation : ID -1 -1 -1 ...
	while (!in.eof())
	{
		int count = 0;
		char temp[8];
		in.ignore();
		in.get(temp, 8, ' ');
		check.push_back(arr());
		strcpy(check[count].id, temp);
		for (int i = 0; i < 20; ++i)
		{
			int x; in >> x;
			check[count].ch[i] = x;
		}
		++count;
	}
	in.close();
}

void Attendance::View_Attendance(vector <arr> &check)
{
	int size = check.size;
	for (int i = 0; i < size; ++i)
	{
		cout << check[i].id << " ";
		for (int j = 0; j < 20; ++j)
		{
			if (check[i].ch[j] == -1) cout << "  ";
			else if (check[i].ch[j] == 0) cout << "A ";
			else if (check[i].ch[j] == 1) cout << "X ";
		}
		cout << endl;
	}
}

void Attendance::Save_Attendance(vector <arr> &check)
{
	int size = check.size;
	ofstream out;
	char year[5], semester[8], mclass[8];
	cin.ignore();
	cout << "input year: ";     cin.ignore(); cin.get(year, 4, '\n');
	cout << "input semester: "; cin.ignore(); cin.get(semester, 8, '\n');
	cout << "input class: ";    cin.ignore(); cin.get(mclass, 8, '\n');
	out.open("path.txt"); // path can be changed
	int size = check.size;
	for (int i = 0; i < size; ++i)
	{
		out << check[i].id;
		for (int j = 0; j < 20; ++j)
			out << check[i].ch[j] << " ";
		cout << endl;
	}
	out.close();
}

void Attendance::Edit_Attendance(vector <arr> &check)
{
	char ID[9];
	cin.ignore();
	cin.get(ID, 8, '\n'); // pass ID of student to edit
	int x;
	cin >> x; // pass x to function to mark if absent or attend or nothing yet, 
			  // -1 is nothing 1 is attend 0 is absent 
	int size = check.size;
	int i = 0;
	int week, lesson;
	cin >> week, cin >> lesson; // week 1 or 2 or 3 
								// lesson 1 or 2 , each week has 2 lessons, pass them in to change the status
	week = (week * 2 - 1) + lesson;
	while (strcmp(check[i].id, ID) == 0)
		++i;
	check[i].ch[week] = x;
}

void Attendance::Generate()
{
	// generate a new attendance list to do something
	ofstream out;
	char ID[9];
	cout << "How many student you want to input: ";
	int n; cin >> n;
	out.open("path.txt"); // path is where the text filem is stored
	for (int i = 0; i < n; ++i)
	{
		cout << "input #" << i << " student: ";
		cin.ignore();
		cin.get(ID, 8, '\n');
		out << ID << " ";
		for (int j = 0; j < 20; ++j)
			out << -1 << " ";
		cout << endl;
	}
	out.close();
}