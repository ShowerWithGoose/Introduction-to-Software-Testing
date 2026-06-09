#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[10000],str2[10000];
int len1,len2;
int mark1[1000],mark2[1000];//空格位置
int num1,num2=0;//空格数量 
int s1,s2;//项数 
int i,j,k=0;
struct point{
	long long a;
	long long x;
};
struct point* p1;
struct point* p2;
struct point* p3;
int comp(const void* a,const void* b)
{
	return(*(struct  point*)a).x<(*(struct  point*)b).x?1:-1;
}
int main()
{
	gets(str1);gets(str2);
	len1=strlen(str1);len2=strlen(str2);
	for(i=0;i<len1;i++)
	{
		if(str1[i]==' ')
		{
		num1++;
		mark1[j]=i;
		j++;
		}
	}
	for(i=0;i<len2;i++)
	{
		if(str2[i]==' ')
		{
		num2++;
		mark2[k]=i;
		k++;
		}
	}//空格所在位置和空格数量
	
	
	s1=(num1+1)/2;
	s2=(num2+1)/2;//项数 
	p1=(struct  point*)malloc(s1*sizeof(struct  point));
	p2=(struct  point*)malloc(s2*sizeof(struct  point));
	p3=(struct  point*)malloc(s1*s2*sizeof(struct  point));
	
	
	for(i=0;i<s1;i++)//初始化结构体的值 
	{
		p1[i].a=0;
		p1[i].x=0;
	}
	for(i=0;i<s2;i++)
	{
		p2[i].a=0;
		p2[i].x=0;
	}
	for(i=0;i<s1*s2;i++)
	{
		p3[i].a=0;
		p3[i].x=0;
	}
	//以上为初始化 
	
	
	if(num1==1)//只有一个项的情况 p1
	{
		for(i=0;i<len1;i++)
		{
			if(i<mark1[0]-1)
			p1[0].a=(p1[0].a+str1[i]-'0')*10;
			else if(i==mark1[0]-1)
			p1[0].a+=str1[i]-'0';
			if(i>mark1[0]&&i<len1-1)
			p1[0].x=(p1[0].x+str1[i]-'0')*10;
			else if(i==len1-1)
			p1[0].x+=str1[i]-'0';
		}
	}
	else//多个空格 （多于一项） 
	{
     for(i=0;i<mark1[1];i++)//p1第一位特殊 （默认空格有2个以上） 
	  {
		if(i<mark1[0]-1)
		{
			p1[0].a=(p1[0].a+str1[i]-'0')*10;
		}
		else if(i==mark1[0]-1)
		{
			p1[0].a+=str1[i]-'0';
		}
		if(i>mark1[0]&&i<mark1[1]-1)
		{
			p1[0].x=(p1[0].x+str1[i]-'0')*10;
		}
		else if(i==mark1[1]-1)
		{
			p1[0].x+=str1[i]-'0';
		}
	  }
        for(i=1;i<num1-2;i=i+2)//这里的i是mark[]用的 
	  {
		for(j=mark1[i]+1;j<mark1[i+2];j++)//两个空格之间的 
		{
			if(j<mark1[i+1]-1)
			p1[(i+1)/2].a=(p1[(i+1)/2].a+str1[j]-'0')*10;
			else if(j==mark1[i+1]-1)
			p1[(i+1)/2].a+=str1[j]-'0';
			if(j>mark1[i+1]&&j<mark1[i+2]-1)
			p1[(i+1)/2].x=(p1[(i+1)/2].x+str1[j]-'0')*10;
			else if(j==mark1[i+2]-1)
			p1[(i+1)/2].x+=str1[j]-'0';
		}//最后一位没有处理 
	  }
	  // 处理最后一位 
	for(i=mark1[num1-2]+1;i<len1;i++)
	  {
		if(i<mark1[num1-1]-1)
		p1[s1-1].a=(p1[s1-1].a+str1[i]-'0')*10;
		else if(i==mark1[num1-1]-1)
		p1[s1-1].a+=str1[i]-'0';
		if(i>mark1[num1-1]&&i<len1-1)
		p1[s1-1].x=(p1[s1-1].x+str1[i]-'0')*10;
		else if(i==len1-1)
		p1[s1-1].x+=str1[i]-'0';
	  }
	} 
	if(num2==1)
	{
		for(i=0;i<len2;i++)
		{
			if(i<mark2[0]-1)
			p2[0].a=(p2[0].a+str2[i]-'0')*10;
			else if(i==mark2[0]-1)
			p2[0].a+=str2[i]-'0';
			if(i>mark2[0]&&i<len2-1)
			p2[0].x=(p2[0].x+str2[i]-'0')*10;
			else if(i==len2-1)
			p2[0].x+=str2[i]-'0';
		}		
	}
	else
	{
	for(i=0;i<mark2[1];i++)//第一位特殊 （默认空格两个以上） 
	  {
		if(i<mark2[0]-1)
		{
			p2[0].a=(p2[0].a+str2[i]-'0')*10;
		}
		else if(i==mark2[0]-1)
		{
			p2[0].a+=str2[i]-'0';
		}
		if(i>mark2[0]&&i<mark2[1]-1)
		{
			p2[0].x=(p2[0].x+str2[i]-'0')*10;
		}
		else if(i==mark2[1]-1)
		{
			p2[0].x+=str2[i]-'0';
		}
	  }
	
	for(i=1;i<num2-2;i=i+2)//这里的i是mark[]用的 ，最后一位除外 
	  {
		for(j=mark2[i]+1;j<mark2[i+2];j++)//两个空格之间的 
		{
			if(j<mark2[i+1]-1)
			p2[(i+1)/2].a=(p2[(i+1)/2].a+str2[j]-'0')*10;
			else if(j==mark2[i+1]-1)
			p2[(i+1)/2].a+=str2[j]-'0';
			if(j>mark2[i+1]&&j<mark2[i+2]-1)
			p2[(i+1)/2].x=(p2[(i+1)/2].x+str2[j]-'0')*10;
			else if(j==mark2[i+2]-1)
			p2[(i+1)/2].x+=str2[j]-'0';
		} 
	  }//最后一位没有处理 	
	for(i=mark2[num2-2]+1;i<len2;i++)
	  {
		if(i<mark2[num2-1]-1)
		p2[s2-1].a=(p2[s2-1].a+str2[i]-'0')*10;
		else if(i==mark2[num2-1]-1)
		p2[s2-1].a+=str2[i]-'0';
		if(i>mark2[num2-1]&&i<len2-1)
		p2[s2-1].x=(p2[s2-1].x+str2[i]-'0')*10;
		else if(i==len2-1)
		p2[s2-1].x+=str2[i]-'0';
	  }
	}
	
	
	
	
	
	for(i=0,k=0;i<s1;i++)
	{
		for(j=0;j<s2;j++)
		{
			p3[k].a=(p1[i].a)*(p2[j].a);
			p3[k].x=p1[i].x+p2[j].x;
			k++;
		}
	}//计算所有乘积 
	
	for(i=0;i<s1*s2-1;i++)
	{
		if(p3[i].a!=0)
		for(j=i+1;j<s1*s2;j++)
		{
			if(p3[i].x==p3[j].x)
			{
				p3[i].a+=p3[j].a;
				p3[j].a=0; 
			}
		}
	}
	qsort(p3,s1*s2,sizeof(p3[0]),comp);
	for(i=0;i<s1*s2;i++)
	{
		if(p3[i].a!=0)
		printf("%lld %lld ",p3[i].a,p3[i].x);
	}


} 



