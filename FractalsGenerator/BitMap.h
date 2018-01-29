#pragma once
#include <cstddef>
#include <string>
#include "FileParser.h"
#include "DataFactory.h"
#include "Data.h"
#include "Windows.h" // dla BITMAPFILEHEADER, BITMAPINFOHEADER, RGBQUAD
//-----------------------------------------------------------------------------------------------------------------------------
// Klasa BitMap, reprezentuj¹ca wszystkie dane potrzebne do stworzenia bitmapy
//-----------------------------------------------------------------------------------------------------------------------------
class BitMap
{
private:
		std::size_t width_; //szerokoœæ bitmapy
		std::size_t height_; //wysokoœæ bitmapy
		BITMAPFILEHEADER bitMapFileHeader_; //FileHeader bitmapy
		BITMAPINFOHEADER bitMapInfoHeader_; //InfoHeader bitmapy
		std::vector<RGBQUAD> rgbQuads; //wektor kolorów
		Data* data_; // wskaŸnik do danych bitmapy

		//-------------------------------------------------------------------------------------
		// Protected Getters (u¿ywane w klasach dziedzicz¹cych). Modifikuj¹ce wartoœæ.
		//-------------------------------------------------------------------------------------
protected:
	BITMAPFILEHEADER& getBitMapFileHeader();
	BITMAPINFOHEADER& getBitMapInfoHeader();
	std::vector<RGBQUAD>& getRgbQuads();
	Data* getData();

public:
	BitMap(const FileParser& fileParser, Data* data); //konstruktor parametryczny
	//----------------------------------------------------------------------------------------------------------------------------
	// Czysto wirtualna metoda zapisuj¹ca BitMapê do pliku
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
