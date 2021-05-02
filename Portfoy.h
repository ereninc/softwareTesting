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
	vector<string> EmirVektoruAl(Emir* emir);
	vector<string> portfoyVector;
	void Oku();
	void Karsilastir(vector<string> vector1, vector<string> vector2);
	void Yazdir();
	vector<string> tempVec;
private:
	string id;
	string sembol;
	float maliyet;
	int adet;
};