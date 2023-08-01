	#include<stdio.h>

	int main() {
		int charge;
		scanf("%d", &charge);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			charge -= (a * b);
		}

		if (charge)printf("No\n");
		else printf("Yes\n");

		return 0;
	}