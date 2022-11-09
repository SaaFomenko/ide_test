#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
	const char* in_file = { "./in.txt" };
	const char* out_file = { "./out.txt" };
  const std::string msg = "Данные были преобразованы и записаны в файл: ";

	int size = 0;

	std::ifstream fin = fileIn(in_file);
	bool check = fin.is_open();
	if (!check) return 1;
	
	std::ofstream fout = fileOut(out_file);
	check = fout.is_open();
	if (!check) return 1;

	while (fin >> size)
	{
		int* arr = arrInit(&fin, size);
		handlerArr(arr, size, &fout);
 
		delete[] arr;
		arr = nullptr;
	}

	fin.close();
	fout.close();

	std::cout << msg << out_file << std::endl;

  return 0;
}
