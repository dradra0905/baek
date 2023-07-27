#include<stdio.h>

int n, m, cnt = 0, min = 1e9;
int arr[9][9];
char visited[6][9][9];
int v[9][9];

void c1(int x, int y, int q);
void c2(int x, int y, int q);
void c3(int x, int y, int q);
void c4(int x, int y, int q);
void c5(int x, int y, int q);

void cctv(int x, int y, int q) {
	int check = 0;
	if (x == n && y == m)return;
	for (int i = 0; i < n; i++) {
		//if (x >= n)break;
		for (int j = 0; j < m; j++) {
			//if (y >= m)break;
			if (check == 0)i = x, j = y, check = 1;
			if (!v[i][j]) {
				if (arr[i][j] == 1)c1(i, j, q);
				else if (arr[i][j] == 2)c2(i, j, q);
				else if (arr[i][j] == 3)c3(i, j, q);
				else if (arr[i][j] == 4)c4(i, j, q);
				else if (arr[i][j] == 5)c5(i, j, q);
			}
		}
	}

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cnt++;
				visited[0][i][j] = '0';
			}
			else visited[0][i][j] = '#';
		}
	}
	//min = min < cnt ? min : cnt;
	if (min > cnt) {
		visited[0][x][y];
		arr[x][y];
		min = cnt;
	}
}


void c1(int x, int y, int q) {
	v[x][y] = 1;
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 7 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 7 + q * 100)arr[i][y] = 0;
	}

	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 8 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 8 + q * 100)arr[x][i] = 0;
	}

	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 9 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 9 + q * 100)arr[i][y] = 0;
	}

	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 10 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 10 + q * 100)arr[x][i] = 0;
	}
	v[x][y] = 0;
}

void c2(int x, int y, int q) {
	v[x][y] = 1;
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 11 + q * 100;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 11 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 11 + q * 100)arr[i][y] = 0;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 11 + q * 100)arr[i][y] = 0;
	}

	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 12 + q * 100;
	}
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 12 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 12 + q * 100)arr[x][i] = 0;
	}
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 12 + q * 100)arr[x][i] = 0;
	}
	v[x][y] = 0;
}

void c3(int x, int y, int q) {
	v[x][y] = 1;

	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 14 + q * 100;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 14 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 14 + q * 100)arr[i][y] = 0;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 14 + q * 100)arr[x][i] = 0;
	}


	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 15 + q * 100;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 15 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 15 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 15 + q * 100)arr[i][y] = 0;
	}


	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 16 + q * 100;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 16 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 16 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 16 + q * 100)arr[i][y] = 0;
	}


	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 17 + q * 100;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 17 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 17 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 17 + q * 100)arr[i][y] = 0;
	}

	v[x][y] = 0;
}

void c4(int x, int y, int q) {
	v[x][y] = 1;

	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 18 + q * 100;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 18 + q * 100;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 18 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 18 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 18 + q * 100)arr[i][y] = 0;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 18 + q * 100)arr[x][i] = 0;
	}


	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 19 + q * 100;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 19 + q * 100;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 19 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 19 + q * 100)arr[i][y] = 0;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 19 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 19 + q * 100)arr[i][y] = 0;
	}


	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 20 + q * 100;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 20 + q * 100;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 20 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 20 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 20 + q * 100)arr[i][y] = 0;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 20 + q * 100)arr[x][i] = 0;
	}


	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 21 + q * 100;
	}
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 21 + q * 100;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 21 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 21 + q * 100)arr[i][y] = 0;
	}
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 21 + q * 100)arr[x][i] = 0;
	}
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 21 + q * 100)arr[i][y] = 0;
	}

	v[x][y] = 0;
}

void c5(int x, int y, int q) {
	v[x][y] = 1;
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 13 + q * 100;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 0)arr[i][y] = 13 + q * 100;
	}
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 13 + q * 100;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 0)arr[x][i] = 13 + q * 100;
	}
	cctv(x, y, q + 1);
	for (int i = x; i < n; i++) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 13 + q * 100)arr[i][y] = 0;
	}
	for (int i = x; i >= 0; i--) {
		if (arr[i][y] == 6)break;
		if (arr[i][y] == 13 + q * 100)arr[i][y] = 0;
	}
	for (int i = y; i >= 0; i--) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 13 + q * 100)arr[x][i] = 0;
	}
	for (int i = y; i < m; i++) {
		if (arr[x][i] == 6)break;
		if (arr[x][i] == 13 + q * 100)arr[x][i] = 0;
	}
	v[x][y] = 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
	}

	cctv(0, 0, 0);

	printf("%d\n", min);

	return 0;
}