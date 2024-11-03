#include "../lib/common.h"

int check_collision(float x1, float y1, size s1, float x2, float y2, size s2) {
	return ((x1 + s1.width > x2) && (x1 < x2 + s2.width) &&
	        (y1 + s1.height > y2) && (y1 < y2 + s2.height));
}

void draw_menu() {
	DrawText("Space Invaders", 12, SCREEN_HEIGHT*0.10, 60, GREEN);
	DrawText("Press ENTER", SCREEN_WIDTH*0.30, SCREEN_HEIGHT*0.35, 30, GREEN);
}

void draw_end(int score) {
	DrawText("Space Invaders", 12, SCREEN_HEIGHT*0.10, 60, GREEN);
	DrawText(TextFormat("Total Score: %d", score), SCREEN_WIDTH*0.30,
		 SCREEN_HEIGHT*0.35, 30, WHITE);
	DrawText("Press ENTER to play again!", SCREEN_WIDTH*0.10,
		 SCREEN_HEIGHT*0.50, 30, WHITE);
}

void draw_hud(int score, int lifes) {
	DrawText(TextFormat("Score: %d", score), 20, 10, 30, WHITE);
}
