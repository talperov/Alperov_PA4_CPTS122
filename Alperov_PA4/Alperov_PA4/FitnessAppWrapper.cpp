#include "FitnessAppWrapper.hpp"
 
FitnessAppWrapper::FitnessAppWrapper(){}

FitnessAppWrapper::~FitnessAppWrapper()
{
	//cout << "DESTRUCTOR ACTIVATED" << endl;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& infile, DietPlan& plan)
{
	infile >> plan;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& infile, ExercisePlan& plan)
{
	infile >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& infile, DietPlan planWeek[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(infile, planWeek[i]);
	}	

}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& infile, ExercisePlan planWeek[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(infile, planWeek[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(const DietPlan& plan) const
{
	cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(const ExercisePlan& plan) const
{
	cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(const DietPlan planWeek[]) const
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(planWeek[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(const ExercisePlan planWeek[]) const
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(planWeek[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(ofstream& infile, const DietPlan& plan) const
{
	infile << plan << endl;
}

void FitnessAppWrapper::storeDailyPlan(ofstream& infile, const ExercisePlan& plan) const
{
	infile << plan << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& infile, const DietPlan planWeek[]) const
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(infile, planWeek[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& infile, const ExercisePlan planWeek[]) const
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(infile, planWeek[i]);
	}
}



int FitnessAppWrapper::displayMenu() const
{
	int pick = 0;
		cout << "WELCOME TO THE FITNESS APPLICATION!" << endl;
		cout << "1. Load weekly diet plan from the file." << endl;
		cout << "2. Load weekly exercise plan from file." << endl;
		cout << "3. Store weekly diet plan to file." << endl;
		cout << "4. Store weekly exercise plan to file." << endl;
		cout << "5. Display weekly diet plan to screen." << endl;
		cout << "6. Display weekly exercise plan to screen." << endl;
		cout << "7. Edit daily diet plan." << endl;
		cout << "8. Edit daily exercise plan." << endl;
		cout << "9. Exit." << endl;
		cout << "Select a Choice from Above: " << endl;
		cin >> pick;
		return pick;
	


}

void FitnessAppWrapper::runApp()
{
	ifstream DietPlans("dietPlans.txt");
	if (!DietPlans.is_open()) 
	{
	    cout << "Error opening dietPlans.txt" << endl;
	    return;
	}
	ifstream ExercisePlans("exercisePlans.txt");
	if (!ExercisePlans.is_open())
	{
	    cout << "Error opening exercisePlans.txt" << endl;
	    return;
	}

	loadWeeklyPlan(DietPlans, dietplan);
	loadWeeklyPlan(ExercisePlans, exerciseplan);

	DietPlans.close();
	ExercisePlans.close();

	bool success = true;

	while (true)
	{
		int pick = displayMenu();
		int num = 0;

		switch (pick)
		{
		case 1:
		{
			ifstream DietPlans("dietPlans.txt");
			if (!DietPlans.is_open())
			{
				cout << "Error opening dietPlans.txt" << endl;
				return;
			}
			loadWeeklyPlan(DietPlans, dietplan);
			DietPlans.close();
			cout << "Weekly Plan Loaded Successfully" << endl;
			break;
		}
		case 2:
		{
			ifstream ExercisePlans("exercisePlans.txt");
			if (!ExercisePlans.is_open()) 
			{
			    cout << "Error opening exercisePlans.txt" << endl;
			    return;
			}
			loadWeeklyPlan(ExercisePlans, exerciseplan);
			ExercisePlans.close();
			cout << "Weekly Plan Loaded Successfully" << endl;
			break;
		}
		case 3:
		{
			ofstream DietPlansStore("dietPlans.txt");
			storeWeeklyPlan(DietPlansStore, dietplan);
			DietPlansStore.close();
			cout << "Weekly Plan Saved Successfully" << endl;
			break;
		}
		case 4: 
		{
			ofstream ExercisePlansStore("exercisePlans.txt");
			storeWeeklyPlan(ExercisePlansStore, exerciseplan);
			ExercisePlansStore.close();
			cout << "Weekly Plan Saved Successfully" << endl;
			break;
		}
		case 5:
			displayWeeklyPlan(dietplan);
			break;
		case 6: 
			displayWeeklyPlan(exerciseplan);
			break;
		case 7:
			cout << "Enter a day from 1-6 to edit diet Plan: " << endl;
			cin >> num;
			if (num >= 1 && num <= 6)
			{
				dietplan[num].editGoal();
			}
			break;
		case 8:
			cout << "Enter a day from 1-6 to edit Exercise Plan: " << endl;
			cin >> num;
			if (num >= 1 && num <= 6)
			{
				exerciseplan[num].editGoal();
			}
			break;
		case 9:
		{
			ofstream DietPlansStore("dietPlans.txt");
			storeWeeklyPlan(DietPlansStore, dietplan);
			DietPlansStore.close();

			ofstream ExercisePlansStore("exercisePlans.txt");
			storeWeeklyPlan(ExercisePlansStore, exerciseplan);
			ExercisePlansStore.close();
			return;
		}
		default:
			cout << "Please Select another Choice." << endl;
		}
	}
}

int file_safe_check()
{ 
	FILE* fileDiet = fopen("dietPlans.txt", "r");
	if (fileDiet == NULL)
	{
		cout << "Error opening File dietPlans.txt" << endl;
		return 1;
	}
	else
	{
		std::cout << "Success opening File (Diet Plans)" << endl;
	}
	FILE* filePlans = fopen("exercisePlans.txt", "r");
	if (filePlans == NULL)
	{
		cout << "Error opening File exercisePlans.txt" << endl;
		return 1;
	}
	else
	{
		cout << "Succees opening File (Exercise Plans)" << endl;
	}

	return 1;
}