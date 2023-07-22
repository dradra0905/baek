#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	struct tree *left;
	char v;
	struct tree *right;
}tree;

tree* t[28];

void preorderTraversal(tree* tr) {
	printf("%c", tr->v);
	if (tr->left)preorderTraversal(tr->left);
	if (tr->right)preorderTraversal(tr->right);
}

void inorderTraversal(tree* tr) {
	if (tr->left)inorderTraversal(tr->left);
	printf("%c", tr->v);
	if (tr->right)inorderTraversal(tr->right);
}

void postorderTraversal(tree* tr) {
	if (tr->left)postorderTraversal(tr->left);
	if (tr->right)postorderTraversal(tr->right);
	printf("%c", tr->v);
}


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		t[i] = (tree*)malloc(sizeof(tree));
	}

	for (int i = 0; i < n; i++) {
		getchar();
		char v, l, r;
		scanf("%c %c %c", &v, &l, &r);
		if (l - 65 >= 0)t[v - 65]->left = t[l - 65];
		else t[v - 65]->left = NULL;
		if (r - 65 >= 0)t[v - 65]->right = t[r - 65];
		else t[v - 65]->right = NULL;
		t[v - 65]->v = v;
	}

	preorderTraversal(t[0]);
	printf("\n");
	inorderTraversal(t[0]);
	printf("\n");
	postorderTraversal(t[0]);
	printf("\n");



	//for (int i = 0; i < n; i++) {
	//	printf("%c ", t[i]->v);
	//	if (t[i]->left)printf("%c ", t[i]->left->v);
	//	else printf("  ");
	//	if (t[i]->right)printf("%c", t[i]->right->v);
	//	printf("\n");
	//}



	return 0;
}