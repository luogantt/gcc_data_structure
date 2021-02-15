/*===================================
 *
 * 线性表顺序存储结构
 ===================================*/

#include "SqList.h"

/*
 * 初始化一个顺序表
 * 成功则返回ok,否则返回ERROR
 */

Status InitList(SqList *L)
   {
    //分配指定容量的内存，如果分配失败，则返回NULL	   
        (*L).elem=(ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));

	if ((*L).elem==NULL)
	    {
              //获取内存失败
              exit(OVERFLOW);

	    }
        //初始化顺序表的长度为0
	L->length=0;
	//顺序表初始内存分配量
	L->listsize=LIST_INIT_SIZE;

	return OK;
    }


