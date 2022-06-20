#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

#include "Wektor2D.hh"
#include "Zbior_wierzcholkow.hh"
#include "Obiekt_graficzny.hh"
#include "lacze_do_gnuplota.hh"
#include "Macierz2D.hpp"

using namespace std;


bool Obiekt_Graficzny::Zapisz_Do_Pliku( const char  *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze)
{

    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    int i;
    i= Wys_Glob.Sprawdz_ilosc();


    for(int k=0;k<i;k++) //dodaje wektor przesuniecia dzieki czemu nie trzeba pisac innych funkcji, a o przesuniecia wie tylko plik w ktorym sie to zapisuje, wspolrzedne globalne sie nie zmieniaja
    {
        StrmPlikowy << setw(16) << fixed << setprecision(10) << Wys_Glob.Wierzcholek[k][0] + Wek_Przesuniecia[0]
                    << setw(16) << fixed << setprecision(10) << Wys_Glob.Wierzcholek[k][1] + Wek_Przesuniecia[1] << endl;
    }
        StrmPlikowy << setw(16) << fixed << setprecision(10) << Wys_Glob.Wierzcholek[0][0] + Wek_Przesuniecia[0]
                    << setw(16) << fixed << setprecision(10) << Wys_Glob.Wierzcholek[0][1] + Wek_Przesuniecia[1] << endl;


    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}


void Obiekt_Graficzny::Obroc(int kat)
{
    kat_rotacji+=kat;                   //dodaje kat do aktualnego kata rotacji
    Macierz2D Mtry;                     //definicja macierzy do obrotu
    Mtry.Stworz_Trygonometryczna(kat_rotacji);

    int i;
    i=Wys_Glob.Sprawdz_ilosc();

    for(int j=0; j<i; j++)         //zmiana wartosci wierzcholkow                        // sprawdzic ilosc elementow i tyle razy iterowac
    {
        Wys_Glob.Wierzcholek[j]= Mtry * Wys_Lok.Wierzcholek[j];
    }
    Ustaw_Glob();
}


void Obiekt_Graficzny::Ustaw_Lok(void)
{
    int i;
    i=Wys_Lok.Sprawdz_ilosc();

    for(int j=0; j<i; j++)
    {
        Wys_Glob.Wierzcholek[j][0] = Wys_Lok.Wierzcholek[j][0];
        Wys_Glob.Wierzcholek[j][1] = Wys_Lok.Wierzcholek[j][1];
    }
}


void Obiekt_Graficzny::Ustaw_Glob(void)
{
    int i;
    i=Wys_Glob.Sprawdz_ilosc();

    for(int j=0; j<i; j++)
    {
        Wys_Glob.Wierzcholek[j][0] += Wek_translacji[0];
        Wys_Glob.Wierzcholek[j][1] += Wek_translacji[1];

    }
}


  void Obiekt_Graficzny::Ustaw_Przesuniecie(Wektor2D Prz)
  {
      Wek_Przesuniecia= Wek_Przesuniecia + Prz;
  }

  void Obiekt_Graficzny::Resetuj_Przesuniecie()
  {
      Wek_Przesuniecia[0]=0;
      Wek_Przesuniecia[1]=0;
  }


  void Obiekt_Graficzny::Zmien_Polozenie(Wektor2D W)
  {
      int i;
      i=Wys_Glob.Sprawdz_ilosc();

      for(int j=0; j<i; j++)
      {
        Wys_Glob.Wierzcholek[j][0] = Wys_Glob.Wierzcholek[j][0] + W[0] - Wek_translacji[0];
        Wys_Glob.Wierzcholek[j][1] = Wys_Glob.Wierzcholek[j][1] + W[1] - Wek_translacji[1];
      }


    Wek_translacji=W;

  }


  void Obiekt_Graficzny::Zmien_Wek_Translacji( Wektor2D W)
  {
      Wek_translacji=W;
  }


  void Obiekt_Graficzny::Obroc_szybko(int kat , PzG::LaczeDoGNUPlota Lacze)
  {
      Obroc(kat);
      Zapisz_Do_Pliku( Nazwa_Pliku.c_str() , Lacze );
  }
