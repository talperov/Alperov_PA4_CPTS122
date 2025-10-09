#include "DietPlan.hpp"
#include <iostream>

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;


DietPlan::DietPlan() 
{
	this->goal_calories = 0;
	this->plan_name = "";
	this->date = "";
}

DietPlan::DietPlan(const std::string& name, int goal, const std::string& plan_date)
{
	this->plan_name = name;
	this->goal_calories = goal;
	this->date = plan_date;
}

DietPlan::DietPlan(const DietPlan& copy)
{
	this->plan_name = copy.plan_name;
	this->goal_calories = copy.goal_calories;
	this->date = copy.date;
}

DietPlan::~DietPlan()
{
	//DECONSTRUCTOR
	//std::cout << "DietPlan being Deconstructed" << std::endl;
	//REMEMBER TO DELETE AFTER BUILD COMPLETE
}

int DietPlan::getGoalCalories() const
{
	return this->goal_calories;
}

std::string DietPlan::getPlanName() const
{
	return this->plan_name;
}

std::string DietPlan::getDate() const
{
	return this->date;
}

void DietPlan::setGoalCalories(int goal)
{
	this->goal_calories = goal;
}

void DietPlan::setPlanName(const std::string& name)
{
	this->plan_name = name;
}

void DietPlan::setDate(const std::string& plan_date)
{
	this->date = plan_date;
}

void DietPlan::editGoal()
{
	cout << "Edit Goal Calories: " << getGoalCalories() << endl;
	int newGoal = 0;
	cout << "Enter new Goal for Calories: " << endl;
	cin >> newGoal;
	setGoalCalories(newGoal);
	cout << "New Updated Goal" << *this << endl;
}

std::ostream& operator<<(std::ostream& lhs, const DietPlan& rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getDate() << endl;
	lhs << rhs.getGoalCalories() << endl;
	return lhs;
}

std::istream& operator>>(std::istream& lhs, DietPlan& rhs)
{
	string name;
	string date;
	string calories; 

	getline(lhs, name);
	if (name.empty())
	{
		getline(lhs, name); 
	}
	getline(lhs, date);
	getline(lhs, calories);

	rhs.plan_name = name;
	rhs.date = date;
	rhs.goal_calories = std::stoi(calories);

	return lhs;
}
