#pragma once
#include <cstddef>

//--------------------------------------------------------------------------------------------------------------------------
// Klasa DATA reprezentuj¹ca dane, które potem zapisywane s¹ w bitmapie
//--------------------------------------------------------------------------------------------------------------------------

class Data
{
	//protected - aby by³o widoczne w klasie pochodnej
protected: 
	std::size_t width_; //szerokoœæ danych
	std::size_t height_; //wysokoœæ danych

public:
	Data() : width_(0), height_(0) {} //konstruktor domyœlny

	//-------------------------------------------------------------------------------------------------------------------------------
	// KONSTRUKTOR przyjmuj¹cy jako parametry szerokoœæ i wysokoœc bitmapy i ustawia te parametry
	//--------------------------------------------------------------------------------------------------------------------------------
	Data(const std::size_t width, const std::size_t height) : width_(width), height_(height) {}

	//------------------------------------------------------------------------------------------------------------------
	// Metoda czysto wirtualna ustawiaj¹ca dany piksel w zbiorze danych. X, Y - wspó³rzedne, Level - poziom nasycenia koloru
	//-------------------------------------------------------------------------------------------------------------------

	virtual void setPixel(const int x, const int y, const int level) = 0;

	//---------------------------------------------------------------------------------------------------------------------------------
	//DESTRUKTOR wirtualny
	//---------------------------------------------------------------------------------------------------------------------------------
	virtual ~Data(){}
};