#include <iostream>
#include <fstream>
#include "functions.h"

std::ifstream fileIn(const char* path)
{
	const std::string msg = "Не удалось отрыть файл, проверьте права доступа и его наличие по адресу: ";
	std::ifstream fin (path);

	if (!fin.is_open())
	{
		std::cout << msg << path << std::endl;	
	}

	return fin;
}


