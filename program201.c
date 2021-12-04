
#include<stdio.h>
#include<stdlib.h>

struct Node               //self-referential structure
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
	PNODE First = NULL;
	
	
	return 0;
}