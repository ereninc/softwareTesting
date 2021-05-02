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
private:
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