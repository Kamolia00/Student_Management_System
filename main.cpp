#include<bits/stdc++.h>
#include "course.h"
#include "student.h"
using namespace std;
int main(){
    vector<Student>students;
    vector <Course> courses;
     string id;
   while(true){
    int n;
    cout<<"press 1 to  add a student \n";
    cout<<"press 2 to add a Course \n";
    cout<<" press 3 to record a grade \n";
    cout<<"press 4 to print a students information \n";
    cout<<"press 0 to exit\n";
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
    addcource(courses);
    break;
    case 3:
    recordGrade(courses,students);
    break;
    case 4:
    cout<<"enter student id";
    cin>>id;
    auto it=findStudentById(students,id);
    if(it==0){
        cout<<"student not found\n";
    }
    else{
printStudent(*it);
    }
break;
        default:
        break;
    }
   }
   return 0; 
}