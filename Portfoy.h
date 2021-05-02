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
	vector<string> portfoyVector;
	void EmirCek();
	void Karsilastir(vector<string> vector1, vector<string> vector2);
	void Yazdir();
	vector<string> emirSembolVector;
	vector<string> emirIslemVector;
	vector<int> emirAdetVector;
private:
	string id;
	string sembol;
	float maliyet;
	int adet;
};