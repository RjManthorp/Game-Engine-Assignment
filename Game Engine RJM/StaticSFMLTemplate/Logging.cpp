#define _CRT_SECURE_NO_WARNINGS
#include "Logging.h"
#include <iostream>
#include <fstream>
#include <ctime>

void Logging::DebugLog(std::string INPUT)
{
	time_t now = time(0);
	char* dt = ctime(&now);
	std::ofstream DebugFile;
	DebugFile.open("DebugLog.txt", std::ios_base::app);
	DebugFile << dt << INPUT << std::endl;
	DebugFile.close();
}



Logging::Logging()
{
	//std::cout << "Contructing" << std::endl;
}


Logging::~Logging()
{

}
