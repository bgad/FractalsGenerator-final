#include "BitMap.h"
#pragma once
//-----------------------------------------------------------------------------------------------------------------------------
// Klasa BitMapMono, reprezentuj¹ca bitmapê 8-bitow¹ z 2 kolorami: bia³y i czarny.
//-----------------------------------------------------------------------------------------------------------------------------
class BitMapEightBitWhiteBlack : public BitMap
{
public:
	BitMapEightBitWhiteBlack(const FileParser& fileParser, Data* data); //konstruktor parametryczny, wywo³uj¹cy konstruktor parametryczny z klasy bazowej
	//Override
	void BitMapEightBitWhiteBlack::saveBitMap(const std::string outFileName);
};