#ifndef course_h
#define course_h

#include <bits/stdc++.h>
#include "student.h"

using namespace std;

struct Course {

string id;
string title;
int credit_hours;
vector<pair<string , double>> grades;

};

void addcource (vector <Course> &courses);

Course * findCoursebyid(vector<Course> &Courses , const string &id);

void recordGrade(vector<Course>& Courses, vector<Student>& students); 

void printCourseReport(vector<Course>& Courses, vector<Student>& students);

#endif
