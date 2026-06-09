#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n;
	int mid,m[100]={0},p=0;
	scanf("%d",&n);
	int x1[100],y1[100],x2[100],y2[100];
	int x,y;
	int f[100],l[100];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (x1[j] > x1[j + 1]) {
                mid=x1[j];
                x1[j]=x1[j+1];
                x1[j+1]=mid;
                mid=y1[j];
                y1[j]=y1[j+1];
                y1[j+1]=mid;
                mid=x2[j];
                x2[j]=x2[j+1];
                x2[j+1]=mid;
                mid=y2[j];
                y2[j]=y2[j+1];
                y2[j+1]=mid;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
    	x=x2[i];
    	y=y2[i];
    	f[p]=x1[i];
    	l[p]=y1[i];
		for(int j=i+1;j<n;j++)
    	{
    		if(x==x1[j]&&y==y1[j])
    		{
    			x=x2[j];
    			y=y2[j];
    			m[p]++;
			}
		}
		p++;
	}
	for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (m[j] < m[j + 1]) {
               mid=m[j];
               m[j]=m[j+1];
               m[j+1]=mid;
               mid=f[j];
               f[j]=f[j+1];
               f[j+1]=mid;
               mid=l[j];
               l[j]=l[j+1];
               l[j+1]=mid;
            }
        }
    }
    printf("%d %d %d",m[0]+1,f[0],l[0]);
    return 0;
}
