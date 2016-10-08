/*
 * Stack
 *
 *  Created on: Sep 23, 2016
 *      Author: yusong
 */

#ifndef DATACONSTRUCTION_STACK_H_
#define DATACONSTRUCTION_STACK_H_


#include "Data_Public.h"

SEQ_STACK *SeqStackInit();
void SeqStackFree(SEQ_STACK *s);
int SeqStackIsEmpty(SEQ_STACK *s);                 //判断栈是否为空
void SeqStackClear(SEQ_STACK *s);               //清空栈
int SeqStackIsFull(SEQ_STACK *s);     //判断栈是否已满
int SeqStackPush(SEQ_STACK *s, DATA data);     //入栈操作
DATA SeqStackPop(SEQ_STACK *s);

#endif /* DATACONSTRUCTION_STACK_H_ */
