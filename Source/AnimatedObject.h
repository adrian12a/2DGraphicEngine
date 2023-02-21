#pragma once
#include "BitmapObject.h"
#include "Direction.h"
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

/*!
* \class AnimatedObject
* \brief Klasa zawierajaca obiekty ktore mozna animowac
*
* \param left kolekcja spriteow wyswietlanych przy ruchu w lewo
* \param right kolekcja spriteow wyswietlanych przy ruchu w prawo
* \param up kolekcja spriteow wyswietlanych przy ruchu w gore
* \param down kolekcja spriteow wyswietlanych przy ruchu w dol
* \param size liczba spriteow w pojedynczej kolekcji
* \param waiter zmienna pomocnicza do tworzenia opoznienia miedzy kolejnymi klatkami animacji
* \param i zmienna pomocnicza do tworzenia opoznienia miedzy kolejnymi klatkami animacji
*/

class AnimatedObject
{
public:
	vector<ALLEGRO_BITMAP*> left;
	vector<ALLEGRO_BITMAP*> right;
	vector<ALLEGRO_BITMAP*> up;
	vector<ALLEGRO_BITMAP*> down;
	int size;
	double waiter;
	int i;
	/**
	 * Konstruktor
	 *
	 * \param number_of_elements liczba spriteow w jednym kierunku
	 */
	AnimatedObject(int number_of_elements);
	/**
	 * Dodanie nowej bitmapy do kolekcji
	 *
	 * \param bitmap bitmapa - obiekt klasy BitmapObject
	 * \param direction kierunek dla ktorego ma byc wyswietlana dana bitmapa
	 */
	void add_bitmap(BitmapObject bitmap, Direction direction);
	/**
	 * Wyswietlenie animacji
	 *
	 * \param x wspolrzedna x
	 * \param y wspolrzedna y
	 * \param direction kierunek poruszania sie
	 */
	void draw(int x, int y, Direction direction);
};
