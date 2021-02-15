/*============================
 * 这是顺序表的头文件
 *===========================*/


//下面的代码必须加，避免头文件重复调用引起的错误
#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/*宏定义*/
#define LIST_INIT_SIZE  100    //顺序表存储空间初始分配量
#define LISTINCREMENT   10     //顺序表存储空间分配增量

/*顺序表元素类型定义*/

typedef int ElemType;


/*
 * 注：elem在使用前需要先为其分配内存，且从elem[0]处开始存储
 * 
 */

typedef struct {
	ElemType  *elem; //顺序表存储空间的基址（指向顺序表所占内存的起始位置）
        int length;      // 当前顺序表长度（包含多少个元素）
        int listsize;

} SqList;


/*
 * 顺序表初始化
 * 初始化成功则返回OK ,否则返回ERROR
 */

Status InitList(SqList* L );

#endif
 





