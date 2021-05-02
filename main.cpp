#include <iostream>
#include "Emir.h"
#include "Portfoy.h"
#include "Hisse.h"
#include <nlohmann/json.hpp>

int main() 
{
	Emir *emir = new Emir();
	Portfoy *portfoy = new Portfoy();
	Hisse* hisse = new Hisse();
	Emir emirObject;
	std::cout << "\n------------------";
	std::cout << "\n------------------";
	std::cout << "\nHISSELER";
	std::cout << "\n------------------";
	std::cout << "\n------------------" << std::endl;
	hisse->JsonOku();
	hisse->Yazdir();

	std::cout << "\n------------------";
	std::cout << "\n------------------";
	std::cout << "\nKULLANICI PORTFOYU";
	std::cout << "\n------------------";
	std::cout << "\n------------------" << std::endl;
	portfoy->JsonOku();
	portfoy->Yazdir();

	std::cout << "\n------------------";
	std::cout << "\n------------------";
	std::cout << "\nACIK EMIRLER";
	std::cout << "\n------------------";
	std::cout << "\n------------------" << std::endl;
	emir->JsonOku();
	emir->Yazdir(emir->VektorGetir());
	
	return 0;
}