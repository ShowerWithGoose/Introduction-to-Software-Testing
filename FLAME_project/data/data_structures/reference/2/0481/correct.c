#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void Shuzi(char s[],int a[])
{
    int i,j;
    for(i=0,j=0;i<strlen(s);i++)
    {
    	if(s[i]<'0'||s[i]>'9')
    	{
    		continue;
		}
        while(s[i]>='0'&&s[i]<='9')
        {
            a[j]=a[j]*10+s[i]-'0';
            i++;
        }
        j++;
    }
}
void Fuhao(char s[],char t[])
{
	int i,j;
	if(s[0]=='-')
    {
       	t[0]='-';
	}
	else 
	{
		t[0]='+';
	}
    for(i=1,j=1;i<strlen(s);i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            t[j++]=s[i];
        	
    }
}
int main()
{
	char s[1000];
	char t[100];
	int a[100];
	int i,j,ans=0; 
	gets(s);
	memset(a,0,100*sizeof(int));
	//删去空格
    for(i=0,j=0;i<strlen(s);i++)
    {
        if(s[i]==32)
        {
            continue;
        }
        s[j++]=s[i];
    }
    s[j]='\0';
    //总结数字符号
	Shuzi(s,a);
	Fuhao(s,t);
	//优先乘除
	for(i=0;i<strlen(t);i++)
    {
    	j=i-1;
        while(t[i]=='*'||t[i]=='/')
        {
        	if(t[i]=='*')
        	{
        		a[j]*=a[i]; 
			}
			else
			{
				a[j]/=a[i];
			}
        	i++;
		}
    } 
    //加减
    ans=0;
	for(i=0;i<strlen(t);i++)
	{
		if(t[i]=='+')
		{
			ans+=a[i];
		}
		else if(t[i]=='-')
		{
			ans-=a[i];
		}
	}  
	printf("%d",ans);
	return 0;
}




