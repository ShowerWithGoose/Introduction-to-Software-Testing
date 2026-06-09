#include <stdio.h>

struct X
{
	int x;
	int z;
}a[100],b[100],f[100],temp;

int main()
{
	char c;
	int i=0,j=0,d,e,p=0,l[100];
	while(scanf("%d %d%c",&a[i].x,&a[i].z,&c))    
    {
        i++;
        if(c == '\n')
            break;
    }
    while(scanf("%d %d%c",&b[j].x,&b[j].z,&c))    
    {
        j++;
        if(c == '\n')
            break;
    }
    if(i>=j)
    {
    	for(d=0;d<i;d++)
    	{
    		for(e=0;e<j;e++)
    		{
				f[p].x=a[d].x * b[e].x;
    			f[p].z=a[d].z + b[e].z;
    			l[p]=1;
				p++;   
			}
		}
	}
	else
    {
    	for(d=0;d<j;d++)
    	{
    		for(e=0;e<i;e++)
    		{
				f[p].x=a[e].x + b[d].x;
    			f[p].z=a[e].z * b[d].z;
    			l[p]=1;
				p++;
			}
		}
	}
	 for(i=0;i<p;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if(f[i].z < f[j].z )
            {
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    } 
	for(i=0;i<p;i++)
    {
        for(j=i+1;j<p;j++)
        {
        	if(f[i].z==f[j].z)
        	{
        		f[i].x=f[i].x+f[j].x;
        		l[j]=2;
			}
		}
	}
    for(i=0;i<p;i++)
    {
    	if(l[i]==1)
    	printf("%d %d ",f[i].x,f[i].z);
	}
    
    
    
    
    
    return 0;
}

