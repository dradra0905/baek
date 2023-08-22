#include<stdio.h>
#include<string.h>

char str[101];

char stack[101];
int top = -1;

void push(char s) {
	stack[++top] = s;
}
char pop() {
	return stack[top--];
}

int main() {
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')printf("%c", str[i]);
		else if (str[i] == ')') {
			while (1) {
				char c = pop();
				if (c == '(')break;
				printf("%c", c);
			}
		}
		else {
			if (str[i] == '+' || str[i] == '-') {
				while (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/') {
					printf("%c", pop());
				}
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (stack[top] == '*' || stack[top] == '/') {
					printf("%c", pop());
				}
			}
			push(str[i]);
		}
	}

	while (top > -1)printf("%c", pop());

	return 0;
}