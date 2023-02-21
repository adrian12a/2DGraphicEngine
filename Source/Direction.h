#pragma once

/*!
* \class Direction
* \brief Typ wyliczeniowy zawierajacy dostepne kierunki w animacji
*
* \param UP animacja w gore
* \param DOWN animacja w dol
* \param RIGHT animacja w prawo
* \param LEFT animacja w lewo
* \param STATIC_UP obiekt nie porusza sie, skierowany w gore
* \param STATIC_DOWN obiekt nie porusza sie, skierowany w dol
* \param STATIC_RIGHT obiekt nie porusza sie, skierowany w prawo
* \param STATIC_LEFT obiekt nie porusza sie, skierowany w lewo
*/

enum Direction {
	UP, DOWN, RIGHT, LEFT, STATIC_UP, STATIC_DOWN, STATIC_RIGHT, STATIC_LEFT
};