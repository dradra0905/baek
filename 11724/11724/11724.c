#include<stdio.h>

int arr[1001][1001];
int visited [1001];
int n, m;

void dfs(int x) {
	visited[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && arr[x][i])
			dfs(i);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}