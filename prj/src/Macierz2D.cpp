#include <cmath>
#include "Macierz2D.hpp"


std::ostream& operator << (std::ostream &Strm, const Macierz2D &Mac)
{
    Strm<<endl<<Mac.Kolumna[0][0]<< " " <<Mac.Kolumna[1][0];
    Strm<<endl<<Mac.Kolumna[0][1]<< " " <<Mac.Kolumna[1][1];
    return Strm;
}


Macierz2D operator * (Macierz2D A, Macierz2D B)
{
    Macierz2D WW;
    WW.Kolumna[0][0]=A.Kolumna[0][0]*B.Kolumna[0][0]+A.Kolumna[1][0]*B.Kolumna[0][1];
    WW.Kolumna[1][0]=A.Kolumna[0][0]*B.Kolumna[1][0]+A.Kolumna[1][0]*B.Kolumna[1][1];
    WW.Kolumna[0][1]=A.Kolumna[0][1]*B.Kolumna[0][0]+A.Kolumna[1][1]*B.Kolumna[0][1];
    WW.Kolumna[1][1]=A.Kolumna[0][1]*B.Kolumna[1][0]+A.Kolumna[1][1]*B.Kolumna[1][1];
    return WW;
}


Wektor2D operator * (Macierz2D M, Wektor2D W){

Wektor2D WW;
WW[0]=(M(0,0)*W[0])+(M(0,1)*W[1]);
WW[1]=(M(1,0)*W[0])+(M(1,1)*W[1]);
return WW;

}


void Macierz2D::Stworz_Trygonometryczna(double kat_rotacji)
{
    double alfa;
    alfa=(kat_rotacji*M_PI)/180.0;      //przeliczenie stopni na radiany


    Kolumna[0][0]=cos(alfa);        //wpisanie wartosci do macierzy
    Kolumna[1][0]=-sin(alfa);
    Kolumna[0][1]=sin(alfa);
    Kolumna[1][1]=cos(alfa);


    ///Poza klasa
    /*
    Mtry(0,0)=cos(alfa);        //wpisanie wartosci do macierzy
    Mtry(0,1)=-sin(alfa);
    Mtry(1,0)=sin(alfa);
    Mtry(1,1)=cos(alfa);
    */
}
