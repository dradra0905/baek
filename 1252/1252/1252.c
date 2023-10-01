#include<stdio.h>
#include<string.h>

char a[81], b[81];
int c[81];

int main() {
	scanf("%s %s", a, b);

	int len1 = strlen(a) - 1, len2 = strlen(b) - 1;

	int idx = 0;
	while (len1 >= 0 || len2 >= 0) {
		if (len1 >= 0)c[idx] += a[len1--] - 48;
		if (len2 >= 0)c[idx] += b[len2--] - 48;
		idx++;
	}

	for (int i = 0; i < idx; i++) {
		if (c[i] >= 2) {
			c[i] -= 2;
			c[i + 1] += 1;
		}
	}

	int flag = 0;
	for (int i = idx; i >= 0; i--) {
		if (!flag && !c[i] && i)continue;
		if (i == idx && !c[i])continue;
		else {
			printf("%d", c[i]);
			flag = 1;
		}
	}

	return 0;
}