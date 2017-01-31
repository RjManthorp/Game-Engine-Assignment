#include "Logging.h"
#include <iostream>
#include <fstream>

void Logging::DebugLog(std::string INPUT)
{
	std::ofstream DebugFile;
	DebugFile.open("DebugLog.txt");
	DebugFile << INPUT << std::endl;
	DebugFile.close();
}





Logging::Logging()
{
	std::cout << "Contructing" << std::endl;
}


Logging::~Logging()
{

}
