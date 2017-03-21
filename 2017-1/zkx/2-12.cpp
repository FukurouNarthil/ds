#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
typedef int ElemType;    //声明变量类型

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;     //结构体的建立

#define OK 0
#define ERROR 1
#define OVERFLOW 2     //预定义常量

void CreateList(LinkList L, int n)
{
 	int i;
 	LNode* p;
 	L->next = NULL;  //带头结点的单链表
 
 	for (i = 0; i < n; ++i)
	{
 		p = (LinkList)malloc(sizeof(LNode));
 		scanf("%d",&p->data);   //输入元素
 		p->next = L->next;    //插入到表头
 		L->next = p;
 	}
}; 
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc)
{
 	LNode *pa = La->next, *pb = Lb->next, *pc;
 	(*Lc) = pc = La;//用La的头节点作为Lc的头节点
 
 	while (pa&&pb)
	{
 		if (pa->data <= pb->data)
		{
 			pc->next = pa; pc = pa; pa = pa->next;
 		}
 		else
		{
 		pc->next = pb; pc = pb; pb = pb->next;
 		}
    }
 	pc->next = pa ? pa : pb;
 	free(Lb);
 }
void TraverseList_L(LinkList L)
{
 	LNode *p = L->next;
 	while (p)
	{
		printf("%d ",p->data);
 		p = p->next;
 	}
 }
 int main()
 {
	 int n1,n2;

	 printf("输入链表La的数据个数：\n");
	 scanf("%d",&n1);

	  printf("输入链表Lb的数据个数：\n");
	  scanf("%d",&n2);

	 LinkList La,Lb,Lc;
	 La = (LinkList)malloc(sizeof(LNode));
	 Lb = (LinkList)malloc(sizeof(LNode));
//srand(time(NULL));

	 printf("按非递增输入La数据：\n");
	 CreateList(La,n1);  //创建La
 	 printf("La:");         //输出La
 	 TraverseList_L(La);
 	 printf("\n");

	 printf("按非递增输入Lb数据：\n");
	 CreateList(Lb,n2);     //创建Lb
 	 printf("Lb:");            //输出Lb
 	 TraverseList_L(Lb);
 	 printf("\n");

	 MergeList_L(La, Lb, &Lc);  //合并La，Lb
	 printf("合并La和Lb，生成新链表Lc：\n");
 	 printf("Lc:");                        //输出合并后Lc
 	 TraverseList_L(Lc);
 	 printf("\n");
 	return 0;
 }