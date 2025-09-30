#include "FitnessAppWrapper.hpp"

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

int FitnessAppWrapper::displayMenu(int pick)
{
	pick = 0;
	while (pick != 9)
	{
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
	}
	

	return pick;
}
