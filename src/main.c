#include <stdio.h>
#include <raylib.h>

#include "../lib/player.h"
#include "../lib/enemy.h"

int main() {
	player p;
	enemy e;

	p = init_player();
	e = init_enemy(250, 50);

	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders!");

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		update_player(&p, dt);
		update_enemy(&e, dt);
		update_bullets(&p.bullets, dt);

		if (IsKeyPressed(KEY_SPACE)) {
			bullet *tmp = create_bullet(p.x, p.y);

			insert_bullet(&p.bullets, tmp);
			debug_bullets(p.bullets);
		}


		BeginDrawing();
			ClearBackground(BLACK);
			draw_player(p);
			draw_enemy(e);
			draw_bullets(p.bullets);
		EndDrawing();
	}
	CloseWindow();
}
