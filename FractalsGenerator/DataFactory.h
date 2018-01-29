#pragma once
#include "DataEightBit.h"
#include "FileParser.h"
//-----------------------------------------------------------------------------------------------------------------------
// Klasa DataFactory tworzy obiekt klasy pochodnej od Data (klasa utworzonego obiektu zale¿y od informacji na temat bitmapy z pliku (1bit, 8bit lub 24 bit)
// Mo¿e generowaæ ró¿ne rodzaje danych (1, 8bit, 24bit).
// , czyli dane dla bitmapy na podstawie danych z pliku. 
//      Wykorzystuje WZORZEC FABRYKI.
//-----------------------------------------------------------------------------------------------------------------------

class DataFactory
{
public:
	//Tworzy obiekt klasy pochodnej od Data ni zwraca wskaŸnik na niego typu Data*
	static Data* createData(const FileParser &fileParser);
};
