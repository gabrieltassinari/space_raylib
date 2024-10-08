#include <stdio.h>
#include <stdlib.h>

#include "../lib/common.h"

bullet *create_bullet(float x, float y) {
	bullet *tmp = malloc(sizeof(bullet));

	*tmp = (bullet) {
		.x = x,
		.y = y,
		.prev = tmp,
		.next = tmp,
	};

	return tmp;
}

void insert_bullet(bullet **head, bullet *tmp) {
	if (*head != NULL) {
		// 1 Bullet or 2+ Bullets.
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

void remove_bullet(bullet **head) {
	if (*head == NULL)
		return;

	bullet *tmp = *head;

	// 2+ Bullets or only 1 Bullet.
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
	} while (head != tmp && head != NULL);
}
