#include<stdio.h>
#include<stdlib.h>
typedef struct linedef{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	int group;
}LINE;
int cmp1(const void* pa,const void* pb)
{
	return (*(LINE*)pa).group-(*(LINE*)pb).group;
}
int cmp2(const void*pa,const void *pb)
{
	return (*(LINE*)pa).x1-(*(LINE*)pb).x1;
}
int selmax(int groupnum[],int len)
{
	int maxid=0;
	for(int i=0;i<len;i++)
	{
		if(groupnum[i]==0)
		continue;
		else 
		{
			if(groupnum[i]>groupnum[maxid])
			{
				maxid=i;
			}
			else
			continue;
		}
	}
	return maxid;
}
int cmp3(const void*pa,const void *pb)
{
	return *(int *)pa-*(int*)pb;
}
int link(LINE line1,LINE line2)
{
	if(line1.x1==line2.x1&&line1.y1==line2.y1)
	return 1;
	else if(line1.x1==line2.x2&&line1.y1==line2.y2)
	return 1;
	else if(line1.x2==line2.x1&&line1.y2==line2.y1)
	return 1;
	else if(line1.x2==line2.x2&&line1.y2==line2.y2)
	return 1;
	else
	return 0;
}

int main()
{
	LINE line[101];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].num=1;
		line[i].group=0;
	}
	int group=2;
	line[0].group=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(link(line[i],line[j]))
			{
				if(line[j].group==0)
				line[j].group=line[i].group;
				else
				{
					if(line[i].group<line[j].group)
					{
						for(int k=0;k<n;k++)
						{
							if(line[k].group==line[j].group)
							line[k].group=line[i].group;
						}
						line[j].group=line[i].group;
					}
					else
					{
						line[i].group=line[j].group;
						for(int k=0;k<n;k++)
						{
							if(line[k].group==line[i].group)
							line[k].group=line[j].group;
						}
					}
				}
			}
			else
			{
				if(line[j].group==0)
				{
					line[j].group=group;
					group++;
				}
			}
		}
	}
	qsort(line,n,sizeof(LINE),cmp1);
	int groupnum[101]={0};
	for(int i=0,j=0;i<n&&j<n;i++)
	{
		while(line[j].group==i)
		{
			groupnum[line[j].group]++;
			j++;
		}
	}
	int cnt=0;
	for(int i=0;i<group;i++)
	{
		if(groupnum[i]!=0)
		{
			qsort(&line[cnt],groupnum[i],sizeof(LINE),cmp2);
			cnt+=groupnum[i];
		}
	}
	int maxid=selmax(groupnum,group);
	for(int i=0;i<n;i++)
	{
		if(line[i].group==maxid)
		{
			printf("%d %d %d\n",groupnum[maxid],line[i].x1,line[i].y1);
			break;
		} 
	}
	
	
	return 0;
}




