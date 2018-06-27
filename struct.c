#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
	struct node * next;
    } node_t;

// this function must come before main
node_t *createSampleList()
{
  int node_size = sizeof(node_t);
  
  printf("the size of the node struct is: %u \n", node_size);

  node_t * head =  malloc(node_size);

  head -> x = 7;
  head -> y = 8;
  head ->next = malloc(node_size);
  head ->next -> x= 12;
  head ->next -> y= 13;
  head ->next -> next = malloc(node_size);
  head ->next -> next -> x= 67;
  head ->next -> next -> y = 68;
  head ->next -> next -> next = NULL;
	
	return head;
}

int main()
{
	node_t * head = createSampleList();

    showList(head);
}


void showList(node_t * head)
{
	node_t * current = head;
	
	while(current != NULL)
	{
		printf("current node info: x:%d, y:%d \n", current->x,current->y);
		current = current -> next;
	}
	
}



//remove the first element in the list
void pop (node_t** phead)
{
    (node_t *) h = (*phead);
	
	(node_t *) n = h-> next;
	
	*phead = n;
	
}














