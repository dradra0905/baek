#include<stdio.h>

#define min(x,y) (((x) > (y)) ? (y) : (x))

char w[9][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

char b[9][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

char cb[51][51];

int wb(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cb[x + i][y + j] != w[i][j])cnt++;
		}
	}
	return cnt;
}

int bb(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cb[x + i][y + j] != b[i][j])cnt++;
		}
	}
	return cnt;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++)scanf("%c", &cb[i][j]);
	}

	int mm = 1e9;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int tmp = min(wb(i, j), bb(i, j));
			if (tmp < mm)mm = tmp;
		}
	}

	printf("%d\n", mm);

	return 0;
}