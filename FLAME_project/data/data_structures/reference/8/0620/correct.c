#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct pole{
int id;
struct pole* next[100];
int ln;
}pic;

static int count[100]={0};
static int queue[100]={0};
int qn=0;
int qi=0;

void depth(pic* a,int start){
count[start]++;
printf("%d ",a[start].id);
int i=0;
while(a[start].next[i]!=NULL){
    if(count[a[start].next[i]->id]==0)
        depth(a,a[start].next[i++]->id);
        else
            i++;
}
}
void width(pic* a,int start,int n){
    printf("%d ",a[start].id);
    int i=0,flag=0;
    while(a[start].next[i]!=NULL){
        flag=0;
        for(int j=0;j<=qn;j++){
                if(queue[j]==a[start].next[i]->id)
                    flag++;
            }
        if(flag!=0){
            i++;
            continue;
        }
        else
          queue[++qn]=a[start].next[i++]->id;
        }
if(qi<n-1)
width(a,queue[++qi],n);
}
pic a[100];
int main(){
int n,line;
for(int i=0;i<100;i++){
    a[i].id=i;
    a[i].ln=0;
    for(int j=0;j<100;j++)
        a[i].next[j]=NULL;
}

scanf("%d%d",&n,&line);

for(int i=0;i<line;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    a[x].next[a[x].ln++]=&a[y];
    a[y].next[a[y].ln++]=&a[x];
    }
for(int i=0;i<n;i++){
    for(int j=0;j<a[i].ln-1;j++){
        for(int k=j+1;k<a[i].ln;k++){
            if(a[i].next[j]->id>a[i].next[k]->id){
                pic* temp=a[i].next[j];
                a[i].next[j]=a[i].next[k];
                a[i].next[k]=temp;
            }
        }
    }
}//输入并排序

depth(a,0);
printf("\n");
memset(count,0,100);
width(a,0,n);
printf("\n");
memset(count,0,100);
memset(queue,0,100);
qi=qn=0;

int del;
scanf("%d",&del);


for(int i=0;i<n;i++){
    for(int j=0;j<a[i].ln;j++){
        if(a[i].next[j]->id==del){
            for(int k=j;k<a[i].ln-1;k++){
                a[i].next[k]=a[i].next[k+1];//向前覆盖
            }
            a[i].next[a[i].ln-1]=NULL;
            a[i].ln--;
        }
    }
}
n--;
depth(a,0);
memset(count,0,100);
printf("\n");
width(a,0,n);
memset(count,0,100);
memset(count,0,100);
printf("\n");
return;
}

