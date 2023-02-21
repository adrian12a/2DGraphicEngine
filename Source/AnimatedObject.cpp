#include "AnimatedObject.h"
#include "BitmapObject.h"
#include <iostream>

AnimatedObject::AnimatedObject(int number_of_elements) {
	size = number_of_elements;
	i = 0;
	waiter = 0;
}

void AnimatedObject::draw(int x, int y, Direction direction) {
	if (waiter == 0) {
		waiter = al_get_time();
	}
	if (al_get_time() >= waiter + 0.5) {
		if (i + 1 < size)
			i++;
		else
			i = 0;
		waiter = 0;
	}
	switch (direction) {
	case LEFT:
		al_draw_bitmap(left[i], x, y, 0);
		break;
	case RIGHT:
		al_draw_bitmap(right[i], x, y, 0);
		break;
	case UP:
		al_draw_bitmap(up[i], x, y, 0);
		break;
	case DOWN:
		al_draw_bitmap(down[i], x, y, 0);
		break;
	case STATIC_LEFT:
		al_draw_bitmap(left[0], x, y, 0);
		break;
	case STATIC_RIGHT:
		al_draw_bitmap(right[0], x, y, 0);
		break;
	case STATIC_UP:
		al_draw_bitmap(up[0], x, y, 0);
		break;
	case STATIC_DOWN:
		al_draw_bitmap(down[0], x, y, 0);
		break;
	}
}

void AnimatedObject::add_bitmap(BitmapObject bitmap, Direction direction) {
	switch (direction) {
	case LEFT:
		left.push_back(bitmap.bitmap);
		break;
	case RIGHT:
		right.push_back(bitmap.bitmap);
		break;
	case UP:
		up.push_back(bitmap.bitmap);
		break;
	case DOWN:
		down.push_back(bitmap.bitmap);
		break;
	}
}