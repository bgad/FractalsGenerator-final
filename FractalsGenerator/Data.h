#pragma once
#include <cstddef>

//--------------------------------------------------------------------------------------------------------------------------
// Klasa DATA reprezentuj�ca dane, kt�re potem zapisywane s� w bitmapie
//--------------------------------------------------------------------------------------------------------------------------

class Data
{
	//protected - aby by�o widoczne w klasie pochodnej
protected: 
	std::size_t width_; //szeroko�� danych
	std::size_t height_; //wysoko�� danych

public:
	Data() : width_(0), height_(0) {} //konstruktor domy�lny

	//-------------------------------------------------------------------------------------------------------------------------------
	// KONSTRUKTOR przyjmuj�cy jako parametry szeroko�� i wysoko�c bitmapy i ustawia te parametry
	//--------------------------------------------------------------------------------------------------------------------------------
	Data(const std::size_t width, const std::size_t height) : width_(width), height_(height) {}

	//------------------------------------------------------------------------------------------------------------------
	// Metoda czysto wirtualna ustawiaj�ca dany piksel w zbiorze danych. X, Y - wsp�rzedne, Level - poziom nasycenia koloru
	//-------------------------------------------------------------------------------------------------------------------

	virtual void setPixel(const int x, const int y, const int level) = 0;

	//---------------------------------------------------------------------------------------------------------------------------------
	//DESTRUKTOR wirtualny
	//---------------------------------------------------------------------------------------------------------------------------------
	virtual ~Data(){}
};