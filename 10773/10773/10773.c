#include<stdio.h>

int K, top = -1;
int stack[100001];

void push(int n) {
	stack[++top] = n;
}

int main() {
	scanf("%d", &K);

	int sum = 0, a;
	for (int i = 0; i < K; i++) {
		scanf("%d", &a);
		if (!a && top > -1)top--;
		else push(a);
	}

	for (int i = 0; i <= top; i++)sum += stack[i];
	printf("%d\n", sum);

	return 0;
}