#include<stdio.h>

int T, n;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		int now, biggest = 0, bi = 0, cnt = 0, total = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &now);
			if (now > biggest)biggest = now, bi = i + 1, cnt = 0;
			else if (now == biggest)cnt++;
			total += now;
		}
		if (cnt)printf("no winner\n");
		else if (total / 2 < biggest)printf("majority winner %d\n", bi);
		else printf("minority winner %d\n", bi);
	}


	return 0;
}