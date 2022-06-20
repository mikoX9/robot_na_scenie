#include <iostream>
#include <stdio.h>

#include "Robot.hh"
#include "lacze_do_gnuplota.hh"
#include "Sciezka.hh"
#include "Scena.hh"

using namespace std;


void aktualna_informacja(Scena Sce);

void menu_wyswietl();


long int Wektor2D::ilosc_stworzonych=0;
long int Wektor2D::ilosc_istniejacych=0;


bool flaga=0;
char ch;

int main()
{
    PzG:: LaczeDoGNUPlota Lacze;
    Lacze.ZmienTrybRys(PzG::TR_2D);
    Lacze.UstawZakresY(0,300);
    Lacze.UstawZakresX(0,300);

    shared_ptr<Scena> Sce;  //tworzy nowy wskaznik
    Nowa_Scena(Sce);   //przypisuje adres do wskaznika
  
    Wektor2D TMP_W;

    TMP_W[0]=50;
    TMP_W[1]=50;
    Sce->Dodaj_Robota( Lacze , TMP_W);
    Sce->RRR[0].R_Sciezka.Rysuj_Sciezka(Sce->RRR[0].Pokaz_Wektor_Translacji() ,Lacze);    //wpisz punkt poczatkowy do pliku sciezki

    TMP_W[0]=70;
    TMP_W[1]=250;
    Sce->Dodaj_Robota( Lacze , TMP_W);
    Sce->RRR[1].R_Sciezka.Rysuj_Sciezka(Sce->RRR[1].Pokaz_Wektor_Translacji() ,Lacze);    //wpisz punkt poczatkowy do pliku sciezki
    Sce->RRR[1].Obroc_szybko( -90 , Lacze);

    TMP_W[0]=260;
    TMP_W[1]=100;
    Sce->Dodaj_Robota( Lacze , TMP_W);
    Sce->RRR[2].R_Sciezka.Rysuj_Sciezka(Sce->RRR[2].Pokaz_Wektor_Translacji() ,Lacze);    //wpisz punkt poczatkowy do pliku sciezki
    Sce->RRR[2].Obroc_szybko( 180 , Lacze);


    Sce->Aktualny_Robot = & Sce->RRR[0];      ///USTAWIENIE AKTUALNEGO WSTAZNIKA ROBOTA NA AKTUALNEGO ROBOTA


    Wektor2D W1,W3;

    W1[0]=15;
    W1[1]=100;
    W3[0]=40;
    W3[1]=170;
    Sce->Dodaj_Przeszkode( Lacze , W1 , W3 );

    W1[0]=130;
    W1[1]=100;
    W3[0]=200;
    W3[1]=200;
    Sce->Dodaj_Przeszkode( Lacze , W1 , W3 );

    W1[0]=150;
    W1[1]=250;
    W3[0]=250;
    W3[1]=285;
    Sce->Dodaj_Przeszkode( Lacze , W1 , W3 );

    W1[0]=140;
    W1[1]=20;
    W3[0]=160;
    W3[1]=40;
    Sce->Dodaj_Przeszkode( Lacze , W1 , W3 );




    Lacze.Rysuj();

    cout<<"Laczna ilosc stworzonych obiektow klasy Wektor2D: "<<Wektor2D::ilosc_stworzonych<<endl;
    cout<<"Ilosc istniejacych obiektow klasy Wektor2D: "<<Wektor2D::ilosc_istniejacych<<endl<<endl;

    menu_wyswietl();

    while(flaga==0)
    {
        aktualna_informacja(*Sce);


        cout<<endl;
        cout<<"Twoj wybor? (m - menu) >";
        cin>>ch;

        switch(ch)
        {

        case 'z':   ///zmiana szybkosci ruchu robota
        {
            double tmp;
            cout<<"Podaj nowa wartosc kroku robota: ";
            cin>>tmp;

            Sce->Aktualny_Robot ->Ustaw_Krok(tmp);
            break;
        }

        case 'o':   ///obrot robota
        {
            int tmp;
            cout<<"Podaj kat obrotu robota: ";
            cin>>tmp;

            Sce->Aktualny_Robot -> Animacja_Obrot(tmp, Lacze);
            break;
        }


        case 'j':   ///jazda na wprost
        {
            int tmp;
            do{
            cout<<"Podaj odleglosc jaka ma przemierzyc robot: ";
            cin>>tmp;
            if(tmp<0)
                cout<<"Odleglosc musi byc dodatnia"<<endl;
            }
            while(tmp<0);

            Sce->Aktualny_Robot -> Animacja_Przod(tmp, Lacze , *Sce);
            break;
        }


        case 'i':   ///skalowanie robota -> powiększenie
        {
            float x;
            cout<<"O ile powiekszyć robota?:" ;
            cin>>x;
            Sce->Aktualny_Robot -> Powieksz_Robota(x , Lacze);

            break;
        }



        case 'd':  ///dodaj robota
        {
                Sce->Dodaj_Robota( Lacze , TMP_W);

                Sce->Aktualny_Robot = & Sce->RRR[0];

                Lacze.Rysuj();


        break;
        }



        case 's':   ///selekcja robota
        {

        aktualna_informacja(*Sce);
        cout<<"   0 - zaniechaj zmiany selekcji"<<endl<<endl;

        int n=Sce->RRR.size();

        for(int i=0 ; i<n ; i++)
        {
          cout <<"Robot "<<Sce->RRR[i].numer_robota <<"."
               <<"   "<<"Wspolrzedne: "
               <<Sce->RRR[i].Pokaz_Wektor_Translacji()<<endl;
        }

        cout<<"Podaj numer robota, dla ktorego maja byc wykonane operacje sterowania"<<endl;

        int numer;
        do
        {
        cout<<"Wprowadz numer robota lub 0: ";

        cin>>numer;
        } while( numer > n);

        if(numer!=0)
        {
        Sce->Aktualny_Robot = & Sce->RRR[numer-1];
        cout <<endl<<"Robot "<<Sce->Aktualny_Robot->numer_robota <<"."
             <<"   "<<"Wspolrzedne: "
             <<Sce->Aktualny_Robot->Pokaz_Wektor_Translacji()<<endl;
        }
        break;
        }



        case 't':   ///zadaj translacje rysunku
        {
            Wektor2D tmp;
            cout<<"Podaj wektor translacji rysunku"<<endl;
            cin>>tmp;

            int n;

            n=Sce->RRR.size();
            for( int i=0 ; i<n ; i++)
            {
                Sce->RRR[i].Ustaw_Przesuniecie(tmp);
                Sce->RRR[i].Zapisz_Do_Pliku( Sce->RRR[i].Nazwa_Pliku.c_str() , Lacze);

                Sce->RRR[i].R_Sciezka.Ustaw_Przesuniecie(tmp);
                Sce->RRR[i].R_Sciezka.Zapisz_Do_Pliku( Sce->RRR[i].R_Sciezka.Nazwa_Pliku.c_str() , Lacze);
            }

            n=Sce->P.size();
            for( int i=0 ; i<n ; i++)
            {
                Sce->P[i].Ustaw_Przesuniecie(tmp);
                Sce->P[i].Zapisz_Do_Pliku( Sce->P[i].Nazwa_Pliku.c_str() , Lacze);

            }

            Lacze.Rysuj();
            break;
        }


        case 'p':   ///powrot do pierwotnego ustawienia rysunku
        {
            int n;

            n=Sce->RRR.size();
            for( int i=0 ; i<n ; i++)
            {
                Sce->RRR[i].Resetuj_Przesuniecie();
                Sce->RRR[i].Zapisz_Do_Pliku( Sce->RRR[i].Nazwa_Pliku.c_str() , Lacze);

                Sce->RRR[i].R_Sciezka.Resetuj_Przesuniecie();
                Sce->RRR[i].R_Sciezka.Zapisz_Do_Pliku( Sce->RRR[i].R_Sciezka.Nazwa_Pliku.c_str() , Lacze);
            }

            n=Sce->P.size();
            for( int i=0 ; i<n ; i++)
            {
                Sce->P[i].Resetuj_Przesuniecie();
                Sce->P[i].Zapisz_Do_Pliku( Sce->P[i].Nazwa_Pliku.c_str() , Lacze);

            }

            Lacze.Rysuj();
            break;
        }


        case 'k':   ///zakoncz dzialanie programu
        {
            flaga=1;
            break;
        }

        case 'm':   ///wyswietl ponownie menu
        {
            cout<<endl;
            menu_wyswietl();
            break;
        }



        default:
        {
            cout<<"Wybierz jedna z opcji"<<endl;
            menu_wyswietl();
        }
        }

    }

    cout<<endl<<"Laczna ilosc stworzonych obiektow klasy Wektor2D: "<<Wektor2D::ilosc_stworzonych<<endl;
    cout<<"Ilosc istniejacych obiektow klasy Wektor2D: "<<Wektor2D::ilosc_istniejacych<<endl;

    return 0;
}





void aktualna_informacja(Scena Sce)
{
    cout<<endl<<"Aktualnie wyselekcjonowanym robotem jest:"<<endl
        <<"Robot "<<Sce.Aktualny_Robot -> numer_robota <<"."
        <<"   "<<"Wspolrzedne: "
        <<Sce.Aktualny_Robot ->Pokaz_Wektor_Translacji()<<endl;
}

void menu_wyswietl()
{

    cout<<"z - zmiana szybkosci ruchu robota"           <<endl
        <<"o - obrot robota"                            <<endl
        <<"j - jazda na wprost"                         <<endl
        <<"i - skaluj robota"                           <<endl
        <<"d - dodaj robota"                            <<endl
        <<"s - selekcja robota"                         <<endl
                                                        <<endl
        <<"t - zadaj translacje rysunku"                <<endl
        <<"p - powrot do pierwotnego ustawienia rysunku"<<endl
                                                        <<endl
        <<"m - wyswietl menu"                           <<endl
                                                        <<endl
        <<"k - koniec dzialania programu"               <<endl;

}
