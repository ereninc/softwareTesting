#pragma once
#include <string>
#include <vector>

using namespace std;
class Hisse 
{
public:
	Hisse();
	void JsonOku();
	void PortfoyveEmirCek();
	void Yazdir();

	vector<string> emirSembolVektorGetir();
	vector<string> emirIslemVektorGetir();
	vector<int> emirAdetVektorGetir();
	vector<string> portfoySembolVektorGetir();
	vector<float> portfoyMaliyetVektorGetir();
	vector<int> portfoyAdetVektorGetir();
	vector<string> hisseSembolVektorGetir();
	vector<float> hisseSembolFiyatGetir();
	int BoyutGetir();

private:
	int boyut = 0;
	vector<string> hisseSembolVector;
	vector<float> hisseFiyatVector;

	vector<string> portfoySembolVector;
	vector<float> portfoyMaliyetVector;
	vector<int> portfoyAdetVector;
	vector<string> emirSembolVector;
	vector<string> emirIslemVector;
	vector<int> emirAdetVector;
	std::string id;
	std::string sembol;
	std::string ad;
	float fiyat;
};