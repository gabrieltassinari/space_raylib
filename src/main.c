#include "../lib/player.h"
#include "../lib/enemy.h"

int main() {
	int screen, score;
	player p;
	enemy *e;
	float dt;

	screen = MENU;
	score = 0;
	e = NULL;

	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders!");

	while (!WindowShouldClose()) {
		dt = GetFrameTime();

		switch (screen) {
		case MENU:
			if (IsKeyPressed(KEY_ENTER)) {
				p = init_player();
				init_enemies(&e);
				screen = GAME;
			}

			break;
		case GAME:
			update_player(&p, dt);
			update_enemies(&e, dt);
			update_bullets(&p.bullets, dt);

			// bullet_enemy_col(&p.bullets, &e[i]);

			if (IsKeyPressed(KEY_SPACE)) {
				bullet *tmp = create_bullet(p.x, p.y);
				insert_bullet(&p.bullets, tmp);
			}

			if (e == NULL)
				screen = END;
			break;
		case END:
			if (IsKeyPressed(KEY_ENTER))
				screen = MENU;
			break;
		}

		BeginDrawing();
			ClearBackground(BLACK);

			switch (screen) {
			case MENU:
				draw_menu();
				break;
			case GAME:
				draw_hud(score, p.lifes);
				draw_player(p);
				draw_enemies(e);
				draw_bullets(p.bullets);
				break;
			case END:
				draw_end(score);
				break;
			}
		EndDrawing();
	}
	CloseWindow();
}
