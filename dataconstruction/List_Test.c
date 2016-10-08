/*
 * List_Test.c
 *
 *  Created on: Sep 13, 2016
 *      Author: yusong
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <string.h>

#include "../dataconstruction/Double_Link_List.h"

int main()
{
	int length = 0;
	uint8_t pdata[4] = {0x21,0xe2,0x17,0x69};
	uint8_t pdata2[4] = {0x21,0xe2,0x17,0x25};
	uint8_t pdata3[4] = {0x21,0xe2,0x21,0x25};
	DATA *data_1;
	data_1 = (DATA*)malloc(sizeof(DATA));
	data_1->data_id = 1;
	memcpy(data_1->data,pdata,4);

	DATA *data_2;
	data_2 = (DATA*)malloc(sizeof(DATA));
	data_2->data_id = 2;
	memcpy(data_2->data,pdata2,4);

	DATA *data_3;
	data_3 = (DATA*)malloc(sizeof(DATA));
	data_3->data_id = 3;
	memcpy(data_3->data,pdata3,4);

	_DOUBLE_LINK_NODE *pDLinkNode_head ;
	pDLinkNode_head = (_DOUBLE_LINK_NODE*)malloc(sizeof(_DOUBLE_LINK_NODE));
	pDLinkNode_head = create_double_link_list(data_1);

	pDLinkNode_head = Append_double_link_list(pDLinkNode_head,data_2);
	pDLinkNode_head = Insert_double_link_list(pDLinkNode_head,0,data_3);
	pDLinkNode_head = Delete_double_link_list(pDLinkNode_head,1);
	Print_double_link_list(pDLinkNode_head);
}
