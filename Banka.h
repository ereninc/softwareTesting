#pragma once
#include <string>
#include <vector>

using namespace std;
class Banka 
{
public:
	Banka();
	void DataCek();	
	void PortfoyveEmirCek();
	vector<string> emirSembolVektorGetir();
	vector<string> emirIslemVektorGetir();
	vector<int> emirAdetVektorGetir();
	vector<string> portfoySembolVektorGetir();
	vector<float> portfoyMaliyetVektorGetir();
	vector<float> portfoyToplamMaliyetVektorGetir();
	vector<int> portfoyAdetVektorGetir();
	void Yazdir();
private:
	int hisseBoyut;

	//banka bilgileri icin
	vector<string> sembolBankaVektor;
	vector<float> toplamMaliyetVektor;
	vector<float> guncelFiyatCarpiEmirAdetiVektor;
	vector<float> degisimVektor;

	//portfoy sinifindan gelecek datalar
	vector<string> portfoySembolVector;
	vector<float> portfoyMaliyetVector;
	vector<int> portfoyAdetVector;
	vector<float> portfoyToplamMaliyetVector;
	vector<string> emirSembolVector;
	vector<string> emirIslemVector;
	vector<int> emirAdetVector;

	//hisse sinifindan gelecek datalar
	vector<string> hisseSembolBankaVector;
	vector<float> hisseGuncelFiyatBankaVector;
};