#include "InfoParser.h"
//-------------------------------------------------------------------------------------------------------------------------------
// InfoParser.cpp
//-------------------------------------------------------------------------------------------------------------------------------
using namespace std;

InfoParser::BMPType InfoParser::getBmpType() const
{
	return bmpType_;
}

size_t InfoParser::getWidth() const
{
	return width_;
}

size_t InfoParser::getHeight() const
{
	return height_;
}

double InfoParser::getMaxX() const
{
	return maxX_;
}

double InfoParser::getMaxY() const
{
	return maxY_;
}
 
double InfoParser::getMinX() const
{
	return minX_;
}

double InfoParser::getMinY() const
{
	return minY_;
}

string InfoParser::getOutFileName() const
{
	return outFileName_;
}

vector<Function> InfoParser::getFunctions() const
{
	return functions_;
}

int InfoParser::getNrIterations() const
{
	return nrIterations_;
}