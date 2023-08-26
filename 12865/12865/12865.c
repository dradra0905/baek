#include<stdio.h>

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

int N, K;
int d[101][100001];

typedef struct bag {
	int W;
	int V;
}bag;
bag bags[101];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)scanf("%d %d", &bags[i].W, &bags[i].V);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			// j�� ���Կ� �󸶸�ŭ�� ����ġ�� ���� �� �ִ��� �� �� �ִ� �迭�� ����
			if (j - bags[i].W >= 0)d[i][j] = max(d[i - 1][j], d[i - 1][j - bags[i].W] + bags[i].V);
			else d[i][j] = d[i - 1][j];
		}
	}

	printf("%d\n", d[N][K]);

	return 0;
}