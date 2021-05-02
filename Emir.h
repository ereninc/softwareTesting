#pragma once
#include <string>
#include <vector>

using namespace std;
class Emir 
{
public:
	Emir();
	void JsonOku();
	const void Yazdir(vector<string> const &vector);
	vector<string> VektorGetir();
	int VektorBoyutuAl();
private:
	int boyut = 0;
	std::vector<std::string> emirVector;
	std::string id;
	std::string sembol;
	std::string islem;
	int adet;
};