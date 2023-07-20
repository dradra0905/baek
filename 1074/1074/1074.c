#include<stdio.h>

int z(int n, int r, int c) {
	if (!n)return 0;
	int half = 1 << (n - 1);

	if (r < half && c < half) {
		return z(n - 1, r, c);
	}
	else if (r < half && c >= half) {
		return half * half + z(n - 1, r, c - half);
	}
	else if (r >= half && c < half) {
		return half * half * 2 + z(n - 1, r - half, c);
	}
	else if (r >= half && c >= half) {
		return half * half * 3 + z(n - 1, r - half, c - half);
	}
}

int main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);

	int ans = z(n, r, c);

	printf("%d\n", ans);

	return 0;
}