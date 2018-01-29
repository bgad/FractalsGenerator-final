#include "BitMap.h"
#include "BitMapEightBitWhiteBlack.h"
#include "DataFactory.h"
#include "DataEightBit.h"
#include "FileParser.h"
#include "Function.h"
#include <iostream>
#include <ctime>  
#include <fstream>
//------------------------------------------------------------------------------------------------------------------------------------
// FractalsGenerator.cpp - g³owny plik programu
//-------------------------------------------------------------------------------------------------------------------------------------

using namespace std;

void GetArguments(int argc, char** & argv, string &nFileName); // ustawia œcie¿ke pliku wejsciowego

//----------------------------------------------------------------------------------------------------------------------------------------------
// PROGRAM: MAIN
//----------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char ** argv)
{
	//wskaŸnik typu BitMap
	BitMap* bitMap = nullptr; // deklaracja tutaj, aby blok catch mia³ dostêp. przypisano nullptr, aby nie pojawia³ siê blad, ze moze byc uninitialized w bloku catch

	try {
		//nazwa/sciezka pliku wejsciowego
		string inFileName;
		//uzyskanie nazwy pliku wejsciowego z parametrow uruchomienia programu:
		GetArguments(argc, argv, inFileName); 

		//Zaalokowanie pamiêci dla fileParser
		//FileParser fileParser(inFileName, functions, nrIterations, bmpWidth, bmpHeight, minX, maxX, minY, maxY);
		FileParser fileParser(inFileName);

		//Przypisanie typu bitmapy do zmiennej bmpType
		InfoParser::BMPType const bmpType = fileParser.getBmpType();

		//--------ROZPOCZECIE ODLICZANIA CZASU:----------------------------------
		clock_t begin = clock(); 
		float t = 0;
		float duration = 0;

		//Jesli podano obslugiwany ty bitmapy to jest tworzona
		if (bmpType == InfoParser::BMPType::EIGHTBIT)
			bitMap = new BitMapEightBitWhiteBlack(fileParser, DataFactory::createData(fileParser)); //alokacja pamiêci!
		else
			throw runtime_error("Blad!\nFractalsGenerator: Podany typ bitmapy nie jest obslugiwany!"); //jesli podany typ bitmapy inny ni¿ EIGHTBIT
		
		if (bitMap == nullptr)
			throw runtime_error("Blad\nFractalsGenerator: Blad przy tworzeniu bitmapy!");

		//ZAKONCZENIE ODLICZANIA CZASU:
		clock_t end = clock();
		t = end - begin;
		duration = t / CLOCKS_PER_SEC;

		//-------------------------------------------------------------------------------------------------
		// POLIMORFIZM:
		//-------------------------------------------------------------------------------------------------
		bitMap->saveBitMap(fileParser.getOutFileName());

		//zwolnienie pamiêci BitMap
		delete bitMap;

		cout << "Z powodzeniem utworzono bitmape i zapisano do pliku: " << fileParser.getOutFileName() << "\n\n" << "Czas wykonania: " << duration << " sekund\n\n";
		system("pause");
		return 0;
	}
	catch (exception &err)
	{
		//zwolnienie pamiêci BitMap
		delete bitMap;
		cout << err.what() << "\n\n";
		system("pause");
	}

}

//--------------------------------------------------------------------------------------------------------------------------------------

void GetArguments(int argc, char** & argv, string &inFileName)
{
	if (argc <= 1)
		throw runtime_error("Blad!\nFractalsGenerator: Nie podano przelacznikow!");
	else if (argc > 3)
		throw runtime_error("Blad!\nFractalsGenerator: Podano za duzo przelacznikow!");

	//Petla po wszystkich argumentach
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			char c_control = argv[i][1];

			switch (c_control)
			{
			case 'i':
			case 'I':   // input

				if (argv[i + 1] != '\0') // czy podano œcie¿kê po prze³¹czniku
					inFileName = argv[++i];
				else
					throw runtime_error("Blad!\nFractalsGenerator: Nie podano nazwy pliku po przelaczniku -i !");

				break;

			default: // jesli niepoprawny przelacznik

				throw runtime_error("Blad!\nFractalsGenerator: Podano niepoprawny przelacznik!");
				break;
			}
		}
		else // jesli niepoprawny przelacznik
		{
			throw runtime_error("Blad!\nFractalsGenerator: Podano niepoprawny przelacznik!");
		}
	}
}
