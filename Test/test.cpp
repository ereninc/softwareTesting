#include "pch.h"
#include "../Emir.h"
#include "../Portfoy.h"
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

//Emir adeti dosya ile uyuyor mu
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
	if (emir->sembolVector.at(0).c_str() == "AKBNK" && emir->islemVector.at(0).c_str() == "SATIR")
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

TEST(PortfoyTest, PortfoySembolTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_STREQ("AKBNK", portfoy->portfoySembolVector.at(0).c_str());
	delete portfoy;
}

TEST(PortfoyTest, PortfoyMaliyetTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_EQ(3.15f, portfoy->portfoyMaliyetVector.at(0));
	delete portfoy;
}

TEST(PortfoyTest, PortfoyAdetTesti) {
	Portfoy* portfoy = new Portfoy();
	ASSERT_EQ(200, portfoy->portfoyAdetVector.at(0));
	delete portfoy;
}

#pragma endregion