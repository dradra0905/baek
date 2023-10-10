#include<stdio.h>
#include<string.h>

char str[2010];

int main() {
	scanf("%s", str);

	int count = 0;
	int len = strlen(str);
	for (int i = 0; i <= len - 4; i++) {
		if (str[i] == 'D' && str[i + 1] == 'K' && str[i + 2] == 'S' && str[i + 3] == 'H')count++;
	}

	printf("%d\n", count);

	return 0;
}