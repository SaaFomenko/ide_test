#include <iostream>
#include <fstream>
#include "functions.h"

std::ofstream fileOut(const char* path)
{
	const std::string msg = "Не удалось создаь файл, проверьте права доступа по адресу: ";
	std::ofstream fout (path);

	if (!fout.is_open())
	{
		std::cout << msg << path << std::endl;	
	}

	return fout;
}


