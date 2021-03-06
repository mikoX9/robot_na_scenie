#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <string>
#include <math.h>

#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
#include "Robot.hh"
#include "Macierz2D.hpp"
#include "Sciezka.hh"
#include "Scena.hh"


using namespace std;


  /*!
   * \brief Zatrzymanie programu
   *
   * Funkcja zatrzymuje program na n sekund.
   */
void delay() {

    float n= 0.025;              /// Podane w sekundach

    clock_t start = clock();
    clock_t end = start;
    end += static_cast<clock_t>(n * CLOCKS_PER_SEC);
    while (start < end)
        start = clock();
}


Robot::Robot( Wektor2D W )
{
    kat_rotacji=0;

    krok= 1;

    Wys_Lok.DodajWierzcholek( -7 , -7 );
    Wys_Lok.DodajWierzcholek(  7 , -7 );
    Wys_Lok.DodajWierzcholek( 10 ,  0 );
    Wys_Lok.DodajWierzcholek(  7 ,  7 );
    Wys_Lok.DodajWierzcholek( -7 ,  7 );

    Wek_translacji=W;

    Wek_Przesuniecia[0]=0;
    Wek_Przesuniecia[1]=0;

    Wys_Glob.DodajWierzcholek(0,0);
    Wys_Glob.DodajWierzcholek(0,0);
    Wys_Glob.DodajWierzcholek(0,0);
    Wys_Glob.DodajWierzcholek(0,0);
    Wys_Glob.DodajWierzcholek(0,0);

    Ustaw_Lok();
    Ustaw_Glob();

    Promien=10;
}


void Robot::Przod(Wektor2D Wlasciwy)
{
    Wektor2D tmp;
    tmp=Wek_translacji;                 ///zapisanie starego wektora translacji
    Wek_translacji = Wlasciwy;
    Ustaw_Glob();
    Wek_translacji= tmp + Wlasciwy;
}


void Robot::Animacja_Przod(double odleglosc, PzG::LaczeDoGNUPlota & Lacze, Scena & SCE)
{

    bool flaga_kolizji=0;     ///flaga sygnalizujaca kolizje

    Wektor2D Nowe_Przesuniecie;

    int ilosc_krokow;
    ilosc_krokow = odleglosc/krok;

    Macierz2D Mtryg;
    Mtryg.Stworz_Trygonometryczna(kat_rotacji);

    Wektor2D Odleglosci;
    Odleglosci[0]=krok;


    Wektor2D Wlasciwy;
    Wlasciwy = Mtryg * Odleglosci;

    for(int i=0; i<ilosc_krokow; i++)
    {
        Nowe_Przesuniecie = Wek_translacji + Wlasciwy;

        int k;
        k = SCE.P.size();

        for(int j=0; j<k; j++)            //sprawdza kolizje dla kazdej przeszkody
        {
            if(   Nowe_Przesuniecie[0] > SCE.P[j].Wys_Glob.Wierzcholek[0][0] - Promien
                    && Nowe_Przesuniecie[0] < SCE.P[j].Wys_Glob.Wierzcholek[1][0] + Promien
                    && Nowe_Przesuniecie[1] > SCE.P[j].Wys_Glob.Wierzcholek[0][1] - Promien
                    && Nowe_Przesuniecie[1] < SCE.P[j].Wys_Glob.Wierzcholek[2][1] + Promien
              )
            {
                ///KOLIZJA
                cout<<endl<<"!!! Ruch nie moze byc kontynuowany ze wzgledu"
                    <<endl
                    <<"!!! na wystapienie kolizji."<<endl;

                flaga_kolizji=1;          ///Nastapila kolizja
                break;                    /// przerwij sprawdzanie innych przeszkod
            }
        }


        int n;
        n = SCE.RRR.size();            //sprawdza ile jest robotow

        for( int j=0 ; j<n ; j++)                                     //sprawdza kolizje dla kazdego robota
        {


            Wektor2D Wektor_Robotow;
            double Odleglosc_Robotow;

            Wektor_Robotow= Nowe_Przesuniecie - SCE.RRR[j].Wek_translacji;

            Odleglosc_Robotow= sqrt( (Wektor_Robotow[0]*Wektor_Robotow[0]) + (Wektor_Robotow[1]*Wektor_Robotow[1]) );

            if( numer_robota == (j+1) )
            {
                continue;
            }
            else if( Odleglosc_Robotow <= (SCE.Aktualny_Robot->Promien + SCE.RRR[j].Promien))
            {
                ///KOLIZJA
                cout<<endl<<"!!! Ruch nie moze byc kontynuowany ze wzgledu"
                    <<endl
                    <<"!!! na wystapienie kolizji."<<endl;

                flaga_kolizji=1;          ///Nastapila kolizja
                break;                    /// przerwij sprawdzanie robotow
            }
        }


        if(flaga_kolizji==1)
            break;                  ///przerwij ruch


        Przod(Wlasciwy);

        Zapisz_Do_Pliku( Nazwa_Pliku.c_str(), Lacze );

        R_Sciezka.Rysuj_Sciezka( Wek_translacji,Lacze);

        Lacze.Rysuj();

        delay();
    }
}


void Robot::Ustaw_Krok(double wymiar)
{
    krok=wymiar;
}


void Robot::Animacja_Obrot(int kat, PzG::LaczeDoGNUPlota & Lacze)
{
    double skok_katowy;
    if(kat>0)
        skok_katowy=2;    //Co ile ma sie obracac przy animacji
    else
        skok_katowy=-2;

    int ilosc_obrotow;
    ilosc_obrotow = abs(kat/skok_katowy);

    for(int i=0; i<ilosc_obrotow; i++)
    {
        Obroc(skok_katowy);
        Zapisz_Do_Pliku( Nazwa_Pliku.c_str() , Lacze );
        Lacze.Rysuj();
        delay();

    }

    double ostatni_obrot;                                 ///Obraca sie do konca o kat mniejszy niz skok katowy, np. skok_kotowy =10  kat = 95 , to ostatni_obrot =5

    if((kat/(ilosc_obrotow * skok_katowy))==1)
        ostatni_obrot=0;
    else
        ostatni_obrot = kat - (ilosc_obrotow * skok_katowy);

    Obroc(ostatni_obrot);
    Zapisz_Do_Pliku( Nazwa_Pliku.c_str() , Lacze );

    Lacze.Rysuj();
    delay();

}


Wektor2D Robot::Pokaz_Wektor_Translacji()
{
    return Wek_translacji;
}


void Robot::Powieksz_Robota(float x, PzG::LaczeDoGNUPlota & Lacze)
{
    int i;
    i=Wys_Lok.Sprawdz_ilosc();


    for(int j=0; j<i; j++)
    {
        Wys_Lok.Wierzcholek[j][0] = Wys_Lok.Wierzcholek[j][0] * x;
        Wys_Lok.Wierzcholek[j][1] = Wys_Lok.Wierzcholek[j][1] * x;


    }
    Ustaw_Lok();

    Obroc(0);

    Promien *= x;

    Zapisz_Do_Pliku( Nazwa_Pliku.c_str(), Lacze );
    Lacze.Rysuj();
}

