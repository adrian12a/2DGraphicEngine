#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/*!
* \class BitmapObject
* \brief Klasa zawierajaca obiekty ktore mozna wyswietlic
*
* \param width szerokosc bitmapy
* \param height wysokosc bitmapy
* \param bitmap bitmapa
*/

class BitmapObject {
public:
	int width;
	int height;
	ALLEGRO_BITMAP* bitmap;
	/**
	 * Konstruktor domyslny
	 *
	 * \param filename nazwa pliku z bitmapa
	 */
	BitmapObject(const char* filename);
	/**
	 * Konstruktor dla bitmapy z przezroczystoscia
	 *
	 * \param filename nazwa pliku z bitmapa
	 * \param mask maska przezroczystosci
	 */
	BitmapObject(const char* filename, ALLEGRO_COLOR mask);
	/**
	 * wyswietlenie bitmapy
	 *
	 * \param x wspolrzedna x
	 * \param y wspolrzedna y
	 */
	void draw(int x, int y);
};
