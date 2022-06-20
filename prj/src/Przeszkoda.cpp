#include <iostream>

#include "Przeszkoda.hh"

using namespace std;


void Przeszkoda::Buduj_Przeszkode( Wektor2D W1, Wektor2D W3)
{
    Wys_Glob.DodajWierzcholek( W1 );
    Wys_Glob.DodajWierzcholek(  W3[0], W1[1] );
    Wys_Glob.DodajWierzcholek( W3 );
    Wys_Glob.DodajWierzcholek(  W1[0], W3[1] );
}
