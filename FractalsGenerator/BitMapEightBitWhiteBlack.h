#include "BitMap.h"
#pragma once
//-----------------------------------------------------------------------------------------------------------------------------
// Klasa BitMapMono, reprezentuj�ca bitmap� 8-bitow� z 2 kolorami: bia�y i czarny.
//-----------------------------------------------------------------------------------------------------------------------------
class BitMapEightBitWhiteBlack : public BitMap
{
public:
	BitMapEightBitWhiteBlack(const FileParser& fileParser, Data* data); //konstruktor parametryczny, wywo�uj�cy konstruktor parametryczny z klasy bazowej
	//Override
	void BitMapEightBitWhiteBlack::saveBitMap(const std::string outFileName);
};