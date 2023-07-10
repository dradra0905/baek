#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list {
	struct list* front;
	struct list* back;
	int value;
}list;

list* head;

void init() {
	head = (list *)malloc(sizeof(list));
	head->front = head;
	head->back = head;
}

int list_size = 0;

int main() {
	int n;
	init();
	scanf("%d", &n);
	while (n--) {
		getchar();
		char command[20] = "";
		scanf("%[^\n]", command);
		char tocken[3][20] = { "" };
		int cnt = 0, wcnt = 0;
		for (int i = 0; i < strlen(command); i++) {
			if (command[i] == 32) {
				cnt++;
				wcnt = 0;
				continue;
			}
			tocken[cnt][wcnt++] = command[i];
		}
		if (strcmp(tocken[0], "push_front") == 0) {
			list* node;
			node = (list*)malloc(sizeof(list));
			node->value = atoi(tocken[1]);

			node->front = head;
			node->back = head->back;
			head->back->front = node;
			head->back = node;

			list_size++;
		}
		else if (strcmp(tocken[0], "push_back") == 0) {
			list* node;
			node = (list*)malloc(sizeof(list));
			node->value = atoi(tocken[1]);

			node->front = head->front;
			node->back = head;
			head->front->back = node;
			head->front = node;

			list_size++;
		}
		else if (strcmp(tocken[0], "pop_front") == 0) {
			if (list_size == 0) {
				printf("-1\n");
			}
			else {
				list* node = head->back;
				list* tmp = node->back;
				printf("%d\n", node->value);
				list_size--;

				head->back = node->back;
				tmp->front = head;

				free(node);
			}
		}
		else if (strcmp(tocken[0], "pop_back") == 0) {
			if (list_size == 0) {
				printf("-1\n");
			}
			else {
				list* node = head->front;
				list* tmp = node->front;
				printf("%d\n", node->value);
				list_size--;

				head->front = node->front;
				tmp->back = head;

				free(node);
			}
		}
		else if (strcmp(tocken[0], "size") == 0) {
			printf("%d\n", list_size);
		}
		else if (strcmp(tocken[0], "empty") == 0) {
			if (list_size == 0)printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(tocken[0], "front") == 0) {
			if (list_size == 0)printf("-1\n");
			else printf("%d\n", head->back->value);
		}
		else if (strcmp(tocken[0], "back") == 0) {
			if (list_size == 0)printf("-1\n");
			else printf("%d\n", head->front->value);
		}
	}

	free(head);
	return 0;
}