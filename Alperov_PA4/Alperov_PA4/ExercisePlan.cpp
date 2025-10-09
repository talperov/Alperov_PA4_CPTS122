#include "ExercisePlan.hpp"
#include <iostream>

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

ExercisePlan::ExercisePlan()
{
    this->goal_steps = 0;
    this->plan_name = "";
    this->date = "";
}

ExercisePlan::ExercisePlan(const std::string& name, int goal, const std::string& plan_date)
{
    this->goal_steps = goal;
    this->plan_name = name;
    this->date = plan_date;
}

ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
    this->goal_steps = copy.goal_steps;
    this->plan_name = copy.plan_name;
    this->date = copy.date;
}

ExercisePlan::~ExercisePlan()
{
    //DECONSTRUCTOR
   // std::cout << "ExercisePlan being Deconstructed" << std::endl;
    //REMEMBER TO DELETE AFTER BUILD COMPLETE
}

int ExercisePlan::getGoalSteps() const
{
    return this->goal_steps;
}

std::string ExercisePlan::getPlanName() const
{
    return this->plan_name;
}

std::string ExercisePlan::getDate() const
{
    return this->date;
}

void ExercisePlan::setGoalSteps(int goal)
{
    this->goal_steps = goal;
}

void ExercisePlan::setPlanName(const std::string& name)
{
    this->plan_name = name;
}

void ExercisePlan::setDate(const std::string& plan_date)
{
    this->date = plan_date;
}

void ExercisePlan::editGoal()
{
    cout << "Edit Goal Steps: " << getGoalSteps() << endl;
    int newGoal = 0;
    cout << "Enter new Goal for Steps: " << endl;
    cin >> newGoal;
    setGoalSteps(newGoal);
    cout << "New Updated Goal" << *this << endl;
}

std::ostream& operator<<(std::ostream& lhs, const ExercisePlan& rhs)
{
    lhs << rhs.plan_name << endl;
    lhs << rhs.date << endl;
    lhs << rhs.goal_steps << endl << endl; 
    return lhs;
}

std::istream& operator>>(std::istream& lhs, ExercisePlan& rhs)
{
    string stepsStr;
    do 
    {
        getline(lhs, rhs.plan_name);
    } while (rhs.plan_name.empty() && !lhs.eof());

    getline(lhs, rhs.date);

    do 
    {
        getline(lhs, stepsStr);
    } while (stepsStr.empty() && !lhs.eof());

    if (!stepsStr.empty())
    {
        rhs.goal_steps = stoi(stepsStr);
    }

    return lhs;
}




