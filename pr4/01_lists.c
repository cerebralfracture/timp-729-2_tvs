#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
int value;
struct node *next;
struct node *prev;
} node;

typedef struct list {
struct node *head;
struct node *tail;
} list;

void init(list *l) {
l -> head = malloc(sizeof(node));
l -> head = l -> tail = NULL;
}

void clean(list *l) {
node *temp = l->head;
node *next = NULL;
while (temp) {
next = temp->next;
free(temp);
temp = next;
}
free(l);
l = NULL;
}

bool is_empty(list *l) {
if(l -> head == NULL) {
return true;
}
return false;
}

node *find(list *l, int key) {
node *current = l -> head;
if(! l -> head) {
return NULL;
}
while(current -> value != key) {
current = current -> next;
if(current == NULL) {
return NULL;
}
}
return current;
}

node *findlast(list *l, int key) {
node *current = l -> tail;
if(! l -> head) {
return NULL;
}
while(current -> value != key) {
current = current -> prev;
if(current == NULL) {
return NULL;
}
}
return current;
}

int push_back(list *l, int key) {
node *current = malloc(sizeof(node));
if (current == NULL) {
return 1;
}
current->value = key;
current->next = NULL;
current->prev = l->tail;
if (l->tail) {
l->tail->next = current;
}
l->tail = current;
if (l->head == NULL) {
l->head = current;
}
return 0;
}

int push_front(list *l, int key) {
node *temp = malloc(sizeof(node));
if (temp == NULL) {
return 1;
}
temp->value = key;
temp->next = l->head;
temp->prev = NULL;
if (l->head) {
l->head->prev = temp;
}
l->head = temp;
if (l -> tail == NULL) {
l->tail = temp;
}
return 0;
}

int insert_after(list *l, node *n, int key) {
if (n == NULL ) {
return 1;
}
else {
if (n -> next == NULL) {
push_back(l, key);
return 0;
}
else {
node *newNode = malloc(sizeof(node));
newNode -> value = key;
node *NodeAfter = n -> next;
newNode -> next = NodeAfter;
NodeAfter ->prev = newNode;
n -> next = newNode;
newNode -> prev = n;
return 0;
}
}
return 0;
}

int insert_before(list *l, node *n, int key) {
if(n == NULL) {
return 1;
}
if (n == l -> head) {
push_front(l, key);
return 0;
}
node *NewNode = malloc(sizeof(node));
NewNode -> value = key;
NewNode -> next = n;
NewNode -> prev = n -> prev;
n -> prev -> next = NewNode;
n -> prev = NewNode;
return 0;
}

int remove_first(list *l, int key) {
node *found = find(l, key);
if (found != NULL) {
node *prev = found -> prev;
node *next = found -> next;
if (prev != NULL) {
prev -> next = next;
}
if (next != NULL) {
next -> prev = prev;
}
if (found == l->head) {
l -> head = found -> next;
}
if (found == l -> tail) {
l -> tail = found -> prev;
}
free(found);
}
return 0;
}

int remove_last(list *l, int key) {
if(l -> head == NULL) {
return 1;
}
node *found = findlast(l, key);
if (found != NULL) {
node *prev = found -> prev;
node *next = found -> next;
if (prev != NULL) {
prev -> next = next;
}
if (next != NULL) {
next -> prev = prev;
}
if (found == l->head) {
l -> head = found -> next;
}
if (found == l -> tail) {
l -> tail = found -> prev;
}
free(found);
}
return 0;
}

void print(list *l) {
node *current = l->head;
if (current == NULL) {
return;
}
while(current != NULL) {
printf("%d ", current-> value);
current = current -> next;
}
printf("\n");
}

void print_invers(list *l) {
node *current = l -> tail;
if(current == NULL) {
return;
}
while(current != NULL) {
printf("%d ", current-> value);
current = current -> prev;
}
printf("\n");
}

node *findbyindex(list *l, int index) {
if(l -> head == NULL) {
return NULL;
}
node *current = l -> head;
int i = 0;
while(i != index) {
current = current -> next;
if(current == NULL) {
return NULL;
}
i++;
}
return current;
}

void checkingexist(node *n1, node *n2, node *n3) {
if(n1 == NULL) {
printf("0 ");
}
else {
printf("1 ");
}
if(n2 == NULL) {
printf("0 ");
}
else {
printf("1 ");
}
if(n3 == NULL) {
printf("0 \n");
}
else {
printf("1 \n");
}
}

int main() {
int i, n, k1, k2, k3, m, t, j, x, z, a, u, y, r;
(void) scanf("%d", &n);
list *link;
link = malloc(sizeof(list));
init(link);
for(i = 1; i <= n; i++) {
(void) scanf("%d", &a);
push_back(link, a);
}
print(link);
(void) scanf("%d %d %d", &k1, &k2, &k3);
node *finder1 = find(link, k1);
node *finder2
 
= find(link, k2);
node *finder3 = find(link, k3);
checkingexist(finder1, finder2, finder3);
scanf("%d", &m);
push_back(link, m);
print_invers(link);
(void)scanf("%d", &t);
push_front(link, t);
print(link);
(void) scanf("%d %d", &j, &x);
node* FindNode = findbyindex(link, j - 1);
insert_after(link, FindNode, x);
print_invers(link);
(void) scanf("%d %d", &u, &y);
FindNode = findbyindex(link, u - 1);
insert_before(link, FindNode, y);
print(link);
(void) scanf("%d", &z);
remove_first(link, z);
print_invers(link);
(void) scanf("%d", &r);
remove_last(link, r);
print(link);
clean(link);
return 0;
}
