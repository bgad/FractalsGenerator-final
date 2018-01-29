#pragma once
#include "Data.h"
#include <vector>
//-------------------------------------------------------------------------------------------------------------------------------
// Klasa DATA reprezentuj�ca dane bajtowe (8bit), kt�re potem zapisywane s� w bitmapie 8-bitowej. Ka�dy piksel reprezentowany 
//       jest przez warto�� 1-bajtow� w tym zbiorze danych. Im wy�sza warto�� danego bajtu, tym mocniejsze nasycenie koloru.
//--------------------------------------------------------------------------------------------------------------------------------
class DataEightBit : public Data
{
private:
	std::vector<unsigned char> data_; //wektor zawieraj�ce dane o poszczeg�lnych pikselach w postaci bajtowej. UNSIGNED CHAR: 0-255

public:
	DataEightBit(){} // konstruktor domy�lny

	//------------------------------------------------------------------------------------------------------------------------------
	// KONSTRUKTOR parametryczny wywo�uj�cy konstruktor z klasy bazowej i ustalaj�cy rozmiar bitsetu
	//------------------------------------------------------------------------------------------------------------------------------
	DataEightBit(const std::size_t width, const std::size_t height); 

	//-------------------------------------------------------------------------------------------------------------------
	// Funkcja ustawiaj�ca odpowiedni bit
	//-------------------------------------------------------------------------------------------------------------------

	void setPixel(const int x, const int y, const int level);

	//--------------------------------------------------------------------------------------------------------------------
	// Data Getter. Prywatny, bo u�ywany tylko przez t� klas�. Modifikuje zbi�r danych!
	//--------------------------------------------------------------------------------------------------------------------

private:
	std::vector<unsigned char>& getData();

public:
	//-----------------------------------------------------------------------------------------------------------------------------------
	// PRZECI��ONY OPERATOR << zwracaj�cy strumie� danych z obiektu DataForMonoBMP
	friend std::ostream & operator<<(std::ostream &s, DataEightBit &data);

};
