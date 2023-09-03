#include<stdio.h>

int N;
int stack[100001];
int arr[100001];
char ans[100001];
int top = 0, idx = 0, cur = 1, ansi = 0;

void push(int n) {
	stack[++top] = n;
}
int pop() {
	return stack[top--];
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);

	while (idx < N) {
		if (stack[top] == arr[idx]) {
			pop();
			ans[ansi] = '-';
			idx++;
		}
		else if (stack[top] < arr[idx]) {
			push(cur++);
			ans[ansi] = '+';
		}
		else {
			printf("NO\n");
			return 0;
		}
		ansi++;
	}

	for (int i = 0; i < ansi; i++)printf("%c\n", ans[i]);

	return 0;
}