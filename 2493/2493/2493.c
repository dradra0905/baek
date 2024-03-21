#include<stdio.h>

int stack[500001] = { 0 };
int idx[500001] = { 0 };
int top = 1;

void push(int n, int id) {
	stack[++top] = n;
	idx[top] = id;
}
int pop() {
	return idx[top--];
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (stack[top] < a) {
			while (stack[top] < a && top >0)pop();
			push(a, i + 1);
			printf("%d ", idx[top - 1]);
		}
		else {
			push(a, i + 1);
			printf("%d ", idx[top - 1]);
		}
	}


	return 0;
}