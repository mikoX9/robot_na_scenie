#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Wektor2D.hh"


/*!
* \brief Klasa modeluje macierz dwuwymiarowa.
*/
class Macierz2D {

public:

  /*!
   *  Pola macierzy
   */
  Wektor2D Kolumna[2];

  /*!
   * Przeciazenie wyjscia dla znaku []
   *
   * Pozwala na prostsze dostanie sie do pol macierzy
   * \param[in] Kol - wskazuje na odpowiedni elment
   * \return odpowiedni wektor
   */
  const Wektor2D& operator[ ] (int Kol) const { return Kolumna[Kol]; }

  /*!
   * Przeciazenie wejscia dla znaku []
   *
   * Pozwala na prostsze dostanie sie do pol macierzy
   * \param[in] Kol - wskazuje na odpowiedni elment
   * \return odpowiedni wektor
   */
  Wektor2D& operator[ ] (int Kol) { return Kolumna[Kol]; }

  /*!
   * Przeciazenie wyjscia dla znaku ()
   *
   * Pozwala na prostsze dostanie sie do pol macierzy
   * \param[in] Wi ,Ko  - wskazuja na odpowiednie elmenty
   * \return liczbe z wskazanego pola
   */
  const double operator( ) (int Wi, int Ko) const {return Kolumna[Ko][Wi];}

  /*!
   * Przeciazenie wejscia dla znaku ()
   *
   * Pozwala na prostsze dostanie sie do pol macierzy.
   * \param[in] Wi ,Ko  - wskazuja na odpowiednie elmenty.
   * \return liczbe z wskazanego pola.
   */
  double& operator( ) (int Wi, int Ko) {return Kolumna[Ko][Wi];}


  /*!
   * \brief Tworzy macierz trygonometryczna.
   *
   * Tworzy macierz trygonometryczna pozwalajaca obrocic punkt.
   * wzgleden srodka ukladu wspolrzednych.
   * \param[in] kat_rotacji - kat dla ktorego tworzy macierz.
   */
    void Stworz_Trygonometryczna(double kat_rotacji);     //kat w stopniach
};


  /*!
   * Przeciazenie mnozenia.
   *
   * Pozwala pomnozyc macierz przez wektor.
   * \param[in] M - macierz do pomnozenia.
   * \param[in] W - wektor do pomnozenia.
   * \return wynik w postaci wektora
   */
  Wektor2D operator * (Macierz2D M, Wektor2D W);


  /*!
   * Przeciazenie wyjscia.
   *
   * Wyswietla macierz.
   * \param[in] Strm - strumien gdzie ma wyswietlic macierz
   * \param[in] W - wektor do pomnozenia.
   * \return wynik w postaci wektora
   */
  std::ostream& operator << (std::ostream &Strm, const Macierz2D &Mac);


  /*!
   * Przeciazenie mnozenia.
   *
   * Pozwala pomnozyc macierz przez macierz.
   * \param[in] A,B - macierze do pomnozenia.
   * \return wynik w postaci macierzy
   */
  Macierz2D operator * (Macierz2D A, Macierz2D B);

#endif
