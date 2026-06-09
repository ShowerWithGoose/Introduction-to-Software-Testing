#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))
int main()
{
    int stack[100];
    int top=-1,i,x=0,y;
    for(i=0;;i++)
    {
        sf("%d",&x);
        if(x==1)
        {
            sf("%d",&y);
            if(top!=100)
            stack[++top]=y;
            else
            pf("error ");
        }
        else if(x==0)
        {
            if(top!=-1)
            pf("%d ",stack[top--]);
            else
            pf("error ");
        }
        if(x==-1)
        break;
    } 
}
