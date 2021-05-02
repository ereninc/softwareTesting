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

vector<string> Portfoy::EmirVektoruAl(Emir *emir)
{
	return emir->VektorGetir();
}

void Portfoy::Oku()
{
	Emir* emir = new Emir();
	int boyut = emir->VektorBoyutuAl();
	for (int i = 0; i < boyut*4; i++)
	{
		tempVec.push_back(emir->VektorGetir().at(i));
		std::cout << tempVec.at(i) << std::endl;
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
	Karsilastir(tempVec, portfoyVector);
	/*for (auto &i : portfoyVector)
	{
		std::cout << i << std::endl;
	}*/
}
