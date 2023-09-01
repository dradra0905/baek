#include<stdio.h>
#include<string.h>

char str[101];

int main() {
	scanf("%s", str);

	int count = 0, len = strlen(str);
	while (len > count) {
		printf("%c", str[count++]);
		if (!(count % 10))printf("\n");
	}

	return 0;
}