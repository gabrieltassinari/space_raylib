#include <stdio.h>
#include "player.h"

void player_debug(player p) {
	printf("(%f, %f)\n", p.pos.x, p.pos.y);
}

void init_player(player *p) {
	p->lifes = 3;

	p->pos.x = 250;
	p->pos.y = 200;

	p->size.width = PLAYER_WIDTH;
	p->size.height = PLAYER_HEIGHT;
}

void update_player(player *p, float dt) {

	if (p->pos.x < 0)
		p->pos.x += 100 * dt;
	if (p->pos.x > SCREEN_WIDTH - PLAYER_WIDTH)
		p->pos.x -= 100 * dt;
	if (p->pos.y < 0)
		p->pos.y += 100 * dt;
	if (p->pos.y > SCREEN_HEIGHT - PLAYER_HEIGHT)
		p->pos.y -= 100 * dt;

	if (IsKeyDown(KEY_RIGHT))
		p->pos.x += 100 * dt;
	if (IsKeyDown(KEY_LEFT))
		p->pos.x -= 100 * dt;
	if (IsKeyDown(KEY_UP))
		p->pos.y -= 100 * dt;
	if (IsKeyDown(KEY_DOWN))
		p->pos.y += 100 * dt;
}

void draw_player(player p) {
	DrawRectangle(p.pos.x, p.pos.y, PLAYER_WIDTH, PLAYER_HEIGHT, GREEN);
}
