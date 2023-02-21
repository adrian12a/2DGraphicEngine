#pragma once
#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Point2D.h"

using namespace std;

/*!
* \class PrimitiveRenderer
* \brief Tworzenie prymitywow
*
*/

class PrimitiveRenderer
{
	/**
	 * Funkcja pomocnicza do rysowania linii
	 *
	 * \param x0 wspolrzedna x poczatku linii
	 * \param y0 wspolrzedna y poczatku linii
	 * \param x1 wspolrzedna x konca linii
	 * \param y1 wspolrzedna y konca linii
	 */
	static void draw_line_x(int x0, int y0, int x1, int y1);
	/**
	 * Funkcja pomocnicza do rysowania linii
	 *
	 * \param x0 wspolrzedna x poczatku linii
	 * \param y0 wspolrzedna y poczatku linii
	 * \param x1 wspolrzedna x konca linii
	 * \param y1 wspolrzedna y konca linii
	 */
	static void draw_line_y(int x0, int y0, int x1, int y1);
public:
	/**
	 * Rysowanie linii
	 *
	 * \param x0 wspolrzedna x poczatku linii
	 * \param y0 wspolrzedna y poczatku linii
	 * \param x1 wspolrzedna x konca linii
	 * \param y1 wspolrzedna y konca linii
	 */
	static void line(int x0, int y0, int x1, int y1);
	/**
	 * Rysowanie piksela
	 *
	 * \param x wspolrzedna x
	 * \param y wspolrzedna y
	 * \param r skladowa koloru - czerwony
	 * \param g skladowa koloru - zielony
	 * \param b skladowa koloru - niebieski
	 */
	static void draw_pixel(int x, int y, int r, int g, int b);
	/**
	 * Rysowanie linii lamanej otwartej
	 *
	 * \param zbior punktow
	 */
	static void broken_line_open(vector<Point2D> v);
	/**
	 * Rysowanie linii lamanej zamknietej
	 *
	 * \param zbior punktow
	 */
	static void broken_line_closed(vector<Point2D> v);
	/**
	 * Rysowanie okregu
	 *
	 * \param xc wspolrzedna x srodka okregu
	 * \param yc wspolrzedna y srodka okregu
	 * \param r promien
	 * \param R skladowa koloru - czerwony
	 * \param G skladowa koloru - zielony
	 * \param B skladowa koloru - niebieski
	 */
	static void circle(int xc, int yc, int r, int R, int G, int B);
	/**
	 * Rysowanie elipsy
	 *
	 * \param xc wspolrzedna x srodka elipsy
	 * \param yc wspolrzedna y srodka elipsy
	 * \param rx promien x
	 * \param ry promien y
	 * \param R skladowa koloru - czerwony
	 * \param G skladowa koloru - zielony
	 * \param B skladowa koloru - niebieski
	 */
	static void ellipse(int xc, int yc, int rx, int ry, int R, int G, int B);
	/**
	 * Punkt wspolny dwoch linii
	 *
	 * \param x1 wspolrzedna x poczatku linii nr 1
	 * \param y1 wspolrzedna y poczatku linii nr 1
	 * \param x2 wspolrzedna x konca linii nr 1
	 * \param y2 wspolrzedna y konca linii nr 1
	 * \param x3 wspolrzedna x poczatku linii nr 2
	 * \param y3 wspolrzedna y poczatku linii nr 2
	 * \param x4 wspolrzedna x konca linii nr 2
	 * \param y4 wspolrzedna y konca linii nr 2
	 * \return
	 */
	static bool common_point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	/**
	 * Rysowanie wielokatu
	 *
	 * \param v zbior punktow
	 * \return true - nie da sie stworzyc wielokatu linie sie przecinaja
	 */
	static bool polygon(vector<Point2D> v);
	/**
	 * Wypelnianie kolorem metoda boundry fill
	 *
	 * \param x wspolrzedna x od ktorej zaczynamy wypelnianie
	 * \param y wspolrzedna y od ktorej zaczynamy wypelnianie
	 * \param fill_color kolor wypelnienia
	 * \param boundry_color kolor granicy
	 * \param display ekran
	 */
	static void boundry_fill(int x, int y, ALLEGRO_COLOR fill_color, ALLEGRO_COLOR boundry_color, ALLEGRO_DISPLAY* display);
	/**
	 * Wypelnianie kolorem metoda flood fill
	 *
	 * \param x wspolrzedna x od ktorej zaczynamy wypelnianie
	 * \param y wspolrzedna y od ktorej zaczynamy wypelnianie
	 * \param fill_color kolor wypelnienia
	 * \param background_color kolor tla
	 * \param display ekran
	 */
	static void flood_fill(int x, int y, ALLEGRO_COLOR fill_color, ALLEGRO_COLOR background_color, ALLEGRO_DISPLAY* display);
	/**
	 * Translacja (przesuniecie)
	 *
	 * \param v zbior punktow
	 * \param t wektor t
	 * \return zbior punktow po translacji
	 */
	static vector<Point2D> translation(vector<Point2D> v, int t);
	/**
	 * Rotacja wzgledem poczatku ukladu wspolrzednych
	 *
	 * \param v zbior punktow
	 * \param alfa kat o jaki nalezy obrocic obiekt
	 * \return zbior punktow po rotacji
	 */
	static vector<Point2D> rotation(vector<Point2D> v, float alfa);
	/**
	 * Rotacja wzgledem dowolnego punktu
	 *
	 * \param v zbior punktow
	 * \param alfa kat o jaki nalezy obrocic obiekt
	 * \param x1 wspolrzedna x punktu wzgledem ktorego nalezy obrocic obiekt
	 * \param y1 wspolrzedna y punktu wzgledem ktorego nalezy obrocic obiekt
	 * \return zbior punktow po rotacji
	 */
	static vector<Point2D> rotation(vector<Point2D> v, float alfa, int x1, int y1);
	/**
	 * Jednokladnosc (skalowanie) wzgledem poczatku ukladu wspolrzednych
	 *
	 * \param v zbior punktow
	 * \param k wspolczynnik skalowania k
	 * \return zbior punktow po wykonaniu operacji skalowania
	 */
	static vector<Point2D> scale(vector<Point2D> v, int k);
	/**
	 * Jednokladnosc (skalowanie) wzgledem dowolnego punktu
	 *
	 * \param v zbior punktow
	 * \param k wspolczynnik skalowania k
	 * \param x wspolrzedna x punktu wzgledem ktorego nalezy wykonac skalowanie
	 * \param y wspolrzedna y punktu wzgledem ktorego nalezy wykonac skalowanie
	 * \return zbior punktow po wykonaniu operacji skalowania
	 */
	static vector<Point2D> scale(vector<Point2D> v, int k, int x, int y);
};
