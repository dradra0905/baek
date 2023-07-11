#include<stdio.h>
#include<string.h>

char stack[101] = "";
int top = -1;

void push(char c) {
	stack[++top] = c;
}

char pop() {
	return stack[top--];
}

int main() {
	char s[101] = "";
	while (1) {
		int check = 0;
		getchar();
		scanf("%[^\n]", s);
		if (strlen(s) == 1 && s[0] == '.')break;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '(' || s[i] == '[')push(s[i]);
			else if (s[i] == ')') {
				char c = pop();
				if (c != '(') {
					top = -1;
					printf("no\n");
					check++;
					break;
				}
			}
			else if (s[i] == ']') {
				char c = pop();
				if (c != '[') {
					top = -1;
					printf("no\n");
					check++;
					break;
				}
			}
		}
		if (top != -1 && check == 0) {
			top = -1;
			printf("no\n");
		}
		else if (top == -1 && check == 0) {
			printf("yes\n");
		}
	}

	return 0;
}