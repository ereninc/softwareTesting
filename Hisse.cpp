#include "Hisse.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;
vector<string> hisseVector;

Hisse::Hisse()
{
}

void Hisse::JsonOku()
{
	std::ifstream jsonFile("hisseler.json");
	json j;
	jsonFile >> j;
	json hisseler = j["Hisseler"];
	for (int i = 0; i < hisseler.size(); i++)
	{
		this->id = hisseler.at(i).at("_id").get<string>();
		this->sembol = hisseler.at(i).at("Sembol").get<string>();
		this->ad = hisseler.at(i).at("Ad").get<string>();
		this->fiyat = hisseler.at(i).at("Fiyat").get<float>();

		hisseVector.push_back(id);
		hisseVector.push_back(sembol);
		hisseVector.push_back(ad);
		stringstream ss;
		ss << fiyat;
		hisseVector.push_back(ss.str());
	}
}

void Hisse::Yazdir()
{
	for (auto &i : hisseVector)
	{
		std::cout << i << std::endl;
	}
}
