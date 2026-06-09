#include <stdio.h>
#include<stdlib.h>
struct m{
	int a;
	int x;
};
struct m mu[100],d[100],z[100];
void pubble(int n)
{
    int i,j;
    struct m temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mu[i].x < mu[j].x )
            {
                temp = mu[i];
                mu[i] = mu[j];
                mu[j] = temp;
            }
            if(mu[i].x==mu[j].x)
            {
            	mu[i].a=mu[j].a+mu[i].a;
            	mu[j].x=-10;	
			}
		}
	}
}
int i=0, j, f,n=0,k;
void li()
{
	for(i=0;i<f;i++)     
    {
        for(k=0;k<f;k++)
        {
            mu[n].a = d[i].a * z[k].a;
            mu[n].x = d[i].x + z[k].x;
            n++;
        }
    }
}
int main()
{
    
    char c;
    while(scanf("%d %d%c",&d[f].a,&d[f].x,&c))
    {f++;
    if(c=='\n')
    break;
	}
while(scanf("%d %d%c",&z[f].a,&z[f].x,&c))
    {f++;
    if(c=='\n')
    break;}
     li();
    pubble(n);
   ko();
    return 0;
}

void ko()
{
	
	 for(i=0;i<n;i++)
    {
        if(mu[i].x != -10&&mu[i].a!=0)
            printf("%d %d ",mu[i].a,mu[i].x);
    }
 } 

