/**
*
* @author Erencan İNANCI - erencan.inanci@ogr.sakarya.edu.tr
* @since ‎2 ‎Mayıs ‎2021 ‎Pazar, ‏‎20:54:57
* <p>
* Portfoy sınıfı. Portfoy json dosyasından dönen verileri burada vektörlere yerleştirip emir 
* sınıfından dönen vektörleri burada başka vektörlere yerleştirdim.
* </p>
*/

#include "Portfoy.h"
#include "Emir.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

Portfoy::Portfoy() 
{
	this->adet = 0;
	this->maliyet = 0.0f;
	JsonOku();
	EmirCek();
}

void Portfoy::JsonOku()
{
	std::ifstream jsonFile("portfoy.json");
	json j;
	jsonFile >> j;
	json portfoy = j["Portfoy"];
	boyut = portfoy.size();
	for (int i = 0; i < portfoy.size(); i++)
	{
		this->id = portfoy.at(i).at("_id").get<string>(); //kullanmayacagim
		this->sembol = portfoy.at(i).at("Sembol").get<string>();
		this->maliyet = portfoy.at(i).at("Maliyet").get<float>();
		this->adet = portfoy.at(i).at("Adet").get<int>();

		portfoySembolVector.push_back(sembol);
		portfoyMaliyetVector.push_back(maliyet);
		portfoyAdetVector.push_back(adet);

		int adt = adet;
		float mlyt = maliyet;
		portfoyToplamMaliyetVector.push_back(adt*mlyt);
	}
}

void Portfoy::EmirCek()
{
	Emir* emir = new Emir();
	int boyut = emir->VektorBoyutuAl();
	for (int i = 0; i < boyut; i++)
	{
		emirSembolVector.push_back(emir->sembolVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		emirIslemVector.push_back(emir->islemVektorGetir().at(i));
	}

	for (int i = 0; i < boyut; i++)
	{
		emirAdetVector.push_back(emir->adetVektorGetir().at(i));
	}
}

void Portfoy::Karsilastir(vector<string> vector1, vector<string> vector2)
{
	for (size_t i = 0; i < vector1.size(); i++)
	{
		for (size_t j = 0; j < vector2.size(); j++)
		{
			if (vector1.at(i) == vector2.at(j))
			{
				std::cout << "EMIRLER" << std::endl;
				std::cout << "SEMBOL : " << vector1.at(i) << std::endl;
				std::cout << "ISLEM : " << emirIslemVector.at(i) << std::endl;
				std::cout << "ADET : " << emirAdetVector.at(i) << std::endl;

				std::cout << std::endl;
				std::cout << "PORTFOY" << std::endl;
				std::cout << "SEMBOL : " << vector2.at(i) << std::endl;
				/*std::cout << "MALIYET : " << portfoyMaliyetVector.at(i) << std::endl;
				std::cout << "ADET : " << portfoyAdetVector.at(i) << std::endl;*/
				std::cout << "TOPLAM MALIYET : " << portfoyToplamMaliyetVector.at(i) << std::endl;
				std::cout << "----------" << std::endl;
			}
		}
	}
}

void Portfoy::Yazdir()
{
	//Karsilastir(emirSembolVector, portfoySembolVector);
	for (auto &i : portfoySembolVector)
	{
		std::cout << i << std::endl;
	}
}

vector<string> Portfoy::emirSembolVektorGetir()
{
	return vector<string>(this->emirSembolVector);
}

vector<string> Portfoy::emirIslemVektorGetir()
{
	return vector<string>(this->emirIslemVector);
}

vector<int> Portfoy::emirAdetVektorGetir()
{
	return vector<int>(this->emirAdetVector);
}

vector<string> Portfoy::portfoySembolVektorGetir()
{
	return vector<string>(this->portfoySembolVector);
}

vector<float> Portfoy::portfoyMaliyetVektorGetir()
{
	return vector<float>(this->portfoyMaliyetVector);
}

vector<int> Portfoy::portfoyAdetVektorGetir()
{
	return vector<int>(this->portfoyAdetVector);
}

vector<float> Portfoy::portfoyToplamMaliyetGetir()
{
	return vector<float>(this->portfoyToplamMaliyetVector);
}

int Portfoy::BoyutGetir()
{
	return boyut;
}