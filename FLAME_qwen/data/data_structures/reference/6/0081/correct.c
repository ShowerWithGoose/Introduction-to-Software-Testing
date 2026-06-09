//
//  main.c
//  栈的基本操作
//
//  Created by  on 2022/4/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int zhan[101];
    int operate;
    int top=-1;
    while(scanf("%d",&operate)!=EOF){
        if(operate==1){
            int temp;
            scanf("%d",&temp);
            zhan[++top]=temp;
        }
        else if(operate==0){
            if(top==-1){
                printf("error ");
                continue;
            }
            else{
                printf("%d ",zhan[top]);
                top--;
            }
        }
        else
            break;
    }
    return 0;
}

