#include "BitMapEightBitWhiteBlack.h"
#include <fstream>
#include "DataEightBit.h"
//------------------------------------------------------------------------------------------------------------------------
// BitMapMono.cpp
//------------------------------------------------------------------------------------------------------------------------

using namespace std;

BitMapEightBitWhiteBlack::BitMapEightBitWhiteBlack(const FileParser& fileParser, Data* data) : BitMap(fileParser, data)
{
	getBitMapInfoHeader().biBitCount = 8; // ustawienie liczby bit�w na 8!
	getBitMapInfoHeader().biClrUsed = 2; //ustawienie liczby u�ywanych kolor�w (2 - skala szaro�ci)

	//BitMapa zawiera dwa kolory: bia�y i czarny.
	RGBQUAD wh = { 0xff,0xff,0xff,0xff }; // white color
	RGBQUAD bl = { 0,0,0,0 };  //black color

	//Pierwszy kolor zapisany to bia�y, a wi�c do wype�niania u�ywany jest czarny
	getRgbQuads().push_back(wh);
	getRgbQuads().push_back(bl);
}

void BitMapEightBitWhiteBlack::saveBitMap(const string outFileName)
{
	//otwarcie pliku do zapisu binarnego
	ofstream file(outFileName, ios::binary | ios::trunc);
	if (file.is_open())
	{
		//Zapisanie danych do pliku

		file.write((char*)&getBitMapFileHeader(), sizeof(BITMAPFILEHEADER)); //write bitmapfileheader
		file.write((char*)&getBitMapInfoHeader(), (sizeof(BITMAPINFOHEADER))); //write bitmapinfoheader
		for (auto &x : getRgbQuads())
		{
			file.write((char*)&x, sizeof(x)); //write RGBQUAD for white
		}


		//Zmiana typu wska�nika na DataEightBit, aby mo�liwe by�o u�ycie przecia�onego operatora <<
		DataEightBit* dataEightBit = dynamic_cast<DataEightBit*>(getData());

		//je�li nieudana konwersja to wyj�tek
		if (dataEightBit == nullptr)
		{
			file.close();
			delete getData(); // zwolnienie pami�ci (bo destruktor w klasie BitMap moze nie zostac wywolany i moze byc wyciek!)
			throw runtime_error("Blad!\nBitMapEightBitWhiteBlack: Wskaznik dataEightBit = nullptr. Nieudana konwersja z Data* do DataEightBit*.");
		}

		// Zapisany danych w postaci bajtowej do pliku
		file << *dataEightBit;

		file.close();
	}
	//je�li problem z plikiem to rzucamy wyj�tek
	else
	{
		delete getData(); // zwolnienie pami�ci (bo destruktor w klasie BitMap moze nie zostac wywolany i moze byc wyciek!)
		throw runtime_error("Blad!\nBitMapEighBitWhiteBlack: Blad zapisu bitmapy do pliku! (Nie mozna otworzyc pliku do zapisu)");
	}
		

}