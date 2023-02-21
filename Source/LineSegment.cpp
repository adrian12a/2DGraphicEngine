#include "LineSegment.h"
#include "PrimitiveRenderer.h"
#include <iostream>

using namespace std;

LineSegment::LineSegment(int x0, int y0, int x1, int y1) {
	modify(x0, y0, x1, y1);
}

void LineSegment::modify(int x0, int y0, int x1, int y1) {
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
}

void LineSegment::draw() {
	PrimitiveRenderer::line(x0, y0, x1, y1);
}