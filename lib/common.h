#ifndef COMMON_H
#define COMMON_H

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

#define ENEMY_WIDTH 50
#define ENEMY_HEIGHT 50

typedef struct {
	int width;
	int height;
} size;


typedef struct bullet {
	float x;
	float y;
	struct bullet *prev;
	struct bullet *next;
} bullet;

int check_collision(float x1, float y1, size s1, float x2, float y2, size s2);

bullet *create_bullet(float x, float y);
void insert_bullet(bullet **head, bullet *tmp);
void remove_bullet(bullet **head);
void debug_bullets(bullet *head);


#endif
