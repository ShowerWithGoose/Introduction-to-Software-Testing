#include<stdio.h>
#include<stdlib.h>

struct unit{
	int coe;
	int pow;
};

int cmp(const void* a,const void* b)
{
	struct unit* f1 = (struct unit*)a;
	struct unit* f2 = (struct unit*)b;
	return f2->pow - f1->pow;
}

int main()
{
	int i=0,j=0,t=0,n=0,m=0;
	char ch;
	struct unit s1[100],s2[100],s3[100];
	
	do{
		scanf("%d%d%c",&s1[i].coe,&s1[i].pow,&ch);
		i++;
		n++;
	}while(ch != '\n');
	do{
		scanf("%d%d%c",&s2[j].coe,&s2[j].pow,&ch);
		j++;
		m++;
	}while(ch != '\n');
	
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			s3[t].coe = s1[i].coe * s2[j].coe;
			s3[t].pow = s1[i].pow + s2[j].pow;
			t++;
		}
	}
	qsort(s3,t,sizeof(struct unit),cmp);
	
	for(i=0;i<t;i++)
	{
		if(s3[i].pow == s3[i-1].pow)
		{
			s3[i].coe += s3[i-1].coe;
			s3[i-1].coe = 0;
		}
	}
	for(i=0;i<t;i++)
	{
		if(s3[i].coe != 0)
		{
			printf("%d %d ",s3[i].coe,s3[i].pow);
		}
	}
	return 0;
}








