#include<stdio.h>
#include<string.h>

typedef struct {
	int r;
	int g;
	int b;
}house;

int main() {
	int n, cost = 0;
	scanf("%d", &n);
	house h[1001];
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &h[i].r, &h[i].g, &h[i].b);
	}


}