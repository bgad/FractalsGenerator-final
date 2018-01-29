#pragma once
#include "Function.h"
#include "InfoParser.h"
#include <string>
#include <vector>

//-----------------------------------------------------------------------------------------------------------------------
// Obiekt klasy FileParser zawiera� b�dzie informacje potrzebne do stworzenia BitMapy uzyskane z pliku wej��iowego
// Klasa dziedziczy po InfoParser wszystkie pola
//-----------------------------------------------------------------------------------------------------------------------
class FileParser : public InfoParser
{
public:
	FileParser(const std::string &inFileName); //konstruktor tworz�cy obiekt na podstawie info z pliku wej�ciowego
};
