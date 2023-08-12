#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int N, apt = 0;
int arr[26][26];
int visited[26][26];
int apart[626];

int xq[1000], yq[1000];
int front = 0, back = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void push(int x, int y) {
	xq[front] = x;
	yq[front++] = y;
}
int popx() {
	return xq[back];
}
int popy() {
	return yq[back++];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int count = 0;
			if (arr[i][j] && !visited[i][j]) {
				push(i, j);
				visited[i][j] = ++apt;
				apart[apt] = ++count;
			}

			while (front != back) {
				int x = popx(), y = popy();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
					if (visited[nx][ny])continue;
					if (!arr[nx][ny])continue;

					push(nx, ny);
					visited[nx][ny] = apt;
					apart[apt] = ++count;
				}
			}
		}
	}

	qsort(apart, apt + 1, sizeof(int), compare);

	printf("%d\n", apt);
	for (int i = 1; i <= apt; i++)printf("%d\n", apart[i]);

	return 0;
}

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}