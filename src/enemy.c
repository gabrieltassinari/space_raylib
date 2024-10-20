#include <stdio.h>
#include "../lib/enemy.h"

void enemy_debug(enemy e) {
	puts("---------------------");
	printf("init:    (%d)\n", e.p_init);
	printf("current: (%f, %f)\n", e.x, e.y);
}

enemy init_enemy(float x, float y) {
	enemy e = {
		.size.width	= ENEMY_WIDTH,
		.size.height	= ENEMY_HEIGHT,
		.speed		= 30,
		.lifes		= 5,
		.x		= x,
		.y		= y,
		.p_init		= x,
	};

	return e;
}

void init_enemies(enemy *e) {
	for (int x = 0; x < TOTAL_ENEMIES/2; x++)  {
		for (int y = 0; y < 2; y++)
			e[y*TOTAL_ENEMIES/2+x] = init_enemy(50*(x+1), 50*(y+1));
	}
}

void draw_enemy(enemy e) {
	DrawRectangle(e.x, e.y, e.size.width, e.size.height, RED);
}

void draw_enemies(enemy *e) {
	for (int i = 0; i < TOTAL_ENEMIES; i++)
		draw_enemy(e[i]);
}

void update_enemy(enemy *e, float dt) {
	if (e->x <= e->p_init - 25.0)
		e->speed *= -1;
	if (e->x >= e->p_init + 25.0)
		e->speed *= -1;

	e->x += e->speed * dt;
}
