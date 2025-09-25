#include "FitnessAppWrapper.hpp"

int file_safe_check()
{
	FILE* fileDiet = fopen("dietPlans.txt", "r");
	if (fileDiet == NULL)
	{
		std::cout << "Error opening File dietPlans.txt" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Success opening File (Diet Plans)" << std::endl;
	}
	FILE* filePlans = fopen("exercisePlans.txt", "r");
	if (filePlans == NULL)
	{
		std::cout << "Error opening File exercisePlans.txt" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Succees opening File (Exercise Plans)" << std::endl;
	}

}
