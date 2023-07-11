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
	char s[31];
	scanf("%[^\n]", s);
	int ans = 0, tmp = 1;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(') {
			tmp *= 2;
			push(s[i]);
		}
		else if (s[i] == '[') {
			tmp *= 3;
			push(s[i]);
		}
		else if (s[i] == ')') {
			if (top == -1 || stack[top] != '(') {
				ans = 0;
				break;
			}
			if (s[i - 1] == pop()) {
				ans += tmp;
				tmp /= 2;
			}
			else {
				tmp /= 2;
			}
		}
		else if (s[i] == ']') {
			if (top == -1 || stack[top] != '[') {
				ans = 0;
				break;
			}
			if (s[i - 1] == pop()) {
				ans += tmp;
				tmp /= 3;
			}
			else {
				tmp /= 3;
			}
		}
	}

	if (top != -1)ans = 0;
	printf("%d\n", ans);

	return 0;
}