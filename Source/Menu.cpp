#include "Menu.h"
#include "MenuOption.h"
#include "Engine.h"
#include "PrimitiveRenderer.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

Menu::Menu() {
	srand(time(0));
	font = al_load_ttf_font("ocr.ttf", 45, 0);
	background = al_load_bitmap("menu_background.png");
	menu_options.push_back(MenuOption("menu_0_a.png", "menu_0_u.png", 100, 100));
	menu_options.push_back(MenuOption("menu_1_a.png", "menu_1_u.png", 100, 200));
	menu_options.push_back(MenuOption("menu_2_a.png", "menu_2_u.png", 100, 300));
	menu_options.push_back(MenuOption("menu_3_a.png", "menu_3_u.png", 100, 400));
	menu_options.push_back(MenuOption("menu_4_a.png", "menu_4_u.png", 100, 500));
	menu_options.push_back(MenuOption("menu_5_a.png", "menu_5_u.png", 100, 600));
	menu_options.push_back(MenuOption("menu_6_a.png", "menu_6_u.png", 100, 700));
	menu_options.push_back(MenuOption("menu_7_a.png", "menu_7_u.png", 100, 800));
	menu_options.push_back(MenuOption("menu_8_a.png", "menu_8_u.png", 350, 100));
	menu_options.push_back(MenuOption("menu_9_a.png", "menu_9_u.png", 350, 200));
	menu_options.push_back(MenuOption("menu_10_a.png", "menu_10_u.png", 350, 300));
	menu_options.push_back(MenuOption("menu_11_a.png", "menu_11_u.png", 350, 400));
	menu_options.push_back(MenuOption("menu_12_a.png", "menu_12_u.png", 350, 500));
	menu_options.push_back(MenuOption("menu_13_a.png", "menu_13_u.png", 350, 600));
	menu_options.push_back(MenuOption("menu_14_a.png", "menu_14_u.png", 350, 700));
	menu_options.push_back(MenuOption("menu_15_a.png", "menu_15_u.png", 350, 800));
	current = -1;
}

Menu::~Menu() {
	al_destroy_bitmap(background);
}

void Menu::view()
{
	srand(time(0));
	vector<Point2D> v;
	switch (current) {
	case 0:
		for (int i = 0; i < 10000; i++)
			PrimitiveRenderer::draw_pixel(100 + rand() % 1800, 100 + rand() % 900, rand() % 128, rand() % 128, rand() % 128);
		break;
	case 1:
		PrimitiveRenderer::line(100 + rand() % 800, 100 + rand() % 400, 800 + rand() % 800, 500 + rand() % 400);
		break;
	case 2:
		for (int i = 0; i < 3 + rand() % 7; i++)
			v.push_back(Point2D(100 + rand() % 1800, 100 + rand() % 900));
		PrimitiveRenderer::broken_line_open(v);
		v.clear();
		break;
	case 3:
		for (int i = 0; i < 3 + rand() % 7; i++)
			v.push_back(Point2D(100 + rand() % 1800, 100 + rand() % 900));
		PrimitiveRenderer::broken_line_closed(v);
		v.clear();
		break;
	case 4:
		PrimitiveRenderer::circle(100 + rand() % 1800, 100 + rand() % 900, 100 + rand() % 200, rand() % 128, rand() % 128, rand() % 128);
		break;
	case 5:
		PrimitiveRenderer::ellipse(100 + rand() % 1600, 100 + rand() % 700, 100 + rand() % 200, 100 + rand() % 200, rand() % 128, rand() % 128, rand() % 128);
		break;
	case 6:
		for (int i = 0; i < 4 + rand() % 2; i++)
			v.push_back(Point2D(100 + rand() % 1800, 100 + rand() % 900));
		if (PrimitiveRenderer::polygon(v))
			al_draw_textf(font, al_map_rgb(128, 128, 128), 600, 500, 0, "Odcinki przecinaja sie");
		v.clear();
		break;
	case 7:
		for (int i = 0; i < 2; i++)
			v.push_back(Point2D(100 + rand() % 1800, 100 + rand() % 900));
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		al_flip_display();
		v = PrimitiveRenderer::translation(v, 20 + rand() % 100);
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		v.clear();
		break;
	case 8:
		for (int i = 0; i < 2; i++)
			v.push_back(Point2D(100 + rand() % 1000, 50));
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		al_flip_display();
		v = PrimitiveRenderer::rotation(v, 1 + rand() % 10 * 0.01);
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		v.clear();
		break;
	case 9:
		for (int i = 0; i < 2; i++)
			v.push_back(Point2D(100 + rand() % 1000, 50));
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		al_flip_display();
		v = PrimitiveRenderer::rotation(v, 1 + rand() % 10 * 0.01, 600, 200);
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		v.clear();
		break;
	case 10:
		for (int i = 0; i < 2; i++)
			v.push_back(Point2D(100 + rand() % 1000, 50));
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		al_flip_display();
		v = PrimitiveRenderer::scale(v, 1 + rand() % 10);
		PrimitiveRenderer::line(v[0].x, v[0].y + 50, v[1].x, v[1].y);
		v.clear();
		al_flip_display();
		break;
	case 11:
		for (int i = 0; i < 2; i++)
			v.push_back(Point2D(100 + rand() % 1000, 50));
		PrimitiveRenderer::line(v[0].x, v[0].y, v[1].x, v[1].y);
		al_flip_display();
		v = PrimitiveRenderer::scale(v, 1 + rand() % 10, 100, 100);
		PrimitiveRenderer::line(v[0].x, v[0].y + 50, v[1].x, v[1].y);
		v.clear();
		al_flip_display();
		break;
	case 12:
		al_draw_rectangle(100, 100, 300, 300, al_map_rgb(128, 128, 0), 4);
		PrimitiveRenderer::boundry_fill(150, 150, al_map_rgb(rand() % 128, rand() % 128, rand() % 128), al_map_rgb(128, 128, 0), al_get_current_display());
		break;
	case 13:
		al_draw_rectangle(100, 100, 300, 300, al_map_rgb(128, 128, 0), 4);
		PrimitiveRenderer::flood_fill(150, 150, al_map_rgb(rand() % 128, rand() % 128, rand() % 128), al_map_rgb(0, 0, 0), al_get_current_display());
		break;
	case 15:
		current = -2;
		break;
	}
}

void Menu::showMenu(vector <MenuOption> bitmaps)
{
	int size = bitmaps.size();
	for (int i = 0; i < size; i++)
		al_draw_bitmap(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, 0);
	al_flip_display();
}

int Menu::menuLeftRight(vector <MenuOption> bitmaps, int current)
{
	if (current == -1)
		current = 0;
	else {
		al_draw_bitmap(bitmaps[current].inactive, bitmaps[current].x, bitmaps[current].y, 0);
		if (current >= 8 && current <= 15)
			current -= 8;
		else
			current += 8;
	}
	al_draw_bitmap(bitmaps[current].active, bitmaps[current].x, bitmaps[current].y, 0);
	al_flip_display();
	return current;
}

int Menu::menuUp(vector <MenuOption> bitmaps, int current)
{
	if (current == -1)
		current = 0;
	else {
		al_draw_bitmap(bitmaps[current].inactive, bitmaps[current].x, bitmaps[current].y, 0);
		if (current == 0)
			current = bitmaps.size() - 1;
		else
			current--;
	}
	al_draw_bitmap(bitmaps[current].active, bitmaps[current].x, bitmaps[current].y, 0);
	al_flip_display();
	return current;
}

int Menu::menuDown(vector <MenuOption> bitmaps, int current)
{
	if (current == -1)
		current = 0;
	else {
		al_draw_bitmap(bitmaps[current].inactive, bitmaps[current].x, bitmaps[current].y, 0);
		if (current == bitmaps.size() - 1)
			current = 0;
		else
			current++;
	}
	al_draw_bitmap(bitmaps[current].active, bitmaps[current].x, bitmaps[current].y, 0);
	al_flip_display();
	return current;
}

int Menu::menuMouse(int x, int y, vector <MenuOption> bitmaps, int current)
{
	int size = menu_options.size();
	for (int i = 0; i < size; i++) {
		if (collision(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, x, y)) {
			al_draw_bitmap(bitmaps[i].active, bitmaps[i].x, bitmaps[i].y, 0);
			current = i;
		}
		else
			al_draw_bitmap(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, 0);
		al_flip_display();
	}
	return current;
}

bool Menu::collision(ALLEGRO_BITMAP* bitmap, double x1, double y1, double x2, double y2)
{
	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);
	if (x2 > x1 && x2 < x1 + w && y2  > y1 && y2 < y1 + h)
		return true;
	else
		return false;
}

int Menu::mainLoop(ALLEGRO_EVENT_QUEUE* queue) {
	bool exit = false;
	current = -1;
	ALLEGRO_EVENT event;
	al_draw_bitmap(background, 0, 0, 0);
	showMenu(menu_options);
	while (!exit) {
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				current = -2;
				break;
			case ALLEGRO_KEY_UP:
				current = menuUp(menu_options, current);
				break;
			case ALLEGRO_KEY_DOWN:
				current = menuDown(menu_options, current);
				break;
			case ALLEGRO_KEY_LEFT:
				current = menuLeftRight(menu_options, current);
				break;
			case ALLEGRO_KEY_RIGHT:
				current = menuLeftRight(menu_options, current);
				break;
			case ALLEGRO_KEY_ENTER:
				if (current >= 0)
					exit = true;
				break;
			}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			current = menuMouse(event.mouse.x, event.mouse.y, menu_options, current);
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button & 1 && current >= 0)
				exit = true;
		}
	}
	return current;
}