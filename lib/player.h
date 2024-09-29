#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "common.h"

typedef struct {
	int lifes;
	float x;
	float y;
	size size;
} player;

player init_player();
void update_player(player *p, float dt);
void draw_player(player p);

#endif
