#include<stdio.h>

#define max(n,m) (((m) > (n)) ? (m) : (n))

int arr[101];
int visited[101];
int finished[101];
int stack[101];
int cycle, start, end = -1, dist = 0;

void dfs(int node) {
	visited[node]++;

	if (!visited[arr[node]]) {
		dfs(arr[node]);
		dist++;
	}
	else if (start == arr[node])
		cycle++;

	if (cycle)
		stack[dist] = arr[node];
	else if (!cycle)
		visited[node]--;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d", &m);
		arr[i] = m;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			start = i;
			cycle = 0;
			dfs(i);
			if (cycle) {
				end = ++dist;
			}
		}
	}

	for (int i = 0; i < end; i++) {
		if (stack[i])
			ans++;
	}

	printf("%d\n", ans);

	for (int i = 0; i < end; i++) {
		for (int j = i; j < end; j++) {
			if (stack[i] > stack[j]) {
				int tmp = stack[i];
				stack[i] = stack[j];
				stack[j] = tmp;
			}
		}
	}

	for (int i = 0; i < end; i++)
		if(stack[i])
			printf("%d\n", stack[i]);

	return 0;
}