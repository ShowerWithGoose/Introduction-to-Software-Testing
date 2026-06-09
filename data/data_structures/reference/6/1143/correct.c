#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int stack[100],*p,count,i,op;


int main(){
    int INT=sizeof(int);
    p=stack;
    while(scanf("%d",&op)){
        if(op==-1)break;
        else if(op==1){
            scanf("%d",&i);
            if(count==100)printf("error ");
            else{
                *p=i;
                p+=INT;
                count++;
            }
        }
        else if(op==0){
            if(count==0)printf("error ");
            else{
                p-=INT;
                printf("%d ",*p);
                *p=0;
                count--;
            }
        }
    }
    return 0;
}


