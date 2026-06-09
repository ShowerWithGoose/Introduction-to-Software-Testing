#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
struct {
	int shu[10000];
	char fu[10000];
}stack;
int top1,top2;
int judge(char b)
{
	if(b=='+'||b=='-')
	{
		return 1;
	}else if(b=='*'||b=='/')
	{
		return 2;
	}
}
int main()
{
	char a[10000],b[10000];
	gets(a);
	int i,j=0;
	int s,flag=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			b[j]=a[i];
			j++;
		}
	}//去掉空格 
	for(i=0;i<strlen(b);i++)
	{
		s=0;
		if(b[i]>='0'&&b[i]<='9')
		{
			while(b[i]>='0'&&b[i]<='9')
			{
				s=s*10+b[i]-'0';
				i++;
			}
			stack.shu[++top1]=s;
			i--; 
		}else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')
		{
			stack.fu[++top2]=b[i];
			if(top2>=2&&judge(stack.fu[1])==2)
			{
				if(stack.fu[1]=='*')
				{
					s=stack.shu[top1-1]*stack.shu[top1]; 
				}else
				{
					s=stack.shu[top1-1]/stack.shu[top1];
				}
				top1--;
				top2--;
				stack.fu[top2]=b[i];
                stack.shu[top1]=s;  
                
			}
			if(top1>=3&&top2>=3&&judge(stack.fu[top2-1])==2)
			{
				if(stack.fu[top2-1]=='*')
				{
					s=stack.shu[top1-1]*stack.shu[top1]; 
				}else
				{
					s=stack.shu[top1-1]/stack.shu[top1];
				}
				top1--;
				top2--;
				stack.fu[top2]=b[i];
                stack.shu[top1]=s;  
			}
			
		}else{
			if(judge(stack.fu[top2])==2)
			{
				if(stack.fu[top2]=='*')
				{
					s=stack.shu[top1-1]*stack.shu[top1]; 
				}else
				{
					s=stack.shu[top1-1]/stack.shu[top1];
				}
				top1--;
				top2--;
                stack.shu[top1]=s;  
			}
		}
	}
	s= stack.shu[1];               //从第一个数开始
    for(i = 1; i< top1; i++)
    {
        if(stack.fu[i]== '+') 
		{
		s+=stack.shu[i+1]; 
		}      //运算加减
        else s-=stack.shu[i+1];
    }
    printf("%d",s);
    return 0;
}

