#include<stdio.h>
#include<stdlib.h>

int arr[502][502];
int visited[502][502];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int xq[250001];
int yq[250001];
int head = 0, tail = 0;

void push(int x, int y) {
	xq[head] = x;
	yq[head++] = y;
}

int popx() {
	return xq[tail];
}
int popy() {
	return yq[tail++];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
	}

	int max = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 1 || arr[i][j] == 0)continue;
			visited[i][j] = 1;
			push(i, j);
			int area = 0;

			while (head != tail) {
				area++;
				int x = popx(), y = popy();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
					if (visited[nx][ny] == 1 || arr[nx][ny] == 0)continue;

					visited[nx][ny]++;
					push(nx, ny);
				}
			}
			cnt++;
			max = max < area ? area : max;
		}
	}

	printf("%d\n%d", cnt, max);

	return 0;
}