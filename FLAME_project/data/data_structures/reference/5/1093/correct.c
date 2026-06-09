#include<stdio.h>
#include<stdlib.h>
struct node{
	int x;
	int z;
}node;
struct node a[100],b[100],s[500],out[200];
int cmp(struct node *p1,struct node *p2)
{
	if(p1->z<p2->z)return 1;
	else if(p1->z>p2->z)return -1;
	return 0;
}
int main()
{
	int i=0,j,k=0;
	int lena,lenb;
	int n;
	char ch;
//	lnode p;
	
	while(1)
	{
		scanf("%d%d%c",&a[i].x,&a[i].z,&ch);
		i++;
		if(ch=='\n')break;
	}
	lena=i;
	i=0;
	while(1)
	{
		scanf("%d%d%c",&b[i].x,&b[i].z,&ch);
		i++;
		if(ch=='\n')break;
	}
	lenb=i;
	
	for(i=0;i<lena;i++)
		for(j=0;j<lenb;j++)
		{
			s[k].x=a[i].x*b[j].x;
			s[k].z=a[i].z+b[j].z;
			k++;
		}
	qsort(s,k,sizeof(node),cmp);
	
	n=k;
	k=0;
	for(i=0;i<n;i++)
	{
		out[k].x=s[i].x;
		out[k].z=s[i].z;
		j=i+1;
		while(s[j].z==s[i].z)
		{
			out[k].x+=s[j].x;
			j++;
		}
		k++;
		i=j-1;
	}
	for(i=0;i<k;i++)
	printf("%d %d ",out[i].x,out[i].z);
	return 0;
}

