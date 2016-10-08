/*
 * Data_Public.h
 *
 *  Created on: Sep 14, 2016
 *      Author: yusong
 */

#ifndef DATACONSTRUCTION_DATA_PUBLIC_H_
#define DATACONSTRUCTION_DATA_PUBLIC_H_


#define STACK_SIZE 512
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef short int int16_t;
typedef int int32_t;



typedef struct data
{
	uint8_t data_id;
	uint8_t data[4];
}DATA;

typedef struct node_data
{
	struct data data_info;
	struct node_data *next;
	struct node_data *prev;
}NODE_DATA ;

typedef struct double_node_data
{
	struct data data_info;
	struct node_data *next;
	struct node_data *prev;
}_DOUBLE_LINK_NODE ;

typedef struct list {
	NODE_DATA *head;
} list_t;

typedef struct stack
{
  struct data data_info[STACK_SIZE];;    //数据元素
  int top;              //栈顶
}SEQ_STACK;



#endif /* DATACONSTRUCTION_DATA_PUBLIC_H_ */
