#include <raylib.h>
#include "common.h"

typedef struct {
	int lifes;
	float x;
	float y;
	size size;
	int dir;
} enemy;

enemy init_enemy(float x, float y);
void update_enemy(enemy *e, float dt);
void draw_enemy(enemy e);
