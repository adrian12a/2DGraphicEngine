#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
#include "Direction.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/*!
* \class Player
* \brief Glowna klasa modelu gracza
*
* \param event event
* \param queue kolejka
* \param front_1 pierwsza bitmapa dla ruchu gracza w gore
* \param front_2 druga bitmapa dla ruchu gracza w gore
* \param front_3 trzecia bitmapa dla ruchu gracza w gore
* \param back_1 pierwsza bitmapa dla ruchu gracza w dol
* \param back_2 druga bitmapa dla ruchu gracza w dol
* \param back_3 trzecia bitmapa dla ruchu gracza w dol
* \param left_1 pierwsza bitmapa dla ruchu gracza w lewo
* \param left_2 druga bitmapa dla ruchu gracza w lewo
* \param left_3 trzecia bitmapa dla ruchu gracza w lewo
* \param right_1 pierwsza bitmapa dla ruchu gracza w prawo
* \param right_2 druga bitmapa dla ruchu gracza w prawo
* \param right_3 trzecia bitmapa dla ruchu gracza w prawo
* \param plater obiekt do animacji modelu gracza
* \param direction kierunek poruszania sie gracza
* \param x wspolrzedna x gracza
* \param y wspolrzedna y gracza
* \param width szerokosc bitmapy gracza
* \param height wysokosc bitmapy gracza
* \param vector_x poruszanie sie gracza w kierunku poziomym
* \param vector_y poruszanie sie gracza w kierunku pionowym
* \param speed predkosc poruszania
* \param timer timer
*/

class Player
{
public:
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE* queue;
	BitmapObject front_1 = BitmapObject("front_1.png");
	BitmapObject front_2 = BitmapObject("front_2.png");
	BitmapObject front_3 = BitmapObject("front_3.png");
	BitmapObject back_1 = BitmapObject("back_1.png");
	BitmapObject back_2 = BitmapObject("back_2.png");
	BitmapObject back_3 = BitmapObject("back_3.png");
	BitmapObject left_1 = BitmapObject("left_1.png");
	BitmapObject left_2 = BitmapObject("left_2.png");
	BitmapObject left_3 = BitmapObject("left_3.png");
	BitmapObject right_1 = BitmapObject("right_1.png");
	BitmapObject right_2 = BitmapObject("right_2.png");
	BitmapObject right_3 = BitmapObject("right_3.png");
	AnimatedObject player = AnimatedObject(3);
	Direction direction;
	int x;
	int y;
	int width;
	int height;
	int vector_x;
	int vector_y;
	int speed;
	ALLEGRO_TIMER* timer;
	/**
	 * Konstruktor
	 *
	 * \param x wspolrzedna x gracza
	 * \param y wspolrzedna y gracza
	 * \param width szerokosc bitmapy gracza
	 * \param height wysokosc bitmapy gracza
	 */
	Player(int x, int y, int width, int height);
	/**
	 * Destruktor
	 *
	 */
	~Player();
	/**
	 * Wyswietlenie modelu gracza
	 *
	 */
	void draw();
};
