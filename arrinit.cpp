#include <fstream>
#include "functions.h"

int* arrInit(std::ifstream* fin, int size)
{
  int* arr = new int[size];
	
	for (int i = 0; i < size; ++i)
	{
		*fin >> arr[i];
	}
	
	return arr;
}
