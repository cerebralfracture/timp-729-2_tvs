#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
struct tree *Right;
struct tree *Left;
struct tree *parent;
double key;
} tree;


void init(tree **n) {
*n = malloc(sizeof(tree));
(*n) -> Right = NULL;
(*n) -> Left = NULL;
(*n) -> key = 123.23;
}

int insert(tree *n, int value) {
if (n -> key == 123.23) {
n -> key = value;
return 0;
}
if (n -> key == value)
return 1;
if (value > n -> key) {
if (n -> Right)
return(insert(n -> Right, value));
else {
n -> Right = malloc(sizeof(tree));
n -> Right -> Right = NULL;
n -> Right -> Left = NULL;
n -> Right -> key = value;
return 0;
}
}
else {
if (n -> Left)
return(insert(n -> Left, value));
else {
n -> Left = malloc(sizeof(tree));
n -> Left -> Right = NULL;
n -> Left -> Left = NULL;
n -> Left -> key = value;
return 0;
}
}
return 2;
}

void inorderTraversal(tree *t) {
if (t == NULL) {
return;
}
inorderTraversal(t -> Left);
inorderTraversal(t -> Right);
printf("%d ", (int)t -> key);
}

int main(void) {
tree *t;
int i;
init(&t);
double a_i;
for(i = 0; i < 7; i++) {
scanf("%lf", &a_i);
insert(t, a_i);
}
inorderTraversal(t);
return 0;
}
