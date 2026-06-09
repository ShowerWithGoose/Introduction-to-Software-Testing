#include <stdio.h>
#include <stdlib.h>
typedef struct term{
    int num;
    int ex;
} term;

int num = 0, num2 = 0, m = 0;
term str[10000], str2[10000], str1[10000];
int input(term node[]);
int cmp(const void *a, const void *b);
int main() {
    num = input(str);
    num2 = input(str2);
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num2; j++) {
            str1[m].num = str[i].num*str2[j].num;
            str1[m].ex = str[i].ex+str2[j].ex;
            m++;
        }
    }
    qsort(str1, m, sizeof(term), cmp);
    for (i = 0; i < m-1; i++) {
        int j = 1;
        while(str1[i].ex == str1[i+j].ex) {
            str1[i].num += str1[i+j].num;
            str1[i+j].num = 0;
            j++;
        }
    }
    qsort(str1, m, sizeof(term), cmp);
    for (i = 0; i < m; i++) {
        if (str1[i].num == 0) {
            continue;
        }else{
            printf("%d %d ", str1[i].num, str1[i].ex);
        }
    }
    return 0;
}

int cmp(const void *a, const void *b){
    term *x = (term*)a;
    term *y = (term*)b;
    if (x->ex <= y->ex) {
        return 1;
    }else{
        return -1;
    }

}
int input(term node[]){
    int i = 0;
    char ch;
    do{
        scanf("%d%d%c", &node[i].num, &node[i].ex, &ch);
        i++;
    }while(ch != '\n');
    return i;
}
/*
10 80000 2 6000 7 300 5 10 18 0

 3 6000 5 20 8 10 6 0
 
30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 31 6010 66 6000 35 320 56 310 42 300 25 30 130 20 174 10 108 0
 */

