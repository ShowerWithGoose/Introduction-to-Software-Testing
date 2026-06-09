#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10
struct point
{
	int a[2];
	int b[2];
 } point[200],tmp;
int xianduan[200];
int cmp(const void *a, const void *b) 
{
    struct point *c = (struct point *)a;
    struct point *d = (struct point *)b;
	return c->a[0] - d->a[0];
}
int main()
{
	/*FILE *fp1;//定义文件指针 
	fp1 = fopen("filein.txt","r");//r为读 
	FILE *fp2; //定义文件指针 
	fp2 = fopen("fileout.txt","w");//w为写 
	fclose(fp1);
	fclose(fp2);*/
	int n,i,j,k,max=0,ans1,ans2,flag=0,len;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&point[i].a[0],&point[i].a[1],&point[i].b[0],&point[i].b[1]);		
	}
/*	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(point[j].a[0]<point[i].a[0])
			{
				tmp=point[j];
				point[j]=point[i];
				point[i]=tmp;	
			}
		}
	}*/
	qsort(point,n,sizeof(point[0]),cmp);
	for(i=0;i<n;i++)
	{
		len=1;
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(point[j].a[0]==point[k].b[0]&&point[j].a[1]==point[k].b[1])
			{
				len++;
				k=j;
			}
		}
		if(len>max)
		{
			max=len;
			ans1=point[i].a[0];
			ans2=point[i].a[1];
		}
	}
	printf("%d %d %d",max,ans1,ans2);
	return 0;	
 }//思路：将线段根据左端点进行排序，然后再以每一个线段为起始片段进行连接，找到线段最长的 




