#include <stdio.h>
#include "enemy.h"

void enemy_debug(enemy e) {
	printf("(%f, %f)\n", e.pos.x, e.pos.y);
}

void init_enemy(enemy *e, float x, float y) {
	e->lifes = 5;

	e->pos.x = x;
	e->pos.y = y;

	e->size.width = PLAYER_WIDTH;
	e->size.height = PLAYER_HEIGHT;

	e->dir = -1;
}

void draw_enemy(enemy e) {
	DrawRectangle(e.pos.x, e.pos.y, PLAYER_WIDTH, PLAYER_HEIGHT, RED);
}

void update_enemy(enemy *e, float dt) {
	if (e->pos.x <= 50.0)
		e->dir *= -1;
	if (e->pos.x >= 400.0)
		e->dir *= -1;

	e->pos.x += 100 * dt * e->dir;
}
