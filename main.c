#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define ERROR   0

typedef char ElemType;
typedef int  Status;

typedef struct LNode{
    ElemType data;
    struct LNode * next;
}LNode, *LinkList;

void visit(ElemType e);
Status InitLinkList(LinkList *L);
Status CreateLinkList(LinkList L);
Status DisplayLinkList(LinkList L);
Status ListEmpty(LinkList L);
Status DestoryList(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList L, int i, ElemType e);
//初始化链表的头节点
Status InitLinkList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        return ERROR;
    (*L)->data = 'H';
    (*L)->next = NULL;
    printf("链表初始化成功！\n");
    return OK;
}
//创建链表
Status CreateLinkList(LinkList L){
    LinkList p,q;
    ElemType e;
    q = L;
    printf("请输入连续字符创建一个链表(回车键表示结束)：\n");
    while(1){
        scanf("%c", &e);
        if(e == 10 ){
            break;
        }
        p = (LinkList)malloc(sizeof(LNode));
        p->data =e;
        q->next = p;
        p->next = NULL;
        q = p;
    }
    printf("创建链表成功！\n");
    return OK;
}

//展示链表的值
Status DisplayLinkList(LinkList L){
    LinkList p;
    //p = L;           //显示头节点的信息
    p = L->next;          //不显示头节点的信息
    printf("链表的值为：");
    while(1){
        if(p == NULL){
            break;
        }
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
//销毁链表
Status DestoryList(LinkList L){

    LinkList p,q;
    p = q = L->next;
    if(ListEmpty(L) == 1 && q != NULL){
        p = q->next;
        free(q);
        q = p;
    }
    free(L);
    printf("销毁队列成功！\n");
    return OK;
}
//判断是否为空链表
Status ListEmpty(LinkList L){
    if(L->next == NULL){
        //printf("链表为空!\n");
        return ERROR;
    }
    return OK;
}

//清空链表，注意和销毁的区别
Status ClearList(LinkList L){
    if(ListEmpty(L) == 1){
        L->next = NULL;
    }
    else{
        printf("此链表本身就是空链表\n");
    }
    return OK;
}

//链表的长度
int ListLength(LinkList L){
    if(ListEmpty(L) == 0){
        return 0;
    }
    else{
        int len = 0;
        LinkList p;
        p = L->next;
        while(p != NULL){
            len++;
            p = p->next;
        }
        return len;
    }
}

//返回链表第i个位置的值
Status GetElem(LinkList L, int i ,ElemType *e){
    LinkList p;
    p = L->next;
    if(i > ListLength(L)){
        printf("输入的值有误，链表没那么长\n");
        return ERROR;
    }
    while(--i){
        p = p->next;
    }
    *e = p->data;
    return OK;
}
//在链表的第i个位置插入值为e的元素
Status ListInsert(LinkList L, int i, ElemType e){
    if(i > ListLength(L)+1){
        printf("插入的位置有误！\n");
        return ERROR;
    }
    else{
        LinkList p,q;
        p = (LinkList)malloc(sizeof(LNode));
        q = L;
        if(i == ListLength(L)+1){
            while(q->next != NULL){
                q = q->next;
            }
        }
        else{
            while(--i){
                q = q->next;
            }
        }

        p->data = e;
        p->next = q->next;
        q->next = p;
        printf("数据插入成功！\n");
        return OK;
    }
}
//删除指定位置的元素并返回值
Status ListDelete(LinkList L, int i, ElemType *e){
    if(i > ListLength(L)){
        printf("删除元素出错，不存在这个索引的元素！\n");
        return ERROR;
    }
    else{

        LinkList p,q;
        p = L;
        while(--i){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        *e = q->data;
        free(q);
        return OK;
    }

}
void visit(ElemType e){
    printf("%c  ", e);
}
int main(){
    LinkList L = NULL;
    ElemType e;
    int i;
    InitLinkList(&L);
    CreateLinkList(L);
    DisplayLinkList(L);
    printf("链表的长度：%d\n", ListLength(L));
    printf("请输入要查询的位置：\n");
    scanf("%d", &i);
    fflush(stdin);  //清空输入缓冲区
    if(GetElem(L, i, &e) == 1)
        printf("链表的第%d个元素的值是：%c\n", i,e);
    printf("请输入要插入的位置：\n");
    scanf("%d", &i);
    fflush(stdin);  //清空输入缓冲区
    printf("请输入要插入的元素：\n");
    scanf("%c", &e);
    fflush(stdin);  //清空输入缓冲区
    if(ListInsert(L, i, e) == 1){
         printf("在链表的第%d个位置插入元素：%c\n", i,e);
    }
    printf("请输入要删除的元素的位置：\n");
    scanf("%d", &i);
    fflush(stdin);  //清空输入缓冲区
    if(ListDelete(L, i, &e) == 1){
        printf("成功是删除链表第%d个位置的元素:%c\n", i, e);
    }
    DisplayLinkList(L);
    ClearList(L);
    printf("清空后的链表的长度：%d\n", ListLength(L));
    DisplayLinkList(L);
    ClearList(L);
    DestoryList(L);

    system("pause");
    return 0;
}
