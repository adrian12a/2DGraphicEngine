#include "BitmapObject.h"

BitmapObject::BitmapObject(const char* filename) {
	bitmap = al_load_bitmap(filename);
	width = al_get_bitmap_width(bitmap);
	height = al_get_bitmap_height(bitmap);
}

BitmapObject::BitmapObject(const char* filename, ALLEGRO_COLOR mask) {
	bitmap = al_load_bitmap(filename);
	width = al_get_bitmap_width(bitmap);
	height = al_get_bitmap_height(bitmap);
	al_convert_mask_to_alpha(bitmap, mask);
}

void BitmapObject::draw(int x, int y) {
	al_draw_bitmap(bitmap, x, y, 0);
}