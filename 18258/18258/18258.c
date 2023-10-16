#include<stdio.h>
#include<string.h>

int N;
int queue[2000001];
int front = 0, back = 0;

void push(int n) {
	queue[front++] = n;
}
int pop() {
	return queue[back++];
}

int main() {
	scanf("%d", &N);
	while (N--) {
		getchar();

		char cmd[20];
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			int input;
			scanf("%d", &input);
			push(input);
		}
		else if (strcmp(cmd, "pop") == 0) {
			if (front != back)printf("%d\n", pop());
			else printf("-1\n");
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", front - back);
		}
		else if (strcmp(cmd, "empty") == 0) {
			if (front != back)printf("0\n");
			else printf("1\n");
		}
		else if (strcmp(cmd, "front") == 0) {
			if (front > back) {
				printf("%d\n", queue[back]);
			}
			else printf("-1\n");
		}
		else if (strcmp(cmd, "back") == 0) {
			if (front > back) {
				printf("%d\n", queue[front - 1]);
			}
			else printf("-1\n");
		}
	}


	return 0;
}