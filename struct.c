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

	node_t * head = malloc(node_size);

	head->x = 7;
	head->y = 8;
	head->next = malloc(node_size);
	head->next->x = 12;
	head->next->y = 13;
	head->next->next = malloc(node_size);
	head->next->next->x = 67;
	head->next->next->y = 68;
	head->next->next->next = NULL;

	return head;
}


void showList(node_t * head)
{
	printf("goint to show list \n");
	node_t * current = head;

	while (current != NULL)
	{
		printf("current node info: x:%d, y:%d \n", current->x, current->y);
		current = current->next;
	}

}

//add at the first
void push(node_t ** head, int x, int y)
{
	printf("going to push \n");

	node_t * newHead = malloc(sizeof(node_t));
	newHead->x = x;
	newHead->y = y;
	newHead->next = *head;

	*head = newHead;
}

//add to last
void appendToList(node_t * head, int x, int y)
{
	printf("going to append \n");
	if (head == NULL)
	{
		head = malloc(sizeof(node_t));
		head->x = x;
		head->y = y;
		head->next = NULL;
	}
	else {
		node_t * current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = malloc(sizeof(node_t));
		current->next->x = x;
		current->next->y = y;
		current->next->next = NULL;
	}
}

//remove the first element in the list
int pop(node_t** phead)
{
	printf("going to pop \n");
	int retVal = -1;
	;
	if (*phead == NULL)
	{
		return -1;
	}

	node_t *next = (*phead)->next;
	retVal = (*phead)->x + (*phead)->y;
	free(*phead);
	*phead = next;

	return retVal;
}

int removeLast(node_t * head)
{
	printf("goint to remove last \n");

	int retVal = -1;

	if (head == NULL)
	{
		return -1;
	}
	if (head->next == NULL)
	{
		retVal = head->x + head->y;
		free(head);
	}

	node_t * current = head;

	while (current->next->next != NULL)
	{
		current = current->next;
	}

	retVal = current->next->x + current->next->y;
	free(current->next);
	current->next = NULL;

	return retVal;
}

int removeAtN(node_t ** head, int n)
{
	printf("goint to remove at Nth \n");

	int retVal = -1;

	node_t * temp_node = NULL;
	node_t * current = *head;

	if (n == 0)
	{
		pop(head);
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (current->next == NULL)
			{
				return -1;
			}
			current = current->next;
		}

		temp_node = current->next; //remove target
		current->next = temp_node->next;
		retVal = temp_node->x + temp_node->y;
		free(temp_node);

		return retVal;
	}


}



int main()
{
	node_t * head = createSampleList();
	showList(head);

	pop(&head);
	showList(head);

	appendToList(head, 444, 555);
	appendToList(head, 666, 777);
	showList(head);

	push(&head, 101, 101);
	showList(head);
	push(&head, 202, 202);
	showList(head);
	pop(&head);
	showList(head);
	removeLast(head);
	showList(head);
	removeAtN(&head, 2);
	showList(head);

}
