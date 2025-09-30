#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ignore;
using std::getline;
using std::fstream;

/*
The class FitnessAppWrapper is used to “wrap” the application. This class should
contain two lists (must be an array, vector, or linked list) of weekly (7 days) plans:
one diet and one exercise weekly plan.
*/

class FitnessAppWrapper
{
private: 
    DietPlan dietplan[7]; // List for DietPlan Class
    ExercisePlan exerciseplan[7]; // List for ExercisePlan Class

public:
    //constructors and copy constructors and deconstructors
    FitnessAppWrapper(); // Initializing the class

    //member functions
    int displayMenu(int pick); 
};

int file_safe_check(); // Checks if FILES opened successfully or not
