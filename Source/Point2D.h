#pragma once
#include <iostream>

using namespace std;

/*!
* \class Point2D
* \brief Punkt/piksel
*
* \param x wspolrzedna x punktu
* \param y wspolrzedna y punktu
*/

class Point2D
{
public:
	int x;
	int y;
	/**
	 * Konstruktor
	 *
	 * \param x wspolrzedna x punktu
	 * \param y wspolrzedna y punktu
	 */
	Point2D(int x, int y);
	/**
	 * Modyfikowanie wspolrzednych punktu
	 *
	 * \param x wspolrzedna x punktu
	 * \param y wspolrzedna y punktu
	 */
	void modify(int x, int y);
	/**
	 * Wyswietlenie punktu w danym kolorze
	 *
	 * \param r skladowa koloru - czerwony
	 * \param g skladowa koloru - zielony
	 * \param b skladowa koloru - niebieski
	 */
	void draw(int r, int g, int b);
};
