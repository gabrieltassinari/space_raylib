#ifndef COMMON_H

#define COMMON_H

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

typedef struct {
	float x;
	float y;
	const int size;
} pos;

typedef struct {
	int width;
	int height;
} size;

int check_collision(pos b1, size s1, pos b2, size s2);

#endif
