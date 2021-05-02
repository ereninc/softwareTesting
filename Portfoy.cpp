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
}

void Portfoy::JsonOku()
{
	std::ifstream jsonFile("portfoy.json");
	json j;
	jsonFile >> j;
	json portfoy = j["Portfoy"];
	for (int i = 0; i < portfoy.size(); i++)
	{
		this->id = portfoy.at(i).at("_id").get<string>();
		this->sembol = portfoy.at(i).at("Sembol").get<string>();
		this->maliyet = portfoy.at(i).at("Maliyet").get<float>();
		this->adet = portfoy.at(i).at("Adet").get<int>();
		portfoyVector.push_back(id);
		portfoyVector.push_back(sembol);
		stringstream ss;
		ss << maliyet;
		portfoyVector.push_back(ss.str());
		stringstream sa;
		sa << adet;
		portfoyVector.push_back(sa.str());
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
	for (auto &i : vector1)
	{
		for (auto &j : vector2)
		{
			if (i == j)
			{
				std::cout << i << std::endl;
			}
		}
	}
}

void Portfoy::Yazdir()
{
	Karsilastir(emirSembolVector, portfoyVector);
}
