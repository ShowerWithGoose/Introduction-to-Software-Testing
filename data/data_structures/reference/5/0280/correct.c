#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct NUM
{
	int x;
	int y;
};//x代表系数，而y代表指数 
struct NUM num1[100000],num2[100000],num3[100000];//num3用来储存新的数组 
int cmp(const void *a,const void *b);
int search(int n);
int temp[2];
int total;//表示num3中项的个数 
int main()
{
	char line[100000];
	int i,j,k=0,len;
	int m=0,n=0;
	int hold[2],flag=0;//flag表示是第一行还是第二行 
	int pos1,pos2;//pos表示两行的项数 
	int wei;//表示找到的是当前多少位 
	while(gets(line)!=NULL)
	{
		len=strlen(line);//尝试用sscanf
		if(flag==0)
		{
			for(i=0;i<len;i++)	
			{
				if(isdigit(line[i]))
				{
					for(j=i;(isdigit(line[j])!=0);j++)
					{
						hold[k]=10*hold[k]+line[j]-'0';
					}
					k++;
					i=j;
				}	
				if(k%2==0)
				{
					num1[m].x=hold[0];
					num1[m].y=hold[1];
					m++;
					for(n=0;n<2;n++)
					hold[n]=0;
					k=0;	
				}	
			}	
			pos1=m;
			m=0;
		}//实现第一行数字的读入 
		k=0;
		if(flag==1)
		{
			for(i=0;i<len;i++)	
			{
				if(isdigit(line[i]))
				{
					for(j=i;(isdigit(line[j])!=0);j++)
					{
						hold[k]=10*hold[k]+line[j]-'0';
					}
					k++;
					i=j;
				}
				if(k%2==0)
				{
					num2[m].x=hold[0];
					num2[m].y=hold[1];
					m++;
					for(n=0;n<2;n++)
					hold[n]=0;
					k=0;	
				}	
				
			}
			pos2=m;
			m=0;
			break;
		}//实现第二行数字的读入
		flag++;
	}//实现数字的读入并且储存在结构体中
	k=0;	
	for(i=0;i<pos1;i++)
	{
		for(j=0;j<pos2;j++)
		{
			temp[0]=(num1[i].x)*(num2[j].x);
			temp[1]=(num1[i].y)+(num2[j].y);
			if(search(temp[1])!=-1) 
			{
				wei=search(temp[1]);
				num3[wei].x+=temp[0];
			}//当找到时
			if(search(temp[1])==-1)
			{
				num3[k].y=temp[1];
				num3[k].x=temp[0];
				total++;
				k++;
			} //当没有找到时
			for(n=0;n<2;n++)
			temp[n]=0;
		}
	}		
	qsort(num3,total,sizeof(num3[0]),cmp);//按照位数进行排序 
	for(i=0;i<total;i++)
	{
		if((num3[i].x)!=0)
		{
			printf("%d %d ",num3[i].x,num3[i].y);
		}
	}
	return 0;
 }
 int search(int n)
 {
 	int i,flag=0;
 	for(i=0;i<total;i++)
 	{
 		if(num3[i].y==n)
 		{
 			return i;
 			flag=1;
		 }
	 }
	 if(flag==0)
	 return -1;
 }
 int cmp(const void *a,const void *b)
 {
 	return (((struct NUM*)b)->y)-(((struct NUM*)a)->y);
 	//struct NUM *c,*d;
 	//c=(struct NUM*)a;
 	//d=(struct NUM*)b;
 	//return (c->y)-(d->y);
 }
 
 

