#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Polynominal_1{
    int an;
    int n;
    struct Polynominal_1 *link;
}LNode1,*LinkList1;

typedef struct Polynominal_2{
    int an;
    int n;
    struct Polynominal_2 *link;
}LNode2,*LinkList2;

typedef struct Polynominal_3{
    int an;
    int n;
    struct Polynominal_3 *link;
}LNode3,*LinkList3;

int main(){
    char s;
    int n1;
    int n2;

    LinkList1 p1,r1,list1 = NULL;
    do{
        scanf("%d %d%c",&n1,&n2,&s);
        p1 = (LinkList1)malloc(sizeof(LNode1));
        p1 -> an = n1;
        p1 -> n = n2;
        p1 -> link = NULL;
        if(list1 == NULL){
            list1 = p1;
            r1 = list1;
        }
        else{
            r1 -> link = p1;
            r1 = r1 -> link;
        }
    }while(s != '\n');
    p1 = (LinkList1)malloc(sizeof(LNode1));
    p1 -> an = -1;
    p1 -> n = -1;
    p1 -> link = NULL;
    r1 -> link = p1;

    LinkList2 p2,r2,list2 = NULL;
    do{
        scanf("%d%d%c",&n1,&n2,&s);
        p2 = (LinkList2)malloc(sizeof(LNode2));
        p2 -> an = n1;
        p2 -> n = n2;
        p2 -> link = NULL;
        if(list2 == NULL){
            list2 = p2;
            r2 = list2;
        }
        else{
            r2 -> link = p2;
            r2 = r2 -> link;
        }
    }while(s != '\n');
    p2 = (LinkList2)malloc(sizeof(LNode2));
    p2 -> an = -1;
    p2 -> n = -1;
    p2 -> link = NULL;
    r2 -> link = p2;

    p1 = list1;
    p2 = list2;
    LinkList3 p3,r3,list3 = NULL;
    n1 = 0;
    n2 = 0;
    int flag = 0;
    while(p1 -> link != NULL){
        while(p2 -> link != NULL){
            n1 = p1 -> an * p2 -> an;
            n2 = p1 -> n + p2 -> n;
            flag = 1;
            while(flag != 0){
                if(list3 == NULL){
                    p3 = (LinkList3)malloc(sizeof(LNode3));
                    p3 -> an = n1;
                    p3 -> n = n2;
                    p3 -> link = NULL;
                    list3 = p3; 
                    r3 = list3;
                    flag = 0;
                }
                else{
                    if(n2 > r3 -> n){
                        p3 = (LinkList3)malloc(sizeof(LNode3));
                        p3 -> an = n1;
                        p3 -> n = n2;
                        p3 -> link = r3;
                        list3 = p3; 
                        r3 = list3;
                        flag = 0;
                    }
                    else{
                        if(r3 -> link != NULL && n2 < r3 -> n && n2 > r3 -> link -> n){
                            p3 = (LinkList3)malloc(sizeof(LNode3));
                            p3 -> an = n1;
                            p3 -> n = n2;
                            p3 -> link = r3 -> link;
                            r3 -> link = p3;
                            r3 = list3;
                            flag = 0;
                        }
                        else if(r3 -> link != NULL && n2 < r3 -> n && n2 <= r3 -> link -> n){
                            r3 = r3 -> link;
                            continue;
                        }
                        else if(n2 == r3 -> n){
                            r3 -> an += n1;
                            r3 = list3;
                            flag = 0;
                        }
                        else if(r3 -> link == NULL){
                            p3 = (LinkList3)malloc(sizeof(LNode3));
                            p3 -> an = n1;
                            p3 -> n = n2;
                            p3 -> link = NULL;
                            r3 -> link = p3;
                            r3 = list3;
                            flag = 0;
                        }
                    }
                }
            }
            p2 = p2 -> link;
        }
        p1 = p1 -> link;
        p2 = list2;
    }
    r3 = list3;
    while(r3 -> link != NULL){
        printf("%d %d ",r3 -> an, r3 -> n);
        r3 = r3 -> link;
    }
    printf("%d %d ",r3 -> an, r3 -> n);
    printf("\n");
    return 0;
}
