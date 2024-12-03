#ifndef __RATIONAL__
#define __RATIONAL__

#include <iostream>
#include <cmath>
#include <exception>

class WrongRatioException : public std::exception{

	int nom;
	public:
	WrongRatioException(){}
	WrongRatioException(int x){
		nom =x;
	}

	const char* what(){
	     return "Denominator can\'t be 0";
	}


	void show(){
		std::cerr<<"Ratio Exception\n"<<nom<<"\n";
	}
};


class Rational{
	private:
	int nom;
	unsigned denom;

	public:
	Rational(){
		nom = 1;
		denom = 1U;
	}
	Rational(int x, unsigned y):nom(x),denom(y){
		if(denom==0) throw WrongRatioException();
		reduce();
	}

	void show();
	int input();



	int setNom(int x){
		nom = x;
		return 0;
	}
	int setDenom(unsigned y){
		if(y!=0){
			denom = y;
			return 0;
		}
		throw WrongRatioException(nom);
		return -1;
	}

	Rational add(const Rational& x); //x.add(y);
	Rational mult(const Rational& x);

	Rational operator+(const Rational& x){ //x.add(y);
		return add(x);
	}

	Rational operator*(const Rational& x){ //x.add(y);
		return mult(x);
	}


	Rational operator-(const Rational& x){ //x.sub(y);
		int ch = static_cast<int>(x.denom * nom - x.nom * denom);
		unsigned zn = x.denom * denom;
		return Rational(ch,zn);
	}

	Rational operator/(const Rational& x){ //x.add(y);
		int ch = static_cast<int>(x.denom *nom);
		unsigned zn = x.denom * nom;
		return Rational(ch,zn);
	}

	Rational operator-(){
		return Rational(-nom,denom);
	}


	bool less(const Rational & x){
		return (nom*x.denom<denom*x.nom);
	}

	double compare(double z){
		return fabs(z - (nom+0.)/denom);
	}

	bool operator<(const Rational & x){
		return less(x);
	}

	bool operator>(const Rational & x){
		return !less(x);
	}

	bool operator==(const Rational & x){
		return (nom*x.denom == denom*x.nom);
	}

	bool operator!=(const Rational & x){
		return (nom*x.denom != denom*x.nom);
	}


	bool operator<(const double x){
		return fabs(x - static_cast<double>(nom)/denom);
	}

	static unsigned gcd(unsigned x, unsigned y);


	friend void writeToFile(std::string fname, const Rational& r);


	friend std::ostream &operator<<( std::ostream &output, const Rational &D ) {
    		output << D.nom << "/" << D.denom <<std::endl;
    		return output;
	}
	 // operotor cin>>>
	friend std::istream &operator>>( std::istream &input, Rational &D ) {
    		input >> D.nom >> D.denom;
    		return input;
  	}


	private:
	void reduce();
};


#endif // __RATIONAL__ header
