#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define MAXSIZE 10
#define ElemType char
#define OK 1
#define ERROR 0

typedef struct Node/*结点类型定义*/
{ ElemType data; struct Node *next;
}Node,*LinkList;/* LinkList为结构体指针类型*/


// 建立一个空的单链表
void  InitiateLinkList(LinkList *H) {
    *H=(LinkList)malloc(sizeof(Node));//建立头结点
    (*H)->next=NULL; //建立空的单链表
}

// 求单链表head的长度
int LengthLinkList(LinkList H) {
    Node *p;
    int  cnt = 0;
    p=H->next;
    while(p->next != NULL) {
        p = p->next;
        cnt++;
    }

    return cnt;
}

// 读表元素
Node *GetLinkList(LinkList H, int i)
{
    int j;
    Node *p;
    p=H;j=0;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(i==j)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

// 插入
int InsertLinkList(LinkList H) {
    Node *r,*s;
    char c;
    int flag = 1; // 设置标志位，控制建表结束
    r = H;
    while(flag)
    {
        c=getchar();
        if(c!='$')
        {
            s=(Node *)malloc(sizeof(Node));
            s->data=c;
            r->next=s;
            r=s;
        }
        else
        {
            flag=0;
            r->next=NULL;//将最后一个结点的next置为空,表示链表结束
        }
    }

    return(OK);
}

//打印链表数据
void PrintOutLinkList(LinkList H)
{
    Node *p;
    p=H->next;//从第一个结点开始
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
}


// 删除
int DeteleLinkList(LinkList H, int i, char *e)
{
    Node *pre, *s;

    pre = GetLinkList(H, i - 1);//调用get函数,找到第i-1个结点
    if (pre == NULL) {
        printf("删除位置不合理");
        return (ERROR);
    } else {
        s = pre->next;
        pre->next = pre->next->next;//删除结点
        *e = s->data;
        printf("删除的元素是:%c", *e);

        printf("删除后的链表:");
        PrintOutLinkList(H);//输出删除后的结点
        free(s);//释放被删除的结点
        return (OK);
    }
}


//单链表插入操作
int InsertList(LinkList H,int i,ElemType e)
{
    Node *pre,*s;
    int L;
    L=LengthLinkList(H);
    if(L>=MAXSIZE)
    {
        printf("单链表已超过要求的长度,无法插入");

        return(ERROR);
    }
    pre=GetLinkList(H,i-1);//调用get函数,找到第i-1个结点
    if(pre==NULL)
    {
        printf("插入位置不合理");

        return(ERROR);
    }
    else
    {
        s=(Node *)malloc(sizeof(Node));//新建s结点
        s->data=e;//将插入数据赋给s的数据域
        s->next=pre->next;//完成插入
        pre->next=s;
        printf("插入后的链表数据:");
        PrintOutLinkList(H);//输出插入后的链表数据
        return(OK);

    }
}


int main( )
{
    printf("Hello, World!\n");
    LinkList H;
    int a,d,f;
    char b,c,e='m';
    InitiateLinkList(&H);//初始化
    printf("初始化插入链表数据:\n");
    InitiateLinkList(H);

    InsertLinkList(H);//尾插发建表
    printf("输出链表数据:\n");
    PrintOutLinkList(H);//输出链表

    printf("\n");
    printf("单链表长度:%d",LengthLinkList(H));

    printf("请输入需查找的节点:");
    scanf("%d",&a);
    if(GetLinkList(H,a)==NULL) //按结点查找
    {
        printf("未找到此节点");
        return(ERROR);
    }
    else printf("\n 查找到的元素:%c",*GetLinkList(H,a));
    printf("请输入要插入的位置和元素,[hint:输入两个数据之间有逗号]:");
    getchar();
    scanf("%d,%c",&d,&c);
    InsertList(H,d,c);//插入
    printf("请输入要删除的位置:");
    getchar();
    scanf("%d",&f);
    DeteleLinkList(H,f,&e);//删除
    return(OK);
}
