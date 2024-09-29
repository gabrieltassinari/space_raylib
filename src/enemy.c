#include <stdio.h>
#include "../lib/enemy.h"

void enemy_debug(enemy e) {
	printf("(%f, %f)\n", e.x, e.y);
}

enemy init_enemy(float x, float y) {
	enemy e = {
		.size.width	= ENEMY_WIDTH,
		.size.height	= ENEMY_HEIGHT,
		.lifes		= 5,
		.x		= x,
		.y		= y,
		.dir		= -1
	};

	return e;
}

void draw_enemy(enemy e) {
	DrawRectangle(e.x, e.y, e.size.width, e.size.height, RED);
}

void update_enemy(enemy *e, float dt) {
	if (e->x <= 50.0)
		e->dir *= -1;
	if (e->x >= 400.0)
		e->dir *= -1;

	e->x += 100 * dt * e->dir;
}
