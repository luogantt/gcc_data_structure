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

Status DestroyList(SqList *L)
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
//
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

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    ElemType* p;

    // 确保顺序表结构存在
    if(L.elem == NULL) {
        return ERROR;
    }

    /*
     * i的初值为第1个元素的位序
     *
     * 其实，更自然的写法是将i初始化为第1个元素的索引
     * 但由于教材中是按位序计数的，所以这里仍写作位序
     */
    i = 1;

    // p的初值为第1个元素的存储位置
    p = L.elem;

    // 遍历顺序表
    while(i <= L.length && !Compare(*p++, e)) {
        ++i;
    }

    if(i <= L.length) {
        return i;
    } else {
        return 0;
    }
}


//查找某个元素的前驱
//如果存在就保存到pre_e中返回OK
//否则返回EEROR


//Status PriorElem(SqList L ,ElemType cur_e,Elemtype * pre_e)
//{



//向顺序表第i个位置上插入e 



void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;

    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
        //printf("%d",L.elem[i])
    }

    printf("\n");
}

//插入元素
//

Status ListInsert(SqList *L,int i,ElemType e)
    { 
      ElemType *newbase;
      ElemType *p,*q;
      //确保顺序表存在
       
      if(L==NULL ||(*L).elem==NULL)
          {return ERROR ;}
      
      //值越界
      if (i<0||i>(*L).length+1)
          { return ERROR;}

     //如果空间已满，则增加新的空间
     if((*L).length >=(*L).listsize)
     {
	    newbase=(ElemType *) realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType)) ;
	    
	    if (newbase==NULL)

		//存储内存失败
		{exit(OVERFLOW);}
	    //新地址
	    (*L).elem=newbase;
	   (*L).listsize+=LISTINCREMENT;

      }
      //q为插入的位置
      q=&(*L).elem[i];
      //右移元素，腾出位置
      for (p=&(*L).elem[(*L).length-1] ;p>=q;--p)
	  {
            *(p+1)=*(p);
	  }
      //插入e
      *q=e;
      //表增加1
      (*L).length++;
      return OK;
    }



/*
 *
 * 删除
 * 删除顺序表第i个位置上的元素，并将被删除元素储存到e 中
 * 删除成功返回OK,否则返回ERROR
 */


Status ListDelete(SqList *L,int i,ElemType *e)
    {
     ElemType *p,*q;

     //确保顺序表结构存在
     if (L==NULL|| (*L).elem==NULL)
         {return ERROR ;}
     //i 值越界
     if (i<0 ||i>(*L).length-1)
         {return ERROR ;}
     //p 为被删除元素的位置
     p=&(*L).elem[i];
     //获取被删除元素
     *e=*p;
     // 表尾部元素位置
     q=(*L).elem+(*L).length -1;


     //左移元素

     for (++p;p<=q;++p)
         {*(p-1)=*p;}
     //表长度减1
     (*L).length--;
     return OK;
    }


/*前驱
 *
 * 获取元素cur_e 的前驱
 * 如果存在，将其存储到pre_e，返回OK
 * 如果不存在则返回ERROR.
 */

Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
    { 
      int i ;
      if (L.elem==NULL || L.length<2)
          {return ERROR ;}
      i=0;
      while (i<L.length && L.elem[i] !=cur_e)
           {i=i+1;}
      
      //如果cur_e 是首个元素没有前驱，或者没有找到元素cur_e返回ERROR
      if (i==0||i>L.length)
	  {return ERROR;}
      
      //存储cur_e 的前驱
      *pre_e=L.elem[i-1];
      
      return OK;
    }
  
/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */

Status NextElem (SqList L ,ElemType cur_e,ElemType * next_e)
    {
      int i;

      //确保顺序存在，且最少包含两个元素
      if (L.elem==NULL|| L.length<2)
          {return ERROR;}

      i=0;

      while (i<L.length-1 && L.elem[i]!=cur_e)
          {i=i+1;}
      
      //如果cur_e 是最后一个元素(没有后继)，或者没有找到元素cur_e返回ERROR
      if (i>=L.length-1)
          {return ERROR;}

      //存储cur_e的后继
       
      *next_e=L.elem[i+1];
      return OK;

    }
       




















































/*
Status LocateElem(SqList L,ElemType e,Status(Compare)(ElemType ,ElemType))
   { 
    int i ;
    ElemType *p;

    if (L.elem==NULL)
	{return ERROR ;}
    i=0;
    p=L.elem;

    while (i<L.length&&!Compare(*p++,e))
          {++i;}
    if (i<=L.length)
	{return i;}
    else
	{return 0;}
   }

*/














































