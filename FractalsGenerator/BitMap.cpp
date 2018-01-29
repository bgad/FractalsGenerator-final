#include"BitMap.h"
//------------------------------------------------------------------------------------------------------------------------
// BitMap.cpp
//------------------------------------------------------------------------------------------------------------------------

using namespace std;
//Inicjalizacja odpowiednich warto�ci z pliku, oraz inicjalizacja danych z fabryki
BitMap::BitMap(const FileParser& fileParser, Data* data) : width_(fileParser.getWidth()), height_(fileParser.getHeight()), data_(DataFactory::createData(fileParser))
{
	//inicjalizacja bitMapFileHeader odpowiednimi warto�ciami
	bitMapFileHeader_.bfType = 0x4d42; // warto�� "BM"
	bitMapFileHeader_.bfSize = 0;
	bitMapFileHeader_.bfReserved1 = 0;
	bitMapFileHeader_.bfReserved2 = 0;
	bitMapFileHeader_.bfOffBits = sizeof(BITMAPFILEHEADER) + (sizeof(BITMAPINFOHEADER)) + 2 * sizeof(RGBQUAD);

	//Inicjalizacja bitMapInfoHeader odpowiednimi warto�ciami
	bitMapInfoHeader_.biSize = (sizeof(BITMAPINFOHEADER));
	bitMapInfoHeader_.biWidth = fileParser.getWidth();
	bitMapInfoHeader_.biHeight = fileParser.getHeight();
	bitMapInfoHeader_.biPlanes = 1;
	// biBitCount ustawiane w klasie dziedzicz�cej
	bitMapInfoHeader_.biCompression = BI_RGB; //no compression needed
	bitMapInfoHeader_.biSizeImage = 0;
	//biClrUser ustawiane w klasie dziedzcz�cej

}

BitMap::~BitMap()
{
	//Usuwamy dane, po usuni�ciu bitmapy, nie b�d� ju� potrzebne
	delete data_;
}

BITMAPFILEHEADER& BitMap::getBitMapFileHeader()
{
	return bitMapFileHeader_;
}

BITMAPINFOHEADER& BitMap::getBitMapInfoHeader()
{
	return bitMapInfoHeader_;
}

vector<RGBQUAD>& BitMap::getRgbQuads()
{
	return rgbQuads;
}


Data* BitMap::getData()
{
	return data_;
}

size_t BitMap::getWidth() const
{
	return width_;
}

size_t BitMap::getHeight() const
{
	return height_;
}