#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <iostream>

using namespace std;

Point2D::Point2D(int x, int y) {
	modify(x, y);
}

void Point2D::modify(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point2D::draw(int r, int g, int b) {
	PrimitiveRenderer::draw_pixel(x, y, r, g, b);
}