#pragma once
//----------------------------------------------------------------------------------------------------------------------------
// Klasa Function przechowuj�ca wsp�czynniki funkcji, kt�ra b�dzie p�niej iterowana, oraz jej prawdopodobnie�stwo
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
	double probability_; //prawdopodobie�stwo
public:
	Function() : a_(0), b_(0), c_(0), d_(0), e_(0), f_(0), probability_(0) {} //konstruktor domy�lny
	//----------------------------------------------------------------------------------------------------------------------------------
	// KONSTRUKTOR inicjalizuj�cy odpowiednie warto�ci
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