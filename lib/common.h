#ifndef COMMON_H
#define COMMON_H

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

typedef struct {
	int width;
	int height;
} size;

int check_collision(float x1, float y1, size s1, float x2, float y2, size s2);

#endif
