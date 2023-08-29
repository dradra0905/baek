#include<stdio.h>
#include<stdlib.h>

int compare(const void* first, const void* second);

int N, ans = 1;

typedef struct meeting {
	int start;
	int end;
}meeting;
meeting m[100001];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)scanf("%d %d", &m[i].start, &m[i].end);

	qsort(m, N, sizeof(meeting), compare);

	int now = 0;
	for (int i = 1; i < N; i++) {
		if (m[now].end <= m[i].start) {
			now = i;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}


int compare(const void* first, const void* second) {
	if(((meeting*)first)->end == ((meeting*)second)->end)return ((meeting*)first)->start - ((meeting*)second)->start;
	return ((meeting*)first)->end - ((meeting*)second)->end;
}