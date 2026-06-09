//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{int a[100],sum=0;
    int p,b;
    while(scanf("%d",&p)){
        if(p==-1)break;
        if(p==0){
            if(sum==0)
                printf("error ");
            else
            {   printf("%d ",a[sum-1]);sum--;}
        }
        if(p==1){
            scanf("%d",&b);
        if(sum==100)
            printf("error ");
        else
        {a[sum]=b;sum++;}
        }
    }
    return 0;
}

