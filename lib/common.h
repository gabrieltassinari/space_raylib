#ifndef COMMON_H
#define COMMON_H

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

#define ENEMY_WIDTH 15
#define ENEMY_HEIGHT 15

#define BULLET_WIDTH 3
#define BULLET_HEIGHT 10

#define TOTAL_ENEMIES 18

enum SCREEN {
	MENU = 0,
	GAME,
	END
};

typedef struct size {
	int width;
	int height;
} size;

typedef struct list {
	struct list *prev;
	struct list *next;
} list;

typedef struct enemy {
	struct enemy *prev;
	struct enemy *next;
	float x;
	float y;
	size size;
	int speed;
	int lifes;
	int p_init;
} enemy;

typedef struct bullet {
	struct bullet *prev;
	struct bullet *next;
	float x;
	float y;
	size size;
} bullet;

int check_collision(float x1, float y1, size s1, float x2, float y2, size s2);
void draw_menu();
void draw_end(int score);
void draw_hud(int score, int lifes);

void insert_list(list **head, list *tmp);
void remove_list(list **head);

bullet *create_bullet(float x, float y);
void debug_bullets(bullet *head);
void draw_bullets(bullet *head);
void update_bullets(bullet **head, float dt);
void bullet_enemy_col(bullet **head, enemy **e, int *score);


#endif
