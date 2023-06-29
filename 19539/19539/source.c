#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int tree;
        scanf("%d", &tree);
        sum += tree;
        x += (tree / 2);
    }

    if (sum % 3 != 0)printf("NO\n");
    else {
        if (sum / 3 <= x)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}