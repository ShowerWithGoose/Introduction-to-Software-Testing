#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[100][4];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		
	} 
	int cnt=0;
	int max=0;
	int m[1][2];
	for(int i=0;i<n;i++)
	{
		int ii=i;
		cnt=1;
		for(int j=0;j<n;j++)
		{
			if(a[i][2]==a[j][0]&&a[i][3]==a[j][1])
			{
				cnt++;
				i=j;
				j=-1;
			}
			
		}
		if(cnt>max)
		{
			max=cnt;
			m[0][0]=a[ii][0];
			m[0][1]=a[ii][1];
		}
		i=ii;
		
	}
	printf("%d %d %d",max,m[0][0],m[0][1]);
	return 0;
}

