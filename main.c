#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define MAXSIZE 10
#define ElemType char
#define OK 1
#define ERROR 0

typedef struct Node/*������Ͷ���*/
{ ElemType data; struct Node *next;
}Node,*LinkList;/* LinkListΪ�ṹ��ָ������*/


// ����һ���յĵ�����
void  InitiateLinkList(LinkList *H) {
    *H=(LinkList)malloc(sizeof(Node));//����ͷ���
    (*H)->next=NULL; //�����յĵ�����
}

// ������head�ĳ���
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

// ����Ԫ��
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

// ����
int InsertLinkList(LinkList H) {
    Node *r,*s;
    char c;
    int flag = 1; // ���ñ�־λ�����ƽ������
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
            r->next=NULL;//�����һ������next��Ϊ��,��ʾ�������
        }
    }

    return(OK);
}

//��ӡ��������
void PrintOutLinkList(LinkList H)
{
    Node *p;
    p=H->next;//�ӵ�һ����㿪ʼ
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
}


// ɾ��
int DeteleLinkList(LinkList H, int i, char *e)
{
    Node *pre, *s;

    pre = GetLinkList(H, i - 1);//����get����,�ҵ���i-1�����
    if (pre == NULL) {
        printf("ɾ��λ�ò�����");
        return (ERROR);
    } else {
        s = pre->next;
        pre->next = pre->next->next;//ɾ�����
        *e = s->data;
        printf("ɾ����Ԫ����:%c", *e);

        printf("ɾ���������:");
        PrintOutLinkList(H);//���ɾ����Ľ��
        free(s);//�ͷű�ɾ���Ľ��
        return (OK);
    }
}


//������������
int InsertList(LinkList H,int i,ElemType e)
{
    Node *pre,*s;
    int L;
    L=LengthLinkList(H);
    if(L>=MAXSIZE)
    {
        printf("�������ѳ���Ҫ��ĳ���,�޷�����");

        return(ERROR);
    }
    pre=GetLinkList(H,i-1);//����get����,�ҵ���i-1�����
    if(pre==NULL)
    {
        printf("����λ�ò�����");

        return(ERROR);
    }
    else
    {
        s=(Node *)malloc(sizeof(Node));//�½�s���
        s->data=e;//���������ݸ���s��������
        s->next=pre->next;//��ɲ���
        pre->next=s;
        printf("��������������:");
        PrintOutLinkList(H);//�����������������
        return(OK);

    }
}


int main( )
{
    printf("Hello, World!\n");
    LinkList H;
    int a,d,f;
    char b,c,e='m';
    InitiateLinkList(&H);//��ʼ��
    printf("��ʼ��������������:\n");
    InitiateLinkList(H);

    InsertLinkList(H);//β�巢����
    printf("�����������:\n");
    PrintOutLinkList(H);//�������

    printf("\n");
    printf("��������:%d",LengthLinkList(H));

    printf("����������ҵĽڵ�:");
    scanf("%d",&a);
    if(GetLinkList(H,a)==NULL) //��������
    {
        printf("δ�ҵ��˽ڵ�");
        return(ERROR);
    }
    else printf("\n ���ҵ���Ԫ��:%c",*GetLinkList(H,a));
    printf("������Ҫ�����λ�ú�Ԫ��,[hint:������������֮���ж���]:");
    getchar();
    scanf("%d,%c",&d,&c);
    InsertList(H,d,c);//����
    printf("������Ҫɾ����λ��:");
    getchar();
    scanf("%d",&f);
    DeteleLinkList(H,f,&e);//ɾ��
    return(OK);
}
