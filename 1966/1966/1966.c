#include<stdio.h>

typedef struct prio {
	int idx;
	int p;
}prio;

int T, N, M;

prio pr[10001];
int front, back;

void push(int n, int p) {
	pr[front].idx = n;
	pr[front++].p = p;
}
prio pop() {
	return pr[back++];
}

int main() {
	scanf("%d", &T);

	int a;
	while (T--) {
		front = back = 0;
		scanf("%d %d", &N, &M);
		int count = M, cur = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d", &a);
			push(i, a);
		}

		do {
			prio max = pr[back];
			int start = back, end = front;
			int flag = 0;
			for (int i = start; i < end; i++) {
				if (max.p < pr[i].p) {
					max = pr[i];
					flag = 1;
				}
			}
			if (flag) {
				if (M == back)M = front;
				prio tmp = pop();
				push(tmp.idx, tmp.p);
				continue;
			}
			pop();
			count--;
			cur++;
		} while (back <= M);
		printf("%d\n", cur);
	}

	return 0;
}