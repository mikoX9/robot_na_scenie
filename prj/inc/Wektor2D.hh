#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <cmath>

using namespace std;

/*!
* \brief Klasa modeluje wektora dwuwymiarowego.
*/
class Wektor2D {

private:

  /*!
   *  Pola wektora
   */
  double _Wsp[2];    // 0=x   1=y

public:

  static long int ilosc_stworzonych;
  static long int ilosc_istniejacych;


  /*!
   * \brief Przeciazenie wyjscia dla znaku []
   *
   * Pozwala na prostsze dostanie sie do pol wektora.
   * \param[in] Ind - wskazuje na odpowiedni elment.
   * \return wskazana liczbe.
   */
  double operator[ ] (int Ind) const { return _Wsp[Ind]; }

  /*!
   * \brief Przeciazenie wejscia dla znaku []
   *
   * Pozwala na prostsze dostanie sie do pol wektora.
   * \param[in] Ind - wskazuje na odpowiedni elment.
   * \return wskazana liczbe.
   */
  double& operator[ ] (int Ind) { return _Wsp[Ind]; }

  /*!
   * \brief Przeciazenie wejscia dla znaku &
   *
   * Pozwala wykonanie operacji iloczynu skalarnego
   * \param[in] V2 - wektor dla ktorego ma sie wykonac.
   * \return wskazana liczbe.
   */
  double operator & (const Wektor2D& V2) const;  //iloczyn skalarny

  /*!
   * \brief Przeciazenie wejscia dla znaku +
   *
   * Pozwala wykonanie operacji dodania dwoch wektorow.
   * \param[in] ex - wektor drugi ktory bierze udzial w opoeracji.
   * \return wynik dodawania w postaci wektora.
   */
  Wektor2D operator+ (Wektor2D const& ex);

  /*!
   * \brief Przeciazenie wejscia dla znaku -
   *
   * Pozwala wykonanie operacji odejmowania dwoch wektorow.
   * \param[in] ex - wektor drugi ktory bierze udzial w opoeracji.
   * \return wynik dodejmowania w postaci wektora.
   */
  Wektor2D operator- (Wektor2D const& ex);

  /*!
   * \brief Przeciazenie wejscia dla znaku =
   *
   * Pozwala przepisac wartosc jednego wektora do drugiego
   * \param[in] ex - wektor ktorego wartosc przepisujemy
   * \return wynik w postaci wektora.
   */
  Wektor2D operator = (Wektor2D ex);

  /*!
   * Konstruktor inicjujacy wektor.
   *
   * Konstruktor wpisuje domyslnie zera do wektora, obraz inkrementuje zmienne 'ilosc'.
   */
  Wektor2D();

  /*!
   * Destruktor czyszczacy.
   *
   * Destruktor dekrementuje zmienna ilosc_istniejacych.
   */
  ~Wektor2D();

};



  /*!
   * Przeciazenie wejscia.
   *
   * Pozwala na wprowadznie wektora.
   * \param[in] Strm - strumienia z ktorego ma czytac wektor.
   * \param[in] Wek - adres wektora do ktorego ma zapisac.
   * \return wynik powodzenia
   */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

  /*!
   * Przeciazenie wyjscia.
   *
   * Wyswietla wektor
   * \param[in] Strm - strumien gdzie ma wyswietlic wektor.
   * \param[in] Wek - wektor ktory ma wyswietlic.
   * \return wynik powodzenia
   */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
