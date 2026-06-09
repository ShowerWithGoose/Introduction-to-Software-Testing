#include<stdio.h>
#include<math.h>
#include<string.h>
#define eps 10e-10
#define GET_BIT(value, bit) (((value) >> bit) & 1)
int mark[10]={0}; // @@ array size too small; should be 11 to index up to 10
char ans[11]; // @@ insufficient for output format; need spaces and two-digit numbers
int x;



int main()
{
scanf("%d",&x);
dg(0,x); // @@ implicit function declaration; missing prototype before main

return 0;
}
void dg(int m, int n)
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans); // @@ output format incorrect; expected numbers separated by spaces
    return;
    }    
    
    
    
    
for(int i=1;i<=x;i++) // @@ when x=10, accesses mark[10] out of bounds; also redeclares i (C99 allows)
if(mark[i]==0) // @@ potential out-of-bounds access when i=10
{
    mark[i]=1; // @@ out-of-bounds when i=10
    ans[m]=i+'0'; // @@ for i>=10, character representation incorrect; no space added
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}