#include "common.h"

int check_collision(pos b1, size s1, pos b2, size s2) {
	return ((b1.x + s1.width > b2.x) && (b1.x < b2.x + s2.width) &&
	        (b1.y + s1.height > b2.y) && (b1.y < b2.y + s2.height));
}
