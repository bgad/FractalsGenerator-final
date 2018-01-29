#include "FileParser.h"
#include <fstream>
#include <sstream>
//-------------------------------------------------------------------------------------------------------------------------------
// FileParser.cpp
//-------------------------------------------------------------------------------------------------------------------------------
using namespace std;
FileParser::FileParser(const std::string &inFileName) : InfoParser() 
{
	//otwarcie pliku do odczytu
	ifstream inFile(inFileName);
	if (inFile.is_open())
	{

		//---------------------------------------------------------------------------------------------------------------
		// SPRAWDZENIE czy plik jest pusty:
		//------------------------------------------------------------------------------------------------------------------

		if (inFile.peek() == std::ifstream::traits_type::eof())
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Plik jest pusty!");
		}
		
		//--------------------------------------------------------------------------------------------------------------------
		// ETAP1: Odczyt typu Bitmapy:
		//---------------------------------------------------------------------------------------------------------------------
		string bmpType;
		if (!(inFile >> bmpType)) // jesli pierwsza linia to nie napis:
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (bmpType)");
		}

		//przypisanie typu bitmapy do odpowiedniej zmiennej
		
		if (bmpType == "ONEBIT" || bmpType == "1BIT")
			bmpType_ = InfoParser::BMPType::ONEBIT;
		else if (bmpType == "FOURBIT" || bmpType == "4BIT")
			bmpType_ = InfoParser::BMPType::FOURBIT;
		else if (bmpType == "EIGHTBIT" || bmpType == "8BIT")
			bmpType_ = InfoParser::BMPType::EIGHTBIT;
		else if (bmpType == "RGB")
			bmpType_ = InfoParser::BMPType::RGB;
		else //jesli bledny typ bitmapy zostal podany:
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (bmpType)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP2: Odczyt nazwy pliku (sciezki do pliku) wyjsciowego
		//------------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> outFileName_)) // jesli to nie tekst
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (nazwa pliku wyjsciowego)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP3: Odczyt liczby iteracji
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> nrIterations_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (liczba iteracji)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP4: Odczyt szerokoœci bitmapy
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> width_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (szerokosc)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP5: Odczyt wysokoœci bitmapy
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> height_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (wysokosc)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP6: Odczyt minX bitmapy
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> minX_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (minX)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP7: Odczyt maxX bitmapy
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> maxX_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (maxX)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP7: Odczyt minY bitmapy
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> minY_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (minY)");
		}

		//-----------------------------------------------------------------------------------------------------------------------
		// ETAP8: Odczyt maxY bitmapy
		//-----------------------------------------------------------------------------------------------------------------------

		if (!(inFile >> maxY_)) // jesli to nie liczba to rzuci wyjatek, jesli tak to zapisze do odpowiedniej zmiennej
		{
			inFile.close();
			throw runtime_error("Blad!\nFileParser: Bledne dane wejsciowe! (maxY)");
		}

		//--------------------------------------------------------------------------------------------------------------------------
		// ETAP9: Odczyt funkcji i ich pradopodobienstw:
		//--------------------------------------------------------------------------------------------------------------------------

		stringstream stream;
		string string = "";
		inFile.ignore(); // przejscie do nastepnej linii

		//zmienne tymczasowe:
		double a, b, c, d, e, f, p;

		//jesli teraz nastapil koniec pliku to rzucamy wyjatek
		if (inFile.eof())
			{
				inFile.close();
				throw runtime_error("Blad!\nFileParser: Nie podano zadnych wspolczynnikow funkcji!");
			}

		//--------------------------------------------------------------------------------------------------------------
		// petla dodajaca po kolei wspolczynniki ze strumienia do zmiennych tymczasowych. A na koncu zapisujaca funkcje
		//-------------------------------------------------------------------------------------------------------------
		while (getline(inFile, string)) // po kolei kazda linie odczytujemy. w kazdej linii powinna byc informacja o jednej funkcji
		{
			stream.clear(); // wyczyszczenie strumienia
			stream << string; // zapis do strumienia

			
			if (!stream.rdbuf()->in_avail() == 0) // jesli strumien nie jest pusty (moze byc pusty gdy np. jest pusta linia na koncu pliku)
			{
					
					//-------------------------------------------------------------------------
					// Wczytanie wspolczynnikow:
					//-------------------------------------------------------------------------

					if (!(stream >> a))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik a pewnej funkcji!");
					}
					if (!(stream >> b))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik b pewnej funkcji!");
					}
					if (!(stream >> c))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik c pewnej funkcji!");
					}
					if (!(stream >> d))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik d pewnej funkcji!");
					}
					if (!(stream >> e))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik e pewnej funkcji!");
					}
					if (!(stream >> f))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik f pewnej funkcji!");
					}
					if (!(stream >> p))
					{
						inFile.close();
						throw runtime_error("Blad!\nFileParser: Bledny wspolczynnik p pewnej funkcji!");
					}

					functions_.push_back(*(new Function(a, b, c, d, e, f, p))); // dodanie funkcji do zbioru funkcji

				
			}

		}

		


	}
	else
		throw runtime_error("Blad!\nFileParser: Blad pliku wejsciowego! (Nie mozna otworzyc pliku)");
}