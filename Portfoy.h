#pragma once
#include <string>
#include <vector>
#include "Emir.h"

using namespace std;
class Portfoy
{
public:
	Portfoy();
	void JsonOku();
	void EmirCek();
	void Karsilastir(vector<string> vector1, vector<string> vector2);
	void Yazdir();
	vector<string> emirSembolVektorGetir();
	vector<string> emirIslemVektorGetir();
	vector<int> emirAdetVektorGetir();
	vector<string> portfoySembolVektorGetir();
	vector<float> portfoyMaliyetVektorGetir();
	vector<int> portfoyAdetVektorGetir();
	vector<float> portfoyToplamMaliyetGetir();
	int BoyutGetir();
private:
	int boyut = 0;
	vector<string> portfoySembolVector;
	vector<float> portfoyMaliyetVector;
	vector<int> portfoyAdetVector;
	vector<float> portfoyToplamMaliyetVector;
	vector<string> emirSembolVector;
	vector<string> emirIslemVector;
	vector<int> emirAdetVector;
	string id;
	string sembol;
	float maliyet;
	int adet;
};