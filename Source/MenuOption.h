#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/*!
* \class MenuOption
* \brief Klasa zawierajaca obiekty przyciskow w menu
*
* \param active bitmapa - przycisk aktywny
* \param inactive bitmapa - przycisk nieaktywny
* \param x wspolrzedna x przycisku
* \param y wspolrzedna y przycisku
*/

class MenuOption {
public:
	MenuOption(const char* bitmap_active, const char* bitmap_inactive, int x, int y);
	ALLEGRO_BITMAP* active;
	ALLEGRO_BITMAP* inactive;
	int x;
	int y;
};
