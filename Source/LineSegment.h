#pragma once

/*!
* \class LineSegment
* \brief Linia
*
* \param x0 wspolrzedna x poczatku linii
* \param y0 wspolrzedna y poczatku linii
* \param x1 wspolrzedna x konca linii
* \param y1 wspolrzedna y konca linii
*/

class LineSegment
{
public:
	int x0, y0, x1, y1;
	/**
	 * Konstruktor
	 *
	 * \param x0 wspolrzedna x poczatku linii
	 * \param y0 wspolrzedna y poczatku linii
	 * \param x1 wspolrzedna x konca linii
	 * \param y1 wspolrzedna y konca linii
	 */
	LineSegment(int x0, int y0, int x1, int y1);
	/**
	 * Modyfikowanie wspolrednych poczatku i konca linii
	 *
	 * \param x0 wspolrzedna x poczatku linii
	 * \param y0 wspolrzedna y poczatku linii
	 * \param x1 wspolrzedna x konca linii
	 * \param y1 wspolrzedna y konca linii
	 */
	void modify(int x0, int y0, int x1, int y1);
	/**
	 * Wyswietlenie linii
	 *
	 */
	void draw();
};
