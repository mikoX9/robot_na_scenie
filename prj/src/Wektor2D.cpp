#include "Wektor2D.hh"
#include "Macierz2D.hpp"


Wektor2D::Wektor2D()    //konstruktor
{
    _Wsp[0]=0;    //x
    _Wsp[1]=0;    //y

    ilosc_stworzonych++;
    ilosc_istniejacych++;
}


Wektor2D::~Wektor2D()
{
    ilosc_istniejacych--;
}


Wektor2D Wektor2D::operator+ (Wektor2D const& ex)
{
    Wektor2D tmp;
    tmp[0]=_Wsp[0] + ex[0];
    tmp[1]=_Wsp[1] + ex[1];
    return tmp;
}


Wektor2D Wektor2D::operator- (Wektor2D const& ex)
{
    Wektor2D tmp;
    tmp[0]=_Wsp[0] - ex[0];
    tmp[1]=_Wsp[1] - ex[1];
    return tmp;
}


Wektor2D Wektor2D::operator = (Wektor2D ex)
{
    _Wsp[0] = ex[0] ;
    _Wsp[1] = ex[1] ;

    return ex;
}


double Wektor2D::operator & ( const Wektor2D& V2 ) const
{
float Wynik = 0;
for (int Ind = 0; Ind < 2; ++Ind) Wynik += _Wsp[Ind]*V2[Ind];
return Wynik;
}

/*
Wektor2D Dodaj( Wektor2D W1, Wektor2D W2 )
{ W1[0] += W2[0]; W1[1] += W2[1]; return W1; }
*/

std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek){
Strm<<"["; Strm<<Wek[0]; Strm<<","; Strm<<Wek[1]; Strm<<"]";
return Strm;
}


std::istream& operator >> (std::istream &Strm, Wektor2D &Wek){
float x,y;
Strm>>x; Strm>>y;
Wek[0]=x; Wek[1]=y;
return Strm;
}



