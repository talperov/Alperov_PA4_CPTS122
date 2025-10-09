#pragma once
#include <string>
#include <iostream>

/*
The class DietPlan is used to represent a daily diet plan. The class will include
three data members to represent your goal calories (an integer), plan name (a
std::string), and date for which the plan is intended (a std::string). The maximum
intake of calories for a day is stored in the goal calories.
*/

class DietPlan
{
private: 
    int goal_calories; // Intended goal for calories
    std::string plan_name; // This is the name of the plan 
    std::string date; // This will be in MM/DD/YYYY

public:
    //constructors and copy constructors and deconstructors
    DietPlan(); // Initialize the class
    DietPlan(const std::string& name, int goal, const std::string& plan_date);
    DietPlan(const DietPlan& copy);
    ~DietPlan(); 

    //getter functions
    int getGoalCalories() const;
    std::string getPlanName() const;
    std::string getDate() const;

    //setter functions 
    void setGoalCalories(int goal);
    void setPlanName(const std::string& name);
    void setDate(const std::string& plan_date);

    //member functions
    void editGoal();

    //overloading functions
    friend std::ostream& operator<<(std::ostream& lhs, const DietPlan& rhs); //access private data in public
    friend std::istream& operator>>(std::istream& lhs, DietPlan& rhs); //access private data in public
};







