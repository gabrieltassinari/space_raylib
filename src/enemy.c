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

void init_enemies(enemy **e) {
	for (int x = 0; x < TOTAL_ENEMIES/2; x++)  {
		for (int y = 0; y < 2; y++) {
			enemy *tmp = init_enemy(50*(x+1), 50*(y+1));
			insert_list((list **) e, (list *) tmp);
		}
	}
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
