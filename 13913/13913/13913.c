#include<stdio.h>

#define min(X,Y) (((X) < (Y)) ? (X) : (Y))

int N, K;

int queue[100001];
int visited[100001];
int arr[100001];
int check[100001];
int tail = 0, head = 0, dist = 1;

void push(int n) {
	queue[head++] = n;
}
int pop() {
	return queue[tail++];
}

int main() {
	scanf("%d %d", &N, &K);

	push(N);
	visited[N] = dist;

	int ans = 0;
	int count = 0;
	while (tail != head) {
		int x = pop();
		if (x == K) {
			ans = visited[x] - 1;
			count++;
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
			visited[nx] = dist;
			check[nx] = x;
		}
	}

	printf("%d\n", ans);

	int index = K, a = 0;
	while (index != N) {
		arr[a++] = index;
		index = check[index];
	}
	arr[a] = N;
	for (int i = a; i >= 0; i--)printf("%d ", arr[i]);

	return 0;
}