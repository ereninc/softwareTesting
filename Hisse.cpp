/**
*
* @author Erencan İNANCI - erencan.inanci@ogr.sakarya.edu.tr
* @since ‎2 ‎Mayıs ‎2021 ‎Pazar, ‏‎20:54:57
* <p>
* Hisse sınıfı. Bu sınıf sadece hisseler.json'dan dönen verileri kullanacağım 2 farklı vektörde depoluyor
* </p>
*/

#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

Hisse::Hisse()
{
	JsonOku();
}

void Hisse::JsonOku()
{
	std::ifstream jsonFile("hisseler.json");
	json j;
	jsonFile >> j;
	json hisseler = j["Hisseler"];
	boyut = hisseler.size();
	for (int i = 0; i < boyut; i++)
	{
		this->id = hisseler.at(i).at("_id").get<string>(); //kullanmayacagim
		this->sembol = hisseler.at(i).at("Sembol").get<string>();
		this->ad = hisseler.at(i).at("Ad").get<string>(); //kullanmayacagim
		this->fiyat = hisseler.at(i).at("Fiyat").get<float>();

		hisseSembolVector.push_back(sembol);
		hisseFiyatVector.push_back(fiyat);
	}
}

vector<string> Hisse::hisseSembolVektorGetir()
{
	return vector<string>(this->hisseSembolVector);
}

vector<float> Hisse::hisseSembolFiyatGetir()
{
	return vector<float>(this->hisseFiyatVector);
}

int Hisse::BoyutGetir()
{
	return boyut;
}