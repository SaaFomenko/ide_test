#include <iostream>
#include <fstream>
#include "functions.h"

void handlerArr(int* arr, int size, std::ofstream* fout, int step)
{
	static int count = 0;

	int shift = count % 2;

	int new_arr[size]{};

	std::cout << size << std::endl;
	*fout << size << "\n";

	if (!shift){
		for (int i = 0; i < size; ++i)
		{
			int index = i + step;
			bool in_arr  = index < size; 
			if (in_arr)
			{
				new_arr[i] = arr[index];
				std::cout << new_arr[i] << " ";
				*fout << new_arr[i] << " ";
			}
			else
			{
				new_arr[i] = arr[index - size];
				std::cout << new_arr[i] << " ";
				*fout << new_arr[i] << " ";
			}
		}
	}
	else
	{
		for (int i = size - 1; i >= 0; --i)
		{
			int index = i - step;
			bool in_arr = index >= 0;
			if (in_arr)
			{
				new_arr[i] = arr[index];	
				std::cout << new_arr[i] << " ";
				*fout << new_arr[i] << " ";
			}
			else
			{
				new_arr[i] = arr[index + size];
				std::cout << arr[i] << " ";
				*fout << new_arr[i] << " ";
			}
		}
	}

	std::cout << std::endl;
	*fout << "\n";
}
