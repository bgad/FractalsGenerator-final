#pragma once
#include <string>
#include <vector>
#include "Function.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// Klasa InfoParser przechowuje informacje potrzebne do utworzenia BitMapy
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class InfoParser
{
public:
	enum class BMPType { ONEBIT, FOURBIT, EIGHTBIT, RGB }; //typ enum, wskazuj¹cy na rodzaj bitmapy
protected:
	BMPType bmpType_; //typ bitmapy
	std::string outFileName_; //nazwa pliku bitmapy
	int nrIterations_; //liczba iteracji
	std::size_t width_; // szerokoœæ bitmapy
	std::size_t height_; // wysokoœæ bitmapy
	double minX_;
	double maxX_;
	double minY_;
	double maxY_;
	std::vector<Function> functions_; //funkcje iterowane
	
public:
	InfoParser(){}
	virtual ~InfoParser(){}

	//------------------------------------------------------------------------------------------------------------------------------------------------
	// GETTERS:
	//------------------------------------------------------------------------------------------------------------------------------------------------
	BMPType getBmpType() const;
	std::size_t getWidth()  const;
	std::size_t getHeight() const;
	double getMaxX() const;
	double getMaxY() const;
	double getMinX() const;
	double getMinY() const;
	std::string getOutFileName() const;
	std::vector<Function> getFunctions() const;
	int getNrIterations() const;
};