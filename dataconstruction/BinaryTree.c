/*
 * BinaryTree.c
 *
 *  Created on: Oct 8, 2016
 *      Author: yusong
 */


#include "BinaryTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <string.h>

//先序构造二叉树
void createBTree(_BINARY_TREE_NODE *proot,DATA *data)
{
        *proot=(_BINARY_TREE_NODE)malloc(sizeof(_BINARY_TREE_NODE));
        memset(proot,0,sizeof(_DOUBLE_LINK_NODE));
        memcpy(&(proot->data_info),data,sizeof(DATA));
        proot->m_pLeft = NULL;
        proot->m_pRight = NULL;
        createBTree(&(*proot)->m_pLeft);
        createBTree(&(*proot)->m_pRight);
}
//递归解：
//（1）如果二叉树为空，节点个数为0
//（2）如果二叉树不为空，二叉树节点个数 = 左子树节点个数 + 右子树节点个数 + 1
int GetBinaryTreeNodeNum(_BINARY_TREE_NODE * proot)
{
    if(proot == NULL) // 递归出口
        return 0;
    return GetBinaryTreeNodeNum(proot->m_pLeft) + GetBinaryTreeNodeNum(proot->m_pRight) + 1;
}
//递归解法：
//（1）如果二叉树为空，二叉树的深度为0
//（2）如果二叉树不为空，二叉树的深度 = max(左子树深度， 右子树深度) + 1
int GetBinaryTreeDepth(_BINARY_TREE_NODE * pRoot)
{
    if(pRoot == NULL) // 递归出口
        return 0;
    int depthLeft = GetBinaryTreeDepth(pRoot->m_pLeft);
    int depthRight = GetBinaryTreeDepth(pRoot->m_pRight);
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
}
//前序遍历递归解法：
//（1）如果二叉树为空，空操作
//（2）如果二叉树不为空，访问根节点，前序遍历左子树，前序遍历右子树
void PreOrderTraverse(_BINARY_TREE_NODE * pRoot)
{
    if(pRoot == NULL)
        return;
    Visit(pRoot); // 访问根节点
    PreOrderTraverse(pRoot->m_pLeft); // 前序遍历左子树
    PreOrderTraverse(pRoot->m_pRight); // 前序遍历右子树
}
//中序遍历递归解法
//（1）如果二叉树为空，空操作。
//（2）如果二叉树不为空，中序遍历左子树，访问根节点，中序遍历右子树
void InOrderTraverse(_BINARY_TREE_NODE * pRoot)
{
    if(pRoot == NULL)
        return;
    InOrderTraverse(pRoot->m_pLeft); // 中序遍历左子树
    Visit(pRoot); // 访问根节点
    InOrderTraverse(pRoot->m_pRight); // 中序遍历右子树
}

