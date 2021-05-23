#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int value;          
	struct node *next;  
} node;

typedef struct list {
	struct node *head;  
	struct node *tail; 
} list;

void init(list *l)
{
	l->head = NULL;
	l->tail = l->head;
}

void clean(list *l)
{
	node *tmp = l->head;
	node *tmp1;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	l->head = NULL;
	l->tail = NULL;
}

bool is_empty(list *l)
{
	if (l->head == NULL)
		return 1;
	else return 0;
}

node *find(list *l, int value)
{
	node *tmp = l->head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

int push_back(list *l, int value)
{
	node *new = (node*)malloc(sizeof(node));
	new->value = value;
	if (l->tail != NULL)
	{
		l->tail->next = new;
	}
	else
	{
		l->head = new;
	}
	l->tail = new;
	if (new != NULL)
	{
		return 0;
	}
}

int push_front(list *l, int value)
{
	node *new = (node*)malloc(sizeof(node));
	new->value = value;
	if (l->head == NULL)
	{
	    l->head = new;
		l->tail = new;
	}
		
	else
	{
		new->next = l->head;
		l->head = new;
	}
	if (new!= NULL)
	{
		return 0;
	}
}

int insert_after(node *n, int value)
{ 
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = n->next;
	n->next = new;
}

void insert_after_num(list* l, int num, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	node* tmp = l->head;
	int count = 1;
	while (count != num)
	{
		tmp = tmp->next;
		count++;
	}
	new->next = tmp->next;
	tmp->next = new;
}

int remove_node(list *l, int value)
{
	node *adress;
	node *temp=l->head;
	adress = find(l, value);
	if (adress==NULL)
	{
		return 1;
	}
	else{
		if (adress==l->head){
			l->head=l->head->next;
		}
		else{
			while (temp->next!=adress){
				temp=temp->next;
			}
			if ((adress==l->tail)&&(temp->next==NULL)){
                        	l->tail=temp;
	                }
			else{
			temp->next=adress->next;
			}
		}
		free(adress);
		return 0;
	}	
}

void print(list *l)
{
	if (is_empty(l) == 0)
	{
		node* tmp = l->head;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
			{
				printf("%d", tmp->value);
				tmp = tmp->next;
			}
			else
			{
				printf("%d ", tmp->value);
				tmp = tmp->next;
			}
		}
		printf("\n");
	}
}

int main() {

	struct list *l;
	init(l);
	int n, val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		push_back(l, val);
	}
	print(l);
	for (int i=0; i<3; i++)
	{
	    scanf("%d", &val);
	    if (find(l, val)==NULL)
	    {
	        printf("%d ", 0);
	    }
	    else 
	    {
	        printf("%d ", 1);
	    }
	}
	printf("\n");
	scanf("%d", &val);
	push_back(l, val);
	print(l);
	scanf("%d", &val);
	push_front(l, val);
	print(l);
	int j, x;
	scanf("%d", &j);
	scanf("%d", &x);
	insert_after_num(l, j, x);
	print(l);
	scanf("%d", &val);
	remove_node(l,val);
	print(l);
	clean(l);
	return 0;
}
