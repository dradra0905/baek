#include<stdio.h>

char map[10][10];

int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%s", map[i]);
		getchar();
	}
	
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 0 && map[i][j] == 'F')cnt++;
			else if (i % 2 == 1&& j % 2 == 1&& map[i][j] == 'F')cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}