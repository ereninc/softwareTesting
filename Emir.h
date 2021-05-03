#pragma once
#include <string>
#include <vector>

using namespace std;
class Emir 
{
public:
	Emir();
	void JsonOku();
	vector<string> sembolVektorGetir();
	vector<string> islemVektorGetir();
	vector<int> adetVektorGetir();
	int VektorBoyutuAl();
private:
	int boyut = 0;
	std::vector<std::string> sembolVector;
	std::vector<std::string> islemVector;
	std::vector<int> adetVector;
	std::string id;
	std::string sembol;
	std::string islem;
	int adet;
};