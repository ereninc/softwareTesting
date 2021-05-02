#pragma once
#include <string>
#include <vector>

class Hisse 
{
public:
	Hisse();
	void JsonOku();
	void Yazdir();
private:
	std::string id;
	std::string sembol;
	std::string ad;
	float fiyat;
};