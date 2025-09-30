#include "DietPlan.hpp"

DietPlan::DietPlan() 
{
	this->goal_calories = 0;
	this->plan_name = "";
	this->date = "";
}

DietPlan::DietPlan(const string& name, int goal, const string& plan_date)
{
	this->plan_name = name;
	this->goal_calories = goal;
	this->date = plan_date;
}

DietPlan::DietPlan(const DietPlan& other)
{
	this->plan_name = other.plan_name;
	this->goal_calories = other.goal_calories;
	this->date = other.date;
}

DietPlan::~DietPlan()
{
	//DECONSTRUCTOR
	cout << "DietPlan being Deconstructed" << endl;
}

int DietPlan::getGoalCalories() const
{
	return this->goal_calories;
}

string DietPlan::getPlanName() const
{
	return this->plan_name;
}

string DietPlan::getDate() const
{
	return this->date;
}

void DietPlan::setGoalCalories(int goal)
{
	this->goal_calories = goal;
}

void DietPlan::setPlanName(const string& name)
{
	this->plan_name = name;
}

void DietPlan::setDate(const string& plan_date)
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

ostream& operator<<(ostream& lhs, const DietPlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
	lhs << "Calorie Goal: " << rhs.getGoalCalories() << endl;
	return lhs;
}

istream& operator>>(istream& lhs, DietPlan& rhs)
{
	getline(lhs, rhs.plan_name);      
	lhs >> rhs.goal_calories;         
	lhs.ignore();                     
	getline(lhs, rhs.date);           
	return lhs;
}
