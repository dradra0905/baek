#include<stdio.h>
#include<string.h>

char str[51];

int main() {
	scanf("%s", str);
	int cnt = 0;
	int start = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'X')cnt++;
		else {
			if (cnt % 2 == 0) {
				if (cnt >= 4) {
					while (cnt - 4 >= 0) {
						str[start] = str[start + 1] = str[start + 2] = str[start + 3] = 'A';
						cnt -= 4;
						start += 4;
					}
				}
				if (cnt == 2) {
					str[start] = str[start + 1] = 'B';
					cnt -= 2;
					start += 2;
				}
			}
			else {
				printf("-1\n");
				return 0;
			}
			start += 1;
		}
	}
	if (cnt % 2 == 0) {
		if (cnt >= 4) {
			while (cnt - 4 >= 0) {
				str[start] = str[start + 1] = str[start + 2] = str[start + 3] = 'A';
				cnt -= 4;
				start += 4;
			}
		}
		if (cnt == 2) {
			str[start] = str[start + 1] = 'B';
			cnt -= 2;
			start += 2;
		}
	}
	else {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < strlen(str); i++)printf("%c", str[i]);
	printf("\n");

	return 0;
}