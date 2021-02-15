#include <stdio.h>
#include "SqList.h"

// 判断data >e 是否成立

Status CmpGreater(ElemType data,ElemType e)
    {
	return data>e ? TRUE:FALSE;
    }

//测试函数，打印元素

void PrintElem(ElemType e)
     {
     printf("%d",e);

     }



int main(int argc ,char** argv )

     {
	 SqList L;
	 int i;
	 ElemType e;
	 printf("初始化顺序表 L ... \n");

         {
	 InitList(&L);
         }
      }

