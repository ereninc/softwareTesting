/**
*
* @author Erencan İNANCI - erencan.inanci@ogr.sakarya.edu.tr
* @since ‎2 ‎Mayıs ‎2021 ‎Pazar, ‏‎20:54:57
* <p>
* Main sınıfım, banka sınıfımdan bir nesne yardımıyla işlemleri yaptırıyor.
* </p>
*/

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