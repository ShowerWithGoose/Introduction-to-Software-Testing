#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void print(int a[10],int stl){
for(int i=0;i<stl-1;i++)
    printf("%d ",a[i]);
printf("%d\n",a[stl-1]);
}
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
void row(int *a,int start,int end,int stl){
qsort(a+start,end-start+1,sizeof(int),cmp);

if(start==end)
    print(a,stl);
else{
    for(int i=start;i<=end;i++){
        int temp=0;
        temp=a[i];
        a[i]=a[start];
        a[start]=temp;


        row(a,start+1,end,stl);
        temp=a[i];
        a[i]=a[start];
        a[start]=temp;
        qsort(a+start,end-start+1,sizeof(int),cmp);

    }
}
}
int a[10];
int main(){
int x;
scanf("%d",&x);

for(int i=0;i<x;i++)
    a[i]=i+1;
row(a,0,x-1,x);
return 0;
}

