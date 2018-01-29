#pragma once
#include <cstddef>
#include <string>
#include "FileParser.h"
#include "DataFactory.h"
#include "Data.h"
#include "Windows.h" // dla BITMAPFILEHEADER, BITMAPINFOHEADER, RGBQUAD
//-----------------------------------------------------------------------------------------------------------------------------
// Klasa BitMap, reprezentuj�ca wszystkie dane potrzebne do stworzenia bitmapy
//-----------------------------------------------------------------------------------------------------------------------------
class BitMap
{
private:
		std::size_t width_; //szeroko�� bitmapy
		std::size_t height_; //wysoko�� bitmapy
		BITMAPFILEHEADER bitMapFileHeader_; //FileHeader bitmapy
		BITMAPINFOHEADER bitMapInfoHeader_; //InfoHeader bitmapy
		std::vector<RGBQUAD> rgbQuads; //wektor kolor�w
		Data* data_; // wska�nik do danych bitmapy

		//-------------------------------------------------------------------------------------
		// Protected Getters (u�ywane w klasach dziedzicz�cych). Modifikuj�ce warto��.
		//-------------------------------------------------------------------------------------
protected:
	BITMAPFILEHEADER& getBitMapFileHeader();
	BITMAPINFOHEADER& getBitMapInfoHeader();
	std::vector<RGBQUAD>& getRgbQuads();
	Data* getData();

public:
	BitMap(const FileParser& fileParser, Data* data); //konstruktor parametryczny
	//----------------------------------------------------------------------------------------------------------------------------
	// Czysto wirtualna metoda zapisuj�ca BitMap� do pliku
	//----------------------------------------------------------------------------------------------------------------------------
	virtual void saveBitMap(const std::string outFileName) = 0;
	//-------------------------------------------------------------------------------------------------------------------------------
	// Wirtualny Destruktor
	//-------------------------------------------------------------------------------------------------------------------------------
	virtual ~BitMap();
	//------------------------------------------------------------------------------------------------------------------------------
	// GETTERS:
	//--------------------------------------------------------------------------------------------------------------------------------
	std::size_t getWidth() const;
	std::size_t getHeight() const;
};
