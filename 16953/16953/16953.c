#include<stdio.h>

int A, B;
int count = 0;
int ans = 0;

void solve(int n) {
	count++;

	if (n == A) {
		ans = n;
		return;
	}
	else if (n < A)return;

	if (n % 2 == 0) {
		solve(n / 2);
	}
	else if (n % 10 == 1) {
		solve(n / 10);
	}
}

int main() {
	scanf("%d %d", &A, &B);

	solve(B);

	if (ans == A)printf("%d\n", count);
	else printf("-1");

	return 0;
}