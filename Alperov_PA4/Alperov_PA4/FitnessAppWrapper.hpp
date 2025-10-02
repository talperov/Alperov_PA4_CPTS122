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
using std::ofstream;
using std::ifstream;

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

    //DAILY PLAN LOADER FOR DIET AND EXCERSICE
    void loadDailyPlan(ifstream &infile, DietPlan &plan);
    void loadDailyPlan(ifstream& infile, ExercisePlan& plan);

    //WEEKLY PLAN LOADER FOR DIET AND EXCERSICE
    void loadWeeklyPlan(ifstream &infile, DietPlan planWeek[]);
    void loadWeeklyPlan(ifstream &infile, ExercisePlan planWeek[]);

    //DISPLAY DAILY PLAN LOADER FOR DIET AND EXCERSICE
    void displayDailyPlan(const DietPlan &plan) const;
    void displayDailyPlan(const ExercisePlan &plan)const;

    //DISPLAY WEEKLY PLAN LOADER FOR DIET AND EXCERSICE
    void displayWeeklyPlan(const DietPlan planWeek[]) const;
    void displayWeeklyPlan(const ExercisePlan planWeek[]) const;

    //STORE DAILY PLAN FOR DIET AND EXCERSICE&)const;
    void storeDailyPlan(ofstream& file, const DietPlan& plan) const;
    void storeDailyPlan(ofstream& file, const ExercisePlan& plan) const;

    //STORE WEEKLY PLAN FOR DIET AND EXERSICE
    void storeWeeklyPlan(ofstream &infile, const DietPlan planWeek[]) const;
    void storeWeeklyPlan(ofstream &infile, const ExercisePlan planWeek[]) const;

public:
    //constructors and copy constructors and deconstructors
    FitnessAppWrapper(); // Initializing the class
    ~FitnessAppWrapper(); //Deconstructor


    //member functions
    void runApp();
    int displayMenu() const; 
};

int file_safe_check(); // Checks if FILES opened successfully or not
