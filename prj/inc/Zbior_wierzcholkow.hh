#ifndef ZBIOR_WIERZCHOLKOW_HH
#define ZBIOR_WIERZCHOLKOW_HH

#include <iostream>
#include <vector>
#include "Wektor2D.hh"


using namespace std;

class Obikt_Graficzny;

/*!
* \brief Klasa modeluje zbior wierzcholkow.
*/
class Zbior_Wierzcholkow{

public:

  /*!
   *  Szablon vector typu Wektor2D
   */
  vector < Wektor2D > Wierzcholek;

  /*!
   * \brief Dodawanie wierzcholka.
   *
   * Metoda dodaje wierzcholek.
   * \param[in] W - wierzcholek ktory jest dodawany.
   */
  void DodajWierzcholek(Wektor2D W);

  /*!
   * \brief Dodawanie wierzcholka.
   *
   * Metoda dodaje wierzcholek.
   * \param[in] a,b - wspolrzedne wierzcholak ktory jest dodawany.
   */
  void DodajWierzcholek(double x, double y);

  /*!
   * \brief Sprawdza ilosc elementow
   *
   * Metoda sprawdza ile wierzcholkow zawiera obiekt
   * \return ilosc elementow w obiekcie
   */
  int Sprawdz_ilosc();



 /// friend class Obiekt_Graficzny;                         !!!!!

};


#endif
