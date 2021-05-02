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
	Yazdir();
}

void Hisse::JsonOku()
{
	std::ifstream jsonFile("hisseler.json");
	json j;
	jsonFile >> j;
	json hisseler = j["Hisseler"];
	for (int i = 0; i < hisseler.size(); i++)
	{
		this->id = hisseler.at(i).at("_id").get<string>(); //kullanmayacagim
		this->sembol = hisseler.at(i).at("Sembol").get<string>();
		this->ad = hisseler.at(i).at("Ad").get<string>(); //kullanmayacagim
		this->fiyat = hisseler.at(i).at("Fiyat").get<float>();

		hisseSembolVector.push_back(sembol);
		hisseFiyatVector.push_back(fiyat);
	}
}

void Hisse::PortfoyveEmirCek()
{
	Portfoy* portfoy = new Portfoy();
	int boyut = portfoy->BoyutGetir();
	for (int i = 0; i < boyut; i++)
	{
		emirSembolVector.push_back(portfoy->emirSembolVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		emirIslemVector.push_back(portfoy->emirIslemVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		emirAdetVector.push_back(portfoy->emirAdetVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		portfoySembolVector.push_back(portfoy->portfoySembolVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		portfoyMaliyetVector.push_back(portfoy->portfoyMaliyetVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		portfoyAdetVector.push_back(portfoy->portfoyAdetVektorGetir().at(i));
	}
}

void Hisse::Yazdir()
{
	for (size_t i = 0; i < hisseSembolVector.size(); i++)
	{
		std::cout << "HISSE ADI : " << hisseSembolVector.at(i);
		std::cout << " - GUNCEL FIYAT : " << hisseFiyatVector.at(i) << std::endl;
	}
}
