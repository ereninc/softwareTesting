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
	std::vector<std::string> emirVector;
private:
	std::string id;
	std::string sembol;
	std::string islem;
	int adet;
};