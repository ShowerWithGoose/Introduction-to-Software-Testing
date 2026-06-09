/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-04-11 21:11:17
 * @LastEditors:
 * @LastEditTime: 2022-04-12 11:40:34
 * @FilePath: \Code\multi.c
 * @CopyRight:  Â©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct muti {
  int num;
  int x;
  int jud;
  struct muti *next;

} muti;

muti *insert(muti *head, int num, int x) {
  head->num = num;
  head->x = x;
  head->next = (muti *)malloc(sizeof(muti));

  head->next->next = NULL;
  head = head->next;

  return head;
}

void sort(muti *head) {
  for (muti *i = head; i->next != NULL; i = head->next) {
    for (muti *h = i->next; h->next != NULL; h = h->next) {
    }
  }
}
int cmp(const void *head1, const void *head2) {
  return (((muti *)head2)->x) - (((muti *)head1)->x);
}
int main() {
  int n = 1;
  char c;
  muti an[1000];
  muti *cycle1 = (muti *)malloc(sizeof(muti));
  muti *first1 = cycle1;
  for (int i = 1; n != 0; i++) {
    scanf("%d", &n);
    scanf("%c", &c);

    if (i % 2 != 0) {
      cycle1->num = n;
    } else {
      cycle1->x = n;
      cycle1->next = (muti *)malloc(sizeof(muti));
      cycle1->next->next = NULL;
      cycle1 = cycle1->next;
    }
    if (c == '\n') {
      break;
    }
  }
  // cycle1->x = 0;
  cycle1->next = NULL;
  n = 1;
  muti *cycle2 = (muti *)malloc(sizeof(muti));
  muti *first2 = cycle2;
  for (int i = 1; n != 0; i++) {
    scanf("%d", &n);
    scanf("%c", &c);

    if (i % 2 != 0) {
      cycle2->num = n;
    } else {
      cycle2->x = n;
      cycle2->next = (muti *)malloc(sizeof(muti));
      cycle2->next->next = NULL;
      cycle2 = cycle2->next;
    }
    if (c == '\n') {
      break;
    }
  }
  // cycle2->x = 0;
  cycle2->next = NULL;
  cycle2 = first2;
  //  muti *ans= (muti *)malloc(sizeof(muti));
  //  muti *ansfir=ans;
  int i = 0;
  while (first1->next != NULL) {
    while (cycle2->next != NULL) {
      int numtm = (first1->num) * (cycle2->num);
      int xtm = (first1->x) + (cycle2->x);
      // ans=insert(ans,numtm,xtm);
      an[i].num = numtm;
      an[i].x = xtm;
      an[i].next = NULL;
      an[i].jud = 0;
      i++;
      cycle2 = cycle2->next;
    }
    cycle2 = first2;
    first1 = first1->next;
  }
  qsort(an, i, sizeof(muti), cmp);
  //     while(ansfir->next!=NULL){
  //     printf("%d %d ",ansfir->num,ansfir->x);
  //     ansfir=ansfir->next;
  //  }
  for (int h = 0; h < i; h++) {
    if (an[h].jud == 1) {
      continue;
    }
    int tmp = an[h].x;
    int i = 1;
    while (tmp == an[h + i].x) {
      an[h].num += an[h + i].num;
      an[h + i].jud = 1;
      i++;
    }
    // if(an[h].x==an[h+1].x){
    //   an[h].num=an[h].num+an[h+1].num;
    //   an[h+1].jud=1;
    // }
  }
  for (int h = 0; h < i; h++) {
    if (an[h].jud == 1) {
      continue;
    }
    printf("%d %d ", an[h].num, an[h].x);
  }
  return 0;
}



