#include"storage.h"
#include <bits/stdc++.h>
using namespace std;
void saveDatabase(const std::vector<Student>& students, const std::vector<Course>&courses, const std::string& filename){
fstream file_1;
file_1.open(filename,ios::out);
if(file_1.is_open()){
    file_1<<students.size()<<'\n';
    for(int i=0;i<students.size();i++){
       file_1<<students[i].id<<'\n'; 
       file_1<<students[i].name<<'\n';
       file_1<<students[i].year<<'\n';
       file_1<<students[i].enrolledCourseIds.size()<<'\n';
       for(int j=0;j<students[i].enrolledCourseIds.size();j++){
        file_1<<students[i].enrolledCourseIds[j]<<' ';
       }
       file_1<<'\n';
    }
       file_1<<courses.size()<<'\n';
for(int i=0;i<courses.size();i++){
    file_1<<courses[i].id<<'\n';
file_1<<courses[i].title<<'\n';
file_1<<courses[i].credit_hours<<'\n';
file_1<<courses[i].grades.size()<<'\n';
for(int j=0;j<courses[i].grades.size();j++){
    file_1<<courses[i].grades[j].first<<' '<<courses[i].grades[j].second<<'\n';
}
}
file_1.close();
}
else{
    cout<<"an error has happend"<<'\n';
    return ;
}
}
void loadDatabase(std::vector<Student>& students, std::vector<Course>& courses,const std::string& filename){
   fstream file_1;
file_1.open(filename,ios::in); 
if(file_1.is_open()){
    students.clear();
    courses.clear();
    int num_students;
    file_1>>num_students;
    for(int i = 0; i < num_students; i++){
        Student s;
        file_1>>s.id;
        file_1.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(file_1,s.name);
        file_1>>s.year;
        int enrolledCourseIds_num;
        file_1>>enrolledCourseIds_num;
        for(int j=0;j<enrolledCourseIds_num;j++){
            string o;
            file_1>>o;
            s.enrolledCourseIds.push_back(o);
        }
        students.push_back(s);
    }
    int num_courses;
    file_1>>num_courses;
    for(int i=0;i<num_courses;i++){
        Course co;
        file_1.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file_1,co.id);
        getline(file_1,co.title);
        file_1>>co.credit_hours;
        int grades_numof;
        file_1>>grades_numof;
        for(int j=0;j<grades_numof;j++){
            string grade_name;
            double grade_val;
            file_1>>grade_name>>grade_val;
            co.grades.push_back({grade_name , grade_val});
        }
        courses.push_back(co);
    }
    file_1.close();
}
else{
    cout<<"an error has happend \n";
    return;
}
}
void exportCourseCSV(Course* course, std::vector<Student>& students){
  fstream f1;  
string filename = "course_" + course->id + ".csv";
f1.open(filename,ios::out);
if(!f1.is_open()){
cout<<"an error has happend\n";
return;
}
f1 << "StudentID,Grade\n";
for(int i=0;i<course->grades.size();i++){
f1<<course->grades[i].first<<','<<course->grades[i].second<<'\n';
}
f1.close();
}