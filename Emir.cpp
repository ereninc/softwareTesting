#include "Emir.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

Emir::Emir()
{
}

void Emir::JsonOku()
{
	std::ifstream jsonFile("emirler.json");
	json j;
	jsonFile >> j;
	json emirler = j["Emirler"];
	for (int i = 0; i < emirler.size(); i++)
	{
		this->id = emirler.at(i).at("_id").get<string>();
		this->sembol = emirler.at(i).at("Sembol").get<string>();
		this->islem = emirler.at(i).at("Islem").get<string>();
		this->adet = emirler.at(i).at("Adet").get<int>();
		emirVector.push_back(id);
		emirVector.push_back(sembol);
		emirVector.push_back(islem);
		stringstream ss;
		ss << adet;
		emirVector.push_back(ss.str());
	}
}

const void Emir::Yazdir(vector<string> const &vector)
{
	for (auto &i : vector)
	{
		std::cout << i << std::endl;
	}
}

vector<string> Emir::VektorGetir()
{
	return vector<string>(this->emirVector);
}