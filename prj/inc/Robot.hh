#ifndef ROBOT_HH
#define ROBOT_HH

#include "Obiekt_graficzny.hh"
#include "Sciezka.hh"


class Scena;

/*!
* \brief Klasa modeluje robota.
*
* Klasa dziedziczy publicznie z klasy Obiekt_Graficzny.
*/
class Robot :public Obiekt_Graficzny
{

   /*!
    *  Pole przechowuje dlugosc kroku robota.
    */
   double krok;

   /*!
    *  Pole przechowuje promien robota
    */
   int Promien;

public:

  /*!
   *  Obiekt sciezka dla robota
   */
  Sciezka R_Sciezka;    //sciezka dla kazdego robota

  /*!
   *  Pole przechowuje numer robota
   */
  int numer_robota;


  /*!
   * Inicjalizuje pola
   *
   * Konstruktor przydziela wartosci startowe.
   */
  Robot( Wektor2D );

  /*!
   * \brief Ruch robta do przodu
   *
   * Metoda oblicza odpowiedni wektor i aktualizuje waktor
   * przesuniecia zgodnie z aktulanym polozeniem
   * \param[in] odleglosc - odleglosc ktora robot ma pokonac
   */
  void Przod( Wektor2D Wlasciwy);

  /*!
   * \brief Animacja ruchu
   *
   * Metoda animuje ruch robota, przesuwa go do miejsca w
   * ktorym ma sie znalezc wektorami o dlugosci kroku robota.
   * \param[in] odleglosc - odleglosc ktora robot ma pokonac.
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   * \param[in] S - obiekt klasy sciezka do ktorego zapisywane i wyswietlane sa kolejne wspolrzedne.
   */
  void Animacja_Przod(double odleglosc, PzG::LaczeDoGNUPlota & Lacze , Scena & SCE);   ///dzieki przekazaniu przez dereferencje NIE otwiera się nowe okno podczas ponownego wywolania funkcji :D
  /// Sciezke S przekazujemy przez dereferencje poniewaz gdyby nie to animacja pracowala by na kopii i nic nie zmianiala w obiekcie, czyli nie dodawalaby nowych punktow do orginalu


  /*!
   * \brief Ustawianie kroku
   *
   * Metoda ustawia krok na podana wartosc.
   * \param[in] wymiar - wartosc nowego kroku.
   */
  void Ustaw_Krok(double wymiar);

  /*!
   * \brief Animacja obrotu
   *
   * Metoda animuje obrot robota, obraca go o zadany wektor dzieki malym kata.
   * \param[in] kat - kat o ktory ma obrocic robota.
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   */
  void Animacja_Obrot(int kat, PzG::LaczeDoGNUPlota & Lacze);

  /*!
   * \brief Pokazywanie wektora
   *
   * Metoda pokazuje wektor.
   * \return Wektor translacji
   */
  Wektor2D Pokaz_Wektor_Translacji();

  /*!
   * \brief Skalowanie robota
   *
   * Metoda powieksza/pomniejsza robota
   * \param[in] x - ile razy ma powiekszyc robota (watorsci 0<x<1 pomniejszaja robota.
   * \param[in] Lacze - potrzebne do wywolania metody Rysuj() dla klasy LaczeDoGNUPlota.
   */
  void Powieksz_Robota(float x , PzG::LaczeDoGNUPlota & Lacze);

};



#endif
