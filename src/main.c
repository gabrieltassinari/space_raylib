#include <raylib.h>

#include "../lib/player.h"
#include "../lib/enemy.h"

int main() {
	player p;
	enemy e[TOTAL_ENEMIES] = {0};

	p = init_player();
	init_enemies(e);

	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders!");

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		update_player(&p, dt);
		update_bullets(&p.bullets, dt);

		for (int i = 0; i < TOTAL_ENEMIES; i++) {
			update_enemy(&e[i], dt);
			bullet_enemy_col(&p.bullets, &e[i]);
		}

		if (IsKeyPressed(KEY_SPACE)) {
			bullet *tmp = create_bullet(p.x, p.y);

			insert_bullet(&p.bullets, tmp);
			debug_bullets(p.bullets);
		}


		BeginDrawing();
			ClearBackground(BLACK);
			draw_player(p);
			draw_enemies(e);
			draw_bullets(p.bullets);
		EndDrawing();
	}
	CloseWindow();
}
