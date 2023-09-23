#include<stdio.h>
#include<string.h>

char str[101];
char tmp[105];
int len, cur, idx;

int main() {
	scanf("%s", str);

	len = strlen(str), cur = 0, idx = 0;
	while (cur < len) {
		tmp[idx++] = str[cur++]; if (strstr(tmp, "dz=")) {
			for (int i = idx - 3; i < idx; i++)tmp[i] = 0;
			idx -= 3;
			tmp[idx++] = 'a';
		}
		else if (strstr(tmp, "c=") || strstr(tmp, "c-") || strstr(tmp, "d-") || strstr(tmp, "lj") || strstr(tmp, "nj") || strstr(tmp, "s=") || strstr(tmp, "z=")) {
			for (int i = idx - 2; i < idx; i++)tmp[i] = 0;
			idx -= 2;
			tmp[idx++] = 'a';
		}
	}

	printf("%d\n", strlen(tmp));
	return 0;
}