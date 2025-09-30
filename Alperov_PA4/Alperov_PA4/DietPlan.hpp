#pragma once
#include "FitnessAppWrapper.hpp"
#include "ExercisePlan.hpp"
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
	string plan_name; // This is the name of the plan 
	string date; // This will be in MM/DD/YYYY




public:


	//constructors and copy constructors and deconstructors

	DietPlan(); // Initialize the class
	DietPlan(const string& name, int goal, const string& plan_date);
	DietPlan(const DietPlan& other);
	~DietPlan(); 


	//getter functions
	int getGoalCalories() const;
	string	getPlanName() const;
	string getDate() const;

	//setter functions 
	void setGoalCalories(int goal);
	void setPlanName(const string& name);
	void setDate(const string& plan_date);

	//member functions
	
	void editGoal();

	//overloading functions
	friend ostream& operator<<(ostream& lhs, const DietPlan& rhs);
	friend istream& operator>>(istream& lhs, DietPlan& rhs);
};




