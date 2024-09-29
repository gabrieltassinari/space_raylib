#include "../lib/common.h"

int check_collision(float x1, float y1, size s1, float x2, float y2, size s2) {
	return ((x1 + s1.width > x2) && (x1 < x2 + s2.width) &&
	        (y1 + s1.height > y2) && (y1 < y2 + s2.height));
}
