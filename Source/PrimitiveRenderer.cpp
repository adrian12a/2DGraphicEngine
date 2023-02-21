#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "Menu.h"
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

void PrimitiveRenderer::draw_pixel(int x, int y, int r, int g, int b) {
	al_draw_pixel(x, y, al_map_rgb(r, g, b));
	al_flip_display();
}

void PrimitiveRenderer::draw_line_x(int x0, int y0, int x1, int y1) {
	float dx, dy, m;
	dx = x1 - x0;
	dy = y1 - y0;
	m = dy / dx;
	float y = y0;
	for (int x = x0; x <= x1; x++) {
		al_draw_pixel(x, (int)(y + 0.5), al_map_rgb(0, 128, 128));
		y += m;
	}
}

void PrimitiveRenderer::draw_line_y(int x0, int y0, int x1, int y1) {
	float dx, dy, m;
	dx = x1 - x0;
	dy = y1 - y0;
	m = dx / dy;
	float x = x0;
	for (int y = y0; y <= y1; y++) {
		al_draw_pixel((int)(x + 0.5), y, al_map_rgb(0, 128, 128));
		x += m;
	}
}

void PrimitiveRenderer::line(int x0, int y0, int x1, int y1) {
	float dx, dy, m;
	dx = x1 - x0;
	dy = y1 - y0;
	m = dy / dx;

	if (abs(m) < 1) {
		if (x0 > x1)
			draw_line_x(x1, y1, x0, y0);
		else
			draw_line_x(x0, y0, x1, y1);
	}
	else {
		if (y0 > y1)
			draw_line_y(x1, y1, x0, y0);
		else
			draw_line_y(x0, y0, x1, y1);
	}
}

void PrimitiveRenderer::broken_line_open(vector<Point2D> v) {
	for (int i = 0; i < (int)v.size() - 1; i++)
		line(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
}

void PrimitiveRenderer::broken_line_closed(vector<Point2D> v) {
	broken_line_open(v);
	int i = v.size() - 1;
	line(v[i].x, v[i].y, v[0].x, v[0].y);
}

void PrimitiveRenderer::circle(int xc, int yc, int r, int R, int G, int B) {
	float a, step;
	step = 1.0 / r;
	for (a = 0; a < 3.14 / 2; a += step) {
		al_draw_pixel(xc + r * cos(a) + 0.5, yc + r * sin(a) + 0.5, al_map_rgb(R, G, B));
		al_draw_pixel(xc - r * cos(a) + 0.5, yc - r * sin(a) + 0.5, al_map_rgb(R, G, B));
		al_draw_pixel(xc - r * cos(a) + 0.5, yc + r * sin(a) + 0.5, al_map_rgb(R, G, B));
		al_draw_pixel(xc + r * cos(a) + 0.5, yc - r * sin(a) + 0.5, al_map_rgb(R, G, B));
	}
}

void PrimitiveRenderer::ellipse(int xc, int yc, int rx, int ry, int R, int G, int B) {
	float a, step;
	int precision = rx + ry;
	step = 1.0 / precision;
	for (a = 0; a < 3.14 / 2; a += step) {
		al_draw_pixel(xc + rx * cos(a) + 0.5, yc + ry * sin(a) + 0.5, al_map_rgb(R, G, B));
		al_draw_pixel(xc - rx * cos(a) + 0.5, yc - ry * sin(a) + 0.5, al_map_rgb(R, G, B));
		al_draw_pixel(xc - rx * cos(a) + 0.5, yc + ry * sin(a) + 0.5, al_map_rgb(R, G, B));
		al_draw_pixel(xc + rx * cos(a) + 0.5, yc - ry * sin(a) + 0.5, al_map_rgb(R, G, B));
	}
}

bool PrimitiveRenderer::polygon(vector<Point2D> v) {
	bool check = false;
	for (int i = 0; i < (int)size(v) - 1; i++) {
		for (int j = 0; j < (int)size(v) - 1; j++)
			if (j != i && common_point(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y, v[j].x, v[j].y, v[j + 1].x, v[j + 1].y))
				check = true;
	}
	for (int i = 0; i < (int)size(v) - 1; i++) {
		if (common_point(v.back().x, v.back().y, v[0].x, v[0].y, v[i].x, v[i].y, v[i + 1].x, v[i + 1].y))
			check = true;
	}
	if (!check)
		broken_line_closed(v);
	return check;
}

bool PrimitiveRenderer::common_point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	float s1 = x1 * y3 + x3 * y4 + x4 * y1 - x4 * y3 - x1 * y4 - x3 * y1;
	float s2 = x2 * y3 + x3 * y4 + x4 * y2 - x4 * y3 - x2 * y4 - x3 * y2;
	float s3 = x3 * y1 + x1 * y2 + x2 * y3 - x2 * y1 - x3 * y2 - x1 * y3;
	float s4 = x4 * y1 + x1 * y2 + x2 * y4 - x2 * y1 - x4 * y2 - x1 * y4;
	if (s1 * s2 < 0 && s3 * s4 < 0)
		return true;
	else
		return false;
}

void PrimitiveRenderer::boundry_fill(int x, int y, ALLEGRO_COLOR fill_color, ALLEGRO_COLOR boundry_color, ALLEGRO_DISPLAY* display) {
	ALLEGRO_BITMAP* bitmap = al_get_backbuffer(display);
	ALLEGRO_COLOR color;
	vector <Point2D> v;
	Point2D p = Point2D(x, y);
	bool check;
	v.push_back(p);
	while (v.size() != 0) {
		check = false;
		p.x = v[size(v) - 1].x;
		p.y = v[size(v) - 1].y;
		color = al_get_pixel(bitmap, p.x, p.y);
		v.pop_back();
		if (color.r == boundry_color.r && color.g == boundry_color.g && color.b == boundry_color.b)
			check = true;
		if (color.r == fill_color.r && color.g == fill_color.g && color.b == fill_color.b)
			check = true;
		if (!check) {
			al_draw_rectangle(p.x, p.y, p.x, p.y, fill_color, 2);
			v.push_back(Point2D(p.x + 2, p.y));
			v.push_back(Point2D(p.x - 2, p.y));
			v.push_back(Point2D(p.x, p.y + 2));
			v.push_back(Point2D(p.x, p.y - 2));
		}
	}
}

void PrimitiveRenderer::flood_fill(int x, int y, ALLEGRO_COLOR fill_color, ALLEGRO_COLOR background_color, ALLEGRO_DISPLAY* display) {
	ALLEGRO_BITMAP* bitmap;
	ALLEGRO_COLOR color;
	vector <Point2D> v;
	Point2D p = Point2D(x, y);
	bool check;
	v.push_back(p);
	while (v.size() != 0) {
		check = false;
		p.x = v[size(v) - 1].x;
		p.y = v[size(v) - 1].y;
		bitmap = al_get_backbuffer(display);
		color = al_get_pixel(bitmap, p.x, p.y);
		v.pop_back();
		if (!(color.r == background_color.r && color.g == background_color.g && color.b == background_color.b))
			check = true;
		if (color.r == fill_color.r && color.g == fill_color.g && color.b == fill_color.b)
			check = true;
		if (!check) {
			al_draw_rectangle(p.x, p.y, p.x, p.y, fill_color, 2);
			v.push_back(Point2D(p.x + 2, p.y));
			v.push_back(Point2D(p.x - 2, p.y));
			v.push_back(Point2D(p.x, p.y + 2));
			v.push_back(Point2D(p.x, p.y - 2));
		}
	}
}

vector<Point2D> PrimitiveRenderer::translation(vector<Point2D> v, int t) {
	for (int i = 0; i < (int)v.size(); i++) {
		v[i].modify(v[i].x + t, v[i].y + t);
	}
	return v;
}

vector<Point2D> PrimitiveRenderer::rotation(vector<Point2D> v, float alfa) {
	for (int i = 0; i < (int)v.size(); i++) {
		v[i].modify(v[i].x * cos(alfa) - v[i].y * sin(alfa), v[i].x * sin(alfa) + v[i].y * cos(alfa));
	}
	return v;
}

vector<Point2D> PrimitiveRenderer::rotation(vector<Point2D> v, float alfa, int x, int y) {
	for (int i = 0; i < (int)v.size(); i++) {
		v[i].modify(v[i].x + (x - v[i].x) * cos(alfa) - (y - v[i].y) * sin(alfa), v[i].x + (x - v[i].x) * sin(alfa) + (y - v[i].y) * cos(alfa));
	}
	return v;
}

vector<Point2D> PrimitiveRenderer::scale(vector<Point2D> v, int k) {
	for (int i = 0; i < (int)v.size(); i++) {
		v[i].modify(v[i].x * k, v[i].y * k);
	}
	return v;
}

vector<Point2D> PrimitiveRenderer::scale(vector<Point2D> v, int k, int x, int y) {
	for (int i = 0; i < (int)v.size(); i++) {
		v[i].modify(v[i].x * k + (1 - k) * x, v[i].y * k + (1 - k) * y);
	}
	return v;
}