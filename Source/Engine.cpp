#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "Player.h"
#include "Direction.h"
#include "Menu.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

Engine::Engine(int width, int height, bool fullscreen, int fps) {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	if (fullscreen)
		al_set_new_display_flags(ALLEGRO_NOFRAME);
	display = al_create_display(width, height);
	this->width = width;
	this->height = height;
	timer = al_create_timer(1.0 / fps);
}

void Engine::free_memory() {
	al_destroy_display(display);
	al_destroy_timer(timer);
}

void Engine::change_resolution(int width, int height)
{
	al_resize_display(display, width, height);
	this->width = width;
	this->height = height;
}

void Engine::clear_screen(int R, int G, int B) {
	al_clear_to_color(al_map_rgb(R, G, B));
	al_flip_display();
}

void Engine::start_timer() {
	al_start_timer(timer);
}

void Engine::stop_timer() {
	al_stop_timer(timer);
}

ALLEGRO_EVENT_QUEUE* Engine::make_queue(bool keyboard, bool mouse) {
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	if (keyboard)
		al_register_event_source(queue, al_get_keyboard_event_source());
	if (mouse)
		al_register_event_source(queue, al_get_mouse_event_source());
	return queue;
}

void Engine::destroy_queue(ALLEGRO_EVENT_QUEUE* queue) {
	al_destroy_event_queue(queue);
}

void Engine::main_loop() {
	bool exit = false;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;
	bool viewed = false;
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE* queue = make_queue(true, true);
	Player player = Player(100, 100, width, height);
	Menu menu = Menu();
	al_register_event_source(queue, al_get_timer_event_source(timer));
	start_timer();
	while (!exit) {
		al_wait_for_event(queue, &event);
		if (menu.current == -1) {
			menu.mainLoop(queue);
			viewed = false;
		}
		if (menu.current == -2)
			exit = true;
		if (menu.current >= 0 && menu.current != 14) {
			if (viewed == false) {
				clear_screen(0, 0, 0);
				menu.view();
				al_flip_display();
				viewed = true;
			}
			switch (event.type) {
			case ALLEGRO_EVENT_KEY_DOWN:
			{
				switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					menu.current = -1;
					break;
				case ALLEGRO_KEY_SPACE:
					viewed = false;
					break;
				}
			}
			}
		}
		else {
			switch (event.type) {
			case ALLEGRO_EVENT_TIMER: {
				clear_screen(0, 0, 0);
				player.draw();
				break;
			}
			case ALLEGRO_EVENT_KEY_DOWN:
			{
				switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					menu.current = -1;
					break;
				case ALLEGRO_KEY_UP:
					up = true;
					player.vector_y -= player.speed;
					if (down == false)
						player.direction = Direction(UP);
					break;
				case ALLEGRO_KEY_DOWN:
					down = true;
					player.vector_y += player.speed;
					if (up == false)
						player.direction = Direction(DOWN);
					break;
				case ALLEGRO_KEY_RIGHT:
					right = true;
					player.vector_x += player.speed;
					if (left == false)
						player.direction = Direction(RIGHT);
					break;
				case ALLEGRO_KEY_LEFT:
					left = true;
					player.vector_x -= player.speed;
					if (right == false)
						player.direction = Direction(LEFT);
					break;
				}
				break;
			}
			case ALLEGRO_EVENT_KEY_UP:
			{
				switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					up = false;
					player.vector_y += player.speed;
					if (left == false && right == false && up == false && down == false)
						player.direction = Direction(STATIC_UP);
					break;
				case ALLEGRO_KEY_DOWN:
					down = false;
					player.vector_y -= player.speed;
					if (left == false && right == false && up == false && down == false)
						player.direction = Direction(STATIC_DOWN);
					break;
				case ALLEGRO_KEY_RIGHT:
					right = false;
					player.vector_x -= player.speed;
					if (left == false && right == false && up == false && down == false)
						player.direction = Direction(STATIC_RIGHT);
					break;
				case ALLEGRO_KEY_LEFT:
					left = false;
					player.vector_x += player.speed;
					if (left == false && right == false && up == false && down == false)
						player.direction = Direction(STATIC_LEFT);
					break;
				}
				break;
			}
			}
			al_flip_display();
		}
	}
	stop_timer();
	destroy_queue(queue);
	free_memory();
}