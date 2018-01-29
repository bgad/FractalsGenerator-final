#include "DataEightBit.h"
#include <iostream>
//------------------------------------------------------------------------------------------------------------------------
// DataForMonoBMP.cpp
//------------------------------------------------------------------------------------------------------------------------
using namespace std;

DataEightBit::DataEightBit(const size_t width, const size_t height) : Data(width, height), data_(width * height)
{
	//wype³nienie wektora danych zerami
	fill(this->getData().begin(), this->getData().end(), 0);
}


void DataEightBit::setPixel(const int x, const int y, const int level)
{	
	//Symulacja struktury danych 2D

	int index = x * width_ + y;

	if (index < width_ * height_)
	this->getData()[x * width_ + y] = level;
	else
		throw out_of_range("Blad!\nDataEighBit: Wybrany indeks jest poza zasiegiem wektora danych!");
}

vector<unsigned char>& DataEightBit::getData()
{
	return data_;
}


ostream & operator<<(ostream &s, DataEightBit &data)
{
	// po kolei zapisujemy do strumienia ka¿dy bajt
	for (auto &x : data.getData())
	{
		s << x;
	}
	return s;
}
