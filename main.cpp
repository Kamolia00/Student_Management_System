
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
    cout<<CYAN<<"====== MENU ======"<<RESET<<'\n';
    cout<<CYAN<<"press 1 to  add a student"<<RESET<<'\n' ;
    cout<<CYAN<<"press 2 to add a Course"<<RESET<<'\n' ;
    cout<<CYAN<<"press 3 to record a grade"<<RESET<<'\n' ;
    cout<<CYAN<<"press 4 to print a students information"<<RESET<<'\n' ;
    cout<<CYAN<<"press 5 to print a students gpa"<<RESET<<'\n';
    cout<<CYAN<<"press 6 for course report"<<RESET<<'\n';
    cout<<CYAN<<"press 7 to save data to database"<<RESET<<'\n';
    cout<<CYAN<<"press 8 to load data from database"<<RESET<<'\n';
    cout<<CYAN<<"press 9 export course CSV"<<RESET<<'\n' ;
    cout<<CYAN<<"press 0 to exit"<<RESET<<'\n';
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
case 8:{
    loadDatabase(students,courses,filename);
    cout<<GREEN<<"Database loaded"<<RESET<<'\n';
    break ;
}
case 9:{
    string cid;
    cout<<CYAN<<"enter course id: "<<RESET<<'\n';
    cin>>cid;
    Course*c=findCourseById(courses,cid);
    if(c==nullptr){
        cout<<RED<<"Course not found!"<<RESET<<'\n';
    }
    else{
        exportCourseCSV(c,students);
        cout<<GREEN<<"CVS exported"<<RESET<<'/n';
    }
    break;
}
        default:
        cout<<RED<<"invalid number pick another one from the menu"<<RESET<<'\n';
        break;
    }
   }
   return 0; 
}
