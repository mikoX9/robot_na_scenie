#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>

#include "Obiekt_graficzny.hh"
#include "Wektor2D.hh"
#include "Zbior_wierzcholkow.hh"


using namespace std;

/*!
* \brief Klasa modeluje przeszkode.
*
* Klasa dziedziczy publicznie z klasy Obiekt_Graficzny, zawiera wspolrzedne przeszkody,
* oraz metode na utworzenie ich.
*/
class Przeszkoda :public Obiekt_Graficzny
{
public:

  /*!
   * \brief Tworzy przeszkode
   *
   * Metoda buduje przeszkode z wykorzystaniem polozenia glownej przekatnej.
   * \param[in] W1, W3 - wspolrzedne polozenia glownej przekatnej.
   */
  void Buduj_Przeszkode( Wektor2D W1 , Wektor2D W3);

};





#endif
