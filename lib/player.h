#include <raylib.h>
#include "common.h"

typedef struct {
	int lifes;
	size size;
	pos pos;
	// TODO: Array with bullets
} player;

void init_player(player *p);
void update_player(player *p, float dt);
void draw_player(player p);
