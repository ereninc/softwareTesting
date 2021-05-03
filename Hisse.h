/**
*
* @author Erencan İNANCI - erencan.inanci@ogr.sakarya.edu.tr
* @since ‎2 ‎Mayıs ‎2021 ‎Pazar, ‏‎20:54:57
* <p>
* Hisse sınıfının başlık dosyası, değişkenler ve fonksiyon başlıkları burada tanımlandı.
* </p>
*/

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