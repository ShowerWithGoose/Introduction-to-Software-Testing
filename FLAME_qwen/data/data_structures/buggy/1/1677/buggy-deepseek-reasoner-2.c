#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int a[11],b[11],c[11];// c[] is used for deciding whether the number has been writen into full permutation
int line(int ,int ); // @@ [Error: Should be void line(int, int); the function does not return an int on all paths.]

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

int line(int m,int n) // @@ [Error: Function declared to return int but does not return a value on all paths. It should be void or return a value.]
{
    int i,j;
    
    if(m==n)//when the number of data in b[] == the number who is going to be permutated , then print the number in this array
    {
        for(i=0;i<n;i++)
        {
            printf("%d",b[i]); // @@ [Error: Missing space between numbers. Expected output requires a space after each number except possibly the last? The reference program prints "%d " with space. This prints no separator, causing wrong format.]
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
} // @@ [Error: No return statement at end of non-void function.]