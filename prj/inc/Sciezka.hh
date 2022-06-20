#ifndef SCIEZKA_HH
#define SCIEZKA_HH

#include "Obiekt_graficzny.hh"
#include "lacze_do_gnuplota.hh"


/*!
* \brief Klasa modeluje sciezke robota.
*
* Klasa sciezka pozwala na ryowanie toru ruchu robota
*/
class Sciezka :public Obiekt_Graficzny
{
public:

  /*!
   * Inicjalizuje pola
   *
   * Konstruktor przydziela warotsc 0,0 waktorowi przesuniecia.
   */
  Sciezka();

  /*!
   * \brief Dopisuje do pliku
   *
   * Metoda zapisuje wektor W jako aktualny wektor tymczasowy oraz dopisuje
   * aktualny wektor translacji robota do pliku.
   * \param[in] W - wektor ktory dopisuje do pliku.
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   */
  void Rysuj_Sciezka(Wektor2D W , PzG::LaczeDoGNUPlota Lacze);

  /*!
   * \brief Dopisuje wektor do pliku
   *
   * Metoda ta dopisuje wektor do pliku. Rozni sie tym od metody z klasy podstawowej,
   * ze otwiera plik do dopisywania, obraz nie zapisuje jeszcze raz pierwszej wspolrzednej
   * \param[in] *sNazwaPliku - nazwa pliku do ktorego ma zapisac dane.
   * \param[in] Lacze  -potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   * \param[in] W - wektor ktory zapisuje do pliku.
   * \return 0 jesli powodzenie, 1 jesli nie.
   */
  bool Zapisz_Do_Pliku( const char  *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze);

  /*!
   * \brief Resetuje plik
   *
   * Metoda ta otwiera nowy czysty plik dzieki czemu usuwa stary o tej samej nazwie.
   * \param[in] *sNazwaPliku - nazwa pliku ktory ma usunac.
   */
  void Resetuj_Plik(const char  *sNazwaPliku);                    /// nadpisuje stary plik sNazwaPliku i tworzy nowy  => docenowo "Sciezka.dat"

};




#endif
