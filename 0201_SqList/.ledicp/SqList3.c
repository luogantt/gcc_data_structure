/*===================================
 *
 * 线性表顺序存储结构
 ===================================*/

#include "SqList.h"
//#include <"stdio.h">
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



//销毁顺序表，并释放内存

Status DestroyLlist(SqList *L)
    {
      //确保顺序表存在
      if (L==NULL || L->elem==NULL)
          { 
              return ERROR;
	  }
       //释放顺序表内存
       free(L->elem) ;
       
       //释放后内存置空指针
       L->elem=NULL;
       L->length=0;
       L->listsize=0;
       return OK;

     }
  
       
//清空顺序表，不释放内存

Status ClearList(SqList *L)
	{
	 //确保顺序表存在
	 if (L==NULL || L->elem==NULL)
	   {
            return ERROR;
           }
          
           L->length=0;
           return OK; 
	}



//判断一个顺序表是否为空
//TRUE  表示是空
//FALSE 表示非空

Status ListEmpty(SqList L)
    {
      return L.length==0 ?TRUE:FALSE;
    }

//返回顺序表元素的个数

Status ListLength(SqList L)
    {
     return L.length;
    }


//取值

Status GetElem(SqList L,int i,ElemType *e)

     {
       if (i<0||i>L.length-1)
	   {return ERROR;}
       *e=L.elem[i];
       return OK;
     }

//查找某个元素
Status LocateElem(SqList L ,ElemType e,Status(Compare)(ElemType,ElemType))
    {
	int i;
	ElemType* p;
        //确保顺序表结构存在
	if (L.elem ==NULL)
	    {return ERROR ;}
	i=1;
	p=L.elem;
	while (i<L.length && !Compare(*p++,e))
	    { ++i;}
	if (i<=L.length)
	    {return i ;}
	else
	    {return 0;}
    }


//查找某个元素的前驱
//如果存在就保存到pre_e中返回OK
//否则返回EEROR


//Status PriorElem(SqList L ,ElemType cur_e,Elemtype * pre_e)
//{



//向顺序表第i个位置上插入e 

Status ListInsert(SqList *L,int i ,ElemType e)
    {
      ElemType * newbase;
      ElemType *p,*q;
    //确保顺序表结构存在
    if (L==NULL || (*L).elem ==NULL)
        {return ERROR ;}
    //i 值越界	
    if (i<0 ||i>(*L).length-1)
        { return ERROR;}
    

    //如果存储空间已经满，就增加新的空间
     
    if ((*L).length>=(*L).listsize)
        {    
           newbase=(ElemType *) realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
	   if (newbase==NULL)
	       {exit(OVERFLOW);}
           //新地址
	   (*L).elem=newbase;
	   //存储空间
	   (*L).listsize+=LISTINCREMENT;
        }	   

	   //q为插入位置
    q=&(*L).elem[i];

	   //右移元素腾出位置
    for (p=&(*L).elem[(*L).length -1];p>=q;--p)
	       {*(p+1)=*p;}
	   //插入e 
    *q=e;

	   //表的长度增加1
     (*L).length++;
     return OK;
	}


void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;

    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
        //printf("%d",L.elem[i])
    }

    printf("\n");
}


























































