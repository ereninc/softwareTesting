#include <iostream>
#include "Emir.h"
#include "Portfoy.h"
#include "Hisse.h"
#include <nlohmann/json.hpp>

int main() 
{
	Portfoy *portfoy = new Portfoy();

	portfoy->JsonOku();
	portfoy->EmirCek();
	portfoy->Yazdir();
	
	return 0;
}