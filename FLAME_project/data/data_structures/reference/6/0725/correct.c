#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int stack[1005];
int top=-1;
int an=0;
void instack(int a)
{
    stack[++top]=a;
}
void outstack()
{
    if(top!=-1){
        printf("%d ",stack[top]);
        top--;
    }
    else{
        printf("error ");
    }
}
int main(){
    int a,n;
    while(1){
        scanf("%d",&n);
        if(n==1){
            scanf("%d",&a);
            instack(a);
        }
        else if(n==0){
            outstack();
        }
        else if(n==-1){
            break;
        }
    }
//    system("pause");
    return 0;
}


