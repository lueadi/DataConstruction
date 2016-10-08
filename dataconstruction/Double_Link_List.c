/*
 * Double_Link_List.c
 *
 *  Created on: Sep 19, 2016
 *      Author: yusong
 */


#include "Double_Link_List.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <string.h>

_DOUBLE_LINK_NODE *create_double_link_list(DATA *data )
{

	_DOUBLE_LINK_NODE *pDLinkNode_head ;
	pDLinkNode_head = (_DOUBLE_LINK_NODE*)malloc(sizeof(_DOUBLE_LINK_NODE));
	if(pDLinkNode_head != NULL)
	{
		pDLinkNode_head ->prev = NULL;
		pDLinkNode_head ->next = NULL;
		memcpy(&pDLinkNode_head->data_info,data,sizeof(DATA));
	}
	return pDLinkNode_head;
}

_DOUBLE_LINK_NODE *create_double_link_list_node(DATA *data )
{
	_DOUBLE_LINK_NODE *pDLinkNode = NULL;
	pDLinkNode = (_DOUBLE_LINK_NODE*)malloc(sizeof(_DOUBLE_LINK_NODE));
	//assert(	pDLinkNode != NULL);
	memset(pDLinkNode,0,sizeof(_DOUBLE_LINK_NODE));
	memcpy(&pDLinkNode->data_info,data,sizeof(DATA));
	return pDLinkNode;
}

int Length_double_link_list(_DOUBLE_LINK_NODE *head)
{
	int len = 0;
	_DOUBLE_LINK_NODE *pnew;
	pnew = head;
	while(pnew != NULL)
	{
		pnew = pnew->next;
		len++;
	}
	printf("THE_DOUBLE_LINK_LIST LENGTH IS : %d \n ",len);
	return len;
}

int Print_double_link_list(_DOUBLE_LINK_NODE *head)
{
	int len = 0,i = 0;
	_DOUBLE_LINK_NODE *pnew;
	pnew = head;
	while(pnew != NULL)
		{
			//add the print context you want
			printf("--------------PRINT NODE DATA--------------------\n");
			printf("the data ID :%d\n",pnew->data_info.data_id);
			printf("the data is :");
			for(i = 0;i<4;i++)
			{
				printf("%x ",pnew->data_info.data[i]);
			}
			printf("\n");
			len++;
			pnew=pnew->next;
		}
	printf("\n");
	return len;
}
//0号为第二个位置
_DOUBLE_LINK_NODE *Insert_double_link_list(_DOUBLE_LINK_NODE *head,int location,DATA *data)
{
	int i = 0;
	_DOUBLE_LINK_NODE *pnew,*s,*t;
	pnew = head;
	s  = (_DOUBLE_LINK_NODE*)malloc(sizeof(_DOUBLE_LINK_NODE));
	memcpy(&(s->data_info),data,sizeof(DATA));
	if(location <0)
	{
		printf("insert location pos error\n");
		return head;
	}

	for(i=0;i<location;i++)
	{
		pnew = pnew->next;
	}
	t = pnew->next;
	pnew->next = s;
	s->next = t;
	s->prev = pnew;
	t->prev = s;
	printf("[test1]\n");
	return head;
}

_DOUBLE_LINK_NODE *search_double_link_node(_DOUBLE_LINK_NODE *head,DATA *data)
{
	int i=0;
	_DOUBLE_LINK_NODE *pnew;
	pnew = head;
	while(pnew->next != NULL)
		{
		if(!memcmp(&pnew->data_info,&data,sizeof(data)))
			{
			     return pnew;
			}
		}
	return NULL;
}

_DOUBLE_LINK_NODE *Append_double_link_list(_DOUBLE_LINK_NODE *head,DATA *data)
{
	int i=0;
	_DOUBLE_LINK_NODE *pnew,*s;
	pnew = head;
	s  = (_DOUBLE_LINK_NODE*)malloc(sizeof(_DOUBLE_LINK_NODE));
	memcpy(&(s->data_info),data,sizeof(DATA));

	while(pnew->next != NULL)
		{
		    printf("dd:%d",i++);
			pnew = pnew->next;
		}
	pnew->next = s;
	s->prev = pnew;
	return head;
}

_DOUBLE_LINK_NODE *Delete_double_link_list(_DOUBLE_LINK_NODE *head,int location)
{
	int i = 0,length = 0;
	_DOUBLE_LINK_NODE *pnew,*s,*t;
	pnew = head;
	length = Length_double_link_list(head);
	if(location <1 || location>length)
	{
		printf("delete location error\n");
		return head;
	}
	if(pnew->next == NULL)
	{
		return head;
	}
	for(i = 0; i < location; i++)
	{
		pnew = pnew->next;
	}
	t = pnew->next;
	s = pnew->prev;

	if(t == NULL)
	{
		s->next = NULL;
		return head;
	}
	else
	{
		s->next = t;
		t->prev = s;
		return head;
	}
}














