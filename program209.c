//Singly Circular LinkedList using C

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE, **PPNODE;


void Display(PNODE Head, PNODE Tail)
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    
    do
    {
        printf("|%d| -> ",Head -> data);
        Head = Head -> next;
    }while(Head != Tail -> next);
    
    printf("\n");
}


int Count(PNODE Head,PPNODE Tail)
{
	int icnt = 0;
	
	if((Head == NULL) && (Tail == NULL))
	{
		return 0;
	}
	
	do
	{
		icnt++;
		Head = Head -> next;
	}while(Head != Tail->next);
	
	return icnt;
}


void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = data;
	newn -> next = NULL;
	
	if((*Head == NULL) && (*Tail == NULL))     //LL is empty
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}
	
	(*Tail) -> next = *Head;   // to maintain circular nature
}


void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = data;
	newn -> next = NULL;
	
	if((*Head == NULL) && (*Tail == NULL))     //LL is empty
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail) -> next = newn;
		*Tail = newn;
	}
	
	(*Tail) -> next = *Head;
}


void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head == NULL) && (*Tail == NULL))    //empty LL
	{
		return;
	}
	else if(*Head == *Tail)   //single LL
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else     //more than one LL 
	{
		*Head = (*Head) -> next;
		free((*Tail) -> next);
		(*Tail) -> next = *Head;
	}
}


void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;
	
	if((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		while(temp -> next != *Tail)
		{
			temp = temp -> next;
		}		
		
		free(*Tail);     //free(temp -> next);
		*Tail = temp;
		(*Tail) -> next = *Head;
	}
}


void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int ipos)
{
	int size = 0, i = 0;
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	size = Count(*Head);
	
	if((iPos < 1) || (iPos > size+1))     //filter for invalid position\n
	{
		printf("Invalid position\n");
		return;
	}
	
	if(iPos == 1)           //first position
	{
		InsertFirst(Head,no);
	}
	else if(iPos == size+1)    //last position
	{
		InsertLast(Head,no);
	}
	else                      // inbetween position
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = no;
		newn -> next = NULL;
		
		for(i = 1; i < iPos-1; i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;	
	}
}


void DeleteAtPos(PPNODE Head,PPNODE Tail,int ipos)
{
	int size = 0, i = 0;
	PNODE temp = *Head;
	PNODE targeted = NULL;
	
	size = Count(*Head);
	
	if((iPos < 1) || (iPos > size))     //filter for invalid position\n
	{
		printf("Invalid position\n");
		return;
	}
	
	if(iPos == 1)           //first position
	{
		DeleteFirst(Head);
	}
	else if(iPos == size)    //last position
	{
		DeleteLast(Head);
	}
	else                      // inbetween position
	{
		for(i = 1; i < iPos-1; i++)
		{
			temp = temp -> next;
		}
		
		targeted = temp -> next;
		
		temp -> next = targeted -> next;
		free(targeted);
		
	}
}

int main()
{
	PNODE first = NULL;
	PNODE last = NULL;
	
	int iret = 0;
	
	InsertFirst(&first,&last,51);
	InsertFirst(&first,&last,21);
	InsertFirst(&first,&last,11);
	
	InsertLast(&first,&last,101);
	
	Display(first,last);
	
	iret =Count(first,last);
	printf("Number of elements : %d\n",iret);
	
	
	DeleteFirst(&first,&last);
	
	DeleteLast(&first,&last);
	
	Display(first,last);
	
	iret =Count(first,last);
	printf("Number of elements : %d\n",iret);
	
	return 0;
}