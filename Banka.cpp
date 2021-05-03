#include "Banka.h"
#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

Banka::Banka()
{
	DataCek();
	Yazdir();
	PortfoyveEmirCek();
}

void Banka::DataCek()
{
	Hisse* hisse = new Hisse();
	Emir* emir = new Emir();
	Portfoy* portfoy = new Portfoy();
	hisseBoyut = hisse->BoyutGetir();
	int portfoyBoyut = portfoy->BoyutGetir();
	for (int i = 0; i < hisseBoyut; i++)
	{
		hisseSembolBankaVector.push_back(hisse->hisseSembolVektorGetir().at(i));
		hisseGuncelFiyatBankaVector.push_back(hisse->hisseSembolFiyatGetir().at(i));
	}
}

void Banka::Yazdir()
{
	std::cout << "HISSELER\n" << std::endl;
	for (size_t i = 0; i < hisseBoyut; i++)
	{
		std::cout << "MARKA : " << hisseSembolBankaVector.at(i) << " - GUNCEL FIYAT : " << hisseGuncelFiyatBankaVector.at(i) << std::endl;
	}
}

void Banka::PortfoyveEmirCek()
{
	Portfoy* portfoy = new Portfoy();
	int boyut = portfoy->BoyutGetir();
	std::cout << "\nBANKA BILGILERI\n" << std::endl;
	for (int i = 0; i < boyut-1; i++)
	{
		emirSembolVector.push_back(portfoy->emirSembolVektorGetir().at(i));
		emirIslemVector.push_back(portfoy->emirIslemVektorGetir().at(i));
		emirAdetVector.push_back(portfoy->emirAdetVektorGetir().at(i));
		portfoySembolVector.push_back(portfoy->portfoySembolVektorGetir().at(i));
		portfoyMaliyetVector.push_back(portfoy->portfoyMaliyetVektorGetir().at(i));
		portfoyAdetVector.push_back(portfoy->portfoyAdetVektorGetir().at(i));
		portfoyToplamMaliyetVector.push_back(portfoy->portfoyToplamMaliyetGetir().at(i)); 

		std::cout << "EMIR SEMBOL : " << emirSembolVector.at(i) << " - ISLEM : " << emirIslemVector.at(i) << " - ADET : " << emirAdetVector.at(i) << std::endl;
		std::cout << "PORTFOY SEMBOL : " << portfoySembolVector.at(i) << " - MALIYET : " << portfoyMaliyetVector.at(i) << " - ADET : " << portfoyAdetVector.at(i) << " - TOPLAM MALIYET : " << portfoyToplamMaliyetVector.at(i) << std::endl;
	}
}


vector<string> Banka::emirSembolVektorGetir()
{
	return vector<string>(this->emirSembolVector);
}

vector<string> Banka::emirIslemVektorGetir()
{
	return vector<string>(this->emirIslemVector);
}

vector<int> Banka::emirAdetVektorGetir()
{
	return vector<int>(this->emirAdetVector);
}

vector<string> Banka::portfoySembolVektorGetir()
{
	return vector<string>(this->portfoySembolVector);
}

vector<float> Banka::portfoyMaliyetVektorGetir()
{
	return vector<float>(this->portfoyMaliyetVector);
}

vector<float> Banka::portfoyToplamMaliyetVektorGetir()
{
	return vector<float>(this->portfoyToplamMaliyetVector);
}

vector<int> Banka::portfoyAdetVektorGetir()
{
	return vector<int>(this->portfoyAdetVector);
}
