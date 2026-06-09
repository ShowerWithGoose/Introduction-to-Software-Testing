#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int a[11],b[11],c[11];// c[] is used for deciding whether the number has been writen into full permutation
int line(int ,int );

int main()
{
    int n;    int i,k;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        a[i]=i+1;

    k=0;
    
    line(k,n);
    
     return 0;
}

int line(int m,int n) // @@ Function is declared as int but lacks a return statement, which causes a compilation error. It should be declared as void or include a return 0; statement.
{
    int i,j;
    
    if(m==n)//when the number of data in b[] == the number who is going to be permutated , then print the number in this array
    {
        for(i=0;i<n;i++)
        {
            printf("%d",b[i]); // @@ Missing space separator between integers in the output. Should be printf("%d ", b[i]); to satisfy the output format requirement.
        }
        printf("\n");
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(c[j]==0)//if this number is not in this permutation 
            {
                b[m]=a[j];//put it in the full permutation
                c[j]=1;//and mark it that this number has been put into the permutation
                line(m+1,n);//other numbers do the permutation
                c[j]=0;//clean up this number from did-permutation-numbers , then come back to the upper
            }
        }
    }
}