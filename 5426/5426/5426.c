#include<stdio.h>
#include<string.h>
#include<math.h>

int T;
char in[10001];
char str[101][101];

int main() {
	scanf("%d", &T);
	while (T--) {
		getchar();
		scanf("%s", in);
		int len = strlen(in), rt = sqrt(len);

		int idx = 0;
		for (int i = 0; i < rt; i++) {
			for (int j = 0; j < rt; j++) {
				str[i][j] = in[idx++];
			}
		}

		for (int i = rt - 1; i >= 0; i--) {
			for (int j = 0; j < rt; j++) {
				printf("%c", str[j][i]);
			}
		}
		printf("\n");
	}


	return 0;
}