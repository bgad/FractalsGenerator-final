#pragma once
//----------------------------------------------------------------------------------------------------------------------------
// Klasa Function przechowuj¹ca wspó³czynniki funkcji, która bêdzie póŸniej iterowana, oraz jej prawdopodobnieñstwo
//-----------------------------------------------------------------------------------------------------------------------------
class Function
{
private:
	double a_; //parametr a
	double b_; // parametr b
	double c_; // parametr c
	double d_; // parametr d
	double e_; // parametr e
	double f_; //parametr f
	double probability_; //prawdopodobieñstwo
public:
	Function() : a_(0), b_(0), c_(0), d_(0), e_(0), f_(0), probability_(0) {} //konstruktor domyœlny
	//----------------------------------------------------------------------------------------------------------------------------------
	// KONSTRUKTOR inicjalizuj¹cy odpowiednie wartoœci
	//-----------------------------------------------------------------------------------------------------------------------------------
	Function(const double a, const double b, const double c, const double d, const double e, const double f, const double probability) : a_(a), b_(b), c_(c), d_(d), e_(e), f_(f), probability_(probability) {}

	//----------------------------------------
	//GETTERS:
	//-----------------------------------------
	double getA() const;
	double getB() const;
	double getC() const;
	double getD() const;
	double getE() const;
	double getF() const;
	double getProbability() const;
};