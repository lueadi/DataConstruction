/*
 * Double_Link_List.h
 *
 *  Created on: Sep 19, 2016
 *      Author: yusong
 */

#ifndef DATACONSTRUCTION_DOUBLE_LINK_LIST_H_
#define DATACONSTRUCTION_DOUBLE_LINK_LIST_H_
#include "../dataconstruction/Data_Public.h"

_DOUBLE_LINK_NODE *create_double_link_list(DATA *data );
_DOUBLE_LINK_NODE *create_double_link_list_node(DATA *data );
int Length_double_link_list(_DOUBLE_LINK_NODE *head);
int Print_double_link_list(_DOUBLE_LINK_NODE *head);
_DOUBLE_LINK_NODE *Insert_double_link_list(_DOUBLE_LINK_NODE *head,int location,DATA *data);
_DOUBLE_LINK_NODE *Delete_double_link_list(_DOUBLE_LINK_NODE *head,int location);
_DOUBLE_LINK_NODE *Append_double_link_list(_DOUBLE_LINK_NODE *head,DATA *data);
_DOUBLE_LINK_NODE *search_double_link_node(_DOUBLE_LINK_NODE *head,DATA *data);

#endif /* DATACONSTRUCTION_DOUBLE_LINK_LIST_H_ */
