/**
*
* @author Erencan İNANCI - erencan.inanci@ogr.sakarya.edu.tr
* @since ‎2 ‎Mayıs ‎2021 ‎Pazar, ‏‎20:54:57
* <p>
* Portfoy sınıfının başlık dosyası. Fonksiyon başlıkları ve kullanılan private fieldlar 
* burada tanımlandı.
* </p>
*/

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
	vector<string> portfoySembolVector;
	vector<float> portfoyMaliyetVector;
	vector<int> portfoyAdetVector;
	vector<float> portfoyToplamMaliyetVector;
private:
	int boyut = 0;
	vector<string> emirSembolVector;
	vector<string> emirIslemVector;
	vector<int> emirAdetVector;
	string id;
	string sembol;
	float maliyet;
	int adet;
};