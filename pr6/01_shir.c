#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
struct tree *Right;
struct tree *Left;
struct tree *parent;
double key;
} tree;

typedef struct node {
void* ptr;
struct node* next;
} node_t;

typedef struct {
node_t* head;
node_t* tail;
} queue_t;

void queue_init(queue_t* q) {
q -> head = q -> tail = NULL;
}

int queue_empty(queue_t* q) {
return (q -> head == NULL);
}

int queue_push(queue_t* q, void* ptr){
node_t* p = malloc(sizeof(node_t));
if(p != NULL) {
p -> ptr = ptr;
p -> next = NULL;
if(q -> head == NULL)
q -> head = q -> tail = p;
else {
q -> tail -> next = p;
q -> tail = p;
}
}
return (p != NULL);
}

void queue_pop(queue_t* q){
node_t* t;
if(q->head != NULL){
t = q->head;
q -> head = q -> head -> next;
free(t);
if(q -> head == NULL)
q -> tail = NULL;
}
}

void* queue_front(queue_t* q) {
return q->head->ptr;
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

void width_traversal(tree* tr) {
tree* current;
queue_t queue_1;
queue_init(&queue_1);
queue_push(&queue_1, tr);
while(!queue_empty(&queue_1)) {
current = (tree*) queue_front(&queue_1);
queue_pop(&queue_1);
printf("%d ",(int)current -> key);
if(current -> Left)
queue_push(&queue_1, current -> Left);
if(current -> Right)
queue_push(&queue_1, current -> Right);
}
}

int main(void) {
tree *t;
int i;
double a_i;
init(&t);
for (i = 0; i < 7; i++) {
scanf("%lf", &a_i);
insert(t, a_i);
}
width_traversal(t);
return 0;
}
