#include<stdio.h>
#include<string.h>
int read(char str[],int i);
int jump(char str[],int i);
void clear(char str[]);
int main(void)
{
    char str[999]={};
    char sign[100]={};
    int number[100]={};
    fgets(str,99,stdin);
    clear(str);
    int i=0;
    int location=0;
    while(str[i]!='=')
    {
        int num=0;
        num=read(str,i);
        i=jump(str,i);
        if(str[i]=='=')
        {
            number[location]=num;
            break;
        }
        while(str[i]=='*'||str[i]=='/')
        {
            i++;
            if(str[i-1]=='*')
            {
                num*=read(str,i);
                i=jump(str,i);
            }
            if(str[i-1]=='/')
            {
                num/=read(str,i);
                i=jump(str,i);
            }   
        }
        if(str[i]=='+')
        {
            i++;
            number[location]=num;
            sign[location]='+';
            location++;
        }
        else if(str[i]=='-')
        {
            i++;
            number[location]=num;
            sign[location]='-';
            location++;
        }
        else
        {
        	number[location]=num;
        	break;
		}
    }
    int num=number[0];
    for(i=0;i<strlen(sign);i++)
    {
        if(sign[i]=='+')
            num+=number[i+1];
        else
            num-=number[i+1];
    }
    printf("%d",num);
}
int read(char str[],int i)
{
    int num=0;
    while(str[i]>='0'&&str[i]<='9')
    {
        num+=str[i]-48;
        i++;
        if(str[i]>='0'&&str[i]<='9')
            num*=10;
    }
    return num;
}
int jump(char str[],int i)
{
    while(str[i]>='0'&&str[i]<='9')
        i++;
    return i;
}
void clear(char str[])
{
    int i=0;
    while(i<strlen(str))
    {
        if(str[i]==' ')
        {
            int j;
            for(j=i;j<strlen(str)-1;j++)
            {
                str[j]=str[j+1];
            }
        }
        if(str[i]!=' ')
        	i++;
    }
}
