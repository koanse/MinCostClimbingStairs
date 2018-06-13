#include "stdafx.h"
#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		return 1;
	}

	int count = argc - 2;

	int* cost = new int[count];
	int i, resultCost;
	for (i = 0; i < count; i++)
	{
		cost[i] = std::stoi(argv[i + 1]);

		//std::cout << "Cost[" << i << "] = " << cost[i] << std::endl;
	}

	int f1 = 0, f2 = 0;
	for (int i = count - 1; i >= 0; i--)
	{
		int f0 = cost[i] + (f1 <= f2 ? f1 : f2);

		//std::cout << "(f1 <= f2 ? f1 : f2) = " << (f1 <= f2 ? f1 : f2) << std::endl;

		//std::cout << "f0 = " << f0 << std::endl;
		//std::cout << "f1 = " << f1 << std::endl;
		//std::cout << "f2 = " << f2 << std::endl;

		f2 = f1;
		f1 = f0;
	}

	resultCost = f1 <= f2 ? f1 : f2;
	//std::cout << "Resut = " << std::endl;
	std::cout << resultCost << std::endl;

	return 0;
}

