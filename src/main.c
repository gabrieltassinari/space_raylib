#include <raylib.h>

#include "../lib/player.h"
#include "../lib/enemy.h"

int main() {
	player p = {0};
	init_player(&p);

	enemy e = {0};
	init_enemy(&e, 250, 50);

	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders!");

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		update_player(&p, dt);
		update_enemy(&e, dt);
		check_collision(p.pos, p.size, e.pos, e.size);

		BeginDrawing();
			ClearBackground(BLACK);
			draw_enemy(e);
			draw_player(p);
		EndDrawing();
	}
	CloseWindow();
}
