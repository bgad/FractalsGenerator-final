#include "DataFactory.h"
#include <random>
#include <iostream>
#include <algorithm>
//------------------------------------------------------------------------------------------------------------------------
// DataFactory.cpp
//------------------------------------------------------------------------------------------------------------------------
using namespace std;

Data* DataFactory::createData(const FileParser &fileParser)
{
	Data* data; // WskaŸnik typu Data
	
		//Tworzenie zbioru danych dla 8-bitowej BMP na pixel
		if (fileParser.getBmpType() == FileParser::BMPType::EIGHTBIT) 
		data = new DataEightBit(fileParser.getWidth(), fileParser.getHeight());
		//------------------------------------
		//Tutaj mog¹ byæ inne Dane tworzone. Np. else if (fileParser.getBmpType() == FileParser::BMPType::ONEBIT) itd...
		//---------------------------------
		else
		{
			throw runtime_error("Blad!\nDataFactory: Wskaznik data = nullptr!"); // je¿eli nie zaalokowano danych do wskaŸnika data
		}

		int dataTempSize = fileParser.getWidth() * fileParser.getHeight();

		//Wektor danych tymczasowych, potrzebnych do obliczeñ
		vector<double> dataTemp(dataTempSize);

		// wyzerowanie wszystkich danych w wektorze dataTemp
		fill(dataTemp.begin(), dataTemp.end(), 0);

		vector<Function> functions_ = fileParser.getFunctions(); // funkcje z których bêdziemy losowaæ
		double minX = fileParser.getMinX();
		double maxX = fileParser.getMaxX();
		double minY = fileParser.getMinY();
		double maxY = fileParser.getMaxY();

		//Obliczenie ratioX i ratioY
		double ratioX = (maxX - minX) / (fileParser.getWidth() * 1.0);
		double ratioY = (maxY - minY) / (fileParser.getHeight() * 1.0);

		int index = 0; //indeks do sprawdzenia czy nie wychodzi poza zakres dataTemp
		double x = 0; //indeks x
		double y = 0; // indeks x
		int level = 0; //poziom wype³nienia pixela kolorem
		double xTemp = 0; //indeks x tymaczasowy
		double yTemp = 0; // indeks y tymczasowy
		int indexRandom = 0; // indeks wylosowanej funkcji
		int nrIterations = fileParser.getNrIterations(); //liczba iteracji

		//utworzenie wektora prawdopodobieñstw do generatora
		vector<double> probabilityArray;
		for (auto& x : functions_) {
			probabilityArray.push_back(x.getProbability());
		}

		//-------------------------------------------------
		//Utworzenie generatora do loswania funkcji
		//--------------------------------------------------
		random_device rd;
		mt19937 gen(rd());
		discrete_distribution<> d(probabilityArray.begin(), probabilityArray.end() );

		//Petla wykonuj¹ca siê nrIterations razy
		for (int i = 0; i < nrIterations; i++)
		{
			//wylosowanie funkcji
			indexRandom = d(gen);

			//Obliczenia punktu
			xTemp = (functions_[indexRandom].getA() * x) + (functions_[indexRandom].getB() * y) + functions_[indexRandom].getE();
			yTemp = (functions_[indexRandom].getC() * x) + (functions_[indexRandom].getD() * y) + functions_[indexRandom].getF();
			x = xTemp;
			y = yTemp;

			//ustawienie punktu w tymczasowym zbiorze danych na ++1
			index = (int)((int)((x - minX) / ratioX) * fileParser.getWidth() + ((y - minY) / ratioY));
			if (index < dataTempSize)
				dataTemp[index]++;
			else
			{
				delete data; // zwolnienie pamiêci zajêtej przez data 
				throw out_of_range("Blad!\nDataFactory: Wyliczony indeks jest poza zasiegiem dataTemp!");
			}

		
		}

		//Wyszukanie najczesciej wystepujacego punktu, za pomoc¹ max_element z algorithm
		double biggest = *max_element(dataTemp.begin(), dataTemp.end());
		

		//Ustawienie pixela w danych do BMP
		for (int i = 0; i<fileParser.getHeight(); i++)
		{
			for (int j = 0; j<fileParser.getWidth(); j++)
			{
				if (dataTemp[j + i*fileParser.getWidth()] > 0)
				{
					level = (log(dataTemp[j + i*fileParser.getWidth()]) / log(biggest)) * 0xff;
					//------------------------------------------------------------------------
					// ZASTOSOWANO POLIMORFIZM:
					//------------------------------------------------------------------------
					data->setPixel(i, j, level);
				}
			}
		}

		//Zwrócenie wskaŸnika
		return data;
}