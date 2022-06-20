#include <iostream>
#include <vector>

#include "Zbior_wierzcholkow.hh"

using namespace std;


void Zbior_Wierzcholkow::DodajWierzcholek(Wektor2D W)
{
    Wierzcholek.push_back(W);
}


void Zbior_Wierzcholkow::DodajWierzcholek(double x, double y)
{
    Wektor2D W;
    W[0]=x;
    W[1]=y;
    DodajWierzcholek(W);
}


int Zbior_Wierzcholkow::Sprawdz_ilosc()
{
    return Wierzcholek.size();
}
