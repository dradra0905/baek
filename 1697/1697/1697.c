#include<stdio.h>

int queue[100001];
int visited[100001];
int tail = 0, head = 0, dist = 1;

void push(int n) {
	queue[head++] = n;
}
int pop() {
	return queue[tail++];
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	push(n);
	visited[n] = dist;

	int ans = 0;

	while (tail != head) {
		int x = pop();
		if (x == k) {
			ans = visited[x] - 1;
			break;
		}
		dist = visited[x] + 1;

		for (int i = 1; i <= 3; i++) {
			int nx = 0;
			if (i == 1)
				nx = x - 1;
			else if (i == 2)
				nx = x + 1;
			else if (i == 3)
				nx = 2 * x;

			if (nx < 0 || nx > 100000)continue;
			if (visited[nx])continue;

			push(nx);
			if (!visited[nx])visited[nx] = dist;
			else if (visited[nx])visited[nx] = visited[nx] > dist ? dist : visited[nx];
		}
	}
	/*
	for (int i = 0; i < 100000; i++)if (visited[i])printf("%3d: %3d\n", i, visited[i]);
	printf("\n");
	*/

	printf("%d\n", ans);
	return 0;
}