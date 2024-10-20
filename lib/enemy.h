#include <raylib.h>
#include "common.h"

enemy init_enemy(float x, float y);
void init_enemies(enemy *e);
void update_enemy(enemy *e, float dt);
void draw_enemy(enemy e);
void draw_enemies(enemy *e);
void enemy_debug(enemy e);
