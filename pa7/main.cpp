#include <iostream>

using namespace std;

class Fraction {
 private :
    int numerator;
    int denominator;
    // to help you for not math error helper
    int gcd(int a, int b){

    a=abs(a);
	b=abs(b);

	if(b>a)
		return gcd( b, a);

	if(b!=0)
		return gcd( b, a%b);
	else
		return a;

    }

    Fraction& reduce (){

    int divisor = gcd(numerator, denominator);
	if (divisor > 1){
		numerator = numerator / divisor;
		denominator = denominator / divisor;
	}

	return *this;

    }

 public :
    Fraction (int num=0 , int den=1 ){
       this->numerator = num;
       this->denominator = den;
       if (den <0){
        den *= -1;
        num *= -1;
       }
       reduce();
    }


};
Fraction operator+(const Fraction& a, const Fraction& b){
Fraction z=a ;
return z+=b;

}

Fraction operator+(const double a , const Fraction& b ){
Fraction z=a ;
return z+=b;

}

Fraction operator+(const Fraction& a, const double b){
Fraction z=a ;
return z+=b;

}
Fraction operator-(const FRaction& a, const Fraction& b){
Fraction z= a;
return z-=b;

}

Fraction operator*(const Fraction& a , const Fraction& b){
Fraction z= a;
return z*=b;

}

Fraction operator/ (const Fraction& a , const Fraction& b){
Fraction z= a;
return z/=b;

}

bool operator== (const Fraction& b1, const Fraction& b2){
	return ((b1.numerator == b2.numerator) && (b1.denominator == b2.denominator));
}

bool operator== (int n, const Fraction& b2){
	Fraction temp(n);
	return ((temp.numerator == b2.numerator) && (temp.denominator == b2.denominator));
}
bool operator== (const Fraction& b2, int n ){
	Fraction temp(n);
	return ((temp.numerator == b2.numerator) && (temp.denominator == b2.denominator));
}
ostream& operator<< (ostream& os, const Fraction& b){
	os << b.numerator << " / " << b.denominator;
	return os;
}

istream& operator>> (istream& in, Fraction& f){
	string s, n_str, d_str;
	int nom = 0;
	int den = 1;				// if no denominator is specified

	getline(in, s);				// read whole line including whitespace into string

	istringstream iss(s);		// initialize input-string-stream with string
	getline(iss, n_str, '/');	// pack everything from iss up to the separator "/" in nominator string
	getline(iss, d_str);		// put the rest in denominator string

	iss.clear();				// iss now points to EOF, therefore reset
	iss.str(n_str);				// assign new string
	iss >> nom;					// convert to int via input operator overloaded for integer

	iss.clear();				// same for denominator
	iss.str(d_str);
	iss >> den;

	f = Fraction(nom, den);		// create fraction

	return in;
}





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
