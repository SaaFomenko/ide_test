#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
	const char* in_file = { "./in.txt" };
	const char* out_file = { "./out.txt" };
  const std::string msg = "Данные были преобразованы и записаны в файл: ";

	int size1 = 0;
	int size2 = 0;

	std::ifstream fin = fileIn(in_file);
	bool check = fin.is_open();
	if (!check) return 1;
	
	std::ofstream fout = fileOut(out_file);
	check = fout.is_open();
	if (!check) return 1;

	fin >> size1;
	int* arr1 = arrInit(&fin, size1);

	fin >> size2;
	int* arr2 = arrInit(&fin, size1);

	fin.close();

	handlerArr(arr2, size2, &fout);
	handlerArr(arr1, size1, &fout);

	fout.close();

	delete[] arr1;
	arr1 = nullptr;
	delete[] arr2;
	arr2 = nullptr;


	std::cout << msg << out_file << std::endl;

  return 0;
}
