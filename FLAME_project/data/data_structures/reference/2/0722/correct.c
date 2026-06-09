#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int b[100],number[100];
int main()
{
    char a[1000];
    int m=0,t,i,j=1,k=0,s=0,into=0;
    gets(a);
    for (i=0;a[i]!='=';)//将数字和运算符分别输入两个数组 
    {
    	while(a[i]==' ')
            {
               i++;
            }
         if (a[i]<='0'||a[i]>='9')
        { 
       		 if(a[i]=='+')
       		 {
        		b[k]=1;
			}
			if (a[i]=='-')
			{
				b[k]=-1;
			}
			if (a[i]=='*')
			{
				b[k]=3;
			}
			if (a[i]=='/')
			{
				b[k]=4;
			}
			i++;
			m=0;
		} 
		while(a[i]==' ')
            {
               i++;
               m=0;
            }
    	
       while(a[i]>='0'&&a[i]<='9')
       {
       	m=10*m+a[i]-'0';
       	i++;
	   }
	   number[k]=m;
	   k++; 
		while(a[i]==' ')
            {
               i++;
               m=0;
            }	
    }
    while (j<k)//乘除 
    {
    	while (b[j]==1||b[j]==-1)
    	{
    		j++;
		}
		t=j-1;
		while (b[t]==0&&t!=0)//判断该位置是否为空 
		{
			t--;
		}
		if (b[j]==3)
		{
			number[t]*=number[j];//将计算结果存在第一个数的位置 
			number[j]=0;//删除计算过的数 
			b[j]=0;//删除计算过的符号 
		}	
		if (b[j]==4)
		{
			number[t]/=number[j];
			number[j]=0;
			b[j]=0;
		}
		j++;
	}
	j=1;
	s=number[0];
	while (j<k)//加减 
	{
		s+=number[j]*b[j];
		j++;
	}
    printf("%d",s);
    
    return 0;
}

