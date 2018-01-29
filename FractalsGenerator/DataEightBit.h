#pragma once
#include "Data.h"
#include <vector>
//-------------------------------------------------------------------------------------------------------------------------------
// Klasa DATA reprezentuj¹ca dane bajtowe (8bit), które potem zapisywane s¹ w bitmapie 8-bitowej. Ka¿dy piksel reprezentowany 
//       jest przez wartoœæ 1-bajtow¹ w tym zbiorze danych. Im wy¿sza wartoœæ danego bajtu, tym mocniejsze nasycenie koloru.
//--------------------------------------------------------------------------------------------------------------------------------
class DataEightBit : public Data
{
private:
	std::vector<unsigned char> data_; //wektor zawieraj¹ce dane o poszczególnych pikselach w postaci bajtowej. UNSIGNED CHAR: 0-255

public:
	DataEightBit(){} // konstruktor domyœlny

	//------------------------------------------------------------------------------------------------------------------------------
	// KONSTRUKTOR parametryczny wywo³uj¹cy konstruktor z klasy bazowej i ustalaj¹cy rozmiar bitsetu
	//------------------------------------------------------------------------------------------------------------------------------
	DataEightBit(const std::size_t width, const std::size_t height); 

	//-------------------------------------------------------------------------------------------------------------------
	// Funkcja ustawiaj¹ca odpowiedni bit
	//-------------------------------------------------------------------------------------------------------------------

	void setPixel(const int x, const int y, const int level);

	//--------------------------------------------------------------------------------------------------------------------
	// Data Getter. Prywatny, bo u¿ywany tylko przez tê klasê. Modifikuje zbiór danych!
	//--------------------------------------------------------------------------------------------------------------------

private:
	std::vector<unsigned char>& getData();

public:
	//-----------------------------------------------------------------------------------------------------------------------------------
	// PRZECI¥¯ONY OPERATOR << zwracaj¹cy strumieñ danych z obiektu DataForMonoBMP
	friend std::ostream & operator<<(std::ostream &s, DataEightBit &data);

};
