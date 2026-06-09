#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int a[110][5],b[5];
int main()
{
    int n,s=0,k;
    scanf("%d",&n);
    for (int i = 0;i < n;i ++)
    {
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	for (int i = 0;i < n;i ++)
	    {
			for (int j = i+1;j < n;j ++)
			    {
				    if(a[i][0]>a[j][0])
				    {
					 	for(int k = 0;k < 4;k ++)
					 	{
						 	b[k]=a[i][k];
						 	a[i][k]=a[j][k];
						 	a[j][k]=b[k];
						}
					} 
				}
		}
		  /* for (int i = 0;i < n;i ++)
		    {
				printf("%d %d %d %d ",a[i][0],a[i][1],a[i][2],a[i][3]);
				puts("");
			}*/
		int x,y,z=0;
    for (int i = 0;i < n;i ++)
    {
    	k=i;
		for (int j = i+1;j < n;j ++)
		    {

				if(a[k][2]==a[j][0]&&a[k][3]==a[j][1])
				{
					s++;
					k=j;
				}
			}
			if(s>z)
			{
				z=s;x=a[i][0];y=a[i][1];
			}
			s=0;
	}
	printf("%d %d %d",z+1,x,y);	
    return 0;
}

