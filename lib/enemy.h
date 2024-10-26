#include "common.h"

void draw_enemy(enemy e);
void enemy_debug(enemy e);

void init_enemies(enemy **e);
void draw_enemies(enemy *head);
void debug_enemies(enemy *head);
void update_enemies(enemy **head, float dt);
