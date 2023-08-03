#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int fa, fb, fc;
	scanf("%d %d %d", &fa, &fb, &fc);

	int ma, mb, mc;
	scanf("%d %d %d", &ma, &mb, &mc);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				int cnt = 0;
				if (abs(ma - i) <= 2 || abs(ma - i) >= n - 2) {
					cnt++;
				}
				if (abs(mb - j) <= 2 || abs(mb - j) >= n - 2) {
					cnt++;
				}
				if (abs(mc - k) <= 2 || abs(mc - k) >= n - 2) {
					cnt++;
				}
				if (cnt == 3) {
					ans++;
					continue;
				}
				cnt = 0;
				if (abs(fa - i) <= 2 || abs(fa - i) >= n - 2) {
					cnt++;
				}
				if (abs(fb - j) <= 2 || abs(fb - j) >= n - 2) {
					cnt++;
				}
				if (abs(fc - k) <= 2 || abs(fc - k) >= n - 2) {
					cnt++;
				}
				if (cnt == 3) {
					ans++;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}