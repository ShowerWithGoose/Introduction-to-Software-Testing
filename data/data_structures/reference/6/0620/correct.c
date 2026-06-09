#include  <string.h>
#include  <stdio.h>
#include<ctype.h>
int main(){
int a[100];
int op,num,point=0;
while(scanf("%d",&op),op!=-1){
    if(op==1)//进栈
    {
        scanf("%d",&num);
        if(point==99){
            printf("error ");
            continue;
        }
        a[point]=num;
        point++;
    }
    if(op==0){//出栈
        if(point==0){
            printf("error ");
            continue;
        }
        printf("%d ",a[point-1]);
        point--;
    }
}
return 0;
}










