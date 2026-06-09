//
//  main.c
//  词频统计
//
//  Created by  on 2022/3/24.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ans{
    char c[30];
    int count;
} alpha[1000], temp;
char a[2000];
int i, j, k, n, type, len1, len2;
void order(struct ans x[1000], struct ans y, int num){
    int i, j;
    for (i=0;i<num;i++){
        for (j=i+1;j<num;j++){
            if (strcmp(x[i].c, x[j].c) == 0){
                strcpy(x[j].c, "\0");
                x[i].count += x[j].count;
            }
            if (strcmp(x[i].c, x[j].c) > 0){
                y = x[i];
                x[i] = x[j];
                x[j] = y;
            }
        }
    }
}
void exchange(struct ans alpha[1000], int acount){
    int len;
    for(i=0;i<acount;i++){
        len = strlen(alpha[i].c);
        for (j=0;j<len;j++){
            if(alpha[i].c[j]<='Z'&&alpha[i].c[j]>='A')
                alpha[i].c[j] += 32;
        }
    }
}
int main(){
    FILE *in;
    in = fopen("article.txt", "r");
    i=0;
    j=0;
    type=0;
    while(fgets(a, 1999, in) != NULL){
        len2 = strlen(a);
        for (k=0;k<len2;k++){
            if((a[k]<='Z'&&a[k]>='A')||(a[k]>='a'&&a[k]<='z')){
                alpha[i].c[j++] = a[k];
                type=1;
            }
            else if(type!= 0){
                alpha[i].c[j]='\0';
                alpha[i++].count=1;
                j=0;
                type=0;
            }
        }
    }
    n=i;
    exchange(alpha, n);
    order(alpha, temp, n);
    for(i=0;i<n;i++){
        len1 = strlen(alpha[i].c);
        if(len1!= 0)
            printf("%s %d\n", alpha[i].c, alpha[i].count);
    }
    return 0;
}


