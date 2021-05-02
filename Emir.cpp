#include "Emir.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

Emir::Emir()
{
	JsonOku();
}

void Emir::JsonOku()
{
	std::ifstream jsonFile("emirler.json");
	json j;
	jsonFile >> j;
	json emirler = j["Emirler"];
	boyut = emirler.size();
	for (int i = 0; i < emirler.size(); i++)
	{
		this->id = emirler.at(i).at("_id").get<string>(); //kullanmayacagim
		this->sembol = emirler.at(i).at("Sembol").get<string>();
		this->islem = emirler.at(i).at("Islem").get<string>();
		this->adet = emirler.at(i).at("Adet").get<int>();

		sembolVector.push_back(sembol);
		islemVector.push_back(islem);
		adetVector.push_back(adet);
	}
}

vector<string> Emir::sembolVektorGetir()
{
	return vector<string>(this->sembolVector);
}

vector<string> Emir::islemVektorGetir()
{
	return vector<string>(this->islemVector);
}

vector<int> Emir::adetVektorGetir()
{
	return vector<int>(this->adetVector);
}

int Emir::VektorBoyutuAl()
{
	return boyut;
}
