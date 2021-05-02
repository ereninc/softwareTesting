#include <iostream>
#include "Emir.h"
#include "Portfoy.h"
#include "Hisse.h"
#include <nlohmann/json.hpp>

int main() 
{
	Portfoy* portfoy = new Portfoy();
	std::cout << "\n\n" << std::endl;
	std::cout << "HISSE LISTESI\n\n" << std::endl;
	Hisse* hisse = new Hisse();
	return 0;
}