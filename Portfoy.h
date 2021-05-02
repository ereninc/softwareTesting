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
	vector<string> EmirVektoruAl(Emir *emir);
	void Yazdir();
private:
	string id;
	string sembol;
	float maliyet;
	int adet;
};