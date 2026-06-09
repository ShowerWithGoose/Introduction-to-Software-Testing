#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int num1;                     
    int num2;
} a[100000],b[100000],p[10000],q[10000];
int k1= 0,k2= 0;
char c = ' ';
int i,j;
int cmp(const void *a, const void*b){
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return d->num2 - c->num2;
}
int main(){
    while( c != '\n'){
        scanf("%d%d%c",&a[k1].num1,&a[k1].num2,&c);
        ++k1;
    }
    c = ' ';
    while( c != '\n'){
        scanf("%d%d%c",&b[k2].num1,&b[k2].num2,&c);
        ++k2;
    }
    int k = 0;
    for(i = 0; i < k1; i++)                       
        for(j = 0; j < k2; j++){
        p[k].num1= a[i].num1*b[j].num1;
        p[k].num2= a[i].num2+ b[j].num2;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp);                     
    for(i = 0; i < k; i++){
        if(p[i].num2 == p[i+1].num2&& p[i].num2 != 0){
            p[i+1].num1= p[i].num1+p[i+1].num1;
            p[i].num1 = 0;
        }
    }
    for(i = 0; i < k; i++)
        if(p[i].num1!= 0)
        printf("%d %d ",p[i].num1,p[i].num2);             
        return 0;
}


