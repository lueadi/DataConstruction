/*
 * Stack.c
 *
 *  Created on: Sep 23, 2016
 *      Author: yusong
 */

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <string.h>

SEQ_STACK *SeqStackInit()
{
	SEQ_STACK *p;
  if (p = (SEQ_STACK *)malloc(sizeof(SEQ_STACK)))         //申请栈内存
  {
    p->top = 0;
    return p;
  }
  return NULL;             //申请内存失败返回空值
}

void SeqStackFree(SEQ_STACK *s)
{
  if(s)
    free(s);
}

//判断栈的状态
int SeqStackIsEmpty(SEQ_STACK *s)                 //判断栈是否为空
{
  return(s->top == 0);
}
void SeqStackClear(SEQ_STACK *s)               //清空栈
{
  s->top = 0;
}

int SeqStackIsFull(SEQ_STACK *s)      //判断栈是否已满
{

	if(s->top == STACK_SIZE)
		return 1;
	else
		return 0;
}

//入栈
int SeqStackPush(SEQ_STACK *s, DATA data)     //入栈操作
{
  if ((s->top+1) > STACK_SIZE)
  {
    printf("栈溢出！\n");
    return 0;
  }
  s->data_info[++s->top] = data;         //将元素入栈
 // memcpy(&s->data_info[++s->top], data,sizeof(DATA));
  return 1;
}
//出栈
DATA SeqStackPop(SEQ_STACK *s)     //出栈操作
{
  if (s->top == 0)
  {
    printf("栈为空！\n");
    exit(0);
  }
  return (s->data_info[s->top--]);            //弹出栈顶元素
}


