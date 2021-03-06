#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n){
// 创建含有n个元素的单链表
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // 先建立一个带头结点的单链表
  q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++) {
	 scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    // 请补全代码
    p->data=e;
    q->next=p;
    q=p;
  }
  return OK;
}

int LoadLink_L(LinkList &L){
// 单链表遍历
 LinkList p = L->next;
 if(!L)printf("The List is empty!"); // 请填空
 else
 {
	 printf("The LinkList is:");
	 while(p)    // 请填空
	 {
		printf("%d ",p->data);
		p=p->next;    // 请填空
	 }
 }
 printf("\n");
 return OK;
}

int LinkInsert_L(LinkList &L,int i,ElemType e){
// 算法2.9
// 在带头结点的单链线性表L中第i个位置之前插入元素e
   if(!L)return ERROR;
   else{
    LinkList p=L,pre;
    int n;
    for(n=0;n<i;n++){
        pre=p;
        p=p->next;
        if(p)break;
    }
    LinkList hey=new LNode;
        hey->data=e;
    if(n==i){
        pre->next=hey;
        hey->next=p;
        return OK;
    }
    if(i-n==1){
        pre->next=hey;
        hey->next=NULL;
        return OK;
    }
   }
   return OK;
// 请补全代码

}

int LinkDelete_L(LinkList &L,int i, ElemType &e){
// 算法2.10
     LinkList p=L,pre;
     if(!L) return ERROR;
     else{
            if(i==1)
            {L=L->next;return OK;}
            int  n;
            for(n=0;n<i;n++){
            pre=p;
            p=p->next;
            if(!p) break;
            }
            if(n==i){//if n==i,说明成功
                e=p->data;
                pre->next=p->next;
                p->next=NULL;
                return OK;
             }
         }
     return ERROR;

}

int main()
{
 LinkList T;
 int a,n,i;
 ElemType x, e;
 printf("Please input the init size of the linklist:\n");
 scanf("%d",&n);
 printf("Please input the %d element of the linklist:\n", n);
 if(CreateLink_L(T,n))     // 判断链表是否创建成功，请填空
 {
	 printf("A Link List Has Created.\n");
	 LoadLink_L(T);
 }
 else printf("ERROR");
 while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				  if(!LinkInsert_L(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Inserted!\n", x);
				  break;
			case 2: scanf("%d",&i);
				  if(!LinkDelete_L(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: LoadLink_L(T);
				  break;
			case 0: return 1;
		}
	}
}
