#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tree {
struct tree *Right;
struct tree *Left;
struct tree *parent;
double key;
} tree;

typedef struct stack_node {
struct tree *data;
struct stack_node *next;
} stack_node;

typedef struct stack {
stack_node *head;
} stack;


void init_stack(stack *s) {
s -> head = NULL;
}

int push(stack *s, tree *n) {
stack_node *snode = malloc(sizeof(stack_node));
snode -> data = n;
snode -> next = s -> head;
s -> head = snode;
return 0;
}

tree* pop(stack *s) {
stack_node *snode = s -> head;
tree *n = s -> head -> data;
s -> head = s -> head -> next;
free(snode);
return n;
}


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

void preorderTraversal(tree *n) {
if (n == NULL) {
return;
}
stack *s = malloc(sizeof(stack));
init_stack(s);
push(s, n);
while (s -> head != NULL) {
n = pop(s);
printf("%d ", (int)n->key);
if (n -> Right) {
push(s, n->Right);
}
if (n -> Left) {
push(s, n->Left);
}
}
}

int main(void) {
tree *t;
int i;
init(&t);
double a_i;
for (i = 0; i < 7; i++) {
scanf("%lf", &a_i);
insert(t, a_i);
}
preorderTraversal(t);
return 0;
}
