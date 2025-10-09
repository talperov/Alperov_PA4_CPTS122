#pragma once
#include <string>
#include <iostream>

/*
This is the ExercisePlan.hpp file where its used to represent a daily exercise plan. The class will
include three data members to represent  goal steps (an integer), plan name
std::string), and date for which the plan is intended (a std::string). Your goal steps
represent the number of desired steps for a day. 
*/

class ExercisePlan
{
private: 
    int goal_steps; // Intended goal for steps
    std::string plan_name; // This is the name of the plan
    std::string date; // This will be in MM/DD/YYYY

public:
    //constructors and copy constructors and deconstructors
    ExercisePlan(); // Initializing the class
    ExercisePlan(const std::string& name, int goal, const std::string& plan_date);
    ExercisePlan(const ExercisePlan& copy);
    ~ExercisePlan();

    //getter functions
    int getGoalSteps() const;
    std::string getPlanName() const;
    std::string getDate() const;

    //setter functions
    void setGoalSteps(int goal);
    void setPlanName(const std::string& name);
    void setDate(const std::string& plan_date);

    //member functions
    void editGoal();

    //overloading functions
    friend std::ostream& operator<<(std::ostream& lhs, const ExercisePlan& rhs); //access private data in public
    friend std::istream& operator>>(std::istream& lhs, ExercisePlan& rhs); //access private data in public
};

