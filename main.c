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
//��ʼ�������ͷ�ڵ�
Status InitLinkList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        return ERROR;
    (*L)->data = 'H';
    (*L)->next = NULL;
    printf("�����ʼ���ɹ���\n");
    return OK;
}
//��������
Status CreateLinkList(LinkList L){
    LinkList p,q;
    ElemType e;
    q = L;
    printf("�����������ַ�����һ������(�س�����ʾ����)��\n");
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
    printf("��������ɹ���\n");
    return OK;
}

//չʾ�����ֵ
Status DisplayLinkList(LinkList L){
    LinkList p;
    //p = L;           //��ʾͷ�ڵ����Ϣ
    p = L->next;          //����ʾͷ�ڵ����Ϣ
    printf("�����ֵΪ��");
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
//��������
Status DestoryList(LinkList L){

    LinkList p,q;
    p = q = L->next;
    if(ListEmpty(L) == 1 && q != NULL){
        p = q->next;
        free(q);
        q = p;
    }
    free(L);
    printf("���ٶ��гɹ���\n");
    return OK;
}
//�ж��Ƿ�Ϊ������
Status ListEmpty(LinkList L){
    if(L->next == NULL){
        //printf("����Ϊ��!\n");
        return ERROR;
    }
    return OK;
}

//�������ע������ٵ�����
Status ClearList(LinkList L){
    if(ListEmpty(L) == 1){
        L->next = NULL;
    }
    else{
        printf("����������ǿ�����\n");
    }
    return OK;
}

//����ĳ���
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

//���������i��λ�õ�ֵ
Status GetElem(LinkList L, int i ,ElemType *e){
    LinkList p;
    p = L->next;
    if(i > ListLength(L)){
        printf("�����ֵ��������û��ô��\n");
        return ERROR;
    }
    while(--i){
        p = p->next;
    }
    *e = p->data;
    return OK;
}
//������ĵ�i��λ�ò���ֵΪe��Ԫ��
Status ListInsert(LinkList L, int i, ElemType e){
    if(i > ListLength(L)+1){
        printf("�����λ������\n");
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
        printf("���ݲ���ɹ���\n");
        return OK;
    }
}
//ɾ��ָ��λ�õ�Ԫ�ز�����ֵ
Status ListDelete(LinkList L, int i, ElemType *e){
    if(i > ListLength(L)){
        printf("ɾ��Ԫ�س������������������Ԫ�أ�\n");
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
    printf("����ĳ��ȣ�%d\n", ListLength(L));
    printf("������Ҫ��ѯ��λ�ã�\n");
    scanf("%d", &i);
    fflush(stdin);  //������뻺����
    if(GetElem(L, i, &e) == 1)
        printf("����ĵ�%d��Ԫ�ص�ֵ�ǣ�%c\n", i,e);
    printf("������Ҫ�����λ�ã�\n");
    scanf("%d", &i);
    fflush(stdin);  //������뻺����
    printf("������Ҫ�����Ԫ�أ�\n");
    scanf("%c", &e);
    fflush(stdin);  //������뻺����
    if(ListInsert(L, i, e) == 1){
         printf("������ĵ�%d��λ�ò���Ԫ�أ�%c\n", i,e);
    }
    printf("������Ҫɾ����Ԫ�ص�λ�ã�\n");
    scanf("%d", &i);
    fflush(stdin);  //������뻺����
    if(ListDelete(L, i, &e) == 1){
        printf("�ɹ���ɾ�������%d��λ�õ�Ԫ��:%c\n", i, e);
    }
    DisplayLinkList(L);
    ClearList(L);
    printf("��պ������ĳ��ȣ�%d\n", ListLength(L));
    DisplayLinkList(L);
    ClearList(L);
    DestoryList(L);

    system("pause");
    return 0;
}
