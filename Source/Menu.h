#pragma once
#include "MenuOption.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>

using namespace std;

/*!
* \class Menu
* \brief Klasa obslugujaca menu
*
* \param current aktualnie wybrana opcja w menu
* \param background bitmapa tla menu
* \param font czcionka do wyswietlania napisow
*/

class Menu
{
public:
	int current;
	vector <MenuOption> menu_options;
	ALLEGRO_BITMAP* background;
	ALLEGRO_FONT* font;
	/**
	 * Destruktor
	 *
	 */
	~Menu();
	/**
	 * Konstruktor
	 *
	 */
	Menu();
	/**
	 * Petla glowna menu
	 *
	 * \param queue kolejka
	 * \return zwraca id wybranej przez uzytkownika opcji
	 */
	int mainLoop(ALLEGRO_EVENT_QUEUE* queue);
	/**
	 * Wyswietlenie danej opcji wybranej w menu
	 */
	void view();
	/**
	 * Wyswietlenie menu
	 */
	void showMenu(vector <MenuOption> bitmaps);
	/**
	 * Zmiana wybranej opcji w menu po nacisnieciu przez uzytkownika strzalki w prawo lub lewo
	 */
	int menuLeftRight(vector <MenuOption> bitmaps, int current);
	/**
	* Zmiana wybranej opcji w menu po nacisnieciu przez uzytkownika strzalki w gore
	*/
	int menuUp(vector <MenuOption> bitmaps, int current);
	/**
	 * Zmiana wybranej opcji w menu po nacisnieciu przez uzytkownika strzalki w dol
	 */
	int menuDown(vector <MenuOption> bitmaps, int current);
	/**
	 * Zmiana wybranej opcji w menu po najechaniu myszka na dana opcje
	 */
	int menuMouse(int x, int y, vector <MenuOption> bitmaps, int current);
	/**
	 * Sprawdzenie kolizji pomiedzy kursorem, a przyciskiem
	 */
	bool collision(ALLEGRO_BITMAP* bitmap, double x1, double y1, double x2, double y2);
};
