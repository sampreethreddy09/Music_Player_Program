#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->next=temp->prev=NULL;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail= temp;
	}
	else
	{
		temp->next = list->head;
		list->head->prev=temp;
		list->head = temp;
	}
	list->size++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->next=temp->prev=NULL;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail= temp;
	}
	else
	{
		list->tail->next = temp;
		temp->prev = list->tail;
		list->tail = temp;
	}
	list->size++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->next=temp->prev=NULL;

	node_t *pres;
	pres = list->head;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail= temp;
	}
	else
	{
		while(pres->data != prev)
		{
			pres=pres->next;
		}
		if(pres->next == NULL)
		{
			pres->next = temp;
			temp->prev = pres;
			list->tail = temp;
		}
		else
		{
			temp->next = pres->next;
			pres->next->prev = temp;
			pres->next = temp;
			temp->prev = pres;
		}
	}
	list->size++;
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	int k;
	node_t *pres;
	pres = list->head;
	if(pres->next == NULL)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		pres->next->prev = NULL;
		list->head = pres->next;
	}
	k= pres->data;
	free(pres);
	list->size--;
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	node_t *pres;
	pres = list->tail;
	if(pres->prev == NULL)
	{
		list->tail = NULL;
		list->head = NULL;
	}
	else
	{
		pres->prev->next = NULL;
		list->tail = pres->next;
	}
	free(pres);
	list->size--;
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t *pres;
	pres = list->head;
	while((pres!=NULL)&&(pres->data != data))
	{
		pres=pres->next;
	}
	if(pres!=NULL)
	{
		if((pres->next==NULL)&&(pres->prev==NULL))
		{
			list->tail = NULL;
			list->head = NULL;
		}
		else if(pres->prev==NULL)
		{
			pres->next->prev = NULL;
			list->head = pres->next;
		}
		else if(pres->next==NULL)
		{
			pres->prev->next = NULL;
			list->tail = pres->prev;
		}
		else
		{
			pres->prev->next = pres->next;
			pres->next->prev = pres->prev;
		}
		free(pres);
	}
	else
	{
		printf("No Data Found!!!\n");
	}
	list->size--;
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
	node_t *pres;
	pres = list->head;
	while((pres!=NULL)&&(pres->data != data))
	{
		pres=pres->next;
	}
	return pres;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

