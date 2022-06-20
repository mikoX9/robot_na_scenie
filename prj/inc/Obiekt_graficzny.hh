#ifndef OBIEKT_GRAFICZNY_HH
#define OBIEKT_GRAFICZNY_HH

#include "Wektor2D.hh"
#include "Zbior_wierzcholkow.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;


/*!
* \brief Klasa modeluje obiekt graficzny.
*
* Klasa Obiekt_Graficzny jest klasa bazowa z ktorej dzidzicza postale klasy.
*/
class Obiekt_Graficzny
{

protected:
    /*!
    *  Pole przechowuje wspolrzedne wierzcholkow globalnych.
    */
  Zbior_Wierzcholkow Wys_Glob;

    /*!
    *  Pole przechowuje wspolrzedne wierzcholkow lokalnych.
    *  Pozostaja niezmienne od inicjalizacji do konca dzialania programu.
    */
  Zbior_Wierzcholkow Wys_Lok;

    /*!
    *  Pole przechowuje wartosc wektora translacji.
    */
  Wektor2D Wek_translacji;

    /*!
    *  Pole przechowuje aktualny kat rotacji.
    */
  int kat_rotacji;                //int -> zeby zaokraglalo


   /*!
    *  Pole przechowuje aktualny wektor przesuniecia obiektu, potrzebny
    * do przesuwania calego rysunku, obraz do wracania pozycji startowej.
    */
  Wektor2D Wek_Przesuniecia;


  friend class Robot;

 //normalnie w public:

  /*!
   * \brief Reseruje globalne wspolrzedne
   *
   * Metoda ustawia Wsp_Glob na Wsp_Lok
   */
  void Ustaw_Lok(void);

  /*!
   * \brief Ustawia odpowienie wspolrzedne globalne
   *
   * Metoda ta dodaje do aktualnych wspolrzednych globalnych wektor translacji.
   */
  void Ustaw_Glob(void);

public:
   string Nazwa_Pliku;    ///nazwa pliku w ktorym zapisuje wspolrzedne


  /*!
   * \brief Zapisuje wzpolrzedne obiektu do pliku
   *
   * Metoda ta automatycznie sprawdza ile wierzcholkow posiada obiekt,
   * a na koncu zapisuje jeszcze raz pierwszy punkt, zeby gnuplot narysowal pelna figure.
   * \param[in] *sNazwaPliku - nazwa pliku do ktorego ma zapisac dane.
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   * \return 0 jesli powodzenie, 1 jesli nie.
   */
  bool Zapisz_Do_Pliku(const char  *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze);

  /*!
   * \brief Obraca obiekt o kat
   *
   * Metoda ta dodaje kat do aktualnego kat_rotacji, reseruje obrot obiektu i obraca
   * obiekt o kat_rotacji. Nie zapisuje do pliku.
   * \param[in] kat - kat o ktory ma obrocic obiekt
   */
  void Obroc(int kat);


  /*!
   * \brief Ustawia przesuniecie
   *
   * Metoda przestawia przesuniecie obiektu
   * \param[in] Prz - wektor przesuniecia ktory dodaje do aktualnego.
   */
  void Ustaw_Przesuniecie(Wektor2D Prz);

  /*!
   * \brief Resetuje przesuniecie
   *
   * Metoda resetuje wektor przsuniecia do 0
   */
  void Resetuj_Przesuniecie();

  /*!
   * \brief Zmiena polozenie
   *
   * Metoda przestawia robota na wskazane polozenie, oraz resetuje sciezke.
   * \param[in] W - nowe plozenie robota
   */
  void Zmien_Polozenie(Wektor2D W);

  /*!
   * \brief Zmienia wektor translacji
   *
   * Metoda przydziela nowa wartosc wektorowi translacji.
   * \param[in] W - nowa wartosc wektora
   */
  void Zmien_Wek_Translacji( Wektor2D W);

  /*!
   * \brief Obraca obiekt
   *
   * Metoda obraca obiekt bez animacji.
   * \param[in] kat - kat o ktory ma obrocic obiekt
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   */
  void Obroc_szybko(int kat , PzG::LaczeDoGNUPlota Lacze);

};



#endif
