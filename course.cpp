#include "course.h"
#include "student.h"
#include "color.h" 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addCourse(vector<Course>& courses) {
    Course c;

    // دخل الكود وشوف موجود قبل كده ولا لا
    cout << CYAN<< "Enter Course ID: " << RESET;
    cin >> c.id;

    if (findCourseById(courses, c.id) != nullptr) {
        cout << RED << "Error: Course with ID " << c.id << " already exists!" << RESET << '\n';
        return;
    }

    //دخل اسم الماده كله 
    cout << CYAN << "Enter Title: " << RESET;
    cin.ignore();
    getline(cin, c.title);

    // دخل عدد الساعات 
    cout << CYAN << "Enter Credit Hours: " << RESET;
    
    while (!(cin >> c.credit_hours) || c.credit_hours < 1 || c.credit_hours > 6) {
        cout << RED << "Invalid input! Enter valid credit hours (1-6): " << RESET;

        cin.clear();
        cin.ignore(10000, '\n');
    }

    courses.push_back(c);
    cout << GREEN << "Course Added Successfully!" << RESET << '\n';
    //تمت بخيرررررررررر 
}

Course* findCourseById(vector<Course>& courses, const string& id) {
    for (int i = 0; i < courses.size(); ++i) {
        if (courses[i].id == id) {
            return &courses[i];
        }
    }
    return nullptr;
}

void recordGrade(vector<Course>& courses, vector<Student>& students) {
    string courseId, studentId;
    double grade;
    
    // دخل كود الماده

    cout << CYAN<< "Enter Course ID: " << RESET;
    cin >> courseId;

    Course* c = findCourseById(courses, courseId);
    if (c == nullptr) {
        cout << RED << "Course not found!" << RESET << '\n';
        return;
    }

    // دخل رقم الطالب 
    cout << CYAN << "Enter Student ID: " << RESET;
    cin >> studentId;

    Student* s = findStudentById(students, studentId);
    if (s == nullptr) {
        cout  << RED<< "Student not found!" << RESET << '\n';
        return;
    }

    // نتأكد انه مش موجود قبل كده
    for (int i = 0; i < c->grades.size(); ++i) {

        if (c->grades[i].first == studentId) {
            cout  << RED<< "Error: Grade already recorded for this student in this course!" << RESET << '\n';
            return;
        }
    }

    
    cout << CYAN << "Enter Grade (0-100): " << RESET;
    while (!(cin >> grade) || grade < 0 || grade > 100) {
        cout << RED << "Invalid input! Enter a valid grade (0-100): " << RESET;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // ضيف الدرجه
    c->grades.push_back({studentId, grade});

    
    bool alreadyEnrolled = false;

    for (int i = 0; i < s->enrolledCourseIds.size(); ++i) {

        if (s->enrolledCourseIds[i] == courseId) {
            alreadyEnrolled = true;
            break;
        }
    }
    //بنضيف الماده لو  مش موجوده 

    if (!alreadyEnrolled) {
        s->enrolledCourseIds.push_back(courseId);
    }

    cout << GREEN << "Grade recorded successfully!" << RESET << '\n';
}

void printCourseReport(vector<Course>& courses, vector<Student>& students) {
    string courseId;
    cout  << CYAN<< "Enter Course ID: " << RESET;
    cin >> courseId;

    Course* c = findCourseById(courses, courseId);
    if (c == nullptr) {
        cout  << RED<< "Course not found!" << RESET << '\n';
        return;
    }

    cout << BLUE<< "==========================================" << RESET << '\n';

    cout <<CYAN << "Course Report: " << RESET << c->title << " (" << c->id << ")\n";
    cout  << CYAN<< "Credit Hours:  " << RESET << c->credit_hours << '\n';

    cout << BLUE<< "==========================================" << RESET << '\n';


    
    if (c->grades.empty()) {
        cout  << RED<< "No grades recorded yet." << RESET << '\n';
        cout << BLUE<< "==========================================" << RESET << '\n';
        return;
    }

    
    double total = 0.0;

    double highest = c->grades[0].second;
    double lowest = c->grades[0].second;

    string topStudent = c->grades[0].first;
    string lastStudent = c->grades[0].first;

    cout  << CYAN<< "Student ID    | Name                | Grade" << RESET << '\n';
    cout  << BLUE<< "===============================================" << RESET << '\n';

    for (int i = 0; i < c->grades.size(); ++i) {

        string sid = c->grades[i].first;
        double g = c->grades[i].second;
        total += g;


        string studentName = "Unknown";
        Student* s = findStudentById(students, sid);
        if (s != nullptr) {
            studentName = s->name;
        }

        cout << CYAN << sid << RESET;

        // شويه مسافات 
        for (int j = sid.length(); j < 14; ++j) cout << ' ';
        cout << "| " << studentName;
        
        for (int j = studentName.length(); j < 20; ++j) cout << ' ';
        cout << "| " << g << '\n';

        // اعلي واقل واحد
        if (g > highest) {
            highest = g;
            topStudent = sid;
        }
        if (g < lowest) {
            lowest = g;
            lastStudent = sid;
        }
    }

    double average = total / c->grades.size();

    cout << BLUE << "------------------------------------------" << RESET << '\n';
    cout << CYAN << "Total Students: " << RESET << c->grades.size() << '\n';
    cout << CYAN << "Average Grade:  " << RESET << average << '\n';
    cout << CYAN << "Highest Grade:  " << RESET << highest << " (Student: " << topStudent << ")\n";
    cout << CYAN << "Lowest Grade:   " << RESET << lowest << " (Student: " << lastStudent << ")\n";
    cout << BLUE << "------------------------------------------" << RESET << '\n';

}