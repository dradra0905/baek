#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char A[10001], B[10001];
int ans[10002];
int idx = 0;

int main() {
	scanf("%s %s", A, B);

	int len1 = strlen(A), len2 = strlen(B);
	while (len1 > 0 || len2 > 0) {
		if (len1 > 0)ans[idx] += (A[--len1] - 48);
		if (len2 > 0)ans[idx] += (B[--len2] - 48);
		idx++;
	}

	for (int i = 0; i < idx; i++) {
		if (ans[i] > 9) {
			ans[i] -= 10;
			ans[i + 1] += 1;
		}
	}
	if (ans[idx] > 9 || ans[idx] < 0)idx--;
	for (int i = idx; i >= 0; i--)
		if (i == idx && ans[i] == 0)continue;
		else printf("%d", ans[i]);

	return 0;
}