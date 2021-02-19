#include <stdio.h>
#include "SqList.h"

// 判断data >e 是否成立

Status CmpGreater(ElemType data,ElemType e)
    {
	return data>=e ? TRUE:FALSE;
    }

//测试函数，打印元素

void PrintElem(ElemType e)
     {
     printf("%d ",e);

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

       printf("判断是否为空表");
             {
	      if( ListEmpty(L)==TRUE)
	         {printf("L 为空\n");}
		else
		  {printf("L不为空\n");} 
	      } 

        printf("顺序表插入");
	{
          for (i=0;i<=8;i++)
	    {
	     printf("作为示范 在L的第%d个位置插入%d...\n",i,2*i);
	     ListInsert(&L,i,2*i);
	    }
	 }


                printf("判断是否为空表");
             {
              if( ListEmpty(L)==TRUE)
                 {printf("L 为空\n");}
                else
                  {printf("L不为空\n");}
              }


	
	 printf("████████ ListTraverse \n");
          {
            printf("█ L 中的元素为：L = ");
            ListTraverse(L, PrintElem);
          }

         printf("ListLength \n");

	 {
	   i=ListLength(L);
	   printf("L的长度为%d\n",i);
	 }

         printf("ListDelete \n");
         {
	   printf("删除前的顺序表：L=");
           ListTraverse(L,PrintElem);

	   printf("尝试删除L中的第6个元素...\n");

	   if (ListDelete(&L,6,&e)==OK)
	       {printf("被删除元素是%d\n",e) ;}
	   else
	       {printf("删除失败\n")  ;}
	   printf("删除后的元素：L=");
           ListTraverse(L,PrintElem);

          }
         
          printf ("GetElem 出某个元素");
          {
	     GetElem(L,4,&e);
             printf("L中第四个位置的元素为 %d\n",e);	     
          }

	  printf("定位某个元素%d",4);
          {
	    i =LocateElem(L,4,CmpGreater);
	    printf("L中第一个大于4的元素是%d\n",L.elem[i]);
	  }

	  printf("PriorElem \n");

	  {
             ElemType cur_e=6;

	     if (PriorElem(L,cur_e,&e)==OK)
		{ printf("元素%d 的前驱为%d\n",cur_e,e);}
	     else
		{printf("元素%d的前驱不存在\n",cur_e);}
          }
          printf("NextElem \n");
	  {
            ElemType cur_e=6;
            if ( NextElem(L,cur_e,&e)== OK)
	        {printf("元素%d 的后继为 %d \n",cur_e,e);}
	    else
		{ printf("元素%d的后继不存在\n",cur_e);}

	  }

	  printf ("ClearList\n");

	  {
            printf("清空L前：\n");

	    if (ListEmpty(L)==TRUE)
                {printf("L 为 空 \n");}
	    else
		{printf("L 不为空\n");}
	    ClearList(&L);
	    
	    printf ("清空L 后：");
	    if (ListEmpty(L)==TRUE)
                {printf("L 为 空 \n");}
            else
                {printf("L 不为空\n");}
            }

	  printf ("DestroyList  \n");
	  {
           printf("销毁L前：");
           if (L.elem !=NULL)
	      {printf("L存在\n");}
           else
	      {printf("L不存在！！！\n");}
           DestroyList(&L);

	   printf("销毁L后：");
           if (L.elem !=NULL)
              {printf("L存在\n");}
           else
              {printf("L不存在！！！\n");}

           }


        

     }
       




  
