#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int x;
	int z;
}sent;
sent s1[1000],s2[1000],s3[10000];
int cmp(const void *a,const void *b)
{
	return -(*(sent*)a).z+(*(sent*)b).z;
}
int main()
{
	int i,j,n1=0,n2=0,n3=0;
	while(1)
	{
		scanf("%d %d",&s1[n1].x,&s1[n1].z);
		n1++;
		if(getchar()=='\n')
		break;
	}
	while(1)
	{
		scanf("%d %d",&s2[n2].x,&s2[n2].z);
		n2++;
		if(getchar()=='\n')
		break;
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			s3[n3].x=s1[i].x*s2[j].x;
			s3[n3].z=s1[i].z+s2[j].z;
			n3++;
		}
	}
	qsort(s3,n3,sizeof(sent),cmp);
	s3[n3].z=1;
	for(i=0;i<n3;i++)
	{
		j=1;
		while(s3[i].z==s3[i+j].z)
		{
			s3[i].x+=s3[i+j].x;
			j++;
		}
		printf("%d %d ",s3[i].x,s3[i].z);
		i+=j-1;
	}
	return 0;
} 

