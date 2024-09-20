#include <raylib.h>
#include "common.h"

typedef struct {
	int lifes;
	size size;
	pos pos;
	int dir;
	// TODO: Array with bullets
} enemy;

void init_enemy(enemy *e, float x, float y);
void update_enemy(enemy *e, float dt);
void draw_enemy(enemy e);
