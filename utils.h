#ifndef utils_h
#define utils_h
#include <iostream>
#include<bits/stdc++.h>
int getIntInput(const std::string& prompt);
double getDoubleInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);
template <typename T>
T findMax(const std::vector<T>& items);
#endif