#include<stdio.h>
#include<string.h>

char plate[51];
int ans = 0;

int main() {
	scanf("%s", plate);
	int len = strlen(plate);

	char before = 0;
	for (int i = 0; i < len; i++) {
		if (before == plate[i])ans += 5;
		else ans += 10;

		before = plate[i];
	}

	printf("%d\n", ans);

	return 0;
}