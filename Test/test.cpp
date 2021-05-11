#include "pch.h"
#include "../Emir.h"
#include "../Portfoy.h"
#include "../Hisse.h"
#include "../Banka.h"
#include <typeinfo>


#pragma region EmirTestleri

//Pointer nesne gosteriyor mu
TEST(EmirTest, EmirNesneTest) {
	bool nesneOlustu = false;
	Emir* emir = new Emir();
	if (emir != nullptr)
	{
		nesneOlustu = true;
	}
	ASSERT_TRUE(nesneOlustu);
	delete emir;
}

//Okunan emirlerin sayisi dosyadaki emirlerin sayisi ile uyuyor mu
TEST(EmirTest, EmirIslemAdetTest) {
	Emir* emir = new Emir();
	ASSERT_EQ(3, emir->VektorBoyutuAl());
	delete emir;
}

//Ilk verilen emir akbank mi
TEST(EmirTest, EmirIlkSembolTest) {
	Emir* emir = new Emir();
	ASSERT_STREQ("AKBNK", emir->sembolVector.at(0).c_str());
	delete emir;
}

//Alis emri verilmis mi
TEST(EmirTest, EmirIslemlerTest) {
	Emir* emir = new Emir();
	string islem[] = {"ALIS", "SATIS"};
	for (auto i : islem)
	{
		ASSERT_STREQ("ALIS", i.c_str());
	}
	delete emir;
}

//Verilen emirde yanlis islem girisi var mi
TEST(EmirTest, EmirIslemlerYanlisGirisTest) {
	Emir* emir = new Emir();
	bool emirTest = true;
	for (size_t i = 0; i < emir->boyut; i++)
	{
		if (emir->islemVector.at(i) != "ALIS" || emir->islemVector.at(i) != "SATIS")
		{
			emirTest = false;
		}
	}
	ASSERT_FALSE(emirTest);
	delete emir;
}

//Girilen marka adi string mi
TEST(EmirTest, EmirIslemVeriTipiTest) {
	Emir* emir = new Emir();
	auto& tip = (typeid("a"));
	auto& islemTip = (typeid(emir->islemVector.at(0)));
	ASSERT_EQ(&tip, &islemTip);
	delete emir;
}

//Girilen adet int mi
TEST(EmirTest, EmirAdetiVeriTipiTest) {
	Emir* emir = new Emir();
	auto& tip = (typeid(1));
	auto& islemTip = (typeid(emir->adet));
	ASSERT_EQ(&tip, &islemTip);
	delete emir;
}

//Ilk verilen emrin islemi satis mi
TEST(EmirTest, EmirIlkIslemTesti) {
	Emir* emir = new Emir();
	ASSERT_STREQ("SATIS", emir->islemVector.at(0).c_str());
	delete emir;
}

//Ilk verilen emir verileri dogru mu
TEST(EmirTest, EmirIlkEmirVeriTest) {
	Emir* emir = new Emir();
	bool emirTest = false;
	if (emir->sembolVector.at(0).c_str() == "AKBNK" && emir->islemVector.at(0).c_str() == "SATIS")
	{
		emirTest = true;
	}
	ASSERT_TRUE(emirTest);
	delete emir;
}

//Son verilen emir verileri dogru mu
TEST(EmirTest, EmirSonEmirVeriTest) {
	Emir* emir = new Emir();
	bool emirTest = false;
	if (emir->sembolVector.at(emir->boyut).c_str() == "TATGD" && emir->islemVector.at(emir->boyut).c_str() == "ALIS")
	{
		emirTest = true;
	}
	ASSERT_TRUE(emirTest);
	delete emir;
}

//Emir adetleri dogru mu testi
TEST(EmirTest, EmirAdetleriTest) {
	Emir* emir = new Emir();
	int verilenEmirAdetleri[3] = { 200, 120, 250 };
	int eslesmeSayac = 0;
	bool kompleEslesme = false;
	for (size_t i = 0; i < 2; i++)
	{
		if (emir->adetVector.at(i) == verilenEmirAdetleri[i])
		{
			eslesmeSayac++;
			if (eslesmeSayac == 3)
			{
				kompleEslesme = true;
			}
		}
	}
	ASSERT_TRUE(kompleEslesme);
	delete emir;
}

TEST(EmirTest, EmirSembolVektorDegerDondurmeTest) {
	Emir* emir = new Emir();
	auto geciciVektor = emir->sembolVektorGetir();
	bool degerGeldi = false;
	if (!geciciVektor.empty())
	{
		degerGeldi = true;
	}
	ASSERT_TRUE(degerGeldi);
	delete emir;
}

TEST(EmirTest, EmirIslemVektorDegerDondurmeTest) {
	Emir* emir = new Emir();
	auto geciciVektor = emir->islemVektorGetir();
	bool degerGeldi = false;
	if (!geciciVektor.empty())
	{
		degerGeldi = true;
	}
	ASSERT_TRUE(degerGeldi);
	delete emir;
}

TEST(EmirTest, EmirAdetVektorDegerDondurmeTest) {
	Emir* emir = new Emir();
	auto geciciVektor = emir->adetVektorGetir();
	bool degerGeldi = false;
	if (!geciciVektor.empty())
	{
		degerGeldi = true;
	}
	ASSERT_TRUE(degerGeldi);
	delete emir;
}

#pragma endregion

#pragma region PortfoyTestleri

TEST(PortfoyTest, PortfoyNesneTesti) {
	bool nesneOlustu = false;
	Portfoy* portfoy = new Portfoy();
	if (portfoy != nullptr)
	{
		nesneOlustu = true;
	}
	ASSERT_TRUE(nesneOlustu);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyAdetTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_EQ(4, portfoy->BoyutGetir());
	delete portfoy;
}

TEST(PortfoyTest, PortfoyIlkSembolTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_STREQ("AKBNK", portfoy->portfoySembolVector.at(0).c_str());
	delete portfoy;
}

TEST(PortfoyTest, PortfoyIlkMaliyetTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_EQ(3.15f, portfoy->portfoyMaliyetVector.at(0));
	delete portfoy;
}

TEST(PortfoyTest, PortfoyIlkAdetiTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_EQ(200, portfoy->portfoyAdetVector.at(0));
	delete portfoy;
}

TEST(PortfoyTest, PortfoyMaliyetlerTest) {
	Portfoy* portfoy = new Portfoy();
	float maliyetler[] = { 3.15f, 16.25f, 8.5f, 86.5f };
	bool hepsiEslesti = false;
	int eslesmeSayac = 0;
	for (size_t i = 0; i < 3; i++)
	{
		if (portfoy->portfoyMaliyetVector.at(i) == maliyetler[i])
		{
			eslesmeSayac++;
			if (eslesmeSayac == 4) hepsiEslesti = true;
		}
	}
	ASSERT_TRUE(hepsiEslesti);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyMaliyetVeriTipiTest) {
	Portfoy* portfoy = new Portfoy();
	auto& tip = (typeid(3.15f));
	auto& islemTip = (typeid(portfoy->portfoyMaliyetVector.at(0)));
	ASSERT_EQ(&tip, &islemTip);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyAdetVeriTipiTest) {
	Portfoy* portfoy = new Portfoy();
	auto& tip = (typeid(1));
	auto& islemTip = (typeid(portfoy->portfoyAdetVector.at(0)));
	ASSERT_EQ(&tip, &islemTip);
	delete portfoy;
}

TEST(PortfoyTest, PortfoySahipOlunanHisseAdetiTesti1) {
	Portfoy* portfoy = new Portfoy();
	bool portfoyTest = false;
	if (portfoy->portfoySembolVector.at(0).c_str() == "AKBNK" && portfoy->portfoyAdetVector.at(0) == 200)
	{
		portfoyTest = true;
	}
	ASSERT_TRUE(portfoyTest);
	delete portfoy;
}

TEST(PortfoyTest, PortfoySahipOlunanHisseAdetiTesti2) {
	Portfoy* portfoy = new Portfoy();
	bool portfoyTest = false;
	if (portfoy->portfoySembolVector.at(3).c_str() == "TUPRS" && portfoy->portfoyAdetVector.at(3) == 1100)
	{
		portfoyTest = true;
	}
	ASSERT_TRUE(portfoyTest);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyHisseAdetleriToplamTest) {
	Portfoy* portfoy = new Portfoy();
	int hisseAdetleri[4] = { 200, 120, 500, 1100 };
	int eslesmeSayac = 0;
	bool kompleEslesme = false;
	for (size_t i = 0; i < 2; i++)
	{
		if (portfoy->portfoyAdetVector.at(i) == hisseAdetleri[i])
		{
			eslesmeSayac++;
			if (eslesmeSayac == 4)
			{
				kompleEslesme = true;
			}
		}
	}
	ASSERT_TRUE(kompleEslesme);
	delete portfoy;
}

TEST(PortfoyTest, PortfoySembolVektorDegerDondurmeTest) {
	Portfoy* portfoy = new Portfoy();
	auto geciciVektor = portfoy->portfoySembolVektorGetir();
	bool degerGeldi = false;
	if (!geciciVektor.empty())
	{
		degerGeldi = true;
	}
	ASSERT_TRUE(degerGeldi);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyMaliyetVektorDegerDondurmeTest) {
	Portfoy* portfoy = new Portfoy();
	auto geciciVektor = portfoy->portfoyMaliyetVektorGetir();
	bool degerGeldi = false;
	if (!geciciVektor.empty())
	{
		degerGeldi = true;
	}
	ASSERT_TRUE(degerGeldi);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyAdetVektorDegerDondurmeTest) {
	Portfoy* portfoy = new Portfoy();
	auto geciciVektor = portfoy->portfoyAdetVektorGetir();
	bool degerGeldi = false;
	if (!geciciVektor.empty())
	{
		degerGeldi = true;
	}
	ASSERT_TRUE(degerGeldi);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyaGelenEmirVektorDegerDondurmeSembolTest) {
	Portfoy* portfoy = new Portfoy();
	auto geciciVektor = portfoy->emirSembolVektorGetir();
	bool digerClasstanDegerGeldi = false;
	if (!geciciVektor.empty())
	{
		digerClasstanDegerGeldi = true;
	}
	ASSERT_TRUE(digerClasstanDegerGeldi);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyaGelenEmirVektorDegerDondurmeIslemTest) {
	Portfoy* portfoy = new Portfoy();
	auto geciciVektor = portfoy->emirIslemVektorGetir();
	bool digerClasstanDegerGeldi = false;
	if (!geciciVektor.empty())
	{
		digerClasstanDegerGeldi = true;
	}
	ASSERT_TRUE(digerClasstanDegerGeldi);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyaGelenEmirVektorDegerDondurmeAdetTest) {
	Portfoy* portfoy = new Portfoy();
	auto geciciVektor = portfoy->emirAdetVektorGetir();
	bool digerClasstanDegerGeldi = false;
	if (!geciciVektor.empty())
	{
		digerClasstanDegerGeldi = true;
	}
	ASSERT_TRUE(digerClasstanDegerGeldi);
	delete portfoy;
}

TEST(PortfoyTest, PortfoyToplamMaliyetHesaplandiMiTest) {
	Portfoy* portfoy = new Portfoy();
	bool hesaplamaYapildi = false;
	if (!portfoy->portfoyToplamMaliyetVector.empty())
	{
		hesaplamaYapildi = true;
	}
	ASSERT_TRUE(hesaplamaYapildi);
	delete portfoy;
}

#pragma endregion

#pragma region HisseTest

TEST(HisseTest, HisseAdeti) {
	Hisse* hisse = new Hisse();
	ASSERT_EQ(100, hisse->BoyutGetir());
	delete hisse;
}

TEST(HisseTest, HisseIlkKontrolTest) {
	Hisse* hisse = new Hisse();
	ASSERT_STREQ("AEFES", hisse->hisseSembolVector.at(0).c_str());
	delete hisse;
}

TEST(HisseTest, HisseOnuncuVeriKontrolTest) {
	Hisse* hisse = new Hisse();
	ASSERT_STREQ("ARCLK", hisse->hisseSembolVector.at(10).c_str());
	delete hisse;
}

TEST(HisseTest, HisseBirinciFiyatKontrolTest) {
	Hisse* hisse = new Hisse();
	ASSERT_EQ(22.74f, hisse->hisseFiyatVector.at(0));
	delete hisse;
}

TEST(HisseTest, HisseVerileriKontrolTesti1) {
	Hisse* hisse = new Hisse();
	bool eslesme = false;
	if (hisse->hisseSembolVector.at(5).c_str() == "AKSGY" && hisse->hisseFiyatVector.at(5) == 1.75f)
	{
		eslesme = true;
	}
	ASSERT_TRUE(eslesme);
	delete hisse;
}

TEST(HisseTest, HisseVerileriKontrolTesti2) {
	Hisse* hisse = new Hisse();
	bool eslesme = false;
	if (hisse->hisseSembolVector.at(88).c_str() == "TSKB" && hisse->hisseFiyatVector.at(88) == 1.21f)
	{
		eslesme = true;
	}
	ASSERT_TRUE(eslesme);
	delete hisse;
}

TEST(HisseTest, HisseFiyatlariVeriTipiDogruMuGirildiTest) {
	Hisse* hisse = new Hisse();
	bool eslesme = false;
	int eslesmeSayac = 0;
	auto& tip = (typeid(1.0f));
	for (size_t i = 0; i < hisse->BoyutGetir() - 1; i++)
	{
		if ((typeid(hisse->hisseFiyatVector.at(i)) == tip))
		{
			eslesmeSayac++;
			if (eslesmeSayac == 100)
			{
				eslesme = true;
			}
		}
	}
	ASSERT_TRUE(eslesme);
	delete hisse;
}


TEST(HisseTest, HisseSemboliVeriTipiDogruMuGirildiTest) {
	Hisse* hisse = new Hisse();
	bool eslesme = false;
	int eslesmeSayac = 0;
	auto& tip = (typeid("A"));
	for (size_t i = 0; i < hisse->BoyutGetir() - 1; i++)
	{
		if ((typeid(hisse->hisseSembolVector.at(i)) == tip))
		{
			eslesmeSayac++;
			if (eslesmeSayac == 100)
			{
				eslesme = true;
			}
		}
	}
	ASSERT_TRUE(eslesme);
	delete hisse;
}

#pragma endregion

#pragma region BankaTest

TEST(BankaTest, BankaHesaplamaNesne) {
	Banka* banka = new Banka();
	bool nesneGosteriyor = false;
	if (banka != nullptr)
	{
		nesneGosteriyor = true;
	}
	ASSERT_TRUE(nesneGosteriyor);
	delete banka;
}

TEST(BankaTest, BankaVerileriBoyutTest) {
	Banka* banka = new Banka();
	ASSERT_EQ(4, banka->portfoyAdetVektorGetir().size());
	delete banka;
}

TEST(BankaTest, BankayaPortfoydenGelenSembolVerileriUlastiMiTest) {
	Banka* banka = new Banka();
	auto geciciVektor = banka->portfoySembolVektorGetir();
	bool digerClasstanDegerGeldi = false;
	if (!geciciVektor.empty())
	{
		digerClasstanDegerGeldi = true;
	}
	ASSERT_TRUE(digerClasstanDegerGeldi);
	delete banka;
}

TEST(BankaTest, BankayaPortfoydenGelenMaliyetVerileriUlastiMiTest) {
	Banka* banka = new Banka();
	auto geciciVektor = banka->portfoyMaliyetVektorGetir();
	bool digerClasstanDegerGeldi = false;
	if (!geciciVektor.empty())
	{
		digerClasstanDegerGeldi = true;
	}
	ASSERT_TRUE(digerClasstanDegerGeldi);
	delete banka;
}

TEST(BankaTest, BankayaPortfoydenGelenToplamMaliyetVerileriUlastiMiTest) {
	Banka* banka = new Banka();
	auto geciciVektor = banka->portfoyToplamMaliyetVektorGetir();
	bool digerClasstanDegerGeldi = false;
	if (!geciciVektor.empty())
	{
		digerClasstanDegerGeldi = true;
	}
	ASSERT_TRUE(digerClasstanDegerGeldi);
	delete banka;
}

#pragma endregion