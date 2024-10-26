#include <stdio.h>
#include "../lib/player.h"
#include "../lib/common.h"

void player_debug(player p) {
	printf("(%f, %f)\n", p.x, p.y);
}

player init_player() {
	player p = {
		.size.width	= PLAYER_WIDTH,
		.size.height	= PLAYER_HEIGHT,
		.lifes		= 3,
		.x		= 225,
		.y		= 400,
		.bullets	= NULL,
	};

	return p;
}

void update_player(player *p, float dt) {

	if (p->x < 0)
		p->x += 100 * dt;
	if (p->x > SCREEN_WIDTH - PLAYER_WIDTH)
		p->x -= 100 * dt;

	if (IsKeyDown(KEY_RIGHT))
		p->x += 100 * dt;
	if (IsKeyDown(KEY_LEFT))
		p->x -= 100 * dt;
}

void draw_player(player p) {
	DrawRectangle(p.x, p.y, p.size.width, p.size.height, GREEN);
}
