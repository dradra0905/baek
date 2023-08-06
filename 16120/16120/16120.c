#include<stdio.h>
#include<string.h>

char str[1000001];

char stack[1000001];
int top = -1;

void push(char c) {
	stack[++top] = c;
}
char pop() {
	return stack[top--];
}

int main() {
	int scnt = 0;

	scanf("%s", str);
	getchar();
	while (1) {
		if (str[scnt] == 0)break;
		push(str[scnt]);
		if (top >= 3) {
			if (stack[top - 3] == 'P' && stack[top - 2] == 'P' && stack[top - 1] == 'A' && stack[top] == 'P') {
				pop();
				pop();
				pop();
			}
		}
		scnt++;
	}

	if (top == 0 && stack[top] == 'P')printf("PPAP\n");
	else printf("NP\n");

	return 0;
}