#include "../lib/common.h"

bullet *create_bullet(float x, float y) {
	bullet *tmp = malloc(sizeof(bullet));

	*tmp = (bullet) {
		.size.width	= BULLET_WIDTH,
		.size.height	= BULLET_HEIGHT,
		.prev		= tmp,
		.next		= tmp,
		.x		= x + (PLAYER_WIDTH / 2),
		.y		= y,
	};

	return tmp;
}

void draw_bullets(bullet *head) {
	if (head == NULL)
		return;

	bullet *tmp = head;

	do {
		DrawRectangle(head->x, head->y, head->size.width,
			      head->size.height, WHITE);
		head = head->next;
	} while (head != tmp);
}

void update_bullets(bullet **head, float dt) {
	if (*head == NULL)
		return;

	bullet *tmp = *head;

	do {
		(*head)->y -= 100 * dt;
		*head = (*head)->next;
	} while (*head != tmp);
}

void debug_bullets(bullet *head) {
	if (head == NULL) {
		puts("Empty bullets");
		return;
	}
	puts("-----");

	bullet *tmp = head;

	do {
		printf("Head:\t%p\nPrev:\t%p\nNext:\t%p\nx:\t%f\ny:\t%f\n\n",
		       head, head->prev, head->next, head->x, head->y);

		head = head->next;
	} while (head != tmp);
}

void bullet_enemy_col(bullet **head, enemy **e, int *score) {
	if (*head == NULL)
		return;

	enemy *tmp_e;
	bullet *tmp_b;

	tmp_e = *e;

	do {
		tmp_b = *head;

		do {
			if (check_collision((*e)->x, (*e)->y, (*e)->size,
					    (*head)->x, (*head)->y,
					    (*head)->size) || (*head)->y < 0) {
				if ((*head)->y > 10)
					(*e)->lifes--;

				remove_list((list **) head);
				tmp_b = *head;
			}

			if (*head == NULL) return;

			*head = (*head)->next;
		} while (*head != tmp_b);

		if ((*e)->lifes < 1) {
			remove_list((list **) e);
			tmp_e = *e;

			(*score) += 30;
		}

		if (*e == NULL) return;

		*e = (*e)->next;
	} while  (*e != tmp_e);

}
