#ifndef stroage_h
#define storage_h
#include <vector>
#include<string>
#include "course.h"
#include "student.h"
void saveDatabase(const std::vector<Student>& students, const std::vector<Course>&courses, const std::string& filename);
void loadDatabase(std::vector<Student>& students, std::vector<Course>& courses,const std::string& filename);
void exportCourseCSV(Course* course, std::vector<Student>& students);
#endif