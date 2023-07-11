#include<stdio.h>
#include<string.h>

char s[100001] = "";

char stack[100001];
int top = -1;

void push(char c) {
	stack[++top];
}

char pop() {
	return stack[top--];
}

int main() {
	int cnt = 0;
	scanf("%[^\n]", s);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(')push(s[i]);
		else {
			if (s[i - 1] == '(') {
				cnt += (top);
				pop();
			}
			else {
				cnt++;
				pop();
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}