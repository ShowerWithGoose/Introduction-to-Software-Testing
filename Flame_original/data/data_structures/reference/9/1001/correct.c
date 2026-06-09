#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line*next;
}l[5000],*p;
int hash[5000];

int main()
{
    int n,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
        for(int j=0;j<i;j++){
            if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
                l[i].next=&l[j];
            }
            else if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2){
                l[j].next=&l[i];
            }
        }
    }
    for(int i=0;i<n;i++){
        p=&l[i];
        while(p->next!=NULL){
            hash[i]++;
            p=p->next;
        }
    }
    for(int i=0;i<n;i++){
        if(hash[i]>max)
            max=hash[i];
    }
    for(int i=0;i<n;i++){
        if(hash[i]==max)
            printf("%d %d %d",hash[i]+1,l[i].x1,l[i].y1);
    }
    return 0;
}

