//
//  main.c
//  testsqure4
//
//  Created by  on 2021/9/22.
//  Copyright Â© 2021 . All rights reserved.
//
#include<stdio.h>
#include<string.h>

int num0[1000];

void f(int n,int a,int num[],int num1[]);
int main()
{
    int n;
    int num[1000];
    int num1[1000];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        num1[i]=i;
        num0[i]=i;
        num[i]=i;
    }
    f(n,0,num,num1);
    return 0;
}
void f(int n,int a,int num[],int num1[])
{
    if(n==2)
    {
        
        for(int i=1;i<=a;i++)
        {
            printf("%d ",num0[i]);
        }
        printf("%d %d",num0[a+1],num0[a+2]);
        printf("\n");
        for(int i=1;i<=a;i++)
        {
            printf("%d ",num0[i]);
        }
        printf("%d %d",num0[a+2],num0[a+1]);
        printf("\n");
        
    }
    else if(n==1)
    {
        printf("1");
    }
    else
    {
        
      
       
        for(int i=a+1;i<=n+a;i++)
        {
            num0[a+1]=num1[i];
            for(int j=a+2,k=a+1;j<=n+a;j++)
            {
                if(k!=i)
                {
                    num0[j]=num1[k];
                    k++;
                }
                else
                {
                    num0[j]=num1[k+1];
                    k+=2;
                }

            }
            int n1[1000];
            for(int j=1;j<=n+a;j++)
            {
                n1[j]=num0[j];
            }
           
            f(n-1,a+1,num,n1);
            
        }
    }
}

