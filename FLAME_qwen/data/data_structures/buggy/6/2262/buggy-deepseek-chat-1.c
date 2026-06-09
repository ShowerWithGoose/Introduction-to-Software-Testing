#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int box[100];
int num=0;

void line(int s[],int b){//此处需要括号 
    if(num==100){
        printf("error ");
    }
    
    else{
        s[num++]=b;
    } 
}

void outline(int s[]){
    if(num==0){
        printf("error ");
        
    }
    
    else{
        printf("%d ",s[--num]);
    }
}
int main()
{
    for(;;)//与 while(1) 是等价的 
    {
        int j;
        scanf("%d",&j);//每回都要输入j； 
        
        if(j == 1){
            int a;
            scanf("%d",&a);
            line(box,a);//数组在函数中不需要括号！ 
        }
        
        else if(j == 0){
            outline(box);
        }
        
        else if(j == -1) break;
    }
    return 0;
}