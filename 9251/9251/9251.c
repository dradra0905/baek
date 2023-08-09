#include<stdio.h>
#include<string.h>

#define max(x,y) (((x) > (y)) ? (x) : (y))

char str1[1001];
char str2[1001];

int mtx[1001][1001];
int mx = 0;
int len1, len2;

int main() {
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);

	len1 = strlen(str1), len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (i == 0 || j == 0) {
				if (str1[i] == str2[j])mtx[i][j] = 1;
				else {
					if (i == 0)mtx[i][j] = mtx[i][j - 1];
					else if (j == 0)mtx[i][j] = mtx[i - 1][j];
				}
			}
			else {
				if (str1[i] == str2[j])mtx[i][j] = mtx[i - 1][j - 1] + 1;
				else mtx[i][j] = max(mtx[i - 1][j], mtx[i][j - 1]);
			}
			mx = max(mx, mtx[i][j]);
		}
	}

	printf("%d\n", mx);

	return 0;
}