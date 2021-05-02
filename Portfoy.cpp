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
vector<string> portfoyVector;

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


void Portfoy::Yazdir()
{
	for (auto &i : portfoyVector)
	{
		std::cout << i << std::endl;
	}
}
