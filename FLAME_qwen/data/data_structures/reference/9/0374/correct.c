#include <stdio.h>
#include <math.h>
#include <string.h>

struct a 
{
	int qd1,qd2,zd1,zd2;
	int num;
}line[105];
int sline[105][4];
int n,k=0,i,j,flag;
void find1(int sline[][4],struct a line[])
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(sline[i][0]==sline[j][2] && sline[i][1]==sline[j][3])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			line[k].qd1=sline[i][0],line[k].qd2=sline[i][1];
			line[k].zd1=sline[i][2],line[k].zd2=sline[i][3];
			k++;
		}
		flag=0;
	}
}
void find2(int sline[][4],struct a line[])
{
	for(i=0;i<k;i++)
	{
		line[i].num=1;
        for (j=0;j<n;j++)
        {
            if (line[i].zd1==sline[j][0] && line[i].zd2==sline[j][1])
            {
                line[i].zd1=sline[j][2];
                line[i].zd2=sline[j][3];
                line[i].num++;
                j=-1;
            }
        }
	}
}

int main()
{
	int max=0,r=0;
	scanf("%d",&n);
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&sline[i][j]);
		}
	}
	find1(sline,line);
	find2(sline,line);
	for(i=0;i<k;i++)
	{
		if(line[i].num>max)
		{
			max=line[i].num;
			r=i;
		}
	}
	printf("%d %d %d",max,line[r].qd1,line[r].qd2);
	return 0;	
} 



