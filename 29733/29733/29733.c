#include<stdio.h>

char arr[101][101][101];
int ans[101][101][101];
int d[27][4] = {
	{1,1,1},{1,1,0},{1,1,-1},
	{1,0,1},{1,0,0},{1,0,-1},
	{1,-1,1},{1,-1,0},{1,-1,-1},
	{0,1,1},{0,1,0},{0,1,-1},
	{0,0,1},{0,0,-1},
	{0,-1,1},{0,-1,0},{0,-1,-1},
	{-1,1,1},{-1,1,0},{-1,1,-1},
	{-1,0,1},{-1,0,0},{-1,0,-1},
	{-1,-1,1},{-1,-1,0},{-1,-1,-1},
};
int R, C, H;

int main() {
	scanf("%d %d %d", &R, &C, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < R; j++) {
			getchar();
			for (int k = 0; k < C; k++) {
				scanf("%c", &arr[i][j][k]);
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (arr[i][j][k] == '*') {
					for (int l = 0; l < 26; l++) {
						if (i + d[l][0] < 0 || j + d[l][1] < 0 || k + d[l][2] < 0 || i + d[l][0] >= H || j + d[l][1] >= R || k + d[l][2] >= C)continue;
						if (arr[i + d[l][0]][j + d[l][1]][k + d[l][2]] == '*')continue;
						ans[i + d[l][0]][j + d[l][1]][k + d[l][2]]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (arr[i][j][k] != '*')printf("%d", ans[i][j][k] % 10);
				else printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}