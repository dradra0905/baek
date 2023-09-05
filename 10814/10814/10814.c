#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct profile {
	int age;
	char name[101];
	int index;
}profile;
profile pro[100001];

int static compare(const void* first, const void* second);

int N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%d %s", &pro[i].age, pro[i].name);
		pro[i].index = i;
	}

	qsort(pro, N, sizeof(profile), compare);
	for (int i = 0; i < N; i++) {
		printf("%d ", pro[i].age);
		for (int j = 0; j < strlen(pro[i].name); j++) {
			printf("%c", pro[i].name[j]);
		}
		printf("\n");
	}

	return 0;
}

int static compare(const void* first, const void* second) {
	if (((profile*)first)->age == ((profile*)second)->age)return ((profile*)first)->index - ((profile*)second)->index;
	return ((profile*)first)->age - ((profile*)second)->age;
}