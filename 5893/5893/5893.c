#include<stdio.h>
#include<string.h>

char arr[1001];
char ans[1010] = "0000";

int main() {
	scanf("%s", arr);

	int len = strlen(arr);

	int idx = 4;
	for (int i = len - 1; i >= 0; i--) {
		ans[idx++] = arr[i];
	}

	for (int i = 0; i < len; i++) {
		ans[i] += (arr[len - i - 1] - 48);
	}

	for (int i = 0; i < strlen(ans); i++) {
		if (ans[i] >= '2') {
			ans[i] -= 2;
			if (i == strlen(ans) - 1)ans[i + 1] += '1';
			else ans[i + 1] += 1;
		}
	}

	for (int i = strlen(ans) - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}


	return 0;
}