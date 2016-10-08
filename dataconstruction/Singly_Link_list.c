/*
 * list.c
 *
 *  Created on: 01/05/2016
 *      Author: duser
 */
#include "../dataconstruction/Singly_Link_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include "../dataconstruction/Data_Public.h"

/*

void list_init(list_t *list)
{
    list->head = NULL;
}

int list_len(list_t *list)
{
    int i = 0;
    NODE_VEH *head = list->head;
    head = list->head;
    for (; head; head = head->next, i++);
    return i;
}



static NODE_VEH *new_node_veh(VEH_MSG *data)
{
    NODE_VEH *node_veh = (NODE_VEH *)malloc(sizeof(NODE_VEH));
    node_veh->veh_info = *data;
    node_veh->next = NULL;
    return node_veh;
}

int list_print(list_t *list)
{
	NODE_VEH *head = list->head;
    if(head == NULL)
        printf(" There's no vehicle in the platoon\n");
    else
    {
	    for (;head;head = head->next)
		     printf(" The id is %d and it's speed is %.2f now \n", \
				     head->veh_info.veh_id,head->veh_info.speed);
    }
    printf("\n");
	return 1;

}

//--------------------------------------------------//
int id_get(list_t *list, int pos)
{
	int i ,j;
	NODE_VEH *head = list->head;
    for (i = 0;head;head = head->next,i++)
        if(i <= pos)
    		j = head->veh_info.veh_id;
    return j;

}

//-------------------------------------------------//
int get_index_by_node(list_t *list, NODE_VEH *p)
{
    int i;
    NODE_VEH *t = list->head;
    for (i = 0; t != p; t = t->next, i++);
    return i;
}

void list_append(list_t *list, void *data)
{
	NODE_VEH *head = list->head, *node = new_node_veh(data);
	//NODE_VEH *head = list->head, *node = data;
    if (head)
    {
        for (; head->next; head = head->next); //goto the last node
        head->next = node;
    }
    else list->head = node;
}

int list_pop_tail(list_t *list)
{
	NODE_VEH *head = list->head;

    if (!head) return 0; //only 0 eles, pop fail

    if (!(head->next)){ //only 1 node , pop it.
        free(head);
        list->head = NULL;
        return 1;
    }

    for (; head->next->next; head = head->next); //goto the last second node
    free(head->next);
    head->next = NULL;
    return 1;
}

int list_pop(list_t *list, int pos)
{
    int i = 0;

    NODE_VEH  *head = list->head;
    NODE_VEH  *temp = head;

    if (!head) return 0; //no nodes at all
    for (; temp && i != pos; temp = temp->next, i++);  //get the node on position pos

    if (!temp) return 0; //unavaliable pos input:go through the list but no position equal pos.temp == NULL means we cycle the list

    if (temp == head)//if pop node is the head node
    {
        list->head = head->next;
        free(head);
        return 1;
    }

    for (; head->next != temp; head = head->next); //else goto the pop node's pre node
    temp = head->next;
    head->next = temp->next;
    list_print(list);
    free(temp);
    return 1;
}

int list_get(list_t *list, int pos, NODE_VEH *data_ptr)
{
	NODE_VEH *head = list->head;
    int i = 0;

    for (; head; head = head->next, i++)
    {

        if (i == pos)
        {
        	//strcpy(data_ptr->veh_info.veh_id,head->veh_info.veh_id);
            data_ptr->veh_info.veh_id = head->veh_info.veh_id;
            data_ptr->veh_info.veh_lane = head->veh_info.veh_lane;
            data_ptr->veh_info.veh_state = head->veh_info.veh_state;
            data_ptr->veh_info.speed = head->veh_info.speed;
            data_ptr->veh_info.lat = head->veh_info.lat;
            data_ptr->veh_info.lon = head->veh_info.lon;

            return 1;
        }
    }
    return 0;
}


int list_set(list_t *list, int pos, VEH_MSG *data)
{

    NODE_VEH *t;
    int i;

    for (t = list->head, i = 0; t != NULL; t = t->next, i++)
    {
        if (i == pos)
        {
            t->veh_info.veh_id = data->veh_id;
            t->veh_info.speed  = data->speed;
            t->veh_info.lat = data->lat;
            t->veh_info.lon = data->lon;
            printf("t->veh_info.veh_id is %d \n",t->veh_info.veh_id);
            return 1;
        }
    }
    return 0;
}

void list_extend(list_t *list_a, list_t *list_b)
{
	NODE_VEH *t;
    if (list_a->head == NULL)
    	list_a->head = list_b->head;
    else
    {
        for (t = list_a->head; t->next; t = t->next);
        t->next = list_b->head;
    }
}

int list_swap(list_t *list, int pos_a, int pos_b)
{
	NODE_VEH *t, *a_pre = 0, *b_pre = 0, *a = 0, *b = 0, *head = list->head;
    int i;

    if (pos_a == 0) a = head;
    if (pos_b == 0) b = head;

    for (t = head, i = 0; t; t = t->next, i++){
        if (i == pos_a-1) {
            a_pre = t;
            a = t->next;
        }
        if (i == pos_b-1) {
            b_pre = t;
            b = t->next;
        }
    }

    if (!a || !b) return 0; //wrong input position
    if (a == b) return 0; //do not swap the same node

    //change pre node's next
    if (a == head){
        list->head = b;
        b_pre->next = a;
    }else if (b == head){
        list->head = a;
        a_pre->next = b;
    }else{
        a_pre->next = b;
        b_pre->next = a;
    }

    //change a and b's next
    t = a->next;
    a->next = b->next;
    b->next = a;
    return 1;
}

void list_reverse(list_t *list)
{
	NODE_VEH *q = 0, *t, *m = list->head;
    for (; m; t = m->next, m->next = q, q = m, m = t);
    list->head = q;
}

int list_index(list_t *list, int veh_id,NODE_VEH *index_veh)
{
	NODE_VEH *t;
    t = list->head;
    int i = 0;

    for (; t; t = t->next, i++)
    {
        if (t->veh_info.veh_id == veh_id)
        	return i;
        index_veh = t;
    }
    return -1;
}

int list_index_macid(list_t *list,  uint8_t mac_id[],NODE_VEH *index_veh)
{
	NODE_VEH *t;
    t = list->head;
    int i = 0;

    for (; t; t = t->next, i++)
    {
        if (!strcmp(t->veh_info.veh_mac_id , mac_id))
        	return i;
        index_veh = t;
    }
    return -1;
}

void list_cycle(list_t *list, VEH_MSG **data_ptr, int * pos_ptr)
{
    NODE_VEH *p = NULL;
    if (!p)
    	p = list->head;
    *data_ptr = &p->veh_info;//get data
    *pos_ptr = get_index_by_node(list, p); //get index
    //move
    p = p->next;
}

int list_from_array(list_t *list, void *ptr, int size, int len)
{
    if (list->head) return 0; //list is not empty

    int i;
    NODE_VEH *t;

    list->head = new_node_veh(ptr); //init head

    for (i = 1, t = list->head; i < len; i++, t = t->next)
        t->next = new_node_veh(ptr+size*i);

    return 1;
}
*/

