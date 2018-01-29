#pragma once
#include "Function.h"
#include "InfoParser.h"
#include <string>
#include <vector>

//-----------------------------------------------------------------------------------------------------------------------
// Obiekt klasy FileParser zawieraæ bêdzie informacje potrzebne do stworzenia BitMapy uzyskane z pliku wejœæiowego
// Klasa dziedziczy po InfoParser wszystkie pola
//-----------------------------------------------------------------------------------------------------------------------
class FileParser : public InfoParser
{
public:
	FileParser(const std::string &inFileName); //konstruktor tworz¹cy obiekt na podstawie info z pliku wejœciowego
};
