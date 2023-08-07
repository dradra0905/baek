#include<stdio.h>
#include<stdlib.h>

int arr[100001]; 

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int n, m, a;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		
		int left = 0, right = n - 1;
		int index = -1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (a > arr[mid]) {
				left = mid + 1;
			}
			else if (a < arr[mid]) {
				right = mid - 1;
			}
			else if (a == arr[mid]) {
				index = mid;
				break;
			}
		}
		if (index != -1)printf("1\n");
		else printf("0\n");
	}


	return 0;
}