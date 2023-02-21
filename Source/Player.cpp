#include "Player.h"
#include "Engine.h"
#include "BitmapObject.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

Player::Player(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	vector_x = 0;
	vector_y = 0;
	speed = 5;
	timer = al_create_timer(1.0 / 60);
	direction = Direction(STATIC_DOWN);
	al_start_timer(timer);
	queue = Engine::make_queue(true, true);
	player.add_bitmap(front_1, Direction(DOWN));
	player.add_bitmap(front_2, Direction(DOWN));
	player.add_bitmap(front_3, Direction(DOWN));
	player.add_bitmap(back_1, Direction(UP));
	player.add_bitmap(back_2, Direction(UP));
	player.add_bitmap(back_3, Direction(UP));
	player.add_bitmap(left_1, Direction(LEFT));
	player.add_bitmap(left_2, Direction(LEFT));
	player.add_bitmap(left_3, Direction(LEFT));
	player.add_bitmap(right_1, Direction(RIGHT));
	player.add_bitmap(right_2, Direction(RIGHT));
	player.add_bitmap(right_3, Direction(RIGHT));
}

Player::~Player()
{
	al_stop_timer(timer);
}

void Player::draw()
{
	x += vector_x;
	y += vector_y;
	if (x < 0 - front_1.width)
		x = width;
	if (x > width + front_1.width)
		x = 0;
	if (y < 0 - front_1.height)
		y = height;
	if (y > height + front_1.height)
		y = 0;
	player.draw(x, y, direction);
}