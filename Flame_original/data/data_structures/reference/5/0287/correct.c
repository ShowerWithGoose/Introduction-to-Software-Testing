#include<stdio.h>
struct line{
	int x;
	int y;
}s1[10005],s2[10005],s3[10005],s4[10005];
int cmp(const void *a,const void *b)
{
	struct line c=*(struct line *)a;
	struct line d=*(struct line *)b;
	return d.y -c.y ;
}
int main()
{
	int i,j,k,l,m;
	char c='a';
	i=0;
	while(c!='\n')
	{
		scanf("%d%d%c",&s1[i].x ,&s1[i].y ,&c);
		i++;
	}
	c=' ';
	j=0;
	while(c!='\n')
	{
		scanf("%d%d%c",&s2[j].x ,&s2[j].y ,&c);
		j++;
	}
	m=0;
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			s3[m].x =s1[k].x *s2[l].x ;
			s3[m].y =s1[k].y +s2[l].y ;
			m++;
		}
	}
	qsort(s3,m,sizeof(s3[0]),cmp);
	for(i=0;i<m;i++)
	{
		if(s3[i].y ==s3[i+1].y&&s3[i].y !=0 )
		{
			s3[i+1].x =s3[i+1].x +s3[i].x ;
			s3[i].x =0;
		}
	}
	for(i=0;i<m;i++)
	{
		if(s3[i].x !=0)	printf("%d %d ",s3[i].x ,s3[i].y );
	}
	return 0;
}

