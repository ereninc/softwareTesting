#include <iostream>
#include "Emir.h"
#include "Portfoy.h"
#include "Hisse.h"
#include "Banka.h"
#include <nlohmann/json.hpp>

int main() 
{
	Banka* banka = new Banka();
	banka->Hesapla();
	return 0;
}