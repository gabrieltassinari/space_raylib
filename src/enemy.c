#include <stdio.h>

#include "../lib/enemy.h"

enemy *init_enemy(float x, float y) {
	enemy *e = malloc(sizeof(enemy));

	*e = (enemy) {
		.size.width	= ENEMY_WIDTH,
		.size.height	= ENEMY_HEIGHT,
		.prev		= e,
		.next		= e,
		.lifes		= 5,
		.speed		= 30,
		.p_init		= x,
		.x		= x,
		.y		= y,
	};

	return e;
}

void insert_enemy(enemy **head, enemy *tmp) {
	if (*head != NULL) {
		// 1 Enemy or 2+ Enemies.
		if ((*head)->next == *head) {
			(*head)->next = tmp;
			tmp->prev = *head;
		} else {
			(*head)->prev->next = tmp;
			tmp->prev = (*head)->prev;
		}

		(*head)->prev = tmp;
		tmp->next = *head;
	}

	*head = tmp;
}

void init_enemies(enemy **e) {
	for (int x = 0; x < TOTAL_ENEMIES/2; x++)  {
		for (int y = 0; y < 2; y++) {
			enemy *tmp = init_enemy(50*(x+1), 50*(y+1));
			insert_enemy(e, tmp);
		}
	}
}

void remove_enemy(enemy **head) {
	if (*head == NULL)
		return;

	enemy *tmp = *head;

	// 2+ Enemies or only 1 Enemy.
	if ((*head)->next != *head) {
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		*head = (*head)->next;
	} else {
		free(*head);
		*head = NULL;
		return;
	}

	free(tmp);
}

void draw_enemies(enemy *head) {
	if (head == NULL)
		return;

	enemy *tmp = head;

	do {
		DrawRectangle(head->x, head->y, head->size.width,
			      head->size.height, RED);
		head = head->next;
	} while (head != tmp);
}

void update_enemies(enemy **head, float dt) {
	if (*head == NULL)
		return;

	enemy *tmp = *head;

	do {
		if ((*head)->x <= (*head)->p_init - 25.0)
			(*head)->speed *= -1;
		if ((*head)->x >= (*head)->p_init + 25.0)
			(*head)->speed *= -1;

		(*head)->x += (*head)->speed * dt;

		*head = (*head)->next;
	} while (*head != tmp);
}

void debug_enemies(enemy *head) {
	if (head == NULL) {
		puts("Empty enemies");
		return;
	}
	puts("-----");

	enemy *tmp = head;

	do {
		printf("Head:\t%p\nPrev:\t%p\nNext:\t%p\nx:\t%f\ny:\t%f\n\n",
		       head, head->prev, head->next, head->x, head->y);

		head = head->next;
	} while (head != tmp);
}

