#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <vector>
#include <sstream>   //dodawanie stringow

#include "Obiekt_graficzny.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"
#include "Robot.hh"

#include <memory>

/*!
* \brief Klasa modeluje pojecie sceny
*
* Klasa zawiera wszystkie obiekty ktore znajduja sie na rysunku.
*/
class Scena
{
public:


  shared_ptr<Scena> PtrRob;

  

   /*!
    *  Wskaznika aktualnego robota.
    */
    Robot * Aktualny_Robot;

   /*!
    *  Wektor zawierajacy wszytkie roboty.
    */
    vector < Robot >  RRR;

   /*!
    *  Wektor zawierajacy wszytkie przeszkody.
    */
    vector < Przeszkoda > P;


  /*!
   * \brief Dodaje nowego robota
   *
   * Metoda tworzy nowego robota dodaje go do wektora, tworzy plik robota, plik sceny,
   * oraz umieszcza robota na scenie w odpowiednim miejscu.
   * \param[in] W - Wektor polozenia poczatkowego robota
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   */
    void Dodaj_Robota( PzG::LaczeDoGNUPlota Lacze , Wektor2D W);

  /*!
   * \brief Dodaje nowa przeszkode
   *
   * Metoda tworzy nowa przeszkode, tworzy plik przeszkody,
   * oraz umieszcza przeszkode na scenie w wybranym miejscu.
   * \param[in] W1, W3 - polozenie prostej tworzacej glowna przekatna.
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   */
    void Dodaj_Przeszkode( PzG::LaczeDoGNUPlota Lacze , Wektor2D W1 , Wektor2D W3);


};


 void Nowa_Scena(shared_ptr<Scena> &SSS);



#endif
