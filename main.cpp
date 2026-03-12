
#include<bits/stdc++.h>
#include "course.h"
#include "student.h"
#include"utils.h"
#include "storage.h"
#include"color.h"
using namespace std;
int main(){
    vector<Student>students;
    vector <Course> courses;
     string id;
    int n;
    string filename="data base.txt";
   while(true){
    cout<<CYAN<<"\n====== MENU ======\n";
    cout<<"press 1 to  add a student \n";
    cout<<"press 2 to add a Course \n";
    cout<<"press 3 to record a grade \n";
    cout<<"press 4 to print a students information \n";
    cout<<"press 5 to print a students gpa\n";
    cout<<"press 6 for course report\n";
    cout<<"press 7 to save data to database\n";
    cout<<"press 8 to load data from database\n";
    cout<<"press 9 export course CSV \n";
    cout<<"press 0 to exit"<<RESET<<'\n';
    cin>>n;
    if(n==0){
        break;
    }
    switch (n)
    {
    case 1:
        addStudent(students);
        break;
    case 2:
    addCourse(courses);
    break;
    case 3:
    recordGrade(courses,students);
    break;
    case 4: {
        cout<<CYAN<<"enter student id"<<RESET<<'\n';
        cin>>id;
        auto it=findStudentById(students,id);
        if(it==0){
            cout<<RED<<"student not found"<<RESET<<'\n';
        }
        else{
            printStudent(*it);
        }
        break;
    }
    case 5:
    printStudentGPA(students,courses);
    break;
    case 6:
    printCourseReport(courses,students);
    break;
    case 7:{
    saveDatabase(students,courses,filename);
    cout<<GREEN<<"Database saved"<<RESET<<'\n';
    break;
}
        default:
        break;
    }
   }
   return 0; 
}
