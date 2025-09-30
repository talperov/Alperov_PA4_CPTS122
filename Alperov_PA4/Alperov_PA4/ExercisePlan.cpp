#include "ExercisePlan.hpp"
#include <iostream>

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
    std::cout << "ExercisePlan being Deconstructed" << std::endl;
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
    std::cout << "Edit Goal Steps: " << getGoalSteps() << std::endl;
    int newGoal = 0;
    std::cout << "Enter new Goal for Steps: " << std::endl;
    std::cin >> newGoal;
    setGoalSteps(newGoal);
    std::cout << "New Updated Goal" << *this << std::endl;
}

std::ostream& operator<<(std::ostream& lhs, const ExercisePlan& rhs)
{
    lhs << "Plan Name: " << rhs.getPlanName() << std::endl;
    lhs << "Date: " << rhs.getDate() << std::endl;
    lhs << "Goal for Steps: " << rhs.getGoalSteps() << std::endl;
    return lhs; 
}

std::istream& operator>>(std::istream& lhs, ExercisePlan& rhs)
{
    std::getline(lhs, rhs.plan_name);
    lhs >> rhs.goal_steps;
    lhs.ignore();
    std::getline(lhs, rhs.date);
    return lhs;
}
