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
