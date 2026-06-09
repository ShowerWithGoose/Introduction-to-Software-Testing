#include <stdio.h>
#include <string.h>
int transform(char a[],int i)
{
	int w=0;
	while(a[i]>='0'&&a[i]<='9')
	{
		w++;
		i++;
	}
	int p=0,q=1;
	for(;w>=1;w--)
	{
		p+=(a[--i]-'0')*q;
		q*=10;
	}
	return p;
}
int length(int a)
{
	int cnt=1;
	while(a/10!=0)
	{
		a/=10;
		cnt++;
	}
	return cnt;
}

    struct group
{
	int num;
	char point;
};

int main()
{
	struct group zbj[100];
	
	char a[105],c[105];
	int i,j=0;
	gets(a);
	//消掉空格 
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ') 
		{
			c[j++]=a[i];
		}
	}
	int l=strlen(c);
	                                     //printf("%d ",transform(c,0));
	//数据存入结构体数组 
	for(i=0,j=0;i<l;j++)
	{
		if(i==0)  
		{
			zbj[j].point='+';
			zbj[j].num=transform(c,i);
			i+=length(zbj[j].num);
		}
		else
		{
			zbj[j].point=c[i];
			zbj[j].num=transform(c,i+1);
			i+=length(zbj[j].num)+1;
		}
	}
	//计算乘除 
	for(i=0;i<j;i++)
	{
		if(zbj[i].point=='*')
		{
			zbj[i-1].num*=zbj[i].num;
			int k;
			for(k=i;k<j;k++)
	      {  
		     zbj[k].num=zbj[k+1].num;
		     zbj[k].point=zbj[k+1].point;
          }
          i=0;
		}
		if(zbj[i].point=='/')
		{
			zbj[i-1].num/=zbj[i].num;
			int k;
			for(k=i;k<j;k++)
	      {  
		     zbj[k].num=zbj[k+1].num;
		     zbj[k].point=zbj[k+1].point;
          }
          i=0;
		}
	}
	//计算加减 
	int result=0;
	
		for(i=0;i<j;i++)
	{
        if(zbj[i].point=='+') result+=zbj[i].num;
        if(zbj[i].point=='-') result-=zbj[i].num;
    }
	printf("%d\n",result);
	
//	for(j=0;j<7;j++)
//	{
//		printf("%d %c\n",zbj[j].num,zbj[j].point);
//	}
	//(+)52-11 * 2 *3+ 12/2/2= 
	//  0    1   2   3   4    5   6
	
	//52+12312-21321+123-21312 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 



