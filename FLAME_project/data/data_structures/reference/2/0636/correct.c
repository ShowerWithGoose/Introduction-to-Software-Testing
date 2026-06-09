/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 1024
char s[MAXLINE],group[200][50];
int groupnum,sum=0;
void shorten(char s[])
{
	int i,j;
 	for(i=0,j=0;s[i]!='=';i++)
  		if(s[i]!=' ')
   			s[j++]=s[i];
 	s[j]='=';
 	return;
}
void divide(char s[])
{
 	int i,j,k;
 	for(i=0,j=0;s[i]!='=';j++)
 	{
		k=0;
		if(s[i]=='+'||s[i]=='-')
  		{
   			group[j][k++]=s[i++];
   			while(s[i]!='+'&&s[i]!='-'&&s[i]!='=')
    			group[j][k++]=s[i++];
  		}
  		else//第一个数无符号
   			while(s[i]!='+'&&s[i]!='-'&&s[i]!='=')
   				group[j][k++]=s[i++];
 	}
 	groupnum=j;
 	return;
}
void calculate(char group[][50])
{
 	int i,j,num,part,flag,flag2;
 	for(i=0;i<groupnum;i++)
 	{
  		flag=0;//判断正负 
  		part=1;
  		for(j=0;group[i][j]!='\0';j++)
  		{
			if(group[i][j]=='-')
   			{
    			flag=-1;
    			j++;
  			}
   			else if(group[i][j]=='+')
    			j++;
   			flag2=0;//判断乘除 
   			if(group[i][j]=='*')
   			{
   				flag2=1;
    			j++;
   			}
   			else if(group[i][j]=='/')
   			{
    			flag2=-1;
    			j++;
   			}
   			num=0;
   			while(group[i][j]>='0'&&group[i][j]<='9')//字符转数字 
    			num=num*10+group[i][j++]-'0';
    		j--;//防止j多加1(for里有j++) 
   			if(flag2==1)
				part*=num;
   			else if(flag2==-1)
    			part/=num;
   			else
    			part=num;
  		}
  		if (flag)
   			part*=-1;
  		sum+=part;
 	}
    return;
}
int main()
{
 	fgets(s,MAXLINE-1,stdin);
 	shorten(s);//去空格
 	divide(s);//以+-分块
 	calculate(group);//计算
 	printf("%d",sum);
}



