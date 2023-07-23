#include <stdio.h>

int arr[21];
int n, s;
int sum = 0, cnt = 0;

void re(int m) {
	if (sum == s && m!=0) {
		cnt++;
	}

	for (int i = m; i < n; i++) {
		sum += arr[i];
		re(i + 1);
		sum -= arr[i];
	}
}

int main() {
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	re(0);

	printf("%d\n", cnt);

	return 0;
}