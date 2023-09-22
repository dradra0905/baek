#include<stdio.h>

int N, input;

int queue[200001];
int front = 0, back = 0;
void push(int n) {
	queue[front++] = n;
}
int pop() {
	return queue[back++];
}

int main() {
	scanf("%d", &N);
	
	while (1) {
		scanf("%d", &input);
		if (input == -1)break;
		else if (input == 0)pop();
		else if (front - back < N)push(input);
	}
	if (back == front)printf("empty\n");
	else for (int i = back; i < front; i++)printf("%d ", queue[i]);


	return 0;
}