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
	//Yazdir();
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

void Banka::Hesapla()
{
	Portfoy* portfoy = new Portfoy();
	int boyut = portfoy->BoyutGetir();
	std::cout << "Satislar Kar/Zarar" << std::endl;
	for (size_t i = 0; i < boyut-1; i++)
	{
		for (size_t j = 0; j < hisseBoyut - 1; j++)
		{
			if (portfoySembolVector.at(i) == hisseSembolBankaVector.at(j))
			{
				if (emirIslemVector.at(i) == "SATIS")
				{
					std::cout << sembolBankaVektor.at(i) << " : ";
					degisimVektor.push_back(guncelFiyatCarpiEmirAdetiVektor.at(i) - toplamMaliyetVektor.at(i));
					if (degisimVektor.at(i) > 0)
					{
						std::cout << degisimVektor.at(i) << " tl kar." << std::endl;
					}
					else if (degisimVektor.at(i) < 0)
					{
						std::cout << (-1) * degisimVektor.at(i) << " tl zarar." << std::endl;
					}
				}

				else if (emirIslemVector.at(i) == "ALIS")
				{
					std::cout << sembolBankaVektor.at(i) << ": ";
					degisimVektor.push_back((toplamMaliyetVektor.at(i) + guncelFiyatCarpiEmirAdetiVektor.at(i)) / (emirAdetVector.at(i) + portfoyAdetVector.at(i)));
					std::cout << "Adet : " << (emirAdetVector.at(i) + portfoyAdetVector.at(i)) << std::endl;
					std::cout << "Yeni Maliyet : " << degisimVektor.at(i) << std::endl;
				}
				if (portfoySembolVector.at(i) != emirSembolVector.at(i))
				{
					std::cout << "Hisse: " << emirSembolVector.at(i) << std::endl;
				}
			}
			
		}
	}
	float toplam = 0;
	for (size_t j = 0; j < degisimVektor.size() - 1; j++)
	{
		toplam += degisimVektor.at(j);
	}
	if (toplam > 0)
	{
		std::cout << "Toplam kar/zarar : +" << toplam << " TL" << std::endl;
	}
	else if (toplam < 0)
	{
		std::cout << "Toplam kar/zarar : -" << toplam << " TL" << std::endl;
	}
	
	
}

void Banka::PortfoyveEmirCek()
{
	Portfoy* portfoy = new Portfoy();
	int boyut = portfoy->BoyutGetir();
	//std::cout << "\nBANKA BILGILERI\n" << std::endl;
	for (int i = 0; i < boyut-1; i++)
	{
		emirSembolVector.push_back(portfoy->emirSembolVektorGetir().at(i));
		emirIslemVector.push_back(portfoy->emirIslemVektorGetir().at(i));
		emirAdetVector.push_back(portfoy->emirAdetVektorGetir().at(i));
		portfoySembolVector.push_back(portfoy->portfoySembolVektorGetir().at(i));
		portfoyMaliyetVector.push_back(portfoy->portfoyMaliyetVektorGetir().at(i));
		portfoyAdetVector.push_back(portfoy->portfoyAdetVektorGetir().at(i));
		portfoyToplamMaliyetVector.push_back(portfoy->portfoyToplamMaliyetGetir().at(i)); 

		//std::cout << "EMIR SEMBOL : " << emirSembolVector.at(i) << " - ISLEM : " << emirIslemVector.at(i) << " - ADET : " << emirAdetVector.at(i) << std::endl;
		//std::cout << "PORTFOY SEMBOL : " << portfoySembolVector.at(i) << " - MALIYET : " << portfoyMaliyetVector.at(i) << " - ADET : " << portfoyAdetVector.at(i) << " - TOPLAM MALIYET : " << portfoyToplamMaliyetVector.at(i) << std::endl;

		sembolBankaVektor.push_back(portfoy->emirSembolVektorGetir().at(i));
		toplamMaliyetVektor.push_back(portfoy->portfoyToplamMaliyetGetir().at(i));
		//std::cout << "Banka Sembol : " << sembolBankaVektor.at(i) << " - Toplam Maliyet : " << toplamMaliyetVektor.at(i) << std::endl;
		for (size_t j = 0; j < hisseBoyut-1; j++)
		{
			if (sembolBankaVektor.at(i) == hisseSembolBankaVector.at(j))
			{
				guncelFiyatCarpiEmirAdetiVektor.push_back(emirAdetVector.at(i) * hisseGuncelFiyatBankaVector.at(j));
				//std::cout << "Guncel Fiyat ("<<hisseGuncelFiyatBankaVector.at(j)<<") * Emir Adet ("<< emirAdetVector.at(i)<<") : " << guncelFiyatCarpiEmirAdetiVektor.at(i) << std::endl;
				//std::cout << "------------------------------" << std::endl;
			}
		}
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