#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

typedef struct {
	int lifes;
	float x;
	float y;
	size size;
	bullet *bullets;
} player;

player init_player();
void update_player(player *p, float dt);
void draw_player(player p);

#endif
