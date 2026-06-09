#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#include <ctype.h>
#define eps 1e-6 
int visit[1000];
struct mul{
    int a,n;

}; 

void getword(char s[],int len)
{
    int i=0;
    
}

int search(int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(visit[i]==x) return i;
    }
    return -1;
}

int main() {
    struct mul*p[100],*q[100],*r[10000];
    char s1[10000],s2[10000];
    p[0]=(struct mul*)malloc(sizeof(struct mul*)); // @@ Incorrect allocation size; should be sizeof(struct mul), leads to insufficient memory and undefined behavior.

    int i=0;
    while(scanf("%d %d ",&p[i++]->a,&p[i]->n)!=EOF) // @@ Undefined behavior: uses p[i] after increment for second argument without proper allocation; also p[i] may not be allocated for i>0.
    {
        p[i]=(struct mul*)malloc(sizeof(struct mul*)); // @@ Wrong allocation size; should be sizeof(struct mul). Also, p[i] was already used in scanf argument for this iteration.
        
    }
    int k;k=i-1;int count=p[0]->n;
    for(i=0;i<k-1;i++) // @@ Logic error: assumes polynomial boundary where exponent increases, but fails when exponents are equal across polynomials (as in test case).
    {
        if(p[i]->n<p[i+1]->n)
        {
            break;
        }
    }
    
    int n1=i+1,n2=k-i-1; // @@ Logic error: n2 becomes 0 in test case because boundary detection fails, causing no multiplication.
    i++; // @@ Unnecessary increment, further misaligns indices.
    for(int j=0;i<k;i++,j++)
    {
        q[j]=p[i];
    }
    int t=0;
    
    for(i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(search(p[i]->n+q[j]->n,t)==-1)
            {
                
                r[t]=(struct mul*)malloc(sizeof(struct mul*)); // @@ Wrong allocation size; should be sizeof(struct mul).
                r[t]->n=p[i]->n+q[j]->n;
                r[t]->a=p[i]->a*q[j]->a;
                visit[t++]=p[i]->n+q[j]->n;
            }
            else
            {
                r[search(p[i]->n+q[j]->n,t)]->a+=p[i]->a*q[j]->a;    
            }
        }
    }
    struct mul*s;
    for(int x=0;x<t;x++)
    {
        for(int y=x+1;y<t;y++)
        {
            if(r[x]->n < r[y]->n)
            {
                s=r[x];
                r[x]=r[y];
                r[y]=s;
            }
        }
    }
    for(int j=0;j<t;j++)
    {
        if(r[j]->a==0) continue;
        printf("%d %d ",r[j]->a,r[j]->n);
    }
    
return 0;
}