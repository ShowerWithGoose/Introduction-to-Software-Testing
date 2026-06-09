#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct ListNode{
    int series;
    int expo;
    struct ListNode *next;
};

struct ListNode* initialize();
struct ListNode* multi(struct ListNode *, struct ListNode *);
struct ListNode* sort(struct ListNode *, struct ListNode *);

int main(){
    struct ListNode *list1, *list2, *list3;
    list1 = initialize();
    list2 = initialize();
    list3 = multi(list1, list2);
    while(list3 != NULL){
        printf("%d %d ", list3->series, list3->expo);
        list3 = list3->next;
    }
    return 0;
}

struct ListNode *initialize(){
    struct ListNode *list, *p1, *p2;
    char c;
    int n;
    list = p1 = NULL;
    while(c != '\n'){
        while(isspace(c = getchar()));
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        for(n = 0; isdigit(c); c = getchar()){
            n = n * 10 + c - '0';
        }
        p2->series = n;
        while(isspace(c = getchar()));
        for(n = 0; isdigit(c); c = getchar()){
            n = n * 10 + c - '0';
        }
        p2->expo = n;
        p2->next = NULL;
        if(list == NULL){
            list = p1 = p2;
        }else{
            p1->next = p2;
            p1 = p1->next;
        }
    }
    return list;
}

struct ListNode *multi(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *list, *p1, *tmp1 = list1, *tmp2 = list2;
    int count = 0;
    list = p1 = NULL;
    while(tmp1 != NULL){
        while(tmp2 != NULL){
            p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            p1->expo = tmp1->expo + tmp2->expo;
            p1->series = tmp1->series * tmp2->series;
            p1->next = NULL;
            tmp2 = tmp2->next;
            count++;
            if(list == NULL){
                list = p1;
            }else{
                list = sort(list, p1);
                p1 = p1->next;
            }
        }
        tmp1 = tmp1->next;
        tmp2 = list2;
    }
    return list;
}

struct ListNode* sort(struct ListNode *list, struct ListNode *buf){
    struct ListNode *p1 = list, *p2;
    if(buf->expo > list->expo){
        list = buf;
        buf->next = p1;
    }
    while(p1 != NULL){
        if(buf->expo == p1->expo){
            p1->series += buf->series;
            return list;
        }else if(buf->expo < p1->expo){
            p2 = p1;
            p1 = p1->next;
        }else{
            buf->next = p1;
            p2->next = buf;
            return list;
        }
    }
    p2->next = buf;
    return list;
}

