#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

/*!
* \class Engine
* \brief Glowna klasa silnika
*
* \param display ekran
* \param timer timer
* \param width szerokosc ekranu
* \param height wysokosc ekranu
*/

class Engine
{
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
public:
	int width;
	int height;
	/**
	 * Konstruktor
	 *
	 * \param width szerokosc ekranu
	 * \param height wysokosc ekranu
	 * \param fullscreen true - uruchomienie aplikacji w trybie pelnoekranowym, false - w oknie
	 * \param fps liczba klatek na sekunde
	 */
	Engine(int width, int height, bool fullscreen, int fps);
	/**
	 * Wyczyszczenie ekranu na dany kolor
	 *
	 * \param R skladowa koloru - czerwony
	 * \param G skladowa koloru - zielony
	 * \param B skladowa koloru - niebieski
	 */
	void clear_screen(int R, int G, int B);
	/**
	 * Zmiana rozdzielczosci aplikacji
	 *
	 * \param width szerokosc ekranu
	 * \param height wysokosc ekranu
	 */
	void change_resolution(int width, int height);
	/**
	 * Uruchomienie timera
	 *
	 */
	void start_timer();
	/**
	 * Zatrzymanie timera
	 *
	 */
	void stop_timer();
	/**
	 * Stworzenie kolejki
	 *
	 * \param keyboard true - kolejka obsluguje klawiature
	 * \param mouse true - kolejka obsluguje mysz
	 * \return zwraca kolejke
	 */
	static ALLEGRO_EVENT_QUEUE* make_queue(bool keyboard, bool mouse);
	/**
	 * Zniszczenie kolejki
	 *
	 * \param queue kolejka
	 */
	void destroy_queue(ALLEGRO_EVENT_QUEUE* queue);
	/**
	 * Czyszczenie pamieci
	 *
	 */
	void free_memory();
	/**
	 * Glowna petla silnika
	 *
	 */
	void main_loop();
};
