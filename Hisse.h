#pragma once
#include <string>
#include <vector>

using namespace std;
class Hisse 
{
public:
	Hisse();
	void JsonOku();
	vector<string> hisseSembolVektorGetir();
	vector<float> hisseSembolFiyatGetir();
	int BoyutGetir();
private:
	int boyut = 0;
	vector<string> hisseSembolVector;
	vector<float> hisseFiyatVector;
	std::string id;
	std::string sembol;
	std::string ad;
	float fiyat;
};